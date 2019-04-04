#include <iostream>
#include <cstdio>
#include <cstdint>

using namespace std;

uint64_t fixedTrue(struct Data[], uint64_t);
uint64_t staticFirst(struct Data[], uint64_t);
uint64_t biModal(struct Data[], uint64_t);
uint64_t twoLayerAdaptive(struct Data[], uint64_t);

struct Data
{
    uint64_t addr1;
    uint64_t addr2;
    char branchTaken;
};

int main(int argc, char *argv[])
{
    // Help stuff
    if (argc == 1 || argv[1] == NULL || !strcmp(argv[1], "-h"))
    {
        cout << "Help."
             << endl
             << "You probably forgot the tokenizer file, silly goose." << endl;
        return 0;
    }
    //
    FILE *traFile = fopen(argv[1], "r");
    if (traFile == NULL)
    {
        cout << "File Error" << endl;
        return 0;
    }
    uint64_t numLines = 0;
    while (!feof(traFile))
    {
        if (fgetc(traFile) == '\n')
        {
            numLines++;
        }
    }
    // cout << numLines;
    rewind(traFile);

    // Get contents of tokenizer file
    Data lines[numLines];
    for (int a = 0; a < numLines; a++)
    {
        fscanf(traFile, "%llx\t%c\t%llx\n", &lines[a].addr1, &lines[a].branchTaken, &lines[a].addr2);

        // cout << hex << lines[a].addr1 << '\t' << lines[a].branchTaken
        //      << '\t' << hex << lines[a].addr2 << endl;
    }
    //

    // Do tests
    uint64_t ftRatio = 0, sfRatio = 0, bmRatio = 0, twRatio = 0;
    ftRatio = fixedTrue(lines, numLines);
    sfRatio = staticFirst(lines, numLines);
    bmRatio = biModal(lines, numLines);
    twRatio = twoLayerAdaptive(lines, numLines);
    //
    // Print results
    cout << "Fixed : " << ftRatio << " / " << numLines << endl;
    cout << "Static : " << sfRatio << " / " << numLines << endl;
    cout << "Bimodal : " << bmRatio << " / " << numLines << endl;
    cout << "2-Layer : " << twRatio << " / " << numLines << endl;
    //
    return 0;
}

uint64_t fixedTrue(Data lines[], uint64_t numLines)
{
    uint64_t correct = 0;
    for (uint64_t a = 0; a < numLines; a++)
    {
        if (lines[a].branchTaken == '@')
        {
            correct++;
        }
    }
    return correct;
}

uint64_t staticFirst(Data lines[], uint64_t numLines)
{
    uint64_t correct = 0;

    // Make prediction table
    uint64_t tags[1024] = {0};
    char prediction[1024] = {'@'};

    for (uint64_t a = 0; a < numLines; a++)
    {
        int index = lines[a].addr1 << 54 >> 54;
        if (tags[index] != (lines[a].addr1 >> 10))
        {
            tags[index] = (lines[a].addr1 >> 10);
            prediction[index] = '@';
            if (lines[a].branchTaken == '@')
            {
                correct++;
            }
            else
            {
                prediction[index] = '.';
            }
        }
        else
        {
            if (prediction[index] == lines[a].branchTaken)
            {
                correct++;
            }
        }
    }

    return correct;
}

uint64_t biModal(Data lines[], uint64_t numLines)
{
    uint64_t correct = 0;

    int tags[1024] = {0};
    int errorCnt[1024] = {1};
    char prediction[1024] = {'@'};

    for (uint64_t c = 0; c < numLines; c++)
    {
        int index = (lines[c].addr1 << 54) >> 54;

        if (tags[index] != (int)(lines[c].addr1 >> 10))
        {
            tags[index] = (int)(lines[c].addr1 >> 10);
            prediction[index] = '@';
            errorCnt[index] = 1;

            if (lines[c].branchTaken == '@')
            {
                correct++;
                errorCnt[index] = 0;
            }
            else
            {
                prediction[index] = '.';
                errorCnt[index] = 0;
            }
        }
        else
        {
            if (prediction[index] == lines[c].branchTaken)
            {
                correct++;
                errorCnt[index] = 0;
            }
            else
            {
                errorCnt[index]++;
                if (errorCnt[index] % 2 == 0)
                {
                    if (prediction[index] == '@')
                    {
                        prediction[index] = '.';
                    }
                    else
                    {
                        prediction[index] = '@';
                    }
                }
            }
        }
    }

    return correct;
}

uint64_t twoLayerAdaptive(Data lines[], uint64_t numLines)
{
    uint64_t correct = 0;

    int history[1024] = {3};
    int errorCnt[1024][4] = {1, 1, 1, 1};
    int prediction[1024][4] = {0, 1, 0, 1};
    int tags[1024] = {0};
    char nextPrediction;

    for (int a = 0; a < numLines; a++)
    {
        int index = lines[a].addr1 << 54 >> 54;
        if (prediction[index][history[index]] == 1)
        {
            nextPrediction = '@';
        }
        else
        {
            nextPrediction = '.';
        }

        if (tags[index] != (int)(lines[a].addr1 >> 10))
        {
            tags[index] = (int)(lines[a].addr1 >> 10);
            for (int rando = 0; rando < 4; rando++)
            {
                prediction[index][rando] = rando % 2;
                errorCnt[index][rando] = 1;
            }
            history[index] = 3;
            if (lines[a].branchTaken == '@')
            {
                correct++;
                errorCnt[index][history[index]] = 0;
            }
            else
            {
                prediction[index][history[index]] = 0;
                errorCnt[index][history[index]] = 0;
            }
        }
        else
        {
            if (nextPrediction == lines[a].branchTaken)
            {
                correct++;
                errorCnt[index][history[index]] = 0;
            }
            else
            {
                errorCnt[index][history[index]]++;
                if (errorCnt[index][history[index]] % 2 == 0)
                {
                    if (prediction[index][history[index]] == 1)
                    {
                        prediction[index][history[index]] = 0;
                    }
                    else
                    {
                        prediction[index][history[index]] = 1;
                    }
                }
            }
        }
        if (lines[a].branchTaken == '@')
        {
            history[index] <<= 1;
            history[index] |= 1;
        }
        else
        {
            history[index] <<= 1;
        }
        history[index] = (history[index] & 3);
    }

    return correct;
}
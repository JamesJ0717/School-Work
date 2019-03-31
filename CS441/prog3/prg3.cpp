#include <iostream>
#include <cstdint>
#include <cstdio>

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
struct Block
{
    int index, dirtyBit, errorCnt;
    uint64_t tag;
    char prediction;
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
    Block predTable[1024];

    for (uint64_t a = 0; a < numLines; a++)
    {
        for (int b = 0; b < 1024; b++)
        {
            if (predTable[b].index == ((lines[a].addr1 << 54) >> 54))
            {
                predTable[b].prediction = '@';
                predTable[b].tag = (lines[a].addr1 >> 11);
                if (predTable[b].prediction == lines[a].branchTaken)
                {
                    correct++;
                }
                else
                {
                    predTable[b].prediction = lines[a].branchTaken;
                }
            }
        }
    }

    return correct;
}

uint64_t biModal(Data lines[], uint64_t numLines)
{
    uint64_t correct = 0;

    Block predTable[1024];
    for (uint64_t c = 0; c < numLines; c++)
    {
        for (uint64_t b = 0; b < 1024; b++)
        {
            // start off predicting true and errorCnt = 1
            predTable[b].prediction = '@';
            predTable[b].errorCnt = 1;

            if ((b) == (lines[c].addr1 << 54 >> 54))
            {
                predTable[b].index = ((lines[c].addr1 << 54) >> 54);
            }

            // if tag is already in table, carry on
            // if not add it
            if (predTable[b].tag == lines[c].addr1 >> 10)
            {
            }
            else
            {
                predTable[b].tag = (lines[c].addr1 >> 10);
                predTable[b].prediction = '@';
                predTable[b].errorCnt = 1;
            }

            // if prediction is what it does, add 1 to correct
            // if not, add 1 to error count
            if (lines[c].branchTaken == predTable[b].prediction)
            {
                correct++;
                predTable[b].errorCnt = 1;
            }
            else
            {
                predTable[b].errorCnt++;

                //if errorCnt is 2, flip prediction
                if (predTable[b].errorCnt == 2)
                {
                    if (predTable[b].prediction == '@')
                    {
                        predTable[b].prediction = '.';
                    }
                    else
                    {
                        predTable[b].prediction = '@';
                    }
                    predTable[b].errorCnt = 1;
                }
            }
            // cout << b << " " << predTable[b % 1024].tag << " " << predTable[b % 1024].prediction << " " << predTable[b % 1024].errorCnt << endl;
        }
    }

    return correct;
}

uint64_t twoLayerAdaptive(Data lines[], uint64_t numLines)
{
    uint64_t correct = 0;

    return correct;
}
#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdio>

using namespace std;
#define ADDRESSSPACE 65536

int fixedTrue(vector<vector<char> >);
int staticFirst(vector<vector<char> >);
int biModal(vector<vector<char> >);
int twoLayerAdaptive(vector<vector<char> >);

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
    if (!traFile)
    {
        cout << "File Error" << endl;
        return 0;
    }
    int numLines = 0;
    while (!feof(traFile))
    {
        if (fgetc(traFile) == '\n')
        {
            numLines++;
        }
    }
    // cout << numLines;
    rewind(traFile);

    vector<vector<uint64_t> > addresses(numLines);
    for (int a = 0; a < addresses.size(); a++)
    {
        addresses[a].resize(2);
    }

    // Get contents of tokenizer file
    string line[numLines];
    char branchTaken;
    uint64_t addr, addr2;
    int a = 0;
    while (!feof(traFile))
    {
        fscanf(traFile, "%llx %c %llx", &addr, &branchTaken, &addr2);
        cout << hex << addr <<" "<<branchTaken<<" "<< hex << addr2<< endl;
        
        a++;
    }

    for (int k = 0; k < addresses.size(); k++)
    {
        for (int l = 0; l < addresses[k].size(); l++)
        {
            // cout << addresses[k][l];
        }
    }
    //

    // Do tests
    int ftRatio, sfRatio, bmRatio, twRatio = 0;
    // ftRatio = fixedTrue(addresses);
    // sfRatio = staticFirst(addresses);
    // bmRatio = biModal(addresses);
    // twRatio = twoLayerAdaptive(addresses);
    //
    // Print results
    cout << "Fixed : " << ftRatio << " / " << numLines << endl;
    cout << "Static : " << sfRatio << " / " << numLines << endl;
    cout << "Bimodal : " << bmRatio << " / " << numLines << endl;
    cout << "2-Layer : " << twRatio << " / " << numLines << endl;
    //
    return 0;
}

int fixedTrue(vector<vector<char> > numLines)
{
    int correct;

    return correct;
}
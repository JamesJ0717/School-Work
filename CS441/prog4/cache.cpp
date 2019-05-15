#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <math.h>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Cache
{
    uint64_t tag;
    int set;
    int lru;
};

int getBits(int);
uint64_t cache(int, int, int, vector<uint64_t>, uint64_t);
int getLast(Cache blocks[], int size)
{
    int lru = -10000, temp = -10000;
    for (int i = 0; i < size; i++)
    {
        if (blocks[i].lru > temp)
        {
            lru = i;
            temp = blocks[i].lru;
        }
    }
    return lru;
}

int main(int argc, char *argv[])
{
    int numSets = atoi(argv[1]);
    int numBlocks = atoi(argv[2]);
    int numlines = atoi(argv[3]);

    ifstream traFile;
    traFile.open(argv[4]);

    int lines = 0;
    while (!traFile.eof())
    {
        char n = traFile.get();
        if (n == '\n')
        {
            lines++;
        }
    }
    traFile.clear();
    traFile.seekg(0, traFile.beg);

    vector<uint64_t> x(lines);
    vector<char> actions(lines);
    int i = 0;
    while (traFile >> hex >> x.at(i) >> actions.at(i))
    {
        if (i < lines - 1)
            i++;
    }
    int setAmt = pow(2, numSets);
    int blockAmt = pow(2, numBlocks);
    int indexAmt = pow(2, numlines);
    uint64_t misses = 0;
    misses = cache(setAmt, blockAmt, indexAmt, x, lines);

    cout << "missed " << dec << misses << " / " << lines << endl;

    return 0;
}

uint64_t cache(int setAmt, int blockAmt, int indexAmt, vector<uint64_t> lines, uint64_t sizeVec)
{
    int set;
    uint64_t tag, misses = 0, hits = 0;
    int lru = 0, hit = 0, loc = 0, setBits = getBits(setAmt), indexBits = getBits(indexAmt);

    Cache data[setAmt][blockAmt];

    for (int e = 0; e < setAmt; e++)
        for (int d = 0; d < blockAmt; d++)
            data[e][d].lru = 0;

    for (int line = 0; line < lines.size(); line++)
    {
        tag = lines.at(line) / indexAmt / setAmt;
        set = lines.at(line) / indexAmt % setAmt;
        for (int a = 0; a < blockAmt; a++)
        {
            if (data[set][a].tag == tag)
            {
                hit = 1;
                loc = a;
                // cout << set << '\t' << data[set][a].tag << '\t' << tag << endl;
                break;
            }
        }
        if (hit == 1)
        {
            // cout << "HIT" << endl;
            hits++;
            for (int c = 0; c < blockAmt; c++)
                data[set][c].lru++;
            data[set][loc].lru = 0;
        }
        else
        {
            misses++;
            lru = getLast(data[set], blockAmt);
            for (int c = 0; c < blockAmt; c++)
                data[set][c].lru++;
            data[set][lru].lru = 0;
            data[set][lru].tag = tag;
        }
        hit = 0;
    }
    return misses;
}

int getBits(int num)
{
    int bits = 0;
    while (num > 1)
    {
        num /= 2;
        bits++;
    }
    return bits;
}
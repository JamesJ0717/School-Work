#! /usr/bin/env python3


# ./block.py <file> <sets> <bpS> <wpB>

import sys
import math
lines = [line.split() for line in open(sys.argv[4]).read().split('\n') if line]

sets = int(math.pow(2, int(sys.argv[1])))
bpS = int(math.pow(2, int(sys.argv[2])))
wpB = int(math.pow(2, int(sys.argv[3])))
newLines = [0]*len(lines)


def parse(addr, sets, bpS, wpB):
    indexCnt = 0
    # blockCnt = 0
    setCnt = 0
    while(wpB > 1):
        wpB //= 2
        indexCnt += 1
    index = addr & ~(~0 << indexCnt)
    while(sets > 1):
        sets //= 2
        setCnt += 1
    setNum = addr & ~(~0 << (indexCnt + setCnt)) >> indexCnt

    tag = addr >> (indexCnt + setCnt)
    # print(tag, '\t', setNum, '\t', index)
    newLine = [tag, setNum, index]
    return newLine


def cache(newLine, sets, bpS):
    lruCnt = [1]*bpS
    tag = [0]*bpS
    miss = 0
    hit = 0
    for line in newLine:

        newTag = line[0]
        newSet = line[1]
        # newIndex = newLine[2]

        for i in range(sets):
            # find set
            if (newSet == i):
                j = 0
                # check tags
                if(newTag in tag):
                    hit += 1
                    lruCnt[j] = 0
                    for k in range(bpS):
                        if(j != k):
                            lruCnt[k] += 1
                else:
                    # find where lru is greatest
                    tag[lruCnt.index(max(lruCnt))] = newTag
                    lruCnt[lruCnt.index(max(lruCnt))] = 0
                    miss += 1
                    for k in range(bpS):
                        if(lruCnt.index(max(lruCnt)) != k):
                            lruCnt[k] += 1
    return(miss)


i = 0
for line in lines:
    newLines[i] = parse(int(line[0], 16), sets, bpS, wpB)
    i += 1

misses = cache(newLines, sets, bpS)

print('missed: ', misses, ' /', len(lines))

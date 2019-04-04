#! /usr/bin/env python3


# ./block.py <file> <sets> <bpS> <wpB>


import sys
lines = [line.split() for line in open(sys.argv[1]).read().split('\n') if line]
sets = int(sys.argv[2])
bpS = int(sys.argv[3])
wpB = int(sys.argv[4])
newLines = [0]*len(lines)


def parse(addr, sets, bpS, wpB):
    indexCnt = 0
    blockCnt = 0
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


def cache(newTag, newSet, newIndex, sets, bpS):
    # print(newTag, '\t', newSet, '\t', newIndex)
    lruCnt = [0]*bpS
    tag = 0
    here = 0
    if (newSet == 0):
        if(tag == newTag):
            if (0 in lruCnt):
                lruCnt[here] = 0
        else:
            tag = newTag
            for i in lruCnt:
                lruCnt[i] += 1
            lruCnt[here] = 0
        here += 1
    elif (newSet == 1):
        if(tag == newTag):
            if (0 in lruCnt):
                lruCnt[here] = 0
        else:
            tag = newTag
            for i in lruCnt:
                lruCnt[i] += 1
            lruCnt[here] = 0
        here += 1
    print(lruCnt)


i = 0
for line in lines:
    newLines[i] = parse(int(line[0], 16), sets, bpS, wpB)
    i += 1
    # print(line[0], '\t', line[1], '\t', line[2])

for abc in newLines:
    cache(abc[0], abc[1], abc[2], sets, bpS)

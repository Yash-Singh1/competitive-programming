#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'findHandSum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER originalRows
#  2. STRING handTiles
#  3. STRING drawPile
#

from time import sleep

def tens(n):
    return 0 if n == 0 else int(n / 10)

def ones(n):
    return 0 if n == 0 else n % 10

def getSplits(stri):
    if stri.strip() == '':
        sleep(10000)
        return []
    try:
        return list(map(int, filter(lambda x: len(x) > 0, stri.split(' '))))
    except ValueError:
        sleep(1000)

def findHandSum(originalRows, handTiles, drawPile):
    game = [[int(originalRows / 1000)], [int(originalRows / 100) % 10], [int(originalRows / 10) % 10], [originalRows % 10]]
    hand = getSplits(handTiles)
    draw = getSplits(drawPile)
    currow = -1
    reqrow = -1

    while len(hand):
        works = False
        blue = 0
        for handCard in hand:
            for i_ in range(currow + 1, currow + 5):
                i = i_ % 4
                if reqrow >= 0 and i != reqrow:
                    continue
                assert i >= 0 and i < 4
                assert len(game[i]) > 0
                if tens(handCard) == ones(game[i][-1]):
                    game[i].append(handCard)
                    try:
                        hand.pop(blue)
                    except:
                        sleep(1000)
                    currow = i
                    reqrow = -1
                    works = True
                elif ones(handCard) == ones(game[i][-1]):
                    game[i].append((ones(handCard) * 10) + tens(handCard))
                    try:
                        hand.pop(blue)
                    except:
                        sleep(1000)
                    currow = i
                    reqrow = -1
                    works = True
                else:
                    assert not works
                if works:
                    if ones(handCard) == tens(handCard):
                        reqrow = i
                    break
            if works:
                break
            blue += 1
        if not works:
            newDraw = [*draw]
            for drawIt in newDraw:
                draw.pop(0)
                for i_ in range(currow + 1, currow + 5):
                    i = i_ % 4
                    if reqrow >= 0 and reqrow != i:
                        continue
                    if tens(drawIt) == ones(game[i][-1]):
                        game[i].append(drawIt)
                        currow = i
                        reqrow = -1
                        works = True
                    elif ones(drawIt) == ones(game[i][-1]):
                        game[i].append((ones(drawIt) * 10) + tens(drawIt))
                        currow = i
                        reqrow = -1
                        works = True
                    else:
                        assert not works
                    if works:
                        if tens(drawIt) == ones(drawIt):
                            reqrow = i
                        break
                if works:
                    break
                else:
                    hand.append(drawIt)
        if not works or len(hand) == 0:
            break
    print(game, hand, draw)
    sm = 0
    for handi in hand:
        sm += handi % 10
        sm += int(handi / 10)
    return sm


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    originalRows = int(input().strip())

    handTiles = input()

    drawPile = input()

    result = findHandSum(originalRows, handTiles, drawPile)

    fptr.write(str(result) + '\n')

    fptr.close()

#include <stdio.h>
#include "traversalLogic.h"

int *sizeX, *sizeY;
int *playerX, *playerY;
int **labPtr;
int res[] = {0, 0};

int keys[29] = {0};

void checkUpperSide(int i) {
    for (i++; i < (*sizeX); i++)
    {
        res[0] = 0;
        res[1] = i;
        if (labPtr[0][i] > -1)
        {
            res[1] = i;
            return;
        }
    }
    res[0] = -1;
    res[1] = -1;
}

void checkLowerSide(int i) {
    res[0] = (*sizeY) - 1;
    res[1] = i;
    for (i++; i < (*sizeX); i++)
    {
        res[1] = i;
        if (labPtr[(*sizeX) - 1][i] > -1)
        {
            res[1] = i;
            return;
        }
    }
    res[0] = -1;
    res[1] = -1;
}

void checkLeftSide(int i) {
    res[0] = i;
    res[1] = 0;
    for (i++; i < (*sizeY); i++)
    {
        res[0] = i;
        if (labPtr[i][0] > -1)
        {
            res[0] = i;
            return;
        }
    }
    res[0] = -1;
    res[1] = -1;
}

void checkRightSide(int i) {
    res[0] = i;
    res[1] = (*sizeX) - 1;
    for (i++; i < (*sizeY); i++)
    {
        res[0] = i;
        if (labPtr[i][(*sizeX) - 1] > -1)
        {
            res[0] = i;
            return;
        }
    }
    res[0] = -1;
    res[1] = -1;
}

int reachPlayer(int *exitCoord, int steps) {
    int temp = 0;
    int *resTemp = exitCoord;
    printf("Pass!\n");
    if ((*playerX) == exitCoord[0])
    {
        if ((*playerY) == exitCoord[1])
        {
            return 1;
        }
    }
    if (labPtr[exitCoord[0]][(exitCoord[1] + 1)] == 0 && (exitCoord[1] + 1) < *sizeY)
    {
        resTemp[1]++;
        temp = reachPlayer(resTemp, (steps + 1));
        if (temp != -1)
        {
            printf("%d -", steps + 1);
            return temp;
        }
        resTemp[1]--;
    }
    if (labPtr[exitCoord[0]][(exitCoord[1] - 1)] == 0 && (exitCoord[1] + 1) > 0)
    {
        resTemp[1]--;
        temp = reachPlayer(resTemp, (steps + 1));
        if (temp != -1)
        {
            printf("%d -", steps + 1);
            return temp;
        }
        resTemp[1]++;
    }
    if (labPtr[(exitCoord[0] + 1)][exitCoord[1]] == 0 && (exitCoord[0] + 1) < *sizeX)
    {
        resTemp[0]++;
        temp = reachPlayer(resTemp, (steps + 1));
        if (temp != -1)
        {
            printf("%d -", steps + 1);
            return temp;
        }
        resTemp[1]--;
    }
    if (labPtr[(exitCoord[0] + 1)][exitCoord[1]] == 0 && (exitCoord[0] + 1) > 0)
    {
        resTemp[0]--;
        temp = reachPlayer(resTemp, (steps + 1));
        if (temp != -1)
        {
            printf("%d -", steps + 1);
            return temp;
        }
        resTemp[1]++;
    }
    return -1;
}

void resetRes() {
    res[0] = -1;
    res[1] = -1;
}

int findExit(int lastPos[], int *playerCoordX, int *playerCoordY, int *xsize, int *ysize, int **layout)
{
    labPtr = layout;
    sizeX = xsize;
    sizeY = ysize;
    playerX = playerCoordX;
    playerY = playerCoordY;
    do 
    {
        checkUpperSide(*(res + 1));
        if (*res != -1)
        {
            reachPlayer(res, 0);
        }
        
    } while (*res != -1);
    do 
    {
        checkLowerSide(*(res + 1));
        if (*res != -1)
        {
            reachPlayer(res, 0);
        }
        
    } while (*res != -1);
    do 
    {
        checkLeftSide(*res);
        if (*res != -1)
        {
            reachPlayer(res, 0);
        }
        
    } while (*res != -1);
    do 
    {
        checkRightSide(*res);
        if (*res != -1)
        {
            reachPlayer(res, 0);
        }
        
    } while (*res != -1);
}
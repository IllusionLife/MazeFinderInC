#include <stdio.h>
#include "traversalLogic.h"

int sizeX, sizeY;
int **labPtr;
int res[] = {0, 0};

void checkUpperSide(int i) {
    for (i++; i < sizeX; i++)
    {
        res[0] = 0;
        res[1] = i;
        if (labPtr[0][i] == 0)
        {
            res[1] = i;
            return;
        }
    }
    res[0] = -1;
    res[1] = -1;
}

void checkLowerSide(int i) {
    res[0] = sizeY - 1;
    res[1] = i;
    for (i++; i < sizeX; i++)
    {
        res[1] = i;
        if (labPtr[sizeY-1][i] == 0)
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
    for (i++; i < sizeY; i++)
    {
        res[0] = i;
        if (labPtr[i][0] == 0)
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
    res[1] = sizeX - 1;
    for (i++; i < sizeY; i++)
    {
        res[0] = i;
        if (labPtr[i][sizeX-1] == 0)
        {
            res[0] = i;
            return;
        }
    }
    res[0] = -1;
    res[1] = -1;
}

void reachPlayer(int *exitCoord) {
    printf("X: %d Y: %d\n", (*exitCoord + 1), (*(exitCoord + 1) + 1));
}

void resetRes() {
    res[0] = -1;
    res[1] = -1;
}


int findExit(int lastPos[], int **layout, int xsize, int ysize) {
    labPtr = layout;
    sizeX = xsize;
    sizeY = ysize;
    do 
    {
        checkUpperSide(*(res + 1));
        if (*res != -1)
        {
            printf("Up: ");
            reachPlayer(res);
        }
        
    } while (*res != -1);
    do 
    {
        checkLowerSide(*(res + 1));
        if (*res != -1)
        {
            printf("Down: ");
            reachPlayer(res);
        }
        
    } while (*res != -1);
    do 
    {
        checkLeftSide(*res);
        if (*res != -1)
        {
            printf("Left: ");
            reachPlayer(res);
        }
        
    } while (*res != -1);
    do 
    {
        checkRightSide(*res);
        if (*res != -1)
        {
            printf("Right: ");
            reachPlayer(res);
        }
        
    } while (*res != -1);
}
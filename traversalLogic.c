#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "traversalLogic.h"

int sizeX = 0;
int sizeY = 0;
int playerX = 0;
int playerY = 0;
//int keys[20] = {0};
int **labPtr = NULL;

// Create allocate memory for new labyrith cell
ListStruct *newNode(int x, int y, int data, int len)
{
    ListStruct *ListNode = (ListStruct *)malloc(sizeof(ListStruct));
    ListNode->value = data;
    ListNode->x = x;
    ListNode->y = y;
    ListNode->lenFromStart = len + 1;
    int *newKeys = (int *)malloc(20 * sizeof(int));
    memset(newKeys, 0, (20 * sizeof(int)));
    ListNode->keys = newKeys;
    ListNode->next = NULL;
    return ListNode;
}

// Change cell status to -100
void changeCellToVisited(int y, int x)
{
    if (labPtr[y][x] == PATH_CELL)
    {
        labPtr[y][x] = VISITED_CELL;
    }
    else if (labPtr[y][x] > DOOR_TWO_ZER)
    {
        labPtr[y][x] *= -1;
    }
    else if (labPtr[y][x] > PATH_CELL)
    {
        labPtr[y][x] *= -10;
    }
    
}

// Change visited cells' path back to walkable path
void resetCells()
{
    for (int i = 0; i < sizeY; i++)
    {
        for (int y = 0; y < sizeX; y++)
        {
            if (labPtr[i][y] == VISITED_CELL)
            {
                labPtr[i][y] = PATH_CELL;
            }
            else if (labPtr[i][y] <= (-KEY_ONE))
            {
                labPtr[i][y] *= -1;
            }
            else if (labPtr[i][y] <= (-DOOR_ONE * 10)) {
                labPtr[i][y] /= -10;
            }
        }
    }
}

// Check if list is empty
int isListEmpty(ListStruct *st)
{
    return (st != NULL);
}

// Check if current cell is at edge ot labyrith
int isAtEnd(ListStruct *st)
{
    return (st->x == 0 || st->x == (sizeX - 1) || st->y == 0 || st->y == (sizeY - 1));
}

// Pass all enabled keys to another struct
void inheritKeys(ListStruct *current, ListStruct **new)
{
    for (int i = 0; i < 20; i++)
    {
        if (current->keys[i] != 0)
        {
            (*new)->keys[i] = (current->keys[i]) - 1;
        }
        else
        {
            (*new)->keys[i] = 0;
        }
    }
}

// Add node next to current List
void appendCell(int x, int y, int content, ListStruct *current, ListStruct **st)
{
    ListStruct *newCell = newNode(x, y, content, current->lenFromStart);
    inheritKeys(current, &newCell);
    (*st)->next = newCell;
    *st = newCell;
}

// Scans surrounding cell's status
void scanCell(int newY, int newX, ListStruct *currentCell, ListStruct **listEnd)
{
    int labValue = labPtr[newY][newX];
    if (labValue == PATH_CELL) // Case walkable path
    {
        // Add current neighbour cell to end of list
        appendCell(newX, newY, labValue, currentCell, listEnd);
    }
    else if (labValue >= KEY_ONE) // Case door key
    {
        int keyToDoorValue = labValue - 101;
        appendCell(newX, newY, labValue, currentCell, &listFullDoor);
        listFullDoor->keys[keyToDoorValue] = 20;
        appendCell(newX, newY, labValue, currentCell, listEnd);
    }
    else if (labValue > PATH_CELL && currentCell->keys[labValue - 1] > 0) // case door (if key has been activated)
    {
        appendCell(newX, newY, labValue, currentCell, listEnd);
    }
}

// Check the 4 sides of the current cell and add them to the list
void checkSurround(ListStruct *currentCell, ListStruct **listEnd)
{
    //  Check lower cell
    int newYCoord = ((currentCell->y) + 1);
    int newXCoord = (currentCell->x);
    if (newYCoord < sizeY)
    {
        scanCell(newYCoord, newXCoord, currentCell, listEnd);
    }

    //  Check upper cell
    newYCoord = ((currentCell->y) - 1);
    newXCoord = (currentCell->x);
    if (newYCoord > -1)
    {
        scanCell(newYCoord, newXCoord, currentCell, listEnd);
    }

    //  Check left cell
    newYCoord = (currentCell->y);
    newXCoord = ((currentCell->x) - 1);
    if (newXCoord > -1)
    {
        scanCell(newYCoord, newXCoord, currentCell, listEnd);
    }

    //  Check right cell
    newYCoord = (currentCell->y);
    newXCoord = ((currentCell->x) + 1);
    if (newXCoord < sizeX)
    {
        scanCell(newYCoord, newXCoord, currentCell, listEnd);
    }

    // change to visited (-100)
    changeCellToVisited(currentCell->y, currentCell->x);
}

// Moves struct pointer to next element and frees the memory
void freeCellAndMove(ListStruct **st)
{
    ListStruct *temp = *st;
    (*st) = (*st)->next;
    free(temp->keys);
    free(temp);
}

// Free list once result has been found
void freeList(ListStruct **st)
{
    while ((*st) != NULL)
    {
        freeCellAndMove(st);
    }
}

// Initial function to start traversal
int initLabTraversal()
{
    int steps = 0;

    // Initiate list with historical values of activated keys
    listFullDoor = newNode(0, 0, 0, 0);
    listDoor = listFullDoor;
    listStartDoor = listDoor;

    do
    {
        // Initiate list with player position or next historical value
        ListStruct *fullList = newNode(playerX, playerY, labPtr[playerY][playerX], --steps);
        ListStruct *listTraversal = fullList;
        inheritKeys(listDoor, &fullList); // Inherit keys of current historical value to new list (no keys for first cycle)
        while (isListEmpty(listTraversal)) // while list is not empty
        {
            if (listTraversal->lenFromStart > MAX_POSSIBLE_STEPS)
            {
                return 0;
            }
            if (isAtEnd(listTraversal)) // if pointer is at an edge (exit of a maze)
            {
                int result = listTraversal->lenFromStart; //store steps taken up to that point in a temporary int
                freeList(&listTraversal);
                freeList(&listDoor); //free rest of the list
                return (result);     //return temporary int
            }
            checkSurround(listTraversal, &fullList); //check surrounding cells for walkable path
            freeCellAndMove(&listTraversal);
        }
        resetCells();
        freeCellAndMove(&listDoor);
        playerX = listDoor->x;
        playerY = listDoor->y;
        steps = listDoor->lenFromStart;
    } while (listDoor->next != NULL);
    return 0;
}
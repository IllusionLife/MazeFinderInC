#ifndef TRAVERSE_TOWN
#define TRAVERSE_TOWN

#define TRUE 1
#define FALSE 0
#define MAX_POSSIBLE_STEPS 1275

enum cellState {
    VISITED_CELL = -100,
    WALL_CELL = -1,
    PATH_CELL,
    DOOR_ONE,
    DOOR_TWO,
    DOOR_THR,
    DOOR_FOU,
    DOOR_FIV,
    DOOR_SIX,
    DOOR_SEV,
    DOOR_EIG,
    DOOR_NIN,
    DOOR_ONE_ZER,
    DOOR_ONE_ONE,
    DOOR_ONE_TWO,
    DOOR_ONE_THR,
    DOOR_ONE_FOU,
    DOOR_ONE_FIV,
    DOOR_ONE_SIX,
    DOOR_ONE_SEV,
    DOOR_ONE_EIG,
    DOOR_ONE_NIN,
    DOOR_TWO_ZER,
    KEY_ONE = 101,
    KEY_TWO,
    KEY_THR,
    KEY_FOU,
    KEY_FIV,
    KEY_SIX,
    KEY_SEV,
    KEY_EIG,
    KEY_NIN,
    KEY_ONE_ZER,
    KEY_ONE_ONE,
    KEY_ONE_TWO,
    KEY_ONE_THR,
    KEY_ONE_FOU,
    KEY_ONE_FIV,
    KEY_ONE_SIX,
    KEY_ONE_SEV,
    KEY_ONE_EIG,
    KEY_ONE_NIN,
    KEY_TWO_ZER,
};

struct ListCells {
    int value;
    int x;
    int y;
    int lenFromStart;
    int *keys;
    struct ListCells *next;  
};
typedef struct ListCells ListStruct;

extern int sizeX;
extern int sizeY;
extern int playerX;
extern int playerY;
extern int **labPtr;

ListStruct *listFullDoor;
ListStruct *listStartDoor;
ListStruct *listDoor;

int initLabTraversal();


#endif
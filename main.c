#include <stdio.h>
#include <stdlib.h>
#include "traversalLogic.h"

int main(int argc, char *argv[]) {
    FILE *fp;

    if (argc < 2)
    {
        fp = fopen("INPUT.TXT", "r"); //scans "INPUT.TXT" file from same folder
    }
    else {
        fp = fopen(argv[1], "r"); //receives a file, dropped in the exe
    }

    // receives player position and labyrinth size
    fscanf(fp, "%d %d", &playerX, &playerY);
    fscanf(fp, "%d %d", &sizeX, &sizeY);

    // Correcting player position by lowering coordinates by 1
    playerX--;
    playerY--;

    // initiate 2D array
    labPtr = (int**) malloc(sizeY * sizeof(int*));
    for (int i = 0; i < sizeY; i++)
    {
        labPtr[i] = (int*) malloc(sizeX * sizeof(int));
        for (int y = 0; y < sizeX; y++)
        {
            fscanf(fp, "%d ", &(labPtr[i][y])); // reads "INPUT.TXT" and fills 2D array with provided X & Y size
        }
    }
    fclose(fp); // closing file pointer after processing all info
    
    // creating new file
    FILE *outfp = fopen("OUTPUT.TXT", "w+");
    
    int turns = initLabTraversal();
    fprintf(outfp, "Result: %d", turns);

    // Freeing up dynamic memory
    for (int i = 0; i < sizeY; i++)
    {
        free(labPtr[i]);
    }
    free(labPtr);
    fclose(outfp);

    return 0;
}
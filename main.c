#include <stdio.h>
#include <stdlib.h>
#include "traversalLogic.h"

int main(int argc, char *argv[]) {
    int playerX = 0, playerY = 0;
    int sizeX = 0, sizeY = 0;
    int exitX = 0, exitY = 0;
    char* filePath;
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

    // initiate 2D array
    int **labyrinthLayout = (int**) malloc(sizeY * sizeof(int*));
    for (int i = 0; i < sizeY; i++)
    {
        labyrinthLayout[i] = (int*) malloc(sizeX * sizeof(int));
        for (int y = 0; y < sizeX; y++)
        {
            fscanf(fp, "%d ", &(labyrinthLayout[i][y])); // reads "INPUT.TXT" and fills 2D array with provided X & Y size
        }
    }
    fclose(fp); // closing file pointer after processing all info
    
    // creating new file
    FILE *outfp = fopen("OUTPUT.TXT", "w+");
    
    for (int i = 0; i < sizeY; i++)
    {
        for (int y = 0; y < sizeX; y++)
        {
            fprintf (outfp, "%d ", labyrinthLayout[i][y]); // print
        }
        fprintf (outfp, "\n");
    }
    int initPos[] = {0,0};
    int turns = findExit(initPos, labyrinthLayout, sizeX, sizeY);
    
    // Freeing up dynamic memory
    for (int i = 0; i < sizeY; i++)
    {
        free(labyrinthLayout[i]);
    }
    free(labyrinthLayout);
    fclose(outfp);

    return 0;
}
//
// Created by Devin Amdahl on 2/1/22.
//

#ifndef ASSIGNMENT1_01_DJAMDAHL_MAP_H
#define ASSIGNMENT1_01_DJAMDAHL_MAP_H

typedef struct map
{
    // The following variables store the coordinates of map's exits.
    int northExit[2];
    int eastExit[2];
    int southExit[2];
    int westExit[2];

    // The following variables store the 'source' coordinates of the tall grass regions.
    int tallGrass1[2];
    int tallGrass2[2];

    // The following variables store the 'source' coordinates of the clearing regions.
    int clearingOne[2];
    int clearingTwo[2];

    // The following variables store the coordinates for the PokeMart and PokeCenter.
    int pokeMart[2];
    int pokeCenter[2];

    // This 2D array is how the map will actually be stored and represented in the terminal.
    char mapArray[80][21];
}

    map_t;

// Function to initialize the map with rock borders and filled with clearings.
int initializeMap(map_t *m);
// Function to generate the tall grass regions.
int TallGrassRegions(map_t *m);
// Function to generate the N-S and E-W paths.
int buildPaths(map_t *m);
// Function to place the PokeMart and PokeCenters along the corresponding paths.
int placePokeMartAndCenter(map_t *m);
// Constructor to randomly initialize the map.
int randomGeneration(map_t *m);
// Constructor to manually (in terms of the coordinates of the exits) the map.
int manualGeneration(map_t *m, int xNorthExit, int yNorthExit, int xEastExit, int yEastExit, int xSouthExit, int ySouthExit, int xWestExit, int yWestExit);

#endif //ASSIGNMENT1_01_DJAMDAHL_MAP_H



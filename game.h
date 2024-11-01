
#ifndef GAME_H
#define GAME_H

#include "file_operations.h"

#define MAX_TITLE_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    float rentalPrice;
    int gameID;
} Game;



void add_game(tof *gameFile);
int rechercher_Game(tof *tof, int gameID, Game *game);
void printGame(Game game);

#endif


#include "game.h"
#include <stdio.h>

void add_game(tof *gameFile) {
    Game game;
    printf("Enter Game ID: ");
    scanf("%d", &game.gameID);
    printf("Enter Game Title: ");
    scanf("%s", game.title);
    printf("Enter Rental Price: ");
    scanf("%f", &game.rentalPrice);
    insert_Game(gameFile, game.gameID, game);
}

int rechercher_Game(tof *tof, int gameID, Game *game) {
    BlocGame block;
    fseek(tof->file, sizeof(Entete), SEEK_SET);

    while (read_BlocGame(tof, &block, tof->header.blockCount)) {
        for (int i = 0; i < block.count; i++) {
            if (block.games[i].gameID == gameID) {
                *game = block.games[i];
                return 1;
            }
        }
    }
    return 0;
}

void printGame(Game game) {
    printf("Game ID: %d\n", game.gameID);
    printf("Title: %s\n", game.title);
    printf("Rental Price: %.2f\n", game.rentalPrice);
}

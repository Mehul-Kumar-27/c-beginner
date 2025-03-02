#include "game.h"
#include "../utils/utils.h"
#include <string.h>
#include <stddef.h>

Error initGame(Game *game, Player *playerList, int numOfPlayers) {
    Error error;
    if (numOfPlayers == 0){
        error.status = 1;
        safe_strncpy(error.message, "error: minimum of 1 player is required for game!", 50);
        return error;
    }

    game->playerArray = (Player *)malloc(numOfPlayers * sizeof(Player));
    if(game->playerArray == NULL){
        error.status = 1;
        safe_strncpy(error.message, "error: memory allocation failed", 50);
        return error;
    }

    for(int i = 0 ; i < numOfPlayers; i++){
        game->playerArray[i] = playerList[i];
    }
    game->players = numOfPlayers;

    error.status = 0;
    return error;
}

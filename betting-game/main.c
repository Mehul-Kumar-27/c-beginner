#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include "player/player.h"
#include "game/game.h"
#include "utils/utils.h"

int main(int argc, char const *argv[])
{
    char name[50];
    Player player;
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    initializePlayer(&player, name);
    Player playerList[1] = {player};
    Game game;
    Error err = initGame(&game, playerList, 1);
    if(err.status == 0){
        printf("Successfully initialized the game with %zu players!", sizeof(playerList) / sizeof(playerList[0]));
    }
    return 0;
}

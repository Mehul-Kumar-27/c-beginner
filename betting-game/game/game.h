#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include "../player/player.h"
#include "../utils/utils.h"
#include <stddef.h>

typedef struct {
    int players;       /**< Number of players in the game */
    Player *playerArray; /**< Dynamic array of players */
} Game;

/**
 * Initializes a Game instance with the given players.
 * Allocates memory and copies the player data.
 *
 * @param game Pointer to the Game structure to initialize.
 * @param playerList Array of existing players.
 * @param numPlayers Number of players in the game.
 */
Error initGame(Game *game, Player *playerList, int numOfPlayers);

/**
 * Frees the memory allocated for the Game instance.
 *
 * @param game Pointer to the Game structure to clean up.
 */
void freeGame(Game *game);

#endif // GAME_H

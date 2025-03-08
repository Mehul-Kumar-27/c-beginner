#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include "../player/player.h"
#include "../utils/utils.h"
#include <stddef.h>

enum GameEventStatus
{
    EVENT_SUCCESS = 0,
    FAILED_TO_GET_INPUT = 1,
    INVALID_USER_INPUT = 2,
    USER_FAILED_TO_PROVIDE_INPUT = 3
};

typedef struct
{
    char gameId[37];     // UUID as a string (36 characters + null terminator)
    int players;         /**< Number of players in the game */
    Player *playerArray; /**< Dynamic array of players */
    int bots;            /**<Number of bots added to the game */
    int magic_number     /* <Random Number that is generated for each round>*/
} Game;

typedef struct
{
    char message[50];
    int data;
    enum GameEventStatus status;
} Message;

/**
 * Initializes a Game instance with the given players.
 * Allocates memory and copies the player data.
 *
 * @param game Pointer to the Game structure to initialize.
 * @param playerList Array of existing players.
 * @param numPlayers Number of players in the game.
 */
Error initGame(Game *game, Player *playerList, int numOfPlayers);
Error startGame(Game *game);

/**
 * Frees the memory allocated for the Game instance.
 *
 * @param game Pointer to the Game structure to clean up.
 */
void freeGame(Game *game);

#endif // GAME_H

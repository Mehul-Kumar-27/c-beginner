#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>

enum PlayerType {
    Human,
    Bot
};

/**
 * @struct Player
 * @brief Represents a player with a name and balance.
 */
typedef struct {
    char name[50];  /**< Player's name */
    int balance;     /**< Player's balance */
    bool isBot;
} Player;

/**
 * @brief Initializes a player with the given name and default balance.
 *
 * @param p     Pointer to the Player structure to initialize.
 * @param name  Name of the player.
 */
void initializePlayer(Player *p, const char *name);

#endif  // PLAYER_H

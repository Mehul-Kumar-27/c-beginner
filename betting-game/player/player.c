#include "player.h"

/**
 * @brief Initializes a player with the given name and default balance.
 *
 * @param p     Pointer to the Player structure to initialize.
 * @param name  Name of the player.
 */
void initializePlayer(Player *p, const char *name) {
    // Copy the name to the player's name field
    strncpy(p->name, name, 49);
    p->name[49] = '\0';  // Ensure null-termination

    // Initialize balance to a default value (e.g., 0)
    p->balance = 1000;
}

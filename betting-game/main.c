#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include "player/player.h"

int main(int argc, char const *argv[])
{
    char name[50];
    Player player;
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    initializePlayer(&player, name);

    printf("Welcome %s, your starting balance is %d \n", player.name, player.balance);
    return 0;
}

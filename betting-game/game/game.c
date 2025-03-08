#include "game.h"
#include "../utils/utils.h"
#include <string.h>
#include <stddef.h>
#include <uuid/uuid.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/time.h>

Error initGame(Game *game, Player *playerList, int numOfPlayers)
{
    Error error;
    if (numOfPlayers == 0)
    {
        error.status = 1;
        safe_strncpy(error.message, "error: minimum of 1 player is required for game!", 50);
        return error;
    }

    game->playerArray = (Player *)malloc(numOfPlayers * sizeof(Player));
    if (game->playerArray == NULL)
    {
        error.status = 1;
        safe_strncpy(error.message, "error: memory allocation failed", 50);
        return error;
    }

    for (int i = 0; i < numOfPlayers; i++)
    {
        game->playerArray[i] = playerList[i];
    }
    game->players = numOfPlayers;
    uuid_t uuid;
    uuid_generate(uuid);
    uuid_unparse(uuid, game->gameId);

    error.status = 0;
    return error;
}

Message input_with_timeout(int *number, unsigned int timeout_sec){
    printf("\n You have %u seconds to enter your lucky number: \n", timeout_sec);
    Message message;
    fd_set read_fds;

    struct timeval tv;
    int ret;

    // Initializing the file descriptor set
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);

    tv.tv_sec = timeout_sec;
    tv.tv_usec = 0;

    ret = select(STDIN_FILENO +1, &read_fds, NULL, NULL, &tv);
    if(ret == -1) {
        perror("failed to get the input from the user!");
        message.status = FAILED_TO_GET_INPUT;
        safe_strncpy(message.message, "failed to get the user lucky number!", 50);
        return message;
    }else if(ret == 0){
        message.status = USER_FAILED_TO_PROVIDE_INPUT;
        safe_strncpy(message.message, "timeout occurred", 50);
        return message;
    }else {
        char buffer[128];
        if(fgets(buffer, sizeof(buffer), stdin) == NULL){
            message.status = FAILED_TO_GET_INPUT;
            safe_strncpy(message.message, "failed to get the user lucky number!", 50);
            return message;
        }
        removeNewLine(buffer);
        void *args [] = {
            buffer,
            number,
            NULL,
            NULL
        };
        Error error = handleNumberInput(args);
        if(error.status != 0){
            message.status = INVALID_USER_INPUT;
            safe_strncpy(message.message, "invalid input provided!", 50);
            return message;
        }
        message.status = EVENT_SUCCESS;
        sprintf(message.message , "Input provided is %d \n", *number);
        return message;
    }
}

Error startGame(Game *game)
{
    printf("\nStarting game, buckle up ! \n");
    Error error;
    int input_number;
    Message message = input_with_timeout(&input_number, 10);
    if(message.status != EVENT_SUCCESS){
        safe_strncpy(error.message, message.message, 50);
        error.status = 1;
        return error;
    }
    printf("%s", message.message);
    return error;
}

void freeGame(Game *game) {
    free(game->playerArray);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include "player/player.h"

// struct Player
// {
//     char name[50];
//     int balance;
// };

// typedef struct
// {
//     char message[50];
//     int status; // status should always contain 0 or 1 value
// } InputError;

// int getRandomNumber()
// {
//     return (rand() % 10) + 1;
// }

// void playGame(struct Player *player)
// {
//     int bet;
//     printf("Enter the bet amount: ");
//     scanf("%d", &bet);

//     if (bet > player->balance)
//     {
//         printf("Insufficient balance! \n");
//     }

//     int userChoice, outcome;

//     printf("Guess the number between 1 and 10 \n");
//     scanf("%d", &userChoice);
//     if (userChoice < 1 || userChoice > 10)
//     {
//         printf("Invalid number input: %d, please choose between 1 and 10.", userChoice);
//         return;
//     }
// }

// void removeNewLine(char *str)
// {
//     size_t len = strlen(str);
//     if (len > 0 && str[len - 1] == '\n')
//     {
//         str[len - 1] = '\0';
//     }
// }

// /// @brief handleNumberInput would take in the number value in the string format and then assign it to destination
// /// @param args An array of arguments:
// ///             args[0] = input (string form of the number)
// ///             args[1] = destination (pointer to int where the result will be stored)
// ///             args[2] = min (optional, minimum value)
// ///             args[3] = max (optional, maximum value)
// /// @return InputError type error status is 0 if copy process is successful
// InputError handleNumberInput(void *args[])
// {
//     InputError error;

//     // Extract arguments from the array
//     char *input = (char *)args[0];
//     int *destination = (int *)args[1];
//     int min = (args[2] != NULL) ? *((int *)args[2]) : INT_MIN; // Default to INT_MIN if not provided
//     int max = (args[3] != NULL) ? *((int *)args[3]) : INT_MAX; // Default to INT_MAX if not provided

//     // Checking if the input is empty
//     if (input == NULL)
//     {
//         strncpy(error.message, "error: input provided is NULL!", sizeof(error.message) - 1);
//         error.status = 1;
//         return error;
//     }

//     int value;
//     if (sscanf(input, "%d", &value) != 1)
//     {
//         strncpy(error.message, "error: invalid number provided!", sizeof(error.message) - 1);
//         error.status = 1;
//         return error;
//     }

//     // Skip bounds check if min and max are set to INT_MIN and INT_MAX respectively
//     if ((min != INT_MIN && value < min) || (max != INT_MAX && value > max))
//     {
//         strncpy(error.message, "error: out of bound value provided", sizeof(error.message) - 1);
//         error.status = 1;
//         return error;
//     }

//     *destination = value;
//     strncpy(error.message, "success", sizeof(error.message) - 1);
//     error.status = 0;
//     return error;
// }

int main(int argc, char const *argv[])
{
    Player player;
    printf("Enter your name: ");
    fgets(player.name, 49, stdin);

    printf("Welcome %s, your starting balance is %d", player.name, player.balance);
    return 0;
}

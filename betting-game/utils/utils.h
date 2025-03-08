#ifndef UTILS_H
#define UTILS_H
#include <stddef.h>

typedef struct
{
    int status;
    char message[50];
} Error;
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

void removeNewLine(char *str);
Error safe_strncpy(char *dest, const char *src, size_t max_len);
Error handleNumberInput(void *args[]);

#endif

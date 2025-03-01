#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct  Player
{
    char name[50];
    int balance;
};

int getRandomNumber() {
    return (rand() % 10) +1 ;
}

void playGame(struct Player *player){
    int bet;
    printf("Enter the bet amount: ");
    scanf("%d", &bet);

    if(bet > player->balance){
        printf("Insufficient balance! \n");
    }

    int userChoice, outcome;

    printf("Guess the number between 1 and 10 \n");
    scanf("%d", &userChoice);
    if(userChoice < 1 || userChoice > 10){
        printf("Invalid number input: %d, please choose between 1 and 10.", userChoice);
        return;
    }

}

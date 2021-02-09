#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RockPaperScissors(char computer, char player) {
    /*
    * Check for the following conditions:
    
    * if same choice
    // TODO Draw

    * For Player:
    // TODO rock paper     -> The computer wins in this. 
    // TODO paper scissors -> The computer wins in this.
    // TODO scissors rock  -> The computer wins in this.

    * For Computer:
   // TODO rock paper     -> The player wins in this
   // TODO paper scissors -> The player wins in this
   // TODO scissors rock  -> The player wins in this
    */

    if (player == computer) {
        printf("Game draw.\n");
        printf("You chose %c and the computer chose %c\n", player, computer);
        return 0;
    } else if (player == 'r' && computer == 'p') {
        printf("Computer Wins.\n");
        printf("You chose %c and the computer chose %c\n", player, computer);
        return -1;
    } else if (player == 'p' && computer == 's') {
        printf("Computer Wins.\n");
        printf("You chose %c and the computer chose %c\n", player, computer);
        return -1;
    } else if (player == 's' && computer == 'r') {
        printf("Computer Wins.\n");
        printf("You chose %c and the computer chose %c\n", player, computer);
        return -1;
    } else if (computer == 'r' && player == 'p') {
        printf("You Win.\n");
        printf("You chose %c and the computer chose %c\n", player, computer);
        return 1;
    } else if (computer == 's' && player == 'r') {
        printf("You Win.\n");
        printf("You chose %c and the computer chose %c\n", player, computer);
        return 1;
    } else {
        printf("You Win.\n");
        printf("You chose %c and the computer chose %c\n", player, computer);
        return 1;
    }
}

int main() {
    // Play a game of Rock, Paper, Scissors vs the computer
    char playerChoice, compChoice;
    int whoWon, playerScore = 0, compScore = 0, randomNum;
    srand(time(0));

    //* the main game loop
    // // ! Loop Running Once only 
    while (playerScore < 5 && compScore < 5) {
        randomNum = rand() % 100;
        if (randomNum >= 0 && randomNum <= 32) {
            compChoice = 'r';
        } else if (randomNum >= 33 && randomNum <= 65) {
            compChoice = 'p';
        } else {
            compChoice = 's';
        }
        printf("Enter your choice (r for rock, p for paper, s for scissors): ");
        scanf(" %c", &playerChoice);
        whoWon = RockPaperScissors(compChoice, playerChoice);
        if (whoWon == 1) {
            playerScore++;
        } else if (whoWon == -1) {
            compScore++;
        } else {
            continue;
        }
    }
    if (compScore == 5) {
        printf("\nComputer won the game.\n");

    } else {
        printf("\nYou won the game.\n");
    }
    printf("Your Score: %d\nComputer\'s Score: %d\n", compScore, playerScore);
    return 0;
}
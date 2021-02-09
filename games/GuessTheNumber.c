#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame(int randomNumber) {
    int guess, chances = 0;
    while (guess != randomNumber && chances != 9) {
        printf("\nGuess a number between 1 and 50: ");
        scanf(" %d", &guess);
        if (guess < randomNumber) {
            printf("The guessed number is less than the original number.\n");
        } else if (guess > randomNumber) {
            printf("The guessed number is more than the original number.\n");
        } else if (guess == randomNumber) {
            printf("Congratulations. You guessed the number. The number was %d.\n\n", randomNumber);
        } else {
            printf("Invalid choice.\n");
            continue;
        }
        chances++;
    }
}

int main() {
    int random, number;
    char playAgain;
    srand(time(0));
    do {
        random = rand() % 50 + 1;
        playGame(random);
        printf("Do you want to play again ([Y]es or [N]o) ?: ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'Y' || playAgain == 'y');
    return 0;
}
#include <stdio.h>
#include <windows.h>

void displayBoard(char board[]) {
    for (int i = 0; i < 7; i += 3) {
        if (i == 6) {
            printf(" %c | %c | %c \n", board[i], board[i + 1], board[i + 2]);
            break;
        }
        printf(" %c | %c | %c \n", board[i], board[i + 1], board[i + 2]);
        printf("---+---+---\n");
    }
}

int checkWin(char board[], char sign) {
    // Check for rows
    for (int i = 0; i <= 6; i += 3) {
        if (board[i] == sign && board[i + 1] == sign && board[i + 2] == sign) {
            return 1;
        }
    }

    // Check for columns
    for (int i = 0; i < 2; i++) {
        if (board[i] == sign && board[i + 3] == sign && board[i + 6] == sign) {
            return 1;
        }
    }

    // Check for diagonals
    if ((board[0] == sign && board[4] == sign && board[8] == sign) || (board[2] == sign && board[4] == sign && board[6] == sign)) {
        return 1;
    }

    return 0;
}

void play() {
    // The game variables
    char board[9], sign;
    int player, choice, count = 0, winner = 0;

    // Initializing the board of tic tac toe
    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }

    // The game loop
    while (count < 9 && winner == 0) {
        displayBoard(board);
        player = count % 2 == 0 ? 1 : 2;
        sign = count % 2 == 0 ? 'X' : 'O';
        printf("Enter your choice player %d (1-9): ", player);
        scanf("%d", &choice);

        // Check if the place has been occupied by X or O
        if (board[choice - 1] == 'X' || board[choice - 1] == 'O') {
            printf("Place Occupied. Choose again\n");
            continue;
        }

        // Check if the number entered is less than 1 or more than 9
        if (choice < 1 || choice > 9) {
            printf("Invalid choice. Choose again\n");
            continue;
        }

        board[choice - 1] = sign;
        winner = checkWin(board, sign);
        count++;
    }
    displayBoard(board);
    if (count == 9 && winner == 0) {
        // Match draw
        printf("Game Draw\n");
    } else {
        // Some one won.
        printf("Player %d wins.\n", player);
    }
}

int main() {
    char playAgain;

    // Play a tic tac toe for two players.

    do {
        // Play the game
        play();

        // Ask for play again
        printf("Do you want to play again ([Y]es or [N]o) ?: ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'Y' || playAgain == 'y');
    return 0;
}
#include <stdio.h>

/*
Print the following pattern:
* * * * * * * * 
* * * * * * *
* * * * * *
* * * * *
* * * * 
* * * 
* *
*
*/

int main() {
    int n = 5;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    for (int row = 0; row < n; row++) {
        for (int column = 0; column < n - row; column++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
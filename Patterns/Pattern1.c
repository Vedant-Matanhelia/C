#include <stdio.h>

/*
Print the following pattern:
*
* *
* * *
* * * *
* * * * *
*...n
*/

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // For the number of rows -> the i loop
    for (int i = 0; i < n; i++) {
        // For the number of columns -> the j loop
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
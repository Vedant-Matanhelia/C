#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int a = rand() % 100;  // Generate number between 0 and 99
    printf("%d\n", a);
    return 0;
}
#include <stdio.h>

void func(int character)

int main() {
    FILE *ptr;
    ptr = fopen("This.txt", "w");
    fprintf(ptr, "This is a file written using c language.");
    return 0;
}
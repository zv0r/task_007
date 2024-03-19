#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    char* string = NULL;

    scanf("%ms", &string);
    int split_position = strlen(string);
    
    while(split_position > 1) {
        printf("%s\n", string);
        split_position = ceil(strlen(string) / 2.0);
        string[split_position] = 0;
    };
    printf("%c\n", string[0]);

    free(string);
    return EXIT_SUCCESS;
}
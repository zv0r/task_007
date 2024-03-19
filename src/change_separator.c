#define _POSIX_C_SOURCE 200809L

#include "change_separator.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char* string = input_string();
    char delimiter = input_delimiter();

    replace_delimiter(string, delimiter);
    printf("%s", string);

    free(string);
    return EXIT_SUCCESS;
}

char* input_string() {
    char* tmp_string = NULL;
    size_t tmp_string_length = 0;
    getline(&tmp_string, &tmp_string_length, stdin);
    return tmp_string;
}

char input_delimiter() {
    char result;
    scanf("%c", &result);
    return result;
}

void replace_delimiter(char* string, char delimiter) {
    for (int i = 0; string[i]; i++) {
        if (string[i] == ' ') string[i] = delimiter;
    }
}
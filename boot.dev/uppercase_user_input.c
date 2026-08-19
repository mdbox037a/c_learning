#include "exercise.h"
#include <stdio.h>

void uppercase_line(char text[]) {
        int i;
        for (i = 0; text[i] != '\0'; i++) {
                if (text[i] == '\n') {
                        text[i] = '\0';
                        break;
                }
                if (text[i] >= 'a' && text[i] <= 'z') {
                        text[i] -= ('a' - 'A');
                }
        }
}

void print_uppercase_input(void) {
        char text[256];

        if (fgets(text, sizeof(text), stdin) == NULL) {
                return;
        }

        uppercase_line(text);
        printf("%s\n", text);
}

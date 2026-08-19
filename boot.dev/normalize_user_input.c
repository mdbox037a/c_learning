#include "exercise.h"
#include <ctype.h>

void normalize_line(char *line) {
        int output_index;

        /* find start of text and skip leading whitespace */
        for (int i = 0; line[i] != '\0'; i++) {
                if (isspace(line[i])) {
                        continue;
                }
                output_index = i;
        }

        /* move through string and condense any consecutive whitespaces */
        char buff = '\0';
        for (int i = output_index; line[i] != '\0'; i++) {
                if (isspace(line[i])) {
                        line[i] = ' ';
                }
                if (buff == ' ' && line[i] == ' ') {
                        continue;
                }
                buff = line[i];
        }
}

#include "LineMethods.h"

void change2LowerCase(char *line) {
    for (int i = 0; line[i]; ++i) {
        line[i] = tolower(line[i]);
    }
}

void change2UpperCase(char *line) {
    for (int i = 0; line[i]; ++i) {
        line[i] = toupper(line[i]);
    }
}

void switchCase(char *line) {
    for (int i = 0; line[i]; ++i) {
        if (islower(line[i])) {
            line[i] = toupper(line[i]);
        }
        else {
            line[i] = tolower(line[i]);
        }
    }
}

void makeNames(char *line) {
    for (int i = 0; line[i]; ++i) {
        if (i == 0) {
            line[i] = toupper(line[i]);
        }
        else {
            line[i] = tolower(line[i]);
        }
    }
}

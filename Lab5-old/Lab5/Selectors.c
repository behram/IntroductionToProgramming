#include "Selectors.h"

void run_with(bool (*mode)(const config *conf, const char *line), const config *conf) {
    char line[LINE_LEN];

    while (fgets(line, LINE_LEN, stdin)) {
        if ((*mode)(conf, line)) { // If lines fulfill expectations
            printf("\t%s", line);
        }
    }
}

bool lineBegins(const config *conf, const char *line) {
    char *pattern = conf->arg1;

    return (strncmp(pattern, line, strlen(pattern)) == 0);
}

// Not implemented
bool lineBeginsInRange(const config *conf, const char *line) {
    return true;
}

// Not implemented
bool firstWordBeginsWith(const config *conf, const char *line) {
    return true;
}

// Not implemented
bool firstWordEndsWith(const config *conf, const char *line) {
    return true;
}




void get_first_word(const char *line, char *word, int len) {
    int i;

    for (i = 0; i < len - 1; ++i) {
        if (isspace(line[i])) {
            word[i] = 0;
            break;
        }

        word[i] = line[i];
    }

    // Overflow guard
    if (i == len - 1) {
        word[++i] = 0;
    }
}

bool in_range(const int num, const int begin, const int end) {
    return (num >= begin && num <= end);
}

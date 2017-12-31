#include "Selectors.h"

void run_with(bool (*mode)(const config *conf), const config *conf) {
    (*mode)(conf);
}

bool lineBegins(const config *conf) {
    char line[LINE_LEN];
    char *pattern = conf->arg1;

    while (fgets(line, LINE_LEN, stdin)) {
        if (strncmp(pattern, line, strlen(pattern)) == 0) {
            printf("%s", line);
        }
    }
    return true;
}

bool lineBeginsInRange(const config *conf) {
    char line[LINE_LEN];
    char *from = conf->arg1;
    char *to = conf->arg2;

    while (fgets(line, LINE_LEN, stdin)) {
        if (strncmp(from, line, strlen(from)) == 0 || strncmp(to, line, strlen(to)) == 0) {
            printf("%s", line);
        }
    }

    return false;
}

// Not implemented
bool firstWordBeginsWith(const config *conf) {
    char line[LINE_LEN];
    char *to = conf->arg2;

    while (fgets(line, LINE_LEN, stdin)) {
        if (strncmp(to, line, strlen(to)) == 0) {
            printf("%s", line);
            return true;
        }else{
            printf("%s", line);
        }
    }

    return true;
}

// Not implemented
bool firstWordEndsWith(const config *conf) {
    char line[LINE_LEN];
    char *from = conf->arg1;
    bool started;

    while (fgets(line, LINE_LEN, stdin)) {
        if (strncmp(from, line, strlen(from)) == 0) {
            started = true;
        }
        if(started){
            printf("%s", line);
        }
    }

    return true;
}

bool in_range(const int num, const int begin, const int end) {
    return (num >= begin && num <= end);
}

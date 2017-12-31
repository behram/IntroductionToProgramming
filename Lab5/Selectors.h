#ifndef selectors_h
#define selectors_h

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "Config.h"
#include "Consts.h"


void run_with(bool (*mode)(const config *conf, const char *line), const config *conf);

bool lineBegins(const config *conf, char *inputGets);

bool lineBeginsInRange(const config *conf, const char *line);

bool firstWordBeginsWith(const config *conf, const char *line);

bool firstWordEndsWith(const config *conf, const char *line);

void get_first_word(const char *line, char *word, int len);

bool in_range(const int num, const int begin, const int end);

#endif /* selectors_h */

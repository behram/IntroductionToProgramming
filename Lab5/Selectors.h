#ifndef selectors_h
#define selectors_h

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "Config.h"
#include "Consts.h"


void run_with(bool (*mode)(const config *conf), const config *conf);

bool lineBegins(const config *conf);

bool lineBeginsInRange(const config *conf);

bool firstWordBeginsWith(const config *conf);

bool firstWordEndsWith(const config *conf);

bool in_range(const int num, const int begin, const int end);

#endif /* selectors_h */

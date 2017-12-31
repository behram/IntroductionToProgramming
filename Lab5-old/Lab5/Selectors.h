#ifndef selectors_h
#define selectors_h

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "Config.h"
#include "Consts.h"


/**
 Starts program egecution in given mode

 @param mode Function wich will decide wether to print line or not.
 */
void run_with(bool (*mode)(const config *conf, const char *line), const config *conf);



/**
 Checks wether line begins with given pattern ( conf.arg1 )

 @param conf Application config
 @param line Input line
 @return Determinates wether line can be printed.
 */
bool line_begins(const config *conf, const char *line);

/**
 NOT IMPLEMENTED

 @param conf Application config
 @param line Input line
 @return NOT IMPLEMENTED
 */
bool line_begins_in_range(const config *conf, const char *line);

/**
 NOT IMPLEMENTED
 
 @param conf Application config
 @param line Input line
 @return NOT IMPLEMENTED
 */
bool first_word_begins_with(const config *conf, const char *line);

/**
 NOT IMPLEMENTED
 
 @param conf Application config
 @param line Input line
 @return NOT IMPLEMENTED
 */
bool first_word_ends_with(const config *conf, const char *line);



/**
 Sets first word to `word` argument from given line.

 @param line Input line
 @param word Output word
 @param len Word length
 */
void get_first_word(const char *line, char *word, int len);

/**
 Determinates wether given number is in range (inclusively).

 @param num Input number
 @param begin Begin of the range
 @param end End of the range
 @return Indicator
 */
bool in_range(const int num, const int begin, const int end);

#endif /* selectors_h */

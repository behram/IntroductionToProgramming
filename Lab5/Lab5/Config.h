#ifndef config_h
#define config_h

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 Running mode
 
 This enum determinates mode which should be used in order to
 run the application.
 */
typedef enum {
    lineBegins,
    lineBeginsInRange,
    firstWordBeginsWith,
    firstWordEndsWith
} running_mode;

/**
 Application config
 */
typedef struct {
    char *arg1;
    char *arg2;
    running_mode rm;
    
} config;



/**
 config's constructor.

 @return New config
 */
config newConfig(void);

/**
 Reads config from given parameters and sets it to the given object.

 @param conf Given config object
 @param argc Number of arguments
 @param argv Arguments
 */
void setConfig(config *conf, int argc, char * argv[]);

/**
 Checks if given string is "-"

 @param str Input string
 @return Indicator
 */
bool _is_dash(const char *str);

#endif /* config_h */

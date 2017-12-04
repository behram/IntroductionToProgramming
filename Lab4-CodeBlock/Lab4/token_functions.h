//
//  token_functions.h
//  lab4
//
//  Created by Mieszko Wawrzyniak on 25/10/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#ifndef token_functions_h
#define token_functions_h

#include <stdio.h>
#include <ctype.h>

#include "bool.h"
#include "const.h"

#define INT_BEGIN (isdigit(c) || c == '+' || c == '-')
#define FLOAT_BEGIN (isdigit(c) || c == '+' || c == '-' || c == '.')
#define FLOAT_CHAR (isdigit(c) || c == '.')

/**
 Finds word in standard input

 @param str Destination string
 @param len Destination string's length
 @return Bool: true{1} on sucess, false{0} on EOF, OVERRIDE{2} on override
 */
bool next_word(char *str, const int len);
bool next_name(char *name, const int len);
bool next_int(char *str, const int len);
bool next_float(char *str, const int len);
bool next_phone_num(char *str, const int len);

bool is_lowercase(const char c);
bool is_uppercase(const char c);
bool in_range(const int num, const int begin, const int end);

#endif /* token_functions_h */

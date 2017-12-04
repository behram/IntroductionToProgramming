//
//  token_functions.c
//  lab4
//
//  Created by Mieszko Wawrzyniak on 25/10/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include "token_functions.h"

bool next_word(char *word, const int len)
{
    bool is_word = false; // Wether loop is inside of the word
    int i = 0; // Char no. in the word
    char c; // Read char
    
    while (EOF != (c = getchar()))
    {
        // Wasn't any alfa character in the stdin
        if (!is_word && !isalpha(c)) continue;
        
        // The first alfa character in the stdin
        if (!is_word && isalpha(c)) is_word = true;
        
        // End of the word
        else if (is_word && !isalpha(c))
        {
            word[++i] = 0;
            return true;
        }
        
        // Override guard
        if (i == len - 1)
        {
            word[++i] = 0;
            return OVERRIDE;
        }
        
        word[i] = c; // Add char to the string
        i++; // It's not for loop because incrementation can happen only when added
        //       char to string.
    }
    
    // End of file
    if (is_word) return true;
    return false;
}

bool next_name(char *name, const int len)
{
    bool is_name = false; // Wether loop is inside of the name
    int i = 0; // Char no. in the word
    char c; // Read char
    
    while (EOF != (c = getchar()))
    {
        // Wasn't any word yet in the stdin
        if (!is_name && !is_uppercase(c)) continue;
        
        // Detect beginning of the name
        if (!is_name && is_uppercase(c)) is_name = true;
        
        // End of the name
        else if (is_name && !is_lowercase(c))
        {
            name[++i] = 0;
            return true;
        }
        
        // Override guard
        if (i == len - 1)
        {
            name[++i] = 0;
            return OVERRIDE;
        }
        
        name[i] = c; // Add char to the string
        i++; // It's not for loop because incrementation can happen only when added
        //       char to string.
    }
    
    // End of file
    if (is_name) return true;
    return false;
}

bool next_int(char *str, const int len)
{
    bool is_int = false; // Wether loop is inside of the integer
    int i = 0; // Char no. in the integer
    char c;  // Read char
    char first_c = '\0'; // First integers character
    
    while (EOF != (c = getchar()))
    {
        // Wasn't any digit yet in the stdin
        if (!is_int && !INT_BEGIN) continue;
        
        // If second char is a digit if staring char was [+-]
        if (i == 1 && (first_c == '-' || first_c == '+') && !isdigit(c))
        {
            is_int = false;
            i = 0;
            continue;
        }
        
        // Detect beginning of the integer
        if (!is_int && INT_BEGIN)
        {
            is_int = true;
            first_c = c;
        }
        
        // End of the integer
        else if (is_int && !isdigit(c))
        {
            str[++i] = 0;
            return true;
        }
        
        // Override guard
        if (i == len - 1)
        {
            str[++i] = 0;
            return OVERRIDE;
        }
        
        str[i] = c; // Add char to the string
        i++; // It's not for loop because incrementation can happen only when added
        //       char to string.
    }
    
    // End of file
    if (is_int) return true;
    return false;
}

bool next_float(char *str, const int len)
{
    bool is_float = false; // Wether loop is inside of the float
    bool was_dot = false; // Determinates wether there was a dot in the float
    int i = 0; // Char no. in the integer
    char c;  // Read char
    char first_c = '\0'; // First integers character
    
    while (EOF != (c = getchar()))
    {
        // Wasn't any digit yet in the stdin
        if (!is_float && !FLOAT_BEGIN) continue;
        
        // If second char is a digit if staring char was [+-]
        if (i == 1 && (first_c == '-' || first_c == '+') && !FLOAT_CHAR)
        {
            is_float = false;
            was_dot = false;
            i = 0;
            continue;
        }
        
        // Detect beginning of the float
        if (!is_float && FLOAT_BEGIN)
        {
            is_float = true;
            first_c = c;
        }
        
        // Second dot detection
        else if (is_float && was_dot && c == '.')
        {
            str[++i] = 0;
            return true;
        }
        
        // End of the float
        else if (is_float && !FLOAT_CHAR)
        {
            str[++i] = 0;
            return true;
        }
        
        // Set flag preventing multiple dots
        if (is_float && c == '.') was_dot = true;
        
        // Override guard
        if (i == len - 1)
        {
            str[++i] = 0;
            return OVERRIDE;
        }
        
        str[i] = c; // Add char to the string
        i++; // It's not for loop because incrementation can happen only when added
        //       char to string.
    }
    
    // End of file
    if (is_float) return true;
    return false;
}

bool next_phone_num(char *str, const int len)
{
    bool is_num = false;
    int i = 0;
    char c;
    
    if (len < 11) return OVERRIDE;
    
    while (EOF != (c = getchar()))
    {
        // Wasn't any number yet in the stdin
        if (!is_num && !isdigit(c)) continue;
        
        // Detect beginning of the phone number
        if (!is_num && isdigit(c)) is_num = true;
        
        // Check the pattern: digits
        if (in_range(i, 0, 2) ||
            in_range(i, 4, 6) ||
            in_range(i, 8, 10))
        {
            if (!isdigit(c))
            {
                is_num = false;
                i = 0;
                continue;
            }
        }
        
        // Check the pattern: slashs
        if (i == 3 ||
            i == 7 ||
            i == 11)
        {
            if (c != '/')
            {
                is_num = false;
                i = 0;
                continue;
            }
        }
        
        str[i] = c;
        i++;
        
        // End of number
        if (i == 11)
        {
            str[i] = 0;
            return true;
        }
    }
    
    return false;
}

bool is_lowercase(const char c)
{
    return (c >= 'a' && c <= 'z');
}

bool is_uppercase(const char c)
{
    return (c >= 'A' && c <= 'Z');
}

bool in_range(const int num, const int begin, const int end)
{
    return (num >= begin && num <= end);
}

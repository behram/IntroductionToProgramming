//
//  main.c
//  lab4
//
//  Created by Mieszko Wawrzyniak on 25/10/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include <stdio.h>

#include "const.h"
#include "bool.h"
#include "token_functions.h"

#include <ctype.h>

int main(int argc, const char * argv[]) {
  char number[LINE_LEN];
  
  while (next_int(number, LINE_LEN)) {
    puts(number);
  }
  
  return 0;
}

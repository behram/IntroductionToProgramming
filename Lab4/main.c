#include <stdio.h>

#include "const.h"
#include "bool.h"
#include "token_functions.h"

int main(int argc, const char * argv[]) {
  char number[LINE_LEN];
  
  while (next_int(number, LINE_LEN)) {
    puts(number);
  }
  
  return 0;
}

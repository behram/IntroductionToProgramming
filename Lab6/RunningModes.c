#include "RunningModes.h"

void runWith(void (*mode)(char*) ) {
  char line[LINE_LEN];
  
  while (fgets(line, LINE_LEN, stdin)) {
    (*mode)(line);
    printf("%s", line);
  }
}

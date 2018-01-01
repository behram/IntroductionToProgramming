#include "func.h"


int
main(){
  personalData data[10];
  printf("\n\n %lu \n\n", sizeof(data)/sizeof(personalData));

  int len = readPtrData(data,sizeof(data)/sizeof(personalData));
  printf("\n\n %d \n\n", len);
  printAllData(data,len);

  /**
  weightSort(data,len);
  puts("after weight sort");
  printAllData(data,len);

  remarkstSort(data,len);
  puts("after remarks sort");
  printAllData(data,len);

  puts("index 2:");
  printData(data[2],len);
  puts("\n End of work!");
*/
  return 0;
}

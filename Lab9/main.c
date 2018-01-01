#include "Functions.h"

int main(){
  struct personalData *data[10];
  int len = readPtrData(data,sizeof(data)/sizeof(*data));
  puts("\n -- first order --");
  printAllData(data,len);

  weightSort(data,len);
  puts("\n-- after weight sort --");
  printAllData(data,len);

  remarkstSort(data,len);
  puts("\n-- after remarks sort --");
  printAllData(data,len);

  puts("\n-- print index (3) --");
  printData(data[3],len);
  puts("\n --- All Finished, Good Day ---");

  return 0;
}

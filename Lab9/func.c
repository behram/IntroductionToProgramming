#include "func.h"

int readPtrData(personalData ar[], int len){
  char line[100];
  int i = 0;

  while(fgets(line, sizeof(line), stdin) != NULL){
    printf("\n\n %s \n\n", "while stdin");
    printf("\n\n %d \n\n", i);
    printf("\n\n len ----> :%d \n\n", len);
    if((i<len-1) && (semicolonCounter((char*)line) == 4)){

      printf("\n\n %s \n\n", "validation pass");
      ar[i] = malloc(sizeof(personalData));
      ar[i++] = getPersonPtr((char*)line);
      if(ar[i-1]->remarks == NULL){
        printf("\n\n %s \n\n", "minus remarks");
        i--;
      }
    }else{
      break;
    }
    printf("\n\n %s \n\n", "while stdin last");
  }
  printf("\n\n %d \n\n", i);
  personalData lastPerson;//according to "The last structure should have remarks set to 0;"
  lastPerson.remarks = NULL;

  printf("\n\n %d \n\n", i);
  ar[i] = malloc(sizeof(personalData));

  printf("\n\n %d \n\n", i);
  ar[i] = &lastPerson;
  printf("\n\n %d \n\n", i);
  return i;
}

personalData getPersonPtr(char * line){

  printf("\n\n %s \n\n", "get person ptr");
  char *data;
  personalData *x;
  x = malloc(sizeof(struct personalData));

  data = strtok (line,";");//name

  printf("\n\n name baby:%s \n\n", data);
  snprintf(x->name, 20, "%s", data);

  data = strtok(NULL, ";");//age
  if(atoi(data) == 0){
    x->remarks = NULL;
    return x;
  }
  x->age = atoi(data);

  data = strtok(NULL, ";");//weight
  if(atof(data) == 0){
    x->remarks = NULL;
    return x;
  }
  unsigned int i;
  for(i = 0; i< strlen(data); i++){
    if(!(isdigit(data[i]) || data[i] == '.')){
      x->remarks = NULL;
      return x;
    }
  }
  x->weight = atof(data);

  data = strtok (NULL,";");//remarks
  x->remarks = malloc(sizeof(char)*(strlen(data)+1));

  printf("\n\n remarks:%s \n\n", data);
  snprintf(x->remarks, (strlen(data)+1), "%s", data);

  return x;
}

int semicolonCounter(char *line){
  int counter = 0;

  unsigned int j;
  for(j = 0;j < strlen(line)-1; j++){
    if(line[j] == ';'){
      counter++;
    }
  }
  return counter;
}

void weightSort(struct personalData *data[], int len){
  qsort(data,len,sizeof(*data),cmpWeight);
}
int cmpWeight (const void *a, const void *b) {
  struct personalData *pd0 = *((struct personalData **)a);
  struct personalData *pd1 = *((struct personalData **)b);

  return (pd0->weight - pd1->weight);
}

void remarkstSort(struct personalData *data[], int len){
  qsort(data,len,sizeof(*data),cmpRemarks);
}
int cmpRemarks (const void *a, const void *b) {
  struct personalData *pd0 = *((struct personalData **)a);
  struct personalData *pd1 = *((struct personalData **)b);

  return (strcmp(pd0->remarks, pd1->remarks));
}

void printAllData(struct personalData *data[], int len){
  int i;
  for(i = 0;i < len; i++){
    printPtrData(&data[i], len);
  }
}

void printData (struct personalData data[], int len){
  if(len < 0){
    puts("It is not working");
  }else{
    int index = 0;
    printf("name: %s\tage: %d\tweight: %.2f\tremark:%s\n"
            ,data[index].name, data[index].age, data[index].weight, data[index].remarks);
  }
}
void printPtrData(struct personalData *data[], int len){
  puts("printPtrData function calls");
  if(len < 0){
    puts("It is not working");
  }else{
    printf("\n\n %s \n\n", "print ptr baby");
    printf("name: %s\tage: %d\tweight: %.2f\tremark:%s\n"
            ,data[0]->name, data[0]->age, data[0]->weight, data[0]->remarks);
  }
}

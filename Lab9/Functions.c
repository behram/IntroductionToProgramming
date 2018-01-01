#include "Functions.h"

int readPtrData(struct personalData *ar[], int len){
  char line[100];
  int i = 0;

  while(fgets(line, 100, stdin) != NULL){
    if((i<len-1) && (semicolonCounter((char*)line) == 4)){
      ar[i] = malloc(sizeof(struct personalData));
      ar[i] = getPersonPtr((char*)line);
    }else{
      break;
    }
    ++i;
  }
  struct personalData lastPerson;
  lastPerson.remarks = NULL;
  ar[i] = malloc(sizeof(struct personalData));
  ar[i] = &lastPerson;

  return i;
}

struct personalData *getPersonPtr(char * line){
  char *data;
  struct personalData *x;
  x = malloc(sizeof(struct personalData));

  data = strtok (line,";");//name
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

void printAllData(struct personalData *data[], int len){
  int i;
  for(i = 0;i < len; i++){
    printPtrData(&data[i], len);
  }
}

int cmpRemarks (const void *a, const void *b) {
  struct personalData *pd0 = *((struct personalData **)a);
  struct personalData *pd1 = *((struct personalData **)b);

  return (strcmp(pd0->remarks, pd1->remarks));
}

void printData (struct personalData data[], int len){
  if(len < 0){
    puts("len is zero");
  }else{
    int index = 0;
    printf("name: %s\tage: %d\tweight: %.2f\tremark:%s\n"
            ,data[index].name, data[index].age, data[index].weight, data[index].remarks);
  }
}
void printPtrData(struct personalData *data[], int len){
  if(len < 0){
    puts("len is 0");
  }else{
    if(data[0]->age == 0){
      return;
    }
    printf("name: %s\tage: %d\tweight: %.2f\tremark:%s\n"
            ,data[0]->name, data[0]->age, data[0]->weight, data[0]->remarks);
  }
}

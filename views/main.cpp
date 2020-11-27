#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../controllers/controllers.h"

int main(){
  int num_patient, cure;
  scanf("%d %d", &num_patient, &cure);getchar();
  for(int i = 0; i < num_patient; i++){
    int date, year;
    char name[255], month[255];
    scanf("%d %s %d - %[^\n]", &date, &month, &year, &name); getchar();
    pushPQ(name, date, month, year);
  }
  for(int i = 0; i < cure; i++){
    removePQ();
  }
  if(num_patient > cure){
    printf("Need %d more cure\n", num_patient-cure);
    printAll();
    puts("");
  }else{
    printf("All patients get the curr, %d cure left\n", cure);
  }

  removeAll();
  return 0;
}
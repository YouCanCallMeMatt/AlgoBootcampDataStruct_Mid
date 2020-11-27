#include "../controllers/controllers.h"

int main(){
  int num_patient, cure;
  scanf("%d %d", &num_patient, &cure);
  for(int i = 0; i < num_patient; i++){
    int date, year;
    char name[255], char month[255];
    scanf("%d %s %d - %[^\n]", &date, month, &year, name);
    pushpq();
  }



  removeAll();
  return 0;
}
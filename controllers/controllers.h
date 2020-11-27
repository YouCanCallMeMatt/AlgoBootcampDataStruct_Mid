#include "headers.h"
#include "../models/models.h"


Node *createNode(char *name, int date, char *month, int year){
  Node *temp = (Node *)malloc(sizeof(Node));
  strcpy(temp->name, name);
  temp->date = date;
  strcpy(temp->month, month);
  temp->year = year;
  return temp;
}

int convertMonth(char *month){
  if(strcmp(month,"january") == 0){
    return 1;
  }else if(strcmp(month,"february") == 0) {
    return 2;
  }else if(strcmp(month,"march") == 0) {
    return 3;
  }else if(strcmp(month,"april") == 0) {
    return 4;
  }else if(strcmp(month,"may") == 0) {
    return 5;
  }else if(strcmp(month,"june") == 0) {
    return 6;
  }else if(strcmp(month,"july") == 0) {
    return 7;
  }else if(strcmp(month,"august") == 0) {
    return 8;
  }else if(strcmp(month,"september") == 0) {
    return 9;
  }else if(strcmp(month,"october") == 0) {
    return 10;
  }else if(strcmp(month,"november") == 0){
    return 11;
  }else if(strcmp(month,"december") == 0){
    return 12;
  }
}

long long int countUmur(int date, char *month, int year){
  long long int days = 0;
  days += days;
  days += convertMonth(month) * 30;
  days += year*365;
  return days;
}


void pushpq(char *name, int date, char *month, int year){
  Node *temp = createNode(name, date, month, year);

  if(!head){
    head = tail = temp;
  }else if(countUmur(date, month, year) > countUmur(head->poe.date, head->poe.month, head->poe.year)){
    temp->next = head;
    head->prev = temp;
    head = temp;
  }else if(countUmur(date, month, year) < countUmur(tail->poe.date, tail->poe.month, tail->poe.year)){
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
  }else{
    Node *curr = head;

    while(curr && curr->next->poe.year < year){
      curr = curr->next;
    }
    
    curr->next->prev =temp;
    temp->next = curr->next;
    curr->next = temp;
    temp->prev = curr;
  }
}

void removepq(){
  if(head && head == tail){
    head = tail = NULL;
    free(head);
  }else{
    Node *newTail = tail->prev;
    tail->prev = newTail->next = NULL;
    free(tail);
    tail = newTail;
  }
}

void removeAll(){
  Node *curr = head;
  while(head){
    removepq();
  }
}

void printAll(){
  Node *curr = tail;
  while(curr){
    printf("%d %s %d - %s\n", curr->peo.days, curr->peo.months, curr->peo.years, curr->peo.name);
    curr = curr->prev;
  }
}
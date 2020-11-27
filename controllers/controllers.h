#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../models/models.h"


Node *createNode(char *name, int date, char *month, int year){
  Node *temp = (Node *)malloc(sizeof(Node));
  strcpy(temp->peo.name, name);
  temp->peo.days = date;
  strcpy(temp->peo.month, month);
  temp->peo.year = year;
  temp->next = temp->prev = NULL;
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
  return 0;
}

long long int countUmur(int date, char *month, int year){
  long long int days = 0;
  days += days;
  days += convertMonth(month) * 30;
  days += year*365;
  return days;
}


void pushPQ(char *name, int date, char *month, int year){
  Node *temp = createNode(name, date, month, year);

  if(!head){
    head = tail = temp;
  }else if(countUmur(date, month, year) > countUmur(head->peo.days, head->peo.month, head->peo.year)){
    temp->next = head;
    head->prev = temp;
    head = temp;
  }else if(countUmur(date, month, year) < countUmur(tail->peo.days, tail->peo.month, tail->peo.year)){
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
  }else{
    Node *curr = head;
    while(curr && (countUmur(date, month, year) < countUmur(curr->next->peo.days, curr->next->peo.month, curr->next->peo.year))){
      curr = curr->next;
    }
    
    curr->next->prev =temp;
    temp->next = curr->next;
    curr->next = temp;
    temp->prev = curr;
  }
}

void removePQ(){
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
    removePQ();
  }
}

void printAll(){
  Node *curr = tail;
  while(curr){
    printf("%d %s %d - %s\n", curr->peo.days, curr->peo.month, curr->peo.year, curr->peo.name);
    curr = curr->prev;
  }
}
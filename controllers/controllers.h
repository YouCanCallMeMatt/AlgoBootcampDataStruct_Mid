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

void pushpq(char *name, int date, char *month, int year){
  Node *temp = (Node *)malloc(sizeof(Node));

  if(!head){
    head = tail = temp;
  }else if()
}
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Patient{
  char name[255];
  int days;
  char month[255];
  int year;
};

struct Node {
  Patient peo;
  Node *next, *prev;
} *head, *tail;

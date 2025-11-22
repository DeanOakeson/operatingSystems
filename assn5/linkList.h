#ifndef LINKLIST_H
#define LINKLIST_H

#include "process.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct LinkList {
  struct Node *root;
  int count;
};

struct Node {
  struct Node *next;
  struct Node *last;
  process *process;
};

bool isEmpty(struct LinkList *linkList);

void initLinkList(struct LinkList *linkList);

struct Node *initNode(process *value);

process *popShortest(struct LinkList *linkList);

int peekShortest(struct LinkList *linkList);

void insert(struct LinkList *linkList, process *value);

void insertHelper(struct Node *node, struct Node *curr);

#endif

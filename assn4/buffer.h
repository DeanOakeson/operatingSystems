////////////////////
/// Dean Oakeson ///
////////////////////

//////////////
/// BUFFER ///
//////////////

#ifndef BUFFER_H
#define BUFFER_H

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 50

typedef struct {

  int arr[MAX_SIZE];
  int count;
  int write;
  int read;

} Buffer;

void initialize(Buffer *buffer);

bool isEmpty(Buffer *buffer);

bool isFull(Buffer *buffer);

int read(Buffer *buffer);

void write(Buffer *buffer, int value);

int peek(Buffer *buffer);

#endif

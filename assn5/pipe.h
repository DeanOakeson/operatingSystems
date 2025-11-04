#ifndef PIPE_H
#define PIPE_H

#include "cpuScheduling.h"
#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 50

typedef struct {

  process arr[MAX_SIZE];
  int front;
  int back;

} Pipe;

void initialize(Pipe *pipe);

bool isEmpty(Pipe *pipe);

bool isFull(Pipe *pipe);

process pop(Pipe *pipe);

void push(Pipe *pipe, process value);

process peek(Pipe *pipe);

#endif

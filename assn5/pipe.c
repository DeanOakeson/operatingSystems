#include "pipe.h"
#include "cpuScheduling.h"

#define MAX_SIZE 50 // make a constant header

void initialize(Pipe *pipe) {
  pipe->back = -1;
  pipe->front = 0;
}

bool isEmpty(Pipe *pipe) {

  if (pipe->back <= pipe->front) {
    return true;
  }
  return false;
}

bool isFull(Pipe *pipe) {

  if (pipe->back == (MAX_SIZE - 1)) {
    return true;
  }
  return false;
}

process pop(Pipe *pipe) {

  if (isEmpty(pipe)) {
    printf("YOU NEED TO ADD AN ERROR FUNCTION YOU IDIOT!\n");
  }

  process popped = pipe->arr[pipe->front];
  pipe->front++;

  return popped;
}

void push(Pipe *pipe, process value) {

  if (isFull(pipe)) {
    return;
  }

  pipe->arr[++pipe->back] = value;
  return;
}

process peek(Pipe *pipe) { return pipe->arr[pipe->back]; }

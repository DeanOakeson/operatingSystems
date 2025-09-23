////////////////////
/// Dean Oakeson ///
////////////////////

////////////
/// PIPE ///
////////////

#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 50

typedef struct {

  int arr[MAX_SIZE];
  int front;
  int back;

} Pipe;

void initialize(Pipe *pipe) {
  pipe->back = -1;
  pipe->front = 0;
}

bool isEmpty(Pipe *pipe) {

  if (pipe->back <= pipe->front) {
    printf("\n\nEMPTY_PIPE\n\n");
    return true;
  }
  return false;
}

bool isFull(Pipe *pipe) {

  if (pipe->back == (MAX_SIZE - 1)) {
    printf("\n\nFULL_PIPE\n\n");
    return true;
  }
  return false;
}

int pop(Pipe *pipe) {

  if (isEmpty(pipe)) {
    return -1;
  }

  int popped = pipe->arr[pipe->front];
  pipe->front++;
  printf("Popped %d from pipe\n", popped);

  return popped;
}

void push(Pipe *pipe, int value) {

  if (isFull(pipe)) {
    return;
  }

  pipe->arr[++pipe->back] = value;
  printf("Pushed %d into pipe\n", value);
  return;
}

int peek(Pipe *pipe) { return pipe->back; }

int main() {

  Pipe pipe;

  initialize(&pipe);

  for (int i = 0; i < (60); i++) {

    push(&pipe, i);
  }

  pop(&pipe);
  pop(&pipe);
  pop(&pipe);
  pop(&pipe);
  pop(&pipe);
  pop(&pipe);
  pop(&pipe);
  pop(&pipe);
  pop(&pipe);
  pop(&pipe);
  pop(&pipe);
  pop(&pipe);
}

#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 50

typedef struct {

  int arr[MAX_SIZE];
  int top;

} Stack;

void initialize(Stack *stack) { stack->top = -1; }

bool isEmpty(Stack *stack) { return stack->top == -1; }

bool isFull(Stack *stack) { return stack->top == (MAX_SIZE - 1); }

void push(Stack *stack, int value) {

  if (isFull(stack)) {
    printf("\n\n STACK_OVERFLOW\n\n");
    return;
  }

  // increment top and add the value to the top of the stack.
  stack->arr[++stack->top] = value;
  printf("\nPushed %d onto the stack\n", value);
}

int pop(Stack *stack) {

  if (isEmpty(stack)) {
    printf("\n\nSTACK_UNDERFLOW\n\n");
    return -1;
  }

  int popped = stack->arr[stack->top];
  --stack->top;
  printf("\nPopped %d off the stack\n", popped);
  return popped;
}

int peek(Stack *stack) {

  if (isEmpty(stack)) {
    printf("\n\nEMPTY_STACK\n\n");
    return -1;
  }

  int peeked = stack->arr[stack->top];
  return peeked;
}

int main() {
  Stack stack;

  initialize(&stack);

  for (int i = 0; i < MAX_SIZE + 1; i++) {
    push(&stack, i);
  }

  return 0;
}

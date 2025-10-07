// Dean Oakeson
// CS3060-001 Fall 2025
// Assn #3

/* Promise of Originality
 I promise that this source code file has, in it's entirety, been
 written by myself and by no other person or persons. If at any time an
 exact copy of this source code is found to be used by another person in
 this term, I understand that both myself and the student that submitted
 the copy will receive a zero on this assignment.
 */

#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//////////////
/// BUFFER ///
//////////////

#define MAX_SIZE 10

typedef struct {

  int arr[MAX_SIZE];
  int write;
  int read;

} Buffer;

void initialize(Buffer *buffer) {
  buffer->read = 0;
  buffer->write = 0;
}

bool isEmpty(Buffer *buffer) {

  if (buffer->read % MAX_SIZE == buffer->write % MAX_SIZE) {
    printf("\n\nEMPTY_BUFFER\n\n");
    return true;
  }
  return false;
}

bool isFull(Buffer *buffer) {

  if ((buffer->write + 1) % MAX_SIZE == buffer->read % MAX_SIZE) {
    printf("\n\nFULL_BUFFER\n\n");
    return true;
  }
  return false;
}

int read(Buffer *buffer) {

  if (isEmpty(buffer)) {
    return -1;
  }

  int read = buffer->arr[buffer->read];
  buffer->read = (buffer->read + 1) % MAX_SIZE;
  printf("read %d from buffer\n", read);

  return read;
}

int write(Buffer *buffer, int value) {

  if (isFull(buffer)) {
    printf("FULL BUFFER");
    return 1;
  }

  buffer->arr[buffer->write] = value;
  buffer->write = (buffer->write + 1) % MAX_SIZE;
  printf("wrote %d\n", value);
  return 0;
}

int peek(Buffer *buffer) { return buffer->read % MAX_SIZE; }

////////////////////
/// MAIN PROGRAM ///
////////////////////

void *runner(void *param);

int main(int argc, char *argv[]) {

  int *arr[10];

  pthread_t tid[argc];
  pthread_attr_t attr;

  if (atoi(argv[1]) < 0) {
    fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
    return -1;
  }

  ///////////////
  // THREADING //
  ///////////////

  pthread_attr_init(&attr);

  for (int i = 1; i <= (argc - 1); i++) {
    tid[i] = i;
    pthread_create(&tid[i], &attr, runner, argv[i]);
  }

  for (int i = 1; i <= (argc - 1); i++) {
    pthread_join(tid[i], (void **)&arr);

    int *myarray = *arr;

    printf("%d: ", atoi(argv[i]));

    for (int i = 0; 9 >= i; i++) {
      if (myarray[i] != 0) {
        printf("%d ", myarray[i]);
      }
    }
    printf("\n");
  }

  free(*arr);
}

//////////////////////
// THREADED PROCESS //
//////////////////////

void *runner(void *param) {

  int factored = atoi(param);
  int *arr = (int *)malloc(10 * sizeof(int)); // RETURN ARRAY //
  int arrIndex = 0;

  ///////////////////
  // PRIME FACTORS //
  //////////////////

  // DIVISIBLE BY 2 //

  if (factored % 2 == 0) {
    while (factored % 2 == 0) {
      arr[arrIndex] = 2;
      arrIndex += 1;
      factored = factored / 2;
    }
  }

  // DIVISIBLE BY ODD //

  for (int i = 3; i <= sqrt(factored); i += 2) {
    while (factored % i == 0) {
      arr[arrIndex] = i;
      arrIndex += 1;
      factored = factored / i;
    }
  }

  // IF REMAINING IS PRIME //

  if (factored > 2) {
    arr[arrIndex] = factored;
    arrIndex += 1;
  }

  return arr;
}

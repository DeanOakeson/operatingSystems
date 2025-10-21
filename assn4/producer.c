
#include "producer.h"

void primeFactor(Buffer *buffer, int number) {

  int *arr = (int *)malloc(10 * sizeof(int)); // RETURN ARRAY//
  int arrIndex = 0;

  if (number % 2 == 0) {
    while (number % 2 == 0) {
      arr[arrIndex] = 2;
      arrIndex += 1;
      number = number / 2;
    }
  }
  // DIVISIBLE BY ODD //
  for (int i = 3; i <= sqrt(number); i += 2) {
    while (number % i == 0) {
      arr[arrIndex] = i;
      arrIndex += 1;
      number = number / i;
    }
  }
  // IF REMAINING IS PRIME //
  if (number > 2) {
    arr[arrIndex] = number;
    arrIndex += 1;
  }

  printf("%d\n", *arr);
  write(buffer, *arr);
}

void *producer(void *data) {

  printf("PRODUCING\n");

  struct thread_data *passedData = (struct thread_data *)data;
  Buffer *bufferOne = passedData->bufferOne;
  // Buffer *bufferTwo = passedData->bufferTwo;
  int argc = passedData->argc;

  printf("ARGC_TEST: %d\n", argc);

  for (int i = 0; i < argc - 1; i++) {
    int n = read(bufferOne);
    printf("%d\n", n);
  }

  pthread_exit(NULL);
}

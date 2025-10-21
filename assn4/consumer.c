
#include "consumer.h"

void *consumer(void *data) {

  printf("CONSUMING\n");

  struct thread_data *passedData = (struct thread_data *)data;
  Buffer *bufferTwo = passedData->bufferTwo;
  int argc = passedData->argc;

  for (int i = 0; i >= argc - 1; i++) {
    int *arr = (int *)malloc(10 * sizeof(int)); // RETURN ARRAY//
    *arr = read(bufferTwo);
    for (int i = 0; MAX_SIZE - 1 >= i; i++) {
      if (arr[i] != 0) {
        printf("%d", arr[i]);
      }
    }
  }
  return 0;
}

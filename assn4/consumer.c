
#include "consumer.h"

void *consumer(void *data) {

  Buffer *bufferTwo = (Buffer *)data;
  printf("CONSUMING\n");

  while (peek(bufferTwo) != -111) {
    printf("%d: ", read(bufferTwo));

    while (peek(bufferTwo) != -11) {
      printf("%d ", read(bufferTwo));
    }

    read(bufferTwo); // CLEAR SENTINAL -11
    printf("\n");
  }
  // read(bufferTwo);
  pthread_exit(NULL);
}

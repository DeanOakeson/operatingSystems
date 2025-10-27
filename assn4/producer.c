#include "producer.h"

void primeFactor(Buffer *buffer, int number) {

  write(buffer, number);

  if (number % 2 == 0) {
    while (number % 2 == 0) {
      write(buffer, 2);
      number = number / 2;
    }
  }
  // DIVISIBLE BY ODD //
  for (int i = 3; i <= sqrt(number); i += 2) {
    while (number % i == 0) {
      write(buffer, i);
      number = number / i;
    }
  }
  // IF REMAINING IS PRIME //
  if (number > 2) {
    write(buffer, number);
  }

  write(buffer, -11); // SENTINAL VALUE
}

void *producer(void *data) {

  Buffer *bufferOne = (Buffer *)data;

  Buffer bufferTwo;
  initialize(&bufferTwo);

  pthread_t tidTwo;
  pthread_create(&tidTwo, NULL, consumer, &bufferTwo);

  int i = read(bufferOne);

  while (i != -1) {
    primeFactor(&bufferTwo, i);
    i = read(bufferOne);
  }

  write(&bufferTwo, -111); // SENTINAL VALUE

  if (pthread_join(tidTwo, NULL) != 0) {
    printf("CONSUMER THREAD FAILED\n");
  } else {
    printf("CONSUMER THREAD FINISHED\n");
  }

  pthread_exit(NULL);
}

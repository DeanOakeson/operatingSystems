// Dean Oakeson
// CS3060-001 Fall 2025
// Assn #4

/* Promise of Originality
 I promise that this source code file has, in it's entirety, been
 written by myself and by no other person or persons. If at any time an
 exact copy of this source code is found to be used by another person in
 this term, I understand that both myself and the student that submitted
 the copy will receive a zero on this assignment.
 */

#include "buffer.h"
#include "consumer.h"
#include "datastruct.h"
#include "producer.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

////////////////////
/// MAIN PROGRAM ///
////////////////////

int main(int argc, char *argv[]) {

  printf("ENTERING MAIN\n");

  //  if (atoi(argv[1]) < 0) {
  //  printf(stderr, "%d must be >= 0\n", atoi(argv[1]));
  // return -1;
  //}

  printf("INITIALIZING BUFFERS\n");

  Buffer bufferOne;
  Buffer bufferTwo;

  initialize(&bufferOne);
  initialize(&bufferTwo);

  struct thread_data *thread_data = malloc(sizeof(struct thread_data));
  ;

  thread_data->argc = argc;
  thread_data->sum = 10;
  thread_data->bufferOne = &bufferOne;
  thread_data->bufferTwo = &bufferTwo;

  pthread_t tid[0];
  pthread_attr_t attr;

  pthread_attr_init(&attr);

  printf("ARGC TEST: %d\n", thread_data->argc);

  pthread_create(&tid[0], NULL, producer, thread_data);

  for (int i = 1; i < argc; i++) {
    write(&bufferOne, atoi(argv[i]));
  }

  pthread_join(tid[0], NULL);

  return 0;
}

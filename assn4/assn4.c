// Dean Oakeson CS3060-001 Fall 2025
// Assn #4

/* Promise of Originality
 I promise that this source code file has, in it's entirety, been
 written by myself and by no other person or persons. If at any time an
 exact copy of this source code is found to be used by another person in
 this term, I understand that both myself and the student that submitted
 the copy will receive a zero on this assignment.
 */

#include "buffer.h"
#include "c-stacktrace.h"
#include "producer.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

////////////////////
/// MAIN PROGRAM ///
////////////////////

int main(int argc, char *argv[]) {

  // TIMER ENTER
  clock_t start, end;
  double elapsed;
  start = clock();

  printf("ENTERING MAIN\n");
  init_exceptions(argv[0]);

  if (argc < 2) {
    printf("%d must be >= 0\n", atoi(argv[1]));
    return -1;
  }

  printf("INITIALIZING BUFFER\n");

  Buffer bufferOne;

  initialize(&bufferOne);

  pthread_t tid;
  pthread_attr_t attr;

  pthread_attr_init(&attr);

  pthread_create(&tid, &attr, producer, &bufferOne);

  for (int i = 1; i < argc; i++) {
    write(&bufferOne, atoi(argv[i]));
  }

  write(&bufferOne, -1);

  if (pthread_join(tid, NULL) != 0) {
    printf("PRODUCER THREAD FAILED\n");
  } else {
    printf("PRODUCER THREAD FINISHED\n");
  }

  // TIMER EXIT
  end = clock();
  elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("ELAPSED TIME: %f sec\n", elapsed);

  return 0;
}

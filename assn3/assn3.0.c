#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *runner(void *param); // THREADS CALL THIS FUNCTION

int main(int argc, char *argv[]) {
  int *sum;
  pthread_t tid;
  pthread_attr_t attr;

  if (argc != 2) {
    fprintf(stderr, "usage: a.out <integer value>\n");
    return -1;
  }

  if (atoi(argv[1]) < 0) {
    fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
    return -1;
  }

  pthread_attr_init(&attr);
  pthread_create(&tid, &attr, runner, argv[1]);
  pthread_join(tid, (void **)&sum);

  printf("sum = %d\n", *sum);
}

void *runner(void *param) {
  int upper = atoi(param);
  int *sum = malloc(sizeof(int));

  for (int i = 1; i <= upper; i++)
    *sum += i;

  return (void *)sum;
}

#include "cpuScheduling.h"
#include "linkList.h"
#include <stdio.h>
#include <stdlib.h>

int **readFile(FILE *file) {

  int count = 0;
  int strt, dur;

  int **retArr;
  retArr = malloc(sizeof(int *) * 2);

  for (int i = 0; i < 2; i++) {
    retArr[i] = malloc(sizeof(int *) * MAX_PROCESS);
  }

  printf("READING....\n");
  while (fscanf(file,
                "%d"
                "%d",
                &strt, &dur) == 2) {
    retArr[0][count] = strt;
    retArr[1][count] = dur;
    count++;
  }

  printf("....DONE READING\n");
  return retArr;
}

int main() {

  int **data = readFile(stdin);

  printf("First Come, First Serve\n");
  printStats(FCFS(data));

  printf("Shortest Job First\n");
  printStats(SJF(data));

  printf("Shortest Remaining Job First\n");
  printStats(SRTF(data));

  printf("Round Robin");
  printStats(RR(data, 100));

  free(data[0]);
  free(data[1]);
  free(data);
}

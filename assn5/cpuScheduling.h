
#ifndef CPUSCHEDULING_H
#define CPUSCHEDULING_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 20

typedef struct {
  int start;
  int duration;
  int waitTime;
  int responseTime;
  int turnAround;

} process;

void init(process *process, int start, int duration);

void printStats(double *stats);

double *FCFS(int **data);

int *SJF(int *start, int *duration);

int *SRTF(int *start, int *duration);

int *RR(int *start, int *duration, int quant);

#endif

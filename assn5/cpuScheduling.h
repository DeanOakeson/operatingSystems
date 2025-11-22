
#ifndef CPUSCHEDULING_H
#define CPUSCHEDULING_H

#include "linkList.h"
#include "process.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void printStats(double *stats);

double *FCFS(int **data);

double *SJF(int **data);

double *SRTF(int **data);

double *RR(int **data, int quant);

#endif

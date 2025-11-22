#include "cpuScheduling.h"

void printStats(double *stats) {
  printf("AVG.RESP.: %f, ", stats[0]);
  printf("AVG.T.A.: %f, ", stats[1]);
  printf("AVG.WAIT: %f, \n", stats[2]);
};

double *FCFS(int **data) {

  int clock = 0;
  double responseTime, turnAround, waitTime = 0.00;

  double *stats = (double *)malloc(sizeof(double) * 3);
  process *pList = (process *)malloc(sizeof(process) * MAX_PROCESS);

  for (int i = 0; i < MAX_PROCESS; i++) {
    initPrc(&pList[i], data[0][i], data[1][i]);
  }

  // ALGORITHM //
  for (int j = 0; j < MAX_PROCESS; j++) {
    if (pList[j].start > clock) {
      clock = pList[j].start;
    }
    pList[j].waitTime = clock - pList[j].start;
    pList[j].responseTime = pList[j].waitTime;
    clock += pList[j].duration;
    pList[j].turnAround = pList[j].waitTime + pList[j].duration;
  }

  // EXIT //
  for (int k = 0; k < MAX_PROCESS; k++) {

    responseTime += pList[k].responseTime;
    turnAround += pList[k].turnAround;
    waitTime += pList[k].waitTime;
  }
  stats[0] = responseTime / MAX_PROCESS;
  stats[1] = turnAround / MAX_PROCESS;
  stats[2] = waitTime / MAX_PROCESS;

  return stats;
}

double *SJF(int **data) {

  double responseTime, turnAround, waitTime = 0.00;
  struct LinkList ready;

  initLinkList(&ready);

  double *stats = (double *)malloc(sizeof(double) * 3);
  process *pList = (process *)malloc(sizeof(process) * MAX_PROCESS);

  for (int i = 0; i < MAX_PROCESS; i++) {
    initPrc(&pList[i], data[0][i], data[1][i]);
  }

  // ALGORITHM //
  int clock = 0;
  int completed = 0;
  int j = 0;
  while (completed < MAX_PROCESS) {

    while (j < MAX_PROCESS && clock >= pList[j].start) {
      insert(&ready, &pList[j]);
      j++;
    }

    if (isEmpty(&ready)) {
      clock = pList[j].start;
      continue;
    }

    process *shortestJob = popShortest(&ready);
    shortestJob->waitTime = clock - shortestJob->start;
    shortestJob->responseTime = shortestJob->waitTime;
    shortestJob->turnAround = shortestJob->waitTime + shortestJob->duration;

    completed++;
    clock += shortestJob->duration;
    // EXIT //
  }
  for (int k = 0; k < MAX_PROCESS; k++) {

    responseTime += pList[k].responseTime;
    turnAround += pList[k].turnAround;
    waitTime += pList[k].waitTime;
  }
  stats[0] = responseTime / MAX_PROCESS;
  stats[1] = turnAround / MAX_PROCESS;
  stats[2] = waitTime / MAX_PROCESS;

  return stats;
}

double *SRTF(int **data) {
  double responseTime, turnAround, waitTime = 0.00;
  struct LinkList ready;

  initLinkList(&ready);

  double *stats = (double *)malloc(sizeof(double) * 3);
  process *pList = (process *)malloc(sizeof(process) * MAX_PROCESS);

  for (int i = 0; i < MAX_PROCESS; i++) {
    initPrc(&pList[i], data[0][i], data[1][i]);
  }

  // ALGORITHM //
  int clock = 0;
  int completed = 0;
  int j = 0;
  while (completed < MAX_PROCESS) {
    while (j < MAX_PROCESS && clock >= pList[j].start) {
      insert(&ready, &pList[j]);
      j++;
    }

    if (isEmpty(&ready)) {
      clock++;
      continue;
    }

    process *shortestRemaining = popShortest(&ready);

    if (shortestRemaining->duration == shortestRemaining->remaining) {
      shortestRemaining->responseTime = clock - shortestRemaining->start;
    }

    shortestRemaining->duration--;

    if (shortestRemaining->duration == 0) {
      clock++;
      shortestRemaining->turnAround = clock - shortestRemaining->start;
      shortestRemaining->waitTime =
          shortestRemaining->turnAround - shortestRemaining->remaining;
      completed++;
      continue;
    }

    insert(&ready, shortestRemaining);
    clock++;
    // EXIT //
  }
  for (int k = 0; k < MAX_PROCESS; k++) {
    responseTime += pList[k].responseTime;
    turnAround += pList[k].turnAround;
    waitTime += pList[k].waitTime;
  }
  stats[0] = responseTime / MAX_PROCESS;
  stats[1] = turnAround / MAX_PROCESS;
  stats[2] = waitTime / MAX_PROCESS;

  return stats;
}

double *RR(int **data, int quant) {
  double responseTime, turnAround, waitTime = 0.00;
  struct LinkList ready;

  initLinkList(&ready);

  double *stats = (double *)malloc(sizeof(double) * 3);
  process *pList = (process *)malloc(sizeof(process) * MAX_PROCESS);

  for (int i = 0; i < MAX_PROCESS; i++) {
    initPrc(&pList[i], data[0][i], data[1][i]);
  }

  // ALGORITHM //
  int clock = 0;
  int completed = 0;
  int j = 0;
  while (completed < MAX_PROCESS) {
    while (j < MAX_PROCESS && clock >= pList[j].start) {
      insert(&ready, &pList[j]);
      j++;
    }

    if (isEmpty(&ready)) {
      clock++;
      continue;
    }

    process *shortestRemaining = popShortest(&ready);

    if (shortestRemaining->duration == shortestRemaining->remaining) {
      shortestRemaining->responseTime = clock - shortestRemaining->start;
    }

    shortestRemaining->duration--;

    if (shortestRemaining->duration == 0) {
      clock++;
      shortestRemaining->turnAround = clock - shortestRemaining->start;
      shortestRemaining->waitTime =
          shortestRemaining->turnAround - shortestRemaining->remaining;
      completed++;
      continue;
    }

    insert(&ready, shortestRemaining);
    clock++;
    // EXIT //
  }
  for (int k = 0; k < MAX_PROCESS; k++) {
    responseTime += pList[k].responseTime;
    turnAround += pList[k].turnAround;
    waitTime += pList[k].waitTime;
  }
  stats[0] = responseTime / MAX_PROCESS;
  stats[1] = turnAround / MAX_PROCESS;
  stats[2] = waitTime / MAX_PROCESS;

  printf("W/ Quant = %d\n", quant);
  return stats;
}

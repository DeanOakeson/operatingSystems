#include "cpuScheduling.h"

void init(process *process, int start, int duration) {
  process->waitTime = 0;
  process->responseTime = 0;
  process->turnAround = 0;
  process->start = start;
  process->duration = duration;
};

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
    init(&pList[i], data[0][i], data[1][i]);
  }

  for (int j = 0; j < MAX_PROCESS; j++) {
    if (pList[j].start > clock) {
      clock = pList[j].start;
    }
    pList[j].waitTime = clock - pList[j].start;
    printf("clock = %d ", clock);
    printf("WaitTime = %d \n", pList[j].waitTime);
    pList[j].responseTime = pList[j].waitTime;
    clock += pList[j].duration;
    pList[j].turnAround = pList[j].waitTime + pList[j].duration;
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

int *SJF(int *start, int *duration);
// while (!isEmpty(&waiting) && !isEmpty(&upcoming)) {
//
//   // UPCOMING ARRIVES BEFORE RUNNING FINISHES//
//   // SENDS UPCOMING TO WAIT //
//   // CLOCK IS SET TO UPCOMING START TIME //
//   if (peek(&upcoming).start <= clock + peek(&running).duration) {
//
//     clock = peek(&upcoming).start;
//     push(&waiting, pop(&upcoming));
//   }
//
//   // RUNNING FINISHES BEFORE UPCOMING ARRIVES//
//   // MOVES RUNNING TO FINISHED //
//   // CLOCK IS SET TO THE RESPONSE TIME + DURATION //
//   if ((peek(&running).responseTime + peek(&running).duration) <
//       peek(&upcoming).start) {
//     clock = peek(&running).responseTime + peek(&running).duration;
//     pop(&running);
//     push(&running, pop(&upcoming));
//   }
// }

int *SRTF(int *start, int *duration);

int *RR(int *start, int *duration, int quant);

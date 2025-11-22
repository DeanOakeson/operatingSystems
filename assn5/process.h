#ifndef PROCESS_H
#define PROCESS_H

#define MAX_PROCESS 20

typedef struct {

  int waitTime;
  int responseTime;
  int turnAround;
  int start;
  int duration;
  int remaining;

} process;

void initPrc(process *process, int start, int duration);

#endif

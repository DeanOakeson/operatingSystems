#include "process.h"

void initPrc(process *process, int start, int duration) {
  process->waitTime = 0;
  process->responseTime = 0;
  process->turnAround = 0;
  process->start = start;
  process->duration = duration;
  process->remaining = duration;
};

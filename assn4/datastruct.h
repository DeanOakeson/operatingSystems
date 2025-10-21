#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#include "buffer.h"

struct thread_data {
  int argc;
  int sum;
  Buffer *bufferOne;
  Buffer *bufferTwo;
};

#endif

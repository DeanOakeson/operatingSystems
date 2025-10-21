#ifndef PRODUCER_H
#define PRODUCER_H

#include "buffer.h"
#include "datastruct.h"
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void primeFactor(Buffer *buffer, int number);

void *producer(void *data);

#endif

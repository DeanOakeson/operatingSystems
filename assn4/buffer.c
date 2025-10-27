////////////////////
/// Dean Oakeson ///
////////////////////

//////////////
/// BUFFER ///
//////////////

#include "buffer.h"

pthread_mutex_t lock;
pthread_cond_t condNotEmpt;
pthread_cond_t condNotFull;

void initialize(Buffer *buffer) {
  buffer->read = 0;
  buffer->write = 0;
  buffer->count = 0;
}

bool isEmpty(Buffer *buffer) {

  if (buffer->count == 0) {
    return true;
  }
  return false;
}

bool isFull(Buffer *buffer) {

  if (buffer->count == MAX_SIZE) {
    return true;
  }
  return false;
}

int read(Buffer *buffer) {

  pthread_mutex_lock(&lock);
  while (isEmpty(buffer)) {
    pthread_cond_wait(&condNotEmpt, &lock);
  }

  buffer->count--;
  int read = buffer->arr[buffer->read];

  pthread_cond_signal(&condNotFull);
  pthread_mutex_unlock(&lock);

  buffer->read = (buffer->read + 1) % MAX_SIZE;
  return read;
}

void write(Buffer *buffer, int value) {

  pthread_mutex_lock(&lock);
  while (isFull(buffer)) {
    pthread_cond_wait(&condNotFull, &lock);
  }

  buffer->count++;
  buffer->arr[buffer->write] = value;

  pthread_cond_signal(&condNotEmpt);
  pthread_mutex_unlock(&lock);

  buffer->write = (buffer->write + 1) % MAX_SIZE;
  return;
}

int peek(Buffer *buffer) {

  pthread_mutex_lock(&lock);
  while (isEmpty(buffer)) {
    // printf("Ep ");
    pthread_cond_wait(&condNotEmpt, &lock);
  }
  pthread_mutex_unlock(&lock);

  return buffer->arr[buffer->read];
}

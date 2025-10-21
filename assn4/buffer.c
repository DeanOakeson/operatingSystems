////////////////////
/// Dean Oakeson ///
////////////////////

//////////////
/// BUFFER ///
//////////////

#include "buffer.h"

pthread_mutex_t lock;
pthread_cond_t cond;

void initialize(Buffer *buffer) {
  buffer->read = 0;
  buffer->write = 0;

  pthread_mutex_init(&lock, NULL);
  pthread_cond_init(&cond, NULL);
}

bool isEmpty(Buffer *buffer) {

  if (buffer->read % MAX_SIZE == buffer->write % MAX_SIZE) {
    printf("EMPTY_BUFFER\n");
    return true;
  }
  return false;
}

bool isFull(Buffer *buffer) {

  if ((buffer->write + 1) % MAX_SIZE == buffer->read % MAX_SIZE) {
    printf("FULL_BUFFER\n");
    return true;
  }
  return false;
}

int read(Buffer *buffer) {
  pthread_mutex_lock(&lock);

  while (isEmpty(buffer)) {
    pthread_cond_wait(&cond, &lock);
  }

  int read = buffer->arr[buffer->read];
  buffer->read = (buffer->read + 1) % MAX_SIZE;
  printf("read %d\n", read);

  pthread_cond_signal(&cond);
  pthread_mutex_unlock(&lock);
  return read;
}

int write(Buffer *buffer, int value) {
  pthread_mutex_lock(&lock);

  if (isFull(buffer)) {
    pthread_cond_wait(&cond, &lock);
  }

  buffer->arr[buffer->write] = value;
  buffer->write = (buffer->write + 1) % MAX_SIZE;
  printf("wrote %d\n", value);

  pthread_cond_signal(&cond);
  pthread_mutex_unlock(&lock);
  return 0;
}

int peek(Buffer *buffer) { return buffer->read % MAX_SIZE; }

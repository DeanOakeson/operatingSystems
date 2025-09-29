////////////////////
/// Dean Oakeson ///
////////////////////

//////////////
/// BUFFER ///
//////////////

#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 10

typedef struct {

  int arr[MAX_SIZE];
  int write;
  int read;

} Buffer;

void initialize(Buffer *buffer) {
  buffer->read = 0;
  buffer->write = 0;
}

bool isEmpty(Buffer *buffer) {

  if (buffer->read % MAX_SIZE == buffer->write % MAX_SIZE) {
    printf("\n\nEMPTY_BUFFER\n\n");
    return true;
  }
  return false;
}

bool isFull(Buffer *buffer) {

  if ((buffer->write + 1) % MAX_SIZE == buffer->read % MAX_SIZE) {
    printf("\n\nFULL_BUFFER\n\n");
    return true;
  }
  return false;
}

int read(Buffer *buffer) {

  if (isEmpty(buffer)) {
    return -1;
  }

  int read = buffer->arr[buffer->read];
  buffer->read = (buffer->read + 1) % MAX_SIZE;
  printf("read %d from buffer\n", read);

  return read;
}

int write(Buffer *buffer, int value) {

  if (isFull(buffer)) {
    printf("FULL BUFFER");
    return 1;
  }

  buffer->arr[buffer->write] = value;
  buffer->write = (buffer->write + 1) % MAX_SIZE;
  printf("wrote %d\n", value);
  return 0;
}

int peek(Buffer *buffer) { return buffer->read % MAX_SIZE; }

int main() {

  Buffer buffer;

  initialize(&buffer);

  // PRODUCER//

  int value = 0;

  while (true) {
    while (!isFull(&buffer)) {
      write(&buffer, value++);
    }

    // CONSUMER//
    while (!isEmpty(&buffer)) {
      read(&buffer);
    }
  }
  return 0;
}

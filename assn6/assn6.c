// Dean Oakeson
// CS3060-001 Fall 2025
// Assn #2

/* Promise of Originality
I promise that this source code file has, in it's entirety, been
written by myself and by no other person or persons. If at any time an
exact copy of this source code is found to be used by another person in
this term, I understand that both myself and the student that submitted
the copy will receive a zero on this assignment.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "FILL THIS OUT");
    return -1;
  }

  unsigned long int value = strtoul(argv[1], NULL, 16);

  fprintf(stdout,
          "Logical ADDR:0x%08lx - PAGE INDEX:0x%08lx - Offset:0x%08lx\n", value,
          value >> 12, value);
}

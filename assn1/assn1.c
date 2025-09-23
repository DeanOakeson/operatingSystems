// Dean Oakeson
// CS3060-001 Fall 2025
// Assn #1

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

  printf("\nAssignment 1 by Dean Oakeson\n");

  for (int i = 0; i <= (argc - 1); i++) {
    printf("Argument #%d:%s\n", i, argv[i]);
  }

  printf("Number of arguments printed: %d\n", argc);
}

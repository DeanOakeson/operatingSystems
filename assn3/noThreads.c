// Dean Oakeson
// CS3060-001 Fall 2025
// Assn #3

/* Promise of Originality
 I promise that this source code file has, in it's entirety, been
 written by myself and by no other person or persons. If at any time an
 exact copy of this source code is found to be used by another person in
 this term, I understand that both myself and the student that submitted
 the copy will receive a zero on this assignment.
 */

#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50
////////////////////
/// MAIN PROGRAM ///
////////////////////

void *runner(void *param);

int main(int argc, char *argv[]) {

  time_t start, end;
  double elapsed;
  start = clock();

  int *arr[MAX_SIZE];

  if (atoi(argv[1]) < 0) {
    fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
    return -1;
  }

  ///////////////
  // THREADING //
  ///////////////

  for (int i = 1; i < argc - 1; i++) {

    int *myarray = *arr;

    myarray = runner(argv[i]);

    printf("%d: ", atoi(argv[i]));

    for (int i = 0; MAX_SIZE - 1 >= i; i++) {
      if (myarray[i] != 0) {
        printf("%d ", myarray[i]);
      }
    }
    printf("\n");
    free(myarray);
  }

  end = clock();
  elapsed = ((double)end - start) / CLOCKS_PER_SEC;
  printf("ELAPSED TIME: %.2f sec\n", elapsed);
}

//////////////////////
// FACORING PROCESS //
//////////////////////

void *runner(void *param) {

  int factored = atoi(param);
  int *arr = (int *)malloc(MAX_SIZE * sizeof(int)); // RETURN ARRAY //
  int arrIndex = 0;

  ///////////////////
  // PRIME FACTORS //
  //////////////////

  // DIVISIBLE BY 2 //

  if (factored % 2 == 0) {
    while (factored % 2 == 0) {
      arr[arrIndex] = 2;
      arrIndex += 1;
      factored = factored / 2;
    }
  }

  // DIVISIBLE BY ODD //

  for (int i = 3; i <= sqrt(factored); i += 2) {
    while (factored % i == 0) {
      arr[arrIndex] = i;
      arrIndex += 1;
      factored = factored / i;
    }
  }

  // IF REMAINING IS PRIME //

  if (factored > 2) {
    arr[arrIndex] = factored;
    arrIndex += 1;
  }

  return arr;
}

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {

  int *a;
  int *b;

  int x = 1;
  int y = 2;

  a = &x;
  b = &y;

  printf("a = %d\n", *a);
  printf("b = %d\n", *b);

  printf("now they swap\n");
  swap(a, b);

  printf("a = %d\n", *a);
  printf("b = %d\n", *b);
}

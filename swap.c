#include <stdio.h>

void swap(int *x, int *y);

int main(void) {
  int a = 5;
  int b = 10;

  printf("[before] (a, b) = %d, %d\n", a, b);
  swap(&a, &b);
  printf("[after] (a, b) = %d, %d\n", a, b);
  
  return 0;
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

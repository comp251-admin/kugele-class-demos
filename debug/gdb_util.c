#include "gdb_util.h"

#include <stdio.h>
#include <stdlib.h>

/* function definitions */
void init(int *arr, int size) {
  int i = 0;

  for (i = 0; i < size; i++) {
    arr[i] = i;
  }
}

void display(int *arr, int size) {
  int i = 0;
  char *sep = NULL;

  printf("[");
  for (i = 0; i < size; i++) {
    sep = (i < size - 1) ? "," : "";
    printf("%d%s", arr[i], sep);
  }
  printf("]\n");
}

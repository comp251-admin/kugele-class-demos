#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <n elements>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  int *i_array = malloc(sizeof(int) * n);

  /* initialize array */
  for (int i = 0; i < n; i++) {
    i_array[i] = i;   // same as *(i_array + i) = i
  }

  for (int i = 0; i < n; i++) {
    printf("i_array[%d]: %d\n", i, i_array[i]); // same as *(i_array + i)
  }

  free(i_array);
  i_array = NULL;

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

void read_ints(int *numbers, int n);
void display_ints(int *numbers, int n);

int main(int argc, char **argv) {
  if (argc < 2) {
    return 0;
  }

  int n = atoi(argv[1]);
  if (n < 1) {
    return 1;
  }

  int *numbers = malloc(sizeof(int) * n);

  read_ints(numbers, n);
  display_ints(numbers, n);

  return 0;
}

void read_ints(int *numbers, int n) {
  for (int i = 0; i < n; i++) {
    printf("enter number %d\n", i + 1);
    scanf("%d", &numbers[i]);
  }
}

void display_ints(int *numbers, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\n", numbers[i]);
  }
}

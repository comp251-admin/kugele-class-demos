#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "gdb_util.h"

void run_one_arg(int argc, char **argv);
void run_two_arg(int argc, char **argv);
void run_three_arg(int argc, char **argv);

int main(int argc, char **argv) {
  switch (argc) {
  case 1:
    run_one_arg(argc, argv);
    break;
  case 2:
    run_two_arg(argc, argv);
    break;
  case 3:
    run_three_arg(argc, argv);
    break;
  default:
    /* error - unsupported number of arguments */
    return 1;
    break;
  }

  return 0;
}

void run_one_arg(int argc, char **argv) {
  srand(time(NULL));
  int n = rand() % 100;
  printf("beginning countdown!\n");
  do {
    printf("%d\n", n);
  } while (--n);
  printf("launch!\n");
}

void run_two_arg(int argc, char **argv) {
  int n = atoi(argv[1]);
  int *array = malloc(sizeof(int) * n);

  init(array, n);
  display(array, n);
}

void run_three_arg(int argc, char **argv) {
  int result = op(argv[1], argv[2]);
  printf("op(%s, %s) = %d\n", argv[1], argv[2], result);
}

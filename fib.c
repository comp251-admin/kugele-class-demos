#include <stdio.h>
#include <stdlib.h>

int fib(int n);

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("usage: %s <integer>\n", argv[0]);

    return 1;
  }

  int n = atoi(argv[1]);
  printf("fib(%d) = %d\n", n, fib(n));

  return 0;
}

int fib(int n) {
  if (n <= 2) {
    return 1;
  }

  return fib(n-2) + fib(n-1);
}

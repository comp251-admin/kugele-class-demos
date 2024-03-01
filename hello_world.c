#include <stdio.h>
#include <unistd.h>

int main(void) {
  printf("[%d] hello world!\n", getpid());
  return 0;
}

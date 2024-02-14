#include <stdio.h>
#include <stdlib.h>

void display_bits(unsigned int n);

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <non-negative integer>\n", argv[0]);
    exit(1);
  }

  unsigned int n = atoi(argv[1]);
  printf("n = %u\n", n);

  display_bits(n);

  return 0;
}

void display_bits(unsigned int n) {
  int num_bits = sizeof(int) * 8;

  for (int i = num_bits - 1; i >= 0; i--) {
    int bit_value = (n >> i) & 1;

    // add space every 4 bits
    if ((i + 1) % 4 == 0) {
      printf(" ");
    }
    printf("%d", bit_value);
  }
  printf("\n");
}

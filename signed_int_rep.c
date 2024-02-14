#include <stdio.h>
#include <stdlib.h>

void display_bits(int n);

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <integer>\n", argv[0]);
    exit(1);
  }

  int n = atoi(argv[1]);
  printf("n = %d\n", n);

  display_bits(n);

  return 0;
}

void display_bits(int n) {
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

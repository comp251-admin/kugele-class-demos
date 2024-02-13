#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void display_bits(mode_t mode);

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("usage: %s <filename>\n", argv[0]);
    return 1;
  }

  struct stat stat_result;
  char *filename = argv[1];

  if (stat(argv[1], &stat_result) != 0) {
    perror("stat");
    return 1;
  }

  mode_t mode = stat_result.st_mode;
  mode_t mask = S_IXUSR;

  printf("mode (octal): %o\n", mode);

  printf("mode as bits: \n");
  display_bits(mode);

  printf("mask as bits: \n");
  display_bits(mask);

  /* checking bit */
  printf("S_IXUSR & mode: %d\n", (S_IXUSR & mode) == S_IXUSR);

  return 0;
}

void display_bits(mode_t mode) {
  unsigned int bitpos = sizeof(mode)*8 - 1;
  unsigned int bitmask = 1 << bitpos;

  for(; bitpos > 0; --bitpos) {
    printf("%u ", mode & bitmask ? 1 : 0);
    bitmask /= 2;
  }
  printf("%u\n", mode & bitmask ? 1 : 0);
}

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    return 1;
  }

  char *buffer = NULL;

  char *str1 = argv[1];
  char *str2 = argv[2];

  buffer = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
  if (buffer == NULL) {
    perror("malloc");
    return 1;
  }

  strcpy(buffer, str1);
  strcat(buffer, str2);

  printf("buffer contains: %s\n", buffer);

  free(buffer);
  buffer = NULL;

  return 0;
}

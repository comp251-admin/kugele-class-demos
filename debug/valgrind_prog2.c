#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    return 1;
  }

  int i;

  int n = argc - 1;
  char **carray = malloc(sizeof(char *) * n);

  int len_all = 0;
  for (i = 0; i < n; i++) {
    carray[i] = strdup(argv[i + 1]);
    len_all += strlen(carray[i]);
  }

  char *concat_all = malloc(sizeof(char) * len_all);
  char *concat_target = concat_all;

  for (i = 0; i < n; i++) {
    strcat(concat_target, carray[i]);
    concat_target += strlen(carray[i]);
  }

  printf("%s\n", concat_all);

  free(carray);

  return 0;
}

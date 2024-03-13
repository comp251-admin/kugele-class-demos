#include <stdio.h>

int main(int argc, char **argv) {
  char *h, *t, c, l;

  if (argc < 2)
    return 0;

  for (h = t = argv[1]; *t; t++)
    ;
  l = (t-- - h) / 2;

  while (l--) {
    c = *t;
    *t-- = *h;
    *h++ = c;
  }

  printf("%s\n", argv[1]);
  return 0;
}

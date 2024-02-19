#include <stdio.h>

int main(void) {
  /* both '\0' and NULL have values of zero */
  printf("0 == '\\0': %s\n", 0 == '\0' ? "True" : "False");
  printf("0 == NULL: %s\n", 0 == NULL ? "True" : "False");

  /* does this mean they are identical? */
  // printf("'\\0' == NULL: %s\n", '\0' == NULL ? "True" : "False");

  return 0;
}

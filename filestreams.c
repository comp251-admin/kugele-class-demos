#include <stdio.h>
#include <string.h>

#define MAXLINE 5

/* Function: readline
 * ------------------
 * Displays prompt and then reads a sequence of characters from 
 * standard input into line until a newline ('\n') or EOF. A 
 * maximum of n characters will be read into line, including a 
 * null terminator ('\0').
 *
 * Returns: the number of bytes read
 ****************************************************************/
int readline(char* line, char* prompt, int n);

int main(void){
  char line[MAXLINE];
  int n_read = 0;

  while ((n_read = readline(line, ">>>> ", MAXLINE))) {
    /* display line in stdout file stream */
    printf("read: %s\n", line);

    /* display line in stdout file stream */
    fprintf(stderr, "bytes read: %d\n", n_read);
  }

  return 0;
}

int readline(char* line, char* prompt, int n) {
  /* displays a prompt to stdout file stream */
  fputs(prompt, stdout);

  /* reads a line from stdin */
  line = fgets(line, n, stdin);

  /* returns the number of bytes read */
  return (line != NULL) ? strlen(line) : 0;
}

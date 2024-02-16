/* An example C program with local and global variables */
#include <stdio.h>

/* function prototypes */
int max(int n1, int n2); 

int g_x;  /* global variable - QUESTION: what memory segment?*/

/* QUESTION: what memory segment contains main's program instructions? */
int main(void) {
    int x, result;   /* local variables in main - QUESTION: what memory segment? */

    printf("Enter a value: ");
    scanf("%d", &x);

    g_x = 10; /* global variables can be accessed in any function */

    result = max(g_x, x);

    return 0;
}

/* QUESTION: what memory segment contains max's program instructions? */
int max(int n1, int n2) {
    int val;    /* local variable - QUESTION: what memory segment contains
                 * max's local variables? */

    val = n1;
    if ( n2 > n1 ) {
        val = n2;
    }

    return val;
}

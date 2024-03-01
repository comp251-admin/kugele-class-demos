#include <unistd.h>
#include <stdio.h>
#include <wait.h>

int main(int argc, char **argv) {
	pid_t pid;
	int  ret;
  char *child_args[2];

  if (argc != 2) {
		printf("usage: %s <program path>\n", argv[0]);
    return 1;
	}
  
	child_args[0] = argv[1];  // initialize command line arguments for main
	child_args[1] = NULL;

	pid = fork();
	if (pid == 0) { /* child process */
    printf("[%d] I am the child process\n", getpid());
		ret = execv(argv[1], child_args);
		if (ret < 0) {
			perror("execv");
			return(ret);
		}
	} else {
    /* parent process */
    printf("[%d] I am the parent process!\n", getpid());
    printf("[%d] I am waiting to reap my child!\n", getpid());
    wait(NULL);
    printf("[%d] My child has been reaped!\n", getpid());
  }
}

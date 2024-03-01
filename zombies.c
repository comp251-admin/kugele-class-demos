#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

#define MAX_CHILDREN 10

int main(int argc, char **argv) {
	pid_t pid;
	int ret;
  int status;
  char *child_args[2];

	child_args[0] = argv[1];  // initialize command line arguments for main
	child_args[1] = NULL;

  for (int i = 0; i < MAX_CHILDREN; i++) {
    pid = fork();
    if (pid == -1) {
      perror("fork");
      return 1;
    }

    // child process
    else if (pid == 0) { 
      ret = execv(argv[1], child_args);
      if (ret < 0) {
        perror("execv");
        return(ret);
      }
    }

    // parent process
    else {
      printf("spawned child: %d\n", pid); fflush(stdout);
      sleep(5);
      wait(&status);
    }
  }
}

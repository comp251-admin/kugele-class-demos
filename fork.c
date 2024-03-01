#include <unistd.h>
#include <stdio.h>

int main(void) {
	pid_t child_pid;

  // check if fork failed
  if ((child_pid = fork()) == -1) {
		perror("fork"); // fork sets errno, so use perror!
		return 1;
	}

  // both parent and child execute this code
  pid_t pid = getpid();
  if (child_pid == 0) {
    // only child
		printf("[pid: %d] I'm the child!\n", pid);
  } else {
    // only parent
		printf("[pid: %d] I'm the parent! My baby's pid is %d\n", pid, child_pid);
	}

  /* no guarantees about the execution order of parent and child
   *************************************************************/

  return 0;
}

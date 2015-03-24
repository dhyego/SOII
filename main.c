/* main.c - Example of system.

   Copyright 2015 - Dhyego Palácios Bonifácio <dhyego@usp.br>

*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* On success, execute 'command' as a subprocess and return
   the value returned by 'command'. On error, return -1.
   The caller process is blocked until subprocess termination. */
int mysystem(char *command) {
  int pid, status;
  char *args[2];
  pid = fork();
  if (pid<0) {			/* Error */
    fprintf(stderr, "%s", strerror(errno));
    exit(EXIT_FAILURE);
  }
  if (pid>0) {			/* Parent */
    wait(&status);
    return WEXITSTATUS(status);
  } else {			/* Child */
    args[0] = command;
    args[1] = NULL;
    execvp(args[0], args);
    exit(-2);
  }
}

int main(int argc, char **argv) {
  int rsc;
  printf("Execute a program in a subprocess.\n");
  rsc = mysystem("lss");
  if (rsc < 0) {
    fprintf(stderr, "%s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }
  printf("Process terminated with return status %d\n", rsc);
  return EXIT_SUCCESS;
}

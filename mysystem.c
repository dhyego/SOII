/* mysystem.c - Example of system.

   Copyright 2015 - Dhyego Palácios Bonifácio <dhyego@usp.br>

*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <debug.h>

/* On success, execute 'command' as a subprocess and return
   the value returned by 'command'. On error, return -1.
   The caller process is blocked until subprocess termination. */
int mysystem(char *command) {
  int pid, status, rsc;
  char *args[2];
  pid = fork();
  fail(pid<0, -1);
  if (pid>0) {			/* Parent */
    rsc = wait(&status);
    fail(rsc<0, -1);
    return WEXITSTATUS(status);
  } else {			/* Child */
    args[0] = command;
    args[1] = NULL;
    rsc = execvp(args[0], args);
    fail(rsc<0, -1);
    exit(-1);
  }
}

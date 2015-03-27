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

#include <foo.h>
#include <debug.h>

int main(int argc, char **argv) {
  int rsc;
  printf("Execute a program in a subprocess.\n");
  rsc = mysystem("date");
  fatal(rsc<0);
  printf("Process terminated with return status %d\n", rsc);
  return EXIT_SUCCESS;
}

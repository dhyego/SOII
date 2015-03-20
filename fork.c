#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
  int a, pid, status;
  char *args[] = {"./loop", "10", NULL};

  printf("Subprocess example\n");

  a = 10;

  pid = fork();

  if (pid<0)
  {
    printf("Error: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  if (pid>0)		/* Parent */
  {
    printf("Luke I'm your father. (pid=%d)\n", pid);
    while (a--)
    {
      printf("P: %d\n",a);
      sleep(1);
    }

    printf("Daddy waiting...\n");
    wait(&status);
    printf("Child terminated %s returned with %d\n", WIFEXITED(status) ? "normally" : "abnormally", WEXITSTATUS(status));
    printf("Parent done\n");
  }
  else
  {
    printf("Noooooooooo. (pid=%d)\n", pid);
    while (a--)
    {
      printf("C: %d (my parent %d)\n", a, getppid());
      sleep(2);
    }

    execvp(args[0], args);

    printf("Child done\n");
  }

  return EXIT_SUCCESS;
}

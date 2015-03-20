#include <stdio.h>

int main(int argc, char **argv) {
  int a;
  a = atoi(argv[1]);
  printf("Argc is %d\n", argc);
  while (a--) {
    printf("%d\n",a);
    sleep(1);
  }
  return 0;
}

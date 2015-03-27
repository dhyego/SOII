#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define fail(expression, val) do { if (expression) { fprintf(stderr, "%s : %d : %s\n", __FILE__, __LINE__, strerror(errno)); return val; } } while(0)

#define fatal(expression) do { if (expression) { fprintf(stderr, "%s : %d : %s\n", __FILE__, __LINE__, strerror(errno)); exit(EXIT_FAILURE); } } while(0)

#endif /* DEBUG_H */

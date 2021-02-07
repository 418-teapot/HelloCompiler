#include "parser.h"
#include <cstdio>

int main(int argc, char *argv[]) {
  fprintf(stderr, "ready> ");
  try {
    double val = ParseStmt();
    printf("%f\n", val);
  } catch(const char* msg) {
    fprintf(stderr, msg);
  }
  return 0;
}

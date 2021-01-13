#include "lexer.h"
#include <stdio.h>

static int cur_tok;
static int GetNextToken() {
  return cur_tok = GetToken();
}

int main(int argc, char *argv[]) {
  fprintf(stderr, "ready> ");
  GetNextToken();
  while (cur_tok != int(kTokenEof)) {
    printf("%d\t", cur_tok);
    GetNextToken();
  }
  printf("%d\n", cur_tok);
  return 0;
}

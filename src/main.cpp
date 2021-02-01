#include "lexer.h"
#include <cstdio>

int main(int argc, char *argv[]) {
  fprintf(stderr, "ready> ");
  enum kTokenType cur_tok = GetToken().type;
  while (cur_tok != kTokenEof) {
    cur_tok = GetToken().type;
    printf("%d ", cur_tok);
  }
  return 0;
}

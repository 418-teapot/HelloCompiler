#include "lexer.h"
#include <cstdio>
#include <vector>

int main(int argc, char *argv[]) {
  fprintf(stderr, "ready> ");
  enum kToken cur_tok = GetToken();
  std::vector<enum kToken> tok_list;
  while (cur_tok != kTokenEof) {
    tok_list.push_back(cur_tok);
    cur_tok = GetToken();
  }
  tok_list.push_back(cur_tok);
  for(auto it = tok_list.begin(); it != tok_list.end(); ++it)
    printf("%d ", *it);
  return 0;
}

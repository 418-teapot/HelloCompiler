#include "lexer.h"
#include <stdlib.h>
#include <string>

double num_val;

// TODO: change static type to const
static std::map<const char, enum kToken> kMapToken {
  {'(', kTokenLeftParn},
  {')', kTokenRightParn},
  {'+', kTokenPlus},
  {'-', kTokenSub},
  {'*', kTokenMul},
  {'/', kTokenDiv}
};

static enum kToken FindToken(const char query_char) {
  return kMapToken[query_char];
}

int GetToken() {
  static int last_char = ' ';

  while (last_char == ' ' || last_char == '\t')
    last_char = getchar();

  if (isdigit(last_char) || last_char == '.') {
    std::string num_str;
    do {
      num_str += last_char;
      last_char = getchar();
    } while (isdigit(last_char) || last_char == '.');
    num_val = strtod(num_str.c_str(), nullptr);
    return kTokenNumber;
  }

  switch (last_char) {
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/': {
      int this_char = last_char;
      last_char = getchar();
      return FindToken(this_char);
    }
    case '\n':
    case '\r':
    case EOF: return kTokenEof;
    default: break;
  };

  last_char = getchar();
  return kTokenIllegal;
}

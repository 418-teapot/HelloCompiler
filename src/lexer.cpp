#include "lexer.h"
#include <cstdlib>
#include <map>
#include <string>

// TODO: change static type to const
static std::map<const char, enum kTokenType> kMapToken {
  {'(', kTokenLeftParn},
  {')', kTokenRightParn},
  {'+', kTokenPlus},
  {'-', kTokenSub},
  {'*', kTokenMul},
  {'/', kTokenDiv}
};

static enum kTokenType FindToken(const char query_char) {
  return kMapToken[query_char];
}

Token GetToken() {
  Token mtoken;
  static int last_char = ' ';

  while (last_char == ' ' || last_char == '\t')
    last_char = getchar();

  if (isdigit(last_char) || last_char == '.') {
    std::string num_str;
    double num_val;
    do {
      num_str += last_char;
      last_char = getchar();
    } while (isdigit(last_char) || last_char == '.');
    num_val = strtod(num_str.c_str(), nullptr);
    mtoken.type = kTokenNumber;
    mtoken.val = num_val;    
    return mtoken;
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
      mtoken.type = FindToken(this_char);
      mtoken.val = this_char;
      return mtoken;
    }
    case '\n':
    case '\r':
    case EOF: {
      mtoken.type = kTokenEof;
      mtoken.val = last_char;
      return mtoken;
    }
    default: break;
  };

  int this_char = last_char;
  last_char = getchar();
  mtoken.type = kTokenIllegal;
  mtoken.val = this_char;
  return mtoken;
}

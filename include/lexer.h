#ifndef LEXER_H_
#define LEXER_H_

#include <map>

enum kToken {
  kTokenEof,
  kTokenLeftParn,
  kTokenRightParn,
  kTokenNumber,
  kTokenPlus,
  kTokenSub,
  kTokenMul,
  kTokenDiv,
  kTokenIllegal
};

extern double num_val;

int GetToken();

#endif

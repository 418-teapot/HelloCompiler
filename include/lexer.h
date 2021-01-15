#ifndef LEXER_H_
#define LEXER_H_

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

enum kToken GetToken();

#endif

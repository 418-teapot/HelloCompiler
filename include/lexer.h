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

typedef struct {
  kToken type;
  double val;
} token;

token GetToken();

#endif

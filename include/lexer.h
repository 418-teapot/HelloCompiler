#ifndef LEXER_H_
#define LEXER_H_

enum kTokenType {
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
  kTokenType type;
  double val;
} Token;

Token GetToken();

#endif

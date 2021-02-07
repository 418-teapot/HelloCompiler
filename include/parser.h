#ifndef PARSER_H_
#define PARSER_H_

#include "lexer.h"

typedef struct {
  double val;
  Token last_token;
  Token this_token;
} PRes;

double ParseStmt();
PRes ParseAdd();
PRes ParseMul();
PRes ParseItem();

#endif

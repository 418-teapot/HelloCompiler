#include "lexer.h"
#include "parser.h"

double ParseStmt() {
  return ParseAdd().val;
}

PRes ParseAdd() {
  PRes res = ParseMul();
  while (res.this_token.type == kTokenPlus || res.this_token.type == kTokenSub) {
    PRes res1 = ParseMul();
    if (res.this_token.type == kTokenPlus) res.val += res1.val;
    else res.val -= res1.val;
    res.this_token = res1.this_token;
  }
  res.last_token = res.this_token;
  return res;
}

PRes ParseMul() {
  PRes res = ParseItem();
  while (res.this_token.type == kTokenMul || res.this_token.type == kTokenDiv) {
    PRes res1 = ParseItem();
    if (res.this_token.type == kTokenMul) res.val *= res1.val;
    else res.val /= res1.val;
    res.this_token = res1.this_token;
  }
  res.last_token = res.this_token;
  return res;
}

PRes ParseItem() {
  PRes res;
  res.last_token = GetToken();
  if (res.last_token.type == kTokenLeftParn) {
    res = ParseAdd();
    if (res.last_token.type != kTokenRightParn)
      throw "Can not match parn!\n";
  } if (res.last_token.type == kTokenNumber) {
    res.val = res.last_token.val;
  } else if (res.last_token.type == kTokenIllegal) {
    throw "Illegal char!\n";
  } else if (res.last_token.type == kTokenEof) {
    throw "Unexcepted end!\n";
  }
  res.this_token = GetToken();
  if (res.this_token.type == kTokenIllegal) {
    throw "Illegal char!\n";
  }
  return res;
}
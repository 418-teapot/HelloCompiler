#ifndef PARSER_H_
#define PARSER_H_

#include "lexer.h"

class BaseNode {
 public:
  enum kToken tok;
  BaseNode *prev;
  BaseNode *next;
};

class NumNode : BaseNode {
 public:
  double num_val;
};

class ItemNode : BaseNode {

};

class AddNode : BaseNode {

};

class MulNode : BaseNode {

};

#endif

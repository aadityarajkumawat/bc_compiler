//
// Created by aditya on 18/12/21.
//

#ifndef BC_COMPILER_EVALUATOR_H
#define BC_COMPILER_EVALUATOR_H

#include "BCUtils.h"
#include "Node.h"

#include "string"

class Evaluator {
  public:
    static Node *buildExpressionTree(std::string *s);
    static int evaluateTree(Node *root);
    static void sanitizeExpression(std::string *expression);
};

#endif // BC_COMPILER_EVALUATOR_H

//
// Created by aditya on 18/12/21.
//

#include "Evaluator.h"
#include "Node.h"

#include <bits/stdc++.h>

Node *Evaluator::buildExpressionTree(std::string *s) {
    /*
     *  A stack to save the nodes, in order to
     *  compute and save the values of nodes
     *
     *  node: for the expression tree
     */
    std::stack<Node *> stackOfNodes;

    /*
     * A stack to save characters, parse the
     * expression and check its correctness.
     */
    std::stack<std::string> stackOfCharacter;

    /*
     * A map to store operators and their
     * corresponding priorities.
     */
    std::unordered_map<std::string, int> map;

    /*
     * define priorities of operators,
     * or operator precedence.
     */
    map[")"] = 0;

    map["+"] = map["-"] = 1;

    map["/"] = map["*"] = 2;

    map["^"] = 3;

    std::string num;

    /*
     * root, left and right nodes,
     * for forming the tree.
     */
    Node *root = nullptr, *left = nullptr, *right = nullptr;

    std::string str = *s;
    for (int i = 0; i < s->length(); i++) {
        std::string currentValue = str.substr(i, 1);

        num = currentValue;

        // to skip spaces
        if (currentValue == " ")
            continue;

        // starting of a expression/ subexpression
        if (currentValue == "(")
            stackOfCharacter.push(currentValue);

        // add the root node of tree to stack of nodes
        else if (!num.empty() && BCUtils::is_number(&num)) {

            // gather the entire number before moving on
            while (i + 1 < s->length() && BCUtils::is_digit(&currentValue)) {
                std::string next_digit = str.substr(i + 1, 1);

                if (next_digit == " ") {
                    i++;
                    break;
                }

                if (BCUtils::is_digit(&next_digit)) {
                    num += next_digit;
                    i++;
                    currentValue = next_digit;
                } else {
                    break;
                }
            }

            root = new Node(num);
            stackOfNodes.push(root);
            num = "";
        }

        //
        else if (map[currentValue] > 0) {
            bool stackHasChars = !stackOfCharacter.empty();
            bool charStackTopIsNotOpen = stackOfCharacter.top() != "(";

            while (stackHasChars && charStackTopIsNotOpen &&
                   ((currentValue != "^" &&
                     map[stackOfCharacter.top()] >= map[currentValue]) ||
                    (currentValue == "^" &&
                     map[stackOfCharacter.top()] > map[currentValue]))) {

                // the char at the top of chars stack will the root of new
                // subtree.
                root = new Node(stackOfCharacter.top());
                stackOfCharacter.pop();

                // the one at top of nodes stack will be the left child of that
                // root, defined above.
                right = stackOfNodes.top();
                stackOfNodes.pop();

                // similarly, the second top of nodes stack will be the right
                // child root.
                left = stackOfNodes.top();
                stackOfNodes.pop();

                // set the left and right child's of root.
                root->setLeft(left);
                root->setRight(right);

                stackOfNodes.push(root);
            }

            stackOfCharacter.push(currentValue);
        } else if (currentValue == ")") {
            while (!stackOfCharacter.empty() && stackOfCharacter.top() != "(") {
                root = new Node(stackOfCharacter.top());
                stackOfCharacter.pop();

                // the one at top of nodes stack will be the left child of that
                // root, defined above.
                right = stackOfNodes.top();
                stackOfNodes.pop();

                // similarly, the second top of nodes stack will be the right
                // child root.
                left = stackOfNodes.top();
                stackOfNodes.pop();

                // set the left and right child's of root.
                root->setLeft(left);
                root->setRight(right);

                stackOfNodes.push(root);
            }

            stackOfCharacter.pop();
        }
    }

    root = stackOfNodes.top();
    return root;
}

int Evaluator::evaluateTree(Node *root) {
    if (!root)
        return 0;

    if (!root->getLeft() && !root->getRight()) {
        std::string val = root->getData();
        return BCUtils::parseInt(&val);
    }

    int leftValue = evaluateTree(root->getLeft());
    int rightValue = evaluateTree(root->getRight());

    if (root->getData() == "+")
        return leftValue + rightValue;
    else if (root->getData() == "-")
        return leftValue - rightValue;
    else if (root->getData() == "*")
        return leftValue * rightValue;
    else
        return leftValue / rightValue;
}

void Evaluator::sanitizeExpression(std::string *expression) {
    // more sanitizations checks to be added
    *expression = "(" + *expression;
    *expression += ")";
}

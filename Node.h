//
// Created by aditya on 30/11/21.
//

#ifndef BC_COMPILER_NODE_H
#define BC_COMPILER_NODE_H

#include "string"

class Node {
    std::string data;
    Node *left;
    Node *right;

public:
    Node();

    explicit Node(std::string data);

    void setData(std::string nodeValue);

    std::string getData() const;

    void setLeft(Node *leftSubTree);

    Node *getLeft();

    void setRight(Node *rightSubTree);

    Node *getRight();
};

#endif // BC_COMPILER_NODE_H

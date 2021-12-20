//
// Created by aditya on 30/11/21.
//

#include "Node.h"
#include "string"

Node::Node() {
    this->data = "";
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(std::string data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

void Node::setData(std::string nodeValue) { this->data = nodeValue; }

std::string Node::getData() const { return data; }

void Node::setLeft(Node *leftSubTree) { this->left = leftSubTree; }

Node *Node::getLeft() { return left; }

void Node::setRight(Node *rightSubTree) { this->right = rightSubTree; }

Node *Node::getRight() { return right; }

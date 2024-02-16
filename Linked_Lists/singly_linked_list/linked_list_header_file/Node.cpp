#include <Node.h>

Node::Node() : value(0),
               next(nullptr){};

Node::Node(int value_) : value(value_),
                         next(nullptr){};

Node::Node(int value_, Node *next_) : value(value_),
                                      next(next_){};
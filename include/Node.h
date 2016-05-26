#ifndef NODE_H
#define NODE_H

#include <iostream>

template<class T>
struct Node
{
    Node(T initData)
    {
      data = initData;
      lnode = nullptr;
      rnode = nullptr;
    };
    virtual ~Node()
    {
      lnode = nullptr;
      rnode = nullptr;
    };
    T data;
    Node *lnode;
    Node *rnode;
};

#endif // NODE_H

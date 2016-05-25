#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "Node.h"

using namespace std;

/**
  1. Determine whether the binary tree is empty.
  2. Search the binary tree for a particular item.
  3. Insert an item in the binary tree.
  4. Delete an item from the binary tree.
  5. Find the height of the binary tree.
  6. Find the number of nodes in the binary tree.
  7. Find the number of leaves in the binary tree.
  8. Traverse the binary tree.
  9. Copy the binary tree.


  BST<map> tree;
  map<date,record> m1;

  tree.insert(m1);
  tree.insert(m2);




*/
/**
  InOrderProcess: Left Current Right
  PreOrderProcess: Current Left Right
  PostOrderProcess: Left Right Current
*/

template <class T>
using vfp = void (*)(T&);

template <class T>
class BinarySearchTree
{
  public:
    BinarySearchTree();
    virtual ~BinarySearchTree();

//    BinarySearchTree(BinarySearchTree &srcBST);
//    operator=(BinarySearchTree rightBST);

    bool isEmpty() const;
    void insert(const T &data);
    void remove(const T &data);
    bool search(const T &data) const;

//    T& getData()

    void inOrder(vfp<T> func);
    void preOrder(vfp<T> func);
    void postOrder(vfp<T> func);

  protected:
  private:
    Node<T> *root;

    void insert(Node<T> *&node, const T &data);
    bool remove(Node<T> *&node, const T &data);

    void clear(Node<T> *&node,Node<T> *&parent);

    void reassign(Node<T> *&clearNode, Node<T> *&node);
    void reassignRoot();

    bool search( Node<T>*const&node,const T &data) const;

    void inOrderProcess(Node<T> *&node,vfp<T> func);
    void preOrderProcess(Node<T> *&node,vfp<T> func);
    void postOrderProcess(Node<T> *&node,vfp<T> func);

    void destroyTree(Node<T> *&node);
};

/*
--------------------------------------
*/


template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
  root = nullptr;
};

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
  //destroy tree
//  clear(root);
  destroyTree(root);
  root = nullptr;
};


template <class T>
bool BinarySearchTree<T>::isEmpty() const
{
  if(root == nullptr) return true;
  return false;
}

template <class T>
void BinarySearchTree<T>::insert(const T &data)
{
  insert(root,data);
}

/**
    n1
  n2  n3

  n2.data < n1.data
  n3.data > n1.data
*/
template <class T>
void BinarySearchTree<T>::insert(Node<T> *&node,const T &data)
{
  if(node == nullptr)
    node = new Node<T>(data);
  else if(node->data == data)
    return; // data already exists
  else if(data < node->data)
    insert(node->lnode,data);
  else
    insert(node->rnode,data);
}

template <class T>
void BinarySearchTree<T>::remove(const T &data)
{
  remove(root,data);
}


template <class T>
bool BinarySearchTree<T>::remove(Node<T> *&node, const T &data)
{
  Node<T> *clearNode;
  if(node == nullptr)
  {
    return false;//not found
  }
  else if(node->data == data)
  {
    if (node == root)
      reassignRoot();
    return true;//node deleted -> delete parent link
  }
  else if(data < node->data)
  {
    clearNode = node->lnode;
  }
  else// data > node->data
  {
    clearNode = node->rnode;
  }
  if( remove(clearNode,data) )
  {
    reassign(clearNode,node);
  }
  return false;
}

template <class T>
void BinarySearchTree<T>::reassignRoot()
{
  if( root->lnode == nullptr && root->rnode == nullptr )
  {
    //no children
    delete root;
    root = nullptr;
  }
  else if( root->lnode == nullptr)
  {
    // rnode children only
    Node<T> *deleteRoot = root;
    root = root->rnode;
    delete deleteRoot;
  }
  else if( root->rnode == nullptr )
  {
    // lnode children only
    Node<T> *deleteRoot = root;
    root = root->lnode;
    delete deleteRoot;
  }
  else//both have children :. rnode > lnnode bring rnode up
  {
    Node<T> *deleteRoot = root;

    Node<T> *lchild;
    Node<T> *rchild;

    lchild = root->lnode;
    rchild = root->rnode;

    delete deleteRoot;

    root = rchild;
    Node<T> *nchild;
    nchild = root;
    while(nchild->lnode != nullptr)
    {
      nchild = nchild->lnode;
    }
    nchild->lnode = lchild;
  }

}

template <class T>
void BinarySearchTree<T>::reassign(Node<T> *&clearNode, Node<T> *&node)
{
  if( clearNode->lnode == nullptr && clearNode->rnode == nullptr )
  {
    //no children
    clear(clearNode,node);
  }
  else if( clearNode->lnode == nullptr )
  {
    // rnode children only
    Node<T> *child;
    child = clearNode->rnode;
    if(node->lnode == clearNode)
      node->lnode = child;
    else
      node->rnode = child;
    clear(clearNode,node);
  }
  else if( clearNode->rnode == nullptr )
  {
    // lnode children only
    Node<T> *child;
    child = clearNode->lnode;
    if(node->lnode == clearNode)
      node->lnode = child;
    else
      node->rnode = child;
    clear(clearNode,node);
  }
  else//both have children :. rnode > lnnode bring rnode up
  {
    Node<T> *lchild;
    Node<T> *rchild;

    lchild = clearNode->lnode;
    rchild = clearNode->rnode;
    clear(clearNode,node);

    node->rnode = rchild;
    Node<T> *nchild;
    nchild = rchild;
    while(nchild->lnode != nullptr)
    {
      nchild = rchild->lnode;
    }
    nchild->lnode = lchild;
  }
}


template <class T>
void BinarySearchTree<T>::clear(Node<T> *&node,Node<T> *&parent)
{
  if(node == nullptr) return;

  // nullify deleted node pointer
  if(parent->lnode == node)
    parent->lnode = nullptr;
  else if(parent->rnode == node)
    parent->rnode = nullptr;

  delete node;
  node = nullptr;
}

template <class T>
void BinarySearchTree<T>::destroyTree(Node<T> *&node)
{
  if(node == nullptr) return;
  destroyTree(node->lnode);
  destroyTree(node->rnode);
  delete node;
}

template <class T>
bool BinarySearchTree<T>::search(const T &data) const
{
  return search(root,data);
}

template <class T>
bool BinarySearchTree<T>::search( Node<T>*const&node,const T &data) const
{
  if(node == nullptr)
  {
    return false;
  }
  else if(node->data == data)
  {
    return true;
  }
  else if(data < node->data)
  {
    // go left
    return search(node->lnode,data);
  }
  else
  {
    //go right
    return search(node->rnode,data);
  }
}


template <class T>
void BinarySearchTree<T>::inOrder(vfp<T> func)
{
  inOrderProcess(root,func);
}

template <class T>
void BinarySearchTree<T>::inOrderProcess(Node<T> *&node,vfp<T> func)
{
  if(node == nullptr)return;
  inOrderProcess(node->lnode,func);
  func(node->data);
  inOrderProcess(node->rnode,func);
}

template <class T>
void BinarySearchTree<T>::preOrder(vfp<T> func)
{
  preOrderProcess(root,func);
}

template <class T>
void BinarySearchTree<T>::preOrderProcess(Node<T> *&node,vfp<T> func)
{
  if(node == nullptr)return;
  func(node->data);
  preOrderProcess(node->lnode,func);
  preOrderProcess(node->rnode,func);
}

template <class T>
void BinarySearchTree<T>::postOrder(vfp<T> func)
{
  postOrderProcess(root,func);
}

template <class T>
void BinarySearchTree<T>::postOrderProcess(Node<T> *&node,vfp<T> func)
{
  if(node == nullptr)return;
  postOrderProcess(node->lnode,func);
  postOrderProcess(node->rnode,func);
  func(node->data);;
}


#endif // BINARYSEARCHTREE_H

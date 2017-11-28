//
// Created by Wang wei on 2017/11/6.
//

#ifndef BINARYTREE_BINARYTREENODE_H
#define BINARYTREE_BINARYTREENODE_H


#include <iostream>
using namespace std;

template <class T> class BinaryTree;
template <class T>
class BinaryTreeNode{
    friend class BinaryTree<T>;

public:
    T element;
    BinaryTreeNode<T>* leftChild;
    BinaryTreeNode<T>* rightChild;
  public:
    BinaryTreeNode();
    BinaryTreeNode(const T& ele);
    BinaryTreeNode(const T& ele, BinaryTreeNode<T>* l, BinaryTreeNode<T>* r);
    BinaryTreeNode<T>* getLeftChild();
    BinaryTreeNode<T>* getRightChild();
    void setLeftChild(BinaryTreeNode<T>* l);
    void setRightChild(BinaryTreeNode<T>* r);
    T getValue() const;
    void setValue(const T& val);
    bool isLeaf() const;
};


#endif //BINARYTREE_BINARYTREENODE_H

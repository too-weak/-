//
// Created by Wang wei on 2017/11/6.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H

#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
#include "BinaryTreeNode.cpp"
using namespace std;

template <class T>
class BinaryTree {
private:
    BinaryTreeNode<T> *root;
public:
    BinaryTreeNode<T>* createTree(T *arr, T length);
    BinaryTree();
    ~BinaryTree();
    void TreeCreate(BinaryTreeNode<T> **ro);
    bool isEmpty() const;
    BinaryTreeNode<T> *getRoot() const;
    BinaryTreeNode<T> *getLeftSibling(BinaryTreeNode<T> *current) const;
    BinaryTreeNode<T> *getRightSibling(BinaryTreeNode<T> *current) const;
    void breadthFirstOrder(BinaryTreeNode<T> *root);
    void preOrder(BinaryTreeNode<T> *root);
    void inOrder(BinaryTreeNode<T> *root);
    void postOrder(BinaryTreeNode<T> *root);
    void levelOrder(BinaryTreeNode<T> *root);
    void deleteBinaryTree(BinaryTreeNode<T> *root);
};


#endif //BINARYTREE_BINARYTREE_H

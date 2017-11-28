//
// Created by Wang wei on 2017/11/6.
//

#include "BinaryTreeNode.h"

template <class T>
BinaryTreeNode<T>::BinaryTreeNode() {
    leftChild = rightChild = nullptr;
}

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T &ele) {
    element = ele;
    leftChild = rightChild = nullptr;
}

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T &ele, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r) {
    element = ele;
    leftChild = l;
    rightChild = r;
}

template <class T>
BinaryTreeNode<T> *BinaryTreeNode<T>::getLeftChild(){
    return leftChild;
}

template <class T>
BinaryTreeNode<T> *BinaryTreeNode<T>::getRightChild(){
    return rightChild;
}

template <class T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T> *l) {
    leftChild = l;
}

template <class T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T> *r) {
    rightChild = r;
}

template <class T>
T BinaryTreeNode<T>::getValue() const{
    return element;
}

template <class T>
void BinaryTreeNode<T>::setValue(const T &val) {
    element = val;
}
template <class T>
bool BinaryTreeNode<T>::isLeaf() const {
    return leftChild == nullptr && rightChild == nullptr;
}

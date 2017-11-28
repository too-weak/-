//
// Created by Wang wei on 2017/11/6.
//

#include "BinaryTree.h"

template <class T>
BinaryTree<T>::BinaryTree() {
    root = 0;
    TreeCreate(&root);
//    root = createTree(arr, length);
}

template <class T>
BinaryTreeNode<T> *BinaryTree<T>::createTree(T *arr, T length) {
    if(length<1) return NULL;
    BinaryTreeNode<T>* root = new BinaryTreeNode<T>(arr[0]);
    deque<pair<BinaryTreeNode<T>*,int> > route;
    route.push_back(make_pair(root,0));
    while(!route.empty()) {
        BinaryTreeNode<T>* temp = route.front().first;
        int ct = route.front().second;
        route.pop_front();
        if(2*ct+1<length) {
            temp->leftChild = new BinaryTreeNode<T>(arr[2*ct+1]);//创建当前节点的左叶子
            route.push_back(make_pair(temp->leftChild,2*ct+1));
        }
        if(2*ct+2<length) {
            temp->rightChild = new BinaryTreeNode<T>(arr[2*ct+2]);//创建当前节点的右叶子
            route.push_back(make_pair(temp->rightChild,2*ct+2));
        }

    }
    return root;
}

template <class T>
void BinaryTree<T>::TreeCreate(BinaryTreeNode<T> **ro){
    T ele;
    cin>>ele;
    if(ele == -1)
        *ro = 0;
    else {
        *ro = new BinaryTreeNode<T>(ele);
        TreeCreate(&((*ro)->leftChild));
        TreeCreate(&((*ro)->rightChild));
    }
}

template <class T>
BinaryTree<T>::~BinaryTree() {
    deleteBinaryTree(root);
}

template <class T>
bool BinaryTree<T>::isEmpty() const {
    return root == nullptr;
}

template <class T>
BinaryTreeNode<T> *BinaryTree<T>::getRoot() const {
    return root;
}

template <class T>
BinaryTreeNode<T> *BinaryTree<T>::getLeftSibling(BinaryTreeNode<T> *current) const {
    return nullptr;
}

template <class T>
BinaryTreeNode<T> *BinaryTree<T>::getRightSibling(BinaryTreeNode<T> *current) const {
    return nullptr;
}

//广度优先遍历
template <class T>
void BinaryTree<T>::breadthFirstOrder(BinaryTreeNode<T> *root) {
    queue<BinaryTreeNode<T>*> nodeQ;
    BinaryTreeNode<T> *p;
    nodeQ.push(root);
    while(!nodeQ.empty()){
        p = nodeQ.front();
        cout<<p->getValue()<<" ";
        nodeQ.pop();
        if(p->leftChild) nodeQ.push(p->leftChild);
        if(p->rightChild) nodeQ.push(p->rightChild);
    }
}

//前序遍历
template <class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T> *root) {
    if(root != nullptr){
        cout<<root->getValue()<<" ";
        preOrder(root->getLeftChild());
        preOrder(root->getRightChild());
    }
}

//中序遍历
template <class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T> *root) {
    if(root != nullptr){
        inOrder(root->leftChild);
        cout<<root->getValue()<<" ";
        inOrder(root->rightChild);
    }
}

//后序遍历
template <class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> *root) {
    if(root != nullptr){
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        cout<<root->getValue()<<" ";
    }
}

//层级遍历
template <class T>
void BinaryTree<T>::levelOrder(BinaryTreeNode<T> *root) {

}

template <class T>
void BinaryTree<T>::deleteBinaryTree(BinaryTreeNode<T> *root) {
    if(root){
        if(root->getLeftChild())
            deleteBinaryTree(root->getLeftChild());
        if(root->getRightChild())
            deleteBinaryTree(root->getRightChild());
        delete root;
        root = nullptr;
    }
}

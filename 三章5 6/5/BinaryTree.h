//
// Created by Wang wei on 2017/11/17.
//

#ifndef INC_5_BINARYTREE_H
#define INC_5_BINARYTREE_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct Node{
    int ele;
    Node *leftChild;
    Node *rightChild;
};

class BinaryTree {
public:
    Node *root;
    BinaryTree(vector<int> v1, int lengthOfS1, vector<int> in, int lengthOfIn, int ways);
    Node *createByPreAndIn(vector<int> pre, int pre_s, int pre_e,
                           vector<int> in, int in_s, int in_e);
    Node *createByPostAndIn(vector<int> post, int post_s, int post_e,
                            vector<int> in, int in_s, int in_e);
    BinaryTree(int *arr, int length);
    BinaryTree();
    ~BinaryTree();
    bool isEmpty();
    Node *getRoot();
    void preOrder(Node *r = NULL);
    void inOrder(Node *r = NULL);
    void postOrder(Node *r = NULL);
    void leverOrder(Node *r = NULL);
    void deleteTree(Node *r = NULL);
    int numOfFulls(Node *p = NULL);
    int numOfSingle(Node *p = NULL);
    int numOfLeaves(Node *p = NULL);
    int getHeight(Node *p = NULL, int height = 0);
    int getBreadth();
    int getBreadth_R(Node *p = NULL);
    void RForBreadth(Node *p, int deepth, int width[]);
    int getLargest(Node *p = NULL, int num = 0);
    void exchangeLAndR(Node *p);
    void deleteAllLeaves(Node **p);
    bool whetherCompleteTree();
};

bool isLeaf(Node *root);


#endif //INC_5_BINARYTREE_H

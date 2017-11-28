//
// Created by Wang wei on 2017/11/17.
//

#include "BinaryTree.h"

BinaryTree::BinaryTree(vector<int> v1, int lengthOfV1,
                          vector<int> in, int lengthOfIn, int ways) {
    /*  ways = 0: 前序和中序
     * ways = 1: 后序和中序
     * */

    switch(ways){
        case 0:
            root = createByPreAndIn(v1, 0, lengthOfV1, in, 0, lengthOfIn);
            break;
        case 1:
            root = createByPostAndIn(v1, 0, lengthOfV1, in, 0, lengthOfIn);
            break;
    }
}

Node *BinaryTree::createByPreAndIn(vector<int> pre, int pre_s, int pre_e,
                                   vector<int> in, int in_s, int in_e) {
    if(in_s > in_e)
        return NULL;
    int p = in_s;
    for(; p < in_e && pre[pre_s] != in[p]; ++p);
    Node *root = new Node();
    root->ele = pre[pre_s];
    root->leftChild = createByPreAndIn(pre, pre_s + 1, pre_s + p - in_s,
                                       in, in_s, p - 1);
    root->rightChild = createByPreAndIn(pre, pre_s + p - in_s + 1, pre_e,
                                        in, p + 1, in_e);
    return root;
}


Node *BinaryTree::createByPostAndIn(vector<int> post, int post_s, int post_e,
                                    vector<int> in, int in_s, int in_e) {
    if(in_s - in_e < 0)
        return NULL;
    int p = in_s;
    for(;p < in_e && in[p] != post[post_e];);
    Node *root = new Node;
    root->ele = in[p];
    root->leftChild = createByPostAndIn(post, post_s, post_s + p - in_s - 1,
                                        in, in_s, p - 1);
    root->rightChild = createByPostAndIn(post, p, post_e - 1,
                                         in, p + 1, in_e);
    return root;
}


BinaryTree::BinaryTree(int *arr, int length){
//    stack<int> sta;
//    Node *p = NULL:
//    while()
}


BinaryTree::BinaryTree() {
    this->root = NULL;
}


BinaryTree::~BinaryTree() {

}


bool BinaryTree::isEmpty() {
    return root == NULL ? true : false;
}


Node *BinaryTree::getRoot() {
    return root;
}


void BinaryTree::preOrder(Node *r) {
    stack<Node *> sta;
    Node *p = (r == NULL? root : r);
    while(!sta.empty() || p){
        while(p){
            cout<<p->ele<<" ";
            sta.push(p);
            p = p->leftChild;
        }
        if(!sta.empty()){
            p = sta.top()->rightChild;
            sta.pop();
        }
    }
     cout<<endl;
}

void BinaryTree::inOrder(Node *r) {
    Node *p = (r == NULL? root : r);
    stack<Node *> sta;
    while(!sta.empty() || p){
        while(p){
            sta.push(p);
            p = p->leftChild;
        }
        if(!sta.empty()){
            p = sta.top();
            sta.pop();
            cout<<p->ele<<" ";
            p = p->rightChild;
        }
    }
    cout<<endl;
}

void BinaryTree::postOrder(Node *r) {
    stack<Node *> sta;
    Node *p = (r == NULL? root : r);
    Node *pre = (r == NULL? root : r);
    while(p){
        while(p->leftChild){
            sta.push(p);
            p = p->leftChild;
        }
        while(p && (p->rightChild == NULL || p->rightChild == pre)){
            cout<<p->ele<<" ";
            pre = p;
            if(sta.empty())
                return;
            p = sta.top();
            sta.pop();
        }
        sta.push(p);
        p = p->rightChild;
    }
    cout<<endl;
}

void BinaryTree::leverOrder(Node *r) {
    queue<Node *> que;
    Node *p = (r == NULL? root : r);
    que.push(p);
    while(!que.empty()){
        p = que.front();
        cout<<p->ele<<" ";
        que.pop();
        if(p->leftChild)que.push(p->leftChild);
        if(p->rightChild)que.push(p->rightChild);
    }
    cout<<endl;
}

void BinaryTree::deleteTree(Node *r) {

}

int BinaryTree::numOfFulls(Node *p) {
    int num = 0;
    if(!p)
        return 0;
    if(p->leftChild && p->rightChild)
        ++num;
    int left = numOfFulls(p->leftChild);
    int right = numOfFulls(p->rightChild);
    num += left;
    num += right;
    return num;
}

int BinaryTree::numOfSingle(Node *p) {
    int num = 0;
    if(!p)
        return 0;
    if((!p->leftChild && p->rightChild) ||
            (p->leftChild && !p->rightChild))
        ++num;
    int left = numOfSingle(p->leftChild);
    int right = numOfSingle(p->rightChild);
    num += left;
    num += right;
    return num;
}

int BinaryTree::numOfLeaves(Node *p) {
    if(!p)
        return 0;
    int num = 0;
    if(!p->leftChild && !p->rightChild)
        ++num;
    int left = numOfLeaves(p->leftChild);
    int right = numOfLeaves(p->rightChild);
    num += left;
    num += right;
    return num;
}

int BinaryTree::getHeight(Node *p, int height) {
    if(p) {
        height++;
        int lH, rH;
        lH = getHeight(p->leftChild, height);
        rH = getHeight(p->rightChild, height);
        height = lH > rH ? lH : rH;
    }
    return height;
}

int BinaryTree::getBreadth() {
    if(root == NULL)
        return 0;
    queue<Node *> que;
    Node *p = root;
    int now = 1, nowCounter = now, pre = 1, next = 0, max = 0;
    que.push(p);
    while(!que.empty()){
        p = que.front();
        que.pop();
        if(p->leftChild){
            ++next;
            que.push(p->leftChild);
        }
        if(p->rightChild){
            ++next;
            que.push(p->rightChild);
        }
        --nowCounter;
        if(nowCounter == 0){
            pre = now;
            now = next;
            next = 0;
            nowCounter = now;
            max = max > pre ? (max > now ? max : now) : (pre > now ? pre : now);
        }
    }
    return max;
}

int BinaryTree::getBreadth_R(Node *p) {
    int deepth = 0;
    int width[20] = {0};
    RForBreadth(root, deepth, width);
    int max = width[0];
    for(int i = 0; i < 20; ++i){
        if(width[i] > max)
            max = width[i];
    }
    return max;
}

void BinaryTree::RForBreadth(Node *p, int deepth, int width[]) {
    if(!p)
        return;
    if(deepth == 0)
        width[0] = 1;
    if(p->leftChild){
        width[deepth + 1] += 1;
        deepth += 1;
        RForBreadth(p->leftChild, deepth, width);
        deepth -= 1;
    }
    if(p->rightChild){
        width[deepth + 1] += 1;
        deepth += 1;
        RForBreadth(p->rightChild, deepth, width);
        deepth -= 1;
    }
}

int BinaryTree::getLargest(Node *p, int max) {
    if(p) {
        if (p->ele > max)
            max = p->ele;
        int left = getLargest(p->leftChild, max);
        int right = getLargest(p->rightChild, max);
        max = max > left ? (max > right ? max : right) : (left > right ? left : right);
        return max;
    }
}

void BinaryTree::exchangeLAndR(Node *p) {
    if(p) {
        Node *temp = p->leftChild;
        p->leftChild = p->rightChild;
        p->rightChild = temp;
        exchangeLAndR(p->leftChild);
        exchangeLAndR(p->rightChild);
    }
}

void BinaryTree::deleteAllLeaves(Node **p) {
    if((*p) != NULL){
        if((*p)->leftChild == NULL && (*p)->rightChild == NULL){
            delete *p;
            *p = NULL;
            return;
        }
        deleteAllLeaves(&((*p)->leftChild));
        deleteAllLeaves(&((*p)->rightChild));
    }
}

bool BinaryTree::whetherCompleteTree() {
    queue<Node *> que;
    Node *p = root;
    que.push(p);
    while((p = que.front()) != NULL){
        que.pop();
        que.push(p->leftChild);
        que.push(p->rightChild);
    }
    while(!que.empty()){
        p = que.front();
        que.pop();
        if(p != NULL)
            return false;
    }
    return true;
}

bool isLeaf(Node *p) {
    if(!p->leftChild && !p->rightChild)
        return true;
    return false;
}

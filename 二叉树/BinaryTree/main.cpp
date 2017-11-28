#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include <vector>


BinaryTreeNode<int> *preAndInOrder(vector<int> pre, int pre_s, int pre_e,
                                 vector<int> in, int in_s, int in_e) {
    BinaryTreeNode<int> *p = NULL;
    if(in_s > in_e)
        return NULL;
    int root = 0;
    for(; root < in_e && in[root] != pre[pre_s]; ++root);
    p = new BinaryTreeNode<int>(in[root]);
    p->leftChild = preAndInOrder(pre, pre_s + 1, pre_s + root - in_s,
                                 in, in_s, root - 1);
    p->rightChild = preAndInOrder(pre, pre_s + root - in_s + 1, pre_e,
                                  in, root + 1, in_e);
    return p;
}

template <class T>
BinaryTreeNode<T> *preAndInOrderNon_r(vector<T> pre, int pre_s, int pre_e,
                                      vector<T> in, int in_s, int in_e){

}

template <class T>
BinaryTreeNode<T> *inAndPostOrder(vector<T> in, int in_s, int in_e,
                                  vector<T> post, int post_s, int post_e) {
    BinaryTreeNode<T> *p = NULL;
    if(in_s > in_e)
        return NULL;
    int root = 0;
    for(; root <= in_e && in[root] != post[post_e]; ++root);
    p = new BinaryTreeNode<T>(in[root]);
    p->leftChild = inAndPostOrder(in, in_s, root - 1,
                                  post, post_s, post_s + root - in_s - 1);
    p->rightChild = inAndPostOrder(in, root + 1, in_e,
                                   post, root, post_e - 1);
    return p;
}

template <class T>
void preOrder(BinaryTreeNode<T> *root) {
    if(root != nullptr){
        cout<<root->getValue()<<" ";
        preOrder(root->getLeftChild());
        preOrder(root->getRightChild());
    }
}

template <class T>
void inOrder(BinaryTreeNode<T> *root) {
    if(root != nullptr){
        preOrder(root->getLeftChild());
        cout<<root->getValue()<<" ";
        preOrder(root->getRightChild());
    }
}

template <class T>
void postOrder(BinaryTreeNode<T> *root) {
    if(root != nullptr){
        preOrder(root->getLeftChild());
        cout<<root->getValue()<<" ";
        preOrder(root->getRightChild());
    }
}
int main() {
//    vector<int> ve;
//    int temp = 0;
//    cin>>temp;
//    while(temp != -1){
//        ve.push_back(temp);
//        cin>>temp;
//    }
//    int length = ve.size();
//    int *arr = new int[length];
//    for(int i = 0; i < length; ++i){
//        arr[i] = ve[i];
//    }
//    BinaryTree<int> tree(arr, length);
    BinaryTree<int> tree;
//    cout<<"前序："<<"   ";
//    tree.preOrder(tree.getRoot());
//    cout<<endl;
//    cout<<"中序："<<"   ";
//    tree.inOrder(tree.getRoot());
//    cout<<endl;
//    cout<<"后序："<<"   ";
//    tree.postOrder(tree.getRoot());
//    cout<<endl;
//    cout<<"层级："<<"   ";
//    tree.breadthFirstOrder(tree.getRoot());
//    cout<<endl;
    tree.non_rPreOrder(tree.getRoot());
    tree.non_rInOrder(tree.getRoot());
    tree.non_rPostOrder(tree.getRoot());
    tree.preorder_deleteleaf(tree.root);
    cout<<endl;
    tree.preOrder(tree.getRoot());
//    vector<int> pre, in, post;
//    int temp;
//    cout<<"先序/后序："<<endl;
//    while(cin>>temp){
//        pre.push_back(temp);
//        if(getchar() == '\n')
//            break;
//    }
//    cout<<"中序："<<endl;
//    while(cin>>temp){
//        in.push_back(temp);
//        if(getchar() == '\n')
//            break;
//    }
//    BinaryTreeNode<int> *p = preAndInOrder(pre, 0, pre.size() - 1, in, 0, in.size() - 1);
//    preOrder(p);
//    BinaryTreeNode<int> *q = inAndPostOrder(in, 0, in.size() - 1, pre, 0, pre.size() - 1);
//    preOrder(q);
    return 0;
}
/*
 * 1
2
3
-1
-1
5
-1
-1
3
6
-1
-1
7
-1
-1*/

/*
 * 前序 1 2 4 6 7 3 5 8
 * 中序 2 6 4 7 1 3 5 8
 * 后序 6 7 4 2 8 5 3 1
 * */



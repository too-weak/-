#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include <vector>

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
    cout<<"前序："<<"   ";
    tree.preOrder(tree.getRoot());
    cout<<endl;
    cout<<"中序："<<"   ";
    tree.inOrder(tree.getRoot());
    cout<<endl;
    cout<<"后序："<<"   ";
    tree.postOrder(tree.getRoot());
    cout<<endl;
    cout<<"层级："<<"   ";
    tree.breadthFirstOrder(tree.getRoot());
    cout<<endl;
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
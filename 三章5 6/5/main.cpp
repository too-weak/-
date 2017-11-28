#include "BinaryTree.h"
//#include "BinaryTree.cpp"

int main() {
    vector<int> pre, in, post;
    int temp;
    cout<<"先序/后序："<<endl;
    while(cin>>temp){
        pre.push_back(temp);
        if(getchar() == '\n')
            break;
    }
    cout<<"中序："<<endl;
    while(cin>>temp){
        in.push_back(temp);
        if(getchar() == '\n')
            break;
    }
    BinaryTree tree(pre, pre.size() - 1, in, in.size() - 1, 0);
    tree.leverOrder();
    tree.preOrder();
    tree.inOrder();
    tree.postOrder();
    cout<<endl;
    cout<<"FULL"<<tree.numOfFulls(tree.getRoot())<<endl;
    cout<<"Single"<<tree.numOfSingle(tree.getRoot())<<endl;
    cout<<"Leaves"<<tree.numOfLeaves(tree.getRoot())<<endl;
    cout<<"Height"<<tree.getHeight(tree.getRoot())<<endl;
    cout<<"Breadth"<<tree.getBreadth()<<endl;
    cout<<"NR_Breadth"<<tree.getBreadth_R(tree.getRoot())<<endl;
    cout<<"Largest"<<tree.getLargest(tree.getRoot(), tree.getRoot()->ele)<<endl;
    tree.exchangeLAndR(tree.getRoot());
    tree.leverOrder();
    tree.deleteAllLeaves(&(tree.root));
    tree.leverOrder();
    cout<<tree.whetherCompleteTree()<<endl;
    return 0;
}

/*
 * 前序 1 2 4 6 7 3 5 8
 * 中序 2 6 4 7 1 3 5 8
 * 后序 6 7 4 2 8 5 3 1
 * */
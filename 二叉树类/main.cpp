#include <iostream>
#include "BinaryTree.h"
#include "BinaryTreeNode.h"
using namespace std;

int main()
{
    BinaryTree tree;
    BinaryTreeNode * pA = NULL;
//  cout<<"依次输入先序和中序序列"<<endl;
    string sA,sB;
//    cin>>sA>>sB;
    sA = "abdgcef";
    sB = "dgbaecf";
    tree.buildTreePreIn(pA,sA,sB,true);
    cout<<"前序为：  ";
    tree.preOrderWithoutRecusion( tree.getRoot() );
    cout<<endl;
    cout<<"中序为：  ";
    tree.inOrderWithoutRecusion( tree.getRoot() );
    cout<<endl;
    cout<<"后序为：  ";
    tree.postOrderWithoutRecusion( tree.getRoot() );
    cout<<endl;
    sA = "dgbaecf";
    sB = "gdbefca";
    tree.setRoot( tree.buildTreeInPost(sA,sB) );
    cout<<"中序为：  ";
    tree.inOrder( tree.getRoot() );
    cout<<endl;
    tree.completeBinaryTree( tree.getRoot() );
    return 0;
}

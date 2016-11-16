#include <iostream>
#include "BinaryTree.h"
#include "BinaryTreeNode.h"
using namespace std;

int main()
{
    BinaryTree tree;
    BinaryTreeNode * pA = NULL;
//  cout<<"���������������������"<<endl;
    string sA,sB;
//    cin>>sA>>sB;
    sA = "abdgcef";
    sB = "dgbaecf";
    tree.buildTreePreIn(pA,sA,sB,true);
    cout<<"ǰ��Ϊ��  ";
    tree.preOrderWithoutRecusion( tree.getRoot() );
    cout<<endl;
    cout<<"����Ϊ��  ";
    tree.inOrderWithoutRecusion( tree.getRoot() );
    cout<<endl;
    cout<<"����Ϊ��  ";
    tree.postOrderWithoutRecusion( tree.getRoot() );
    cout<<endl;
    sA = "dgbaecf";
    sB = "gdbefca";
    tree.setRoot( tree.buildTreeInPost(sA,sB) );
    cout<<"����Ϊ��  ";
    tree.inOrder( tree.getRoot() );
    cout<<endl;
    tree.completeBinaryTree( tree.getRoot() );
    return 0;
}

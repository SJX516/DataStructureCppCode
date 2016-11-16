#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree<int> bSearchTree;
    int temp;
//    int a[8] = {122,99,250,200,300,110,105,225};
    int a[10] = {9,8,20,15,13,17,16,24,21,26};
    for(int i = 0; i < 10; i++)
        bSearchTree.insertNode( a[i] );
    cout<<"前序为:   ";
    bSearchTree.preOrder( bSearchTree.getRoot() );
    cout<<endl<<"中序为:   ";
    bSearchTree.inOrder( bSearchTree.getRoot() );
    cout<<endl<<"后序为:   ";
    bSearchTree.postOrder( bSearchTree.getRoot() );
    cout<<endl;
    cout<<"输入要查找的节点:";
    cin>>temp;
    BinarySearchTreeNode<int> ** m = NULL;
    BinarySearchTreeNode<int> * p = bSearchTree.getRoot();
    m = bSearchTree.search( p,temp );
    if( *m )
        cout<<(*m)->data<<endl;
    else
        cout<<"没有找到"<<endl;
    cout<<"输入要复制删除的节点:  ";
    cin>>temp;

    bSearchTree.deleteByCopying( bSearchTree.search(p,temp) );
    cout<<"复制删除"<<temp<<"节点后的前序和中序: "<<endl;
    bSearchTree.preOrder( bSearchTree.getRoot());
    cout<<endl;
    bSearchTree.inOrder( bSearchTree.getRoot() );
    cout<<endl;

    cout<<"输入要合并删除的节点:  ";
    cin>>temp;

    bSearchTree.deleteByMerging( bSearchTree.search(p,temp) );
    cout<<"合并删除"<<temp<<"节点后的前序和中序: "<<endl;
    bSearchTree.preOrder( bSearchTree.getRoot());
    cout<<endl;
    bSearchTree.inOrder( bSearchTree.getRoot() );
    cout<<endl;
    return 0;
}

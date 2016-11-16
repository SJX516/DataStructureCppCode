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
    cout<<"ǰ��Ϊ:   ";
    bSearchTree.preOrder( bSearchTree.getRoot() );
    cout<<endl<<"����Ϊ:   ";
    bSearchTree.inOrder( bSearchTree.getRoot() );
    cout<<endl<<"����Ϊ:   ";
    bSearchTree.postOrder( bSearchTree.getRoot() );
    cout<<endl;
    cout<<"����Ҫ���ҵĽڵ�:";
    cin>>temp;
    BinarySearchTreeNode<int> ** m = NULL;
    BinarySearchTreeNode<int> * p = bSearchTree.getRoot();
    m = bSearchTree.search( p,temp );
    if( *m )
        cout<<(*m)->data<<endl;
    else
        cout<<"û���ҵ�"<<endl;
    cout<<"����Ҫ����ɾ���Ľڵ�:  ";
    cin>>temp;

    bSearchTree.deleteByCopying( bSearchTree.search(p,temp) );
    cout<<"����ɾ��"<<temp<<"�ڵ���ǰ�������: "<<endl;
    bSearchTree.preOrder( bSearchTree.getRoot());
    cout<<endl;
    bSearchTree.inOrder( bSearchTree.getRoot() );
    cout<<endl;

    cout<<"����Ҫ�ϲ�ɾ���Ľڵ�:  ";
    cin>>temp;

    bSearchTree.deleteByMerging( bSearchTree.search(p,temp) );
    cout<<"�ϲ�ɾ��"<<temp<<"�ڵ���ǰ�������: "<<endl;
    bSearchTree.preOrder( bSearchTree.getRoot());
    cout<<endl;
    bSearchTree.inOrder( bSearchTree.getRoot() );
    cout<<endl;
    return 0;
}

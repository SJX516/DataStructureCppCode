#include <iostream>
#include <string>
#include <stack>
using namespace std;

class BinaryTreeNode
{
    friend class BinaryTree;
private:
    char data;
    BinaryTreeNode * pLeftChild;
    BinaryTreeNode * pRightChild;
public:
    BinaryTreeNode()
    { pLeftChild = NULL; pRightChild = NULL; }

    BinaryTreeNode(const char& ele)
    {
        data = ele;
    }
    char getValue() const
    {
        return data;
    }

    bool isLeafNode()
    {
        if( pLeftChild == NULL && pRightChild == NULL )
            return true;
        return false;
    }
};

class BinaryTree
{
private:
    BinaryTreeNode * pRoot;
public:

    BinaryTree( BinaryTreeNode * temp = NULL )
    { pRoot = temp; }

    ~BinaryTree(){}

    BinaryTreeNode *  getRoot()
    {
        return pRoot;
    }

    void setRoot( BinaryTreeNode * temp )
    {
        pRoot = temp;
    }

    void preOrder(BinaryTreeNode * root)
    {
        if( root )
        {
            cout<<root->getValue();
            preOrder( root->pLeftChild );
            preOrder( root->pRightChild );
        }
    }
    void inOrder(BinaryTreeNode * root)
    {
        if( root )
        {
            inOrder( root->pLeftChild );
            cout<<root->getValue();
            inOrder( root->pRightChild );
        }
    }
    void postOrder(BinaryTreeNode * root)
    {
        if( root )
        {
            postOrder( root->pLeftChild );
            postOrder( root->pRightChild );
            cout<<root->getValue();
        }
    }

    BinaryTreeNode * buildTreeInPost( string  in,string & post )
    {
        if( in == "")
            return NULL;
        int k = 0;
        BinaryTreeNode * temp;
        temp = new BinaryTreeNode( post[in.size()-1] );
        while( post[ in.size()-1 ] != in[k] )
            k++;
        post.erase( in.size()-1 ,1);
    //  cout<<"in   "<<in.substr(0,k)<<"    post   "<<post<<endl;
    //  cout<<"in   "<<in.substr(k+1,in.size()-k-1)<<"    post   "<<post<<endl;
        temp->pLeftChild = buildTreeInPost( in.substr(0,k), post );
        temp->pRightChild = buildTreeInPost( in.substr( k+1 , in.size()-k-1) , post);

        return temp;
    }

    void countTreeDegree(BinaryTreeNode * root, int & iDu0,int & iDu1, int & iDu2)
    {
        if( root == NULL )
            return;
        if( root->pLeftChild != NULL && root->pRightChild != NULL )
            iDu2++;
        else if( root->pLeftChild == NULL && root->pRightChild == NULL )
            iDu0++;
        else
            iDu1++;
        countTreeDegree(root->pLeftChild,iDu0,iDu1,iDu2);
        countTreeDegree(root->pRightChild,iDu0,iDu1,iDu2);
    }

    int countTreeHeight(BinaryTreeNode * root)
    {
        if( root == NULL )
            return 0;
        else if( root->isLeafNode() )
            return 1;
        else
        {
            int a = countTreeHeight(root->pLeftChild);
            int b = countTreeHeight(root->pRightChild);
            return (a>b?a:b) + 1;
        }
    }

    int countTreeWidth(BinaryTreeNode * root)
    {
        if ( root == NULL ) return 0;
        else
        {
            BinaryTreeNode * Q[30];
            int front=1, rear=1, last=1;
            int temp=0, maxw=0;
            Q[rear] = root;
            while(front <= last)
            {
                BinaryTreeNode * p = Q[front++]; temp++;
                if (p->pLeftChild != NULL ) Q[++rear]=p->pLeftChild;
                if (p->pRightChild != NULL ) Q[++rear]=p->pRightChild;
                if (front>last)
                {
                    last=rear;
                    if(temp>maxw) maxw=temp;
                    temp=0;
                }

            }
            return maxw;
        }
    }

    void countTreeMax(BinaryTreeNode * root ,char & max)
    {
        if( root != NULL )
        {
            max = root->data > max? root->data:max;
            countTreeMax( root->pLeftChild ,max);
            countTreeMax( root->pRightChild,max);
        }
    }

    void changeTreeLRChild( BinaryTreeNode * root )
    {
        if(root != NULL )
        {
            BinaryTreeNode * temp;
            temp = root->pLeftChild;
            root->pLeftChild = root->pRightChild;
            root->pRightChild = temp;
            changeTreeLRChild(root->pLeftChild);
            changeTreeLRChild(root->pRightChild);
        }
    }

    void deleteTreeAllLeaf( BinaryTreeNode ** root )
    {
        if( (*root) != NULL )
        {
            if( !(*root)->isLeafNode() )
            {
                deleteTreeAllLeaf( &(*root)->pLeftChild);
                deleteTreeAllLeaf( &(*root)->pRightChild);
            }
            else
                *root = NULL;
        }
    }

//    void deleteTreeAllLeaf( BinaryTreeNode *& root )
//    {
//        if( (root) != NULL )
//        {
//            if( !(root)->isLeafNode() )
//            {
//                deleteTreeAllLeaf( (root)->pLeftChild);
//                deleteTreeAllLeaf( (root)->pRightChild);
//            }
//            else
//                root = NULL;
//        }
//    }

};


int main()
{
    BinaryTree tree;
    string sA,sB;
    sA = "dgbaecf";
    sB = "gdbefca";
    tree.setRoot( tree.buildTreeInPost(sA,sB) );
    cout<<"中序为：  ";
    tree.inOrder( tree.getRoot() );
    cout<<endl;
    int a = 0,b = 0,c = 0;
    tree.countTreeDegree(tree.getRoot(),a,b,c);
    cout<<"度为0:   "<<a<<"    度为1:   "<<b<<"   度为2:   "<<c<<endl;
    cout<<"高度为:  "<<tree.countTreeHeight( tree.getRoot() )<<endl;
    cout<<"宽度为:  "<<tree.countTreeWidth( tree.getRoot() )<<endl;
    char max = 'Z';
    tree.countTreeMax( tree.getRoot() ,max);
    cout<<"最大元素的值为:   "<<max<<endl;
    tree.changeTreeLRChild( tree.getRoot() );
    cout<<"交换后中序:    ";
    tree.inOrder( tree.getRoot() );
    cout<<endl<<"交换后前序:    ";
    tree.preOrder( tree.getRoot() );
    cout<<endl;
    BinaryTreeNode * temp = tree.getRoot();
    tree.deleteTreeAllLeaf( &temp );
    cout<<"删除后中序:    ";
    tree.inOrder( tree.getRoot() );
    cout<<endl;
    return 0;
}

#ifndef _B_T_H
#define _B_T_H

#include "BinaryTreeNode.h"
#include <string>
#include <stack>
#include <queue>
using namespace std;

class BinaryTree
{
private:
    BinaryTreeNode * pRoot;
public:
    BinaryTree( BinaryTreeNode * temp = NULL )
    { pRoot = temp; }

    ~BinaryTree(){}
    bool isEmpty() const;

    BinaryTreeNode *  getRoot()
    {
        return pRoot;
    }

    void setRoot( BinaryTreeNode * temp )
    {
        pRoot = temp;
    }

    BinaryTreeNode * getParent(BinaryTreeNode * current) const;
    BinaryTreeNode * getLeftBrother(BinaryTreeNode * current) const;
    BinaryTreeNode * getRightBrother(BinaryTreeNode * current) const;

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

    void preOrderWithoutRecusion( BinaryTreeNode * root )
    {
        stack<BinaryTreeNode *> sNodeStack;
        BinaryTreeNode * pointer = root;
        while( !sNodeStack.empty() || pointer != NULL )
        {
            cout<<pointer->getValue();
            if( pointer->pRightChild )
                sNodeStack.push( pointer->pRightChild );
            if( pointer->pLeftChild )
                pointer = pointer->pLeftChild;
            else
            {
                if( !sNodeStack.empty() )
                {
                    pointer = sNodeStack.top();
                    sNodeStack.pop();
                }
                else
                    pointer = NULL;
            }
        }
    }

    void inOrderWithoutRecusion( BinaryTreeNode * root )
    {
        stack<BinaryTreeNode *> sNodeStack;
        BinaryTreeNode * pointer = root;
        while( !sNodeStack.empty() || pointer )
        {
            if( pointer )
            {
                sNodeStack.push( pointer );
                pointer = pointer->pLeftChild;
            }
            else
            {
                pointer = sNodeStack.top();
                cout<<pointer->getValue();
                sNodeStack.pop();
                pointer = pointer->pRightChild;
            }

        }
    }

    void postOrderWithoutRecusion( BinaryTreeNode * root )
    {
        stack<BinaryTreeNode *> sNodeStack;
        BinaryTreeNode * pointer = root;
        BinaryTreeNode * temp = root;
        while( pointer )
        {
            for( ; pointer->pLeftChild != NULL ; pointer = pointer->pLeftChild )
                sNodeStack.push( pointer );
            while( pointer != NULL && ( pointer->pRightChild == NULL || pointer->pRightChild == temp) )
            {
                cout<<pointer->getValue();
                temp = pointer;
                if( sNodeStack.empty() )
                    return ;
                pointer = sNodeStack.top();
                sNodeStack.pop();
            }
            sNodeStack.push(pointer);
            pointer = pointer->pRightChild;
        }


    }

    void completeBinaryTree(BinaryTreeNode *root)
    {
        if(root == NULL)
           cout<<"是完全二叉树"<<endl;
        queue<BinaryTreeNode *> Q;
        Q.push(root);
        int flag=0;
        while(!Q.empty())
        {
            if(!Q.front())
               flag=1;
            else if(flag)
            {
                cout<<"不是完全二叉树"<<endl;
                return ;
            }
            else
            {
                Q.push(Q.front()->pLeftChild);
                Q.push(Q.front()->pRightChild);
            }
            Q.pop();
        }
        cout<<"是完全二叉树"<<endl;
        return;
    }






    void buildTreePreIn(BinaryTreeNode * temp,string pre,string in,bool bIsLeft)
    {
        if( !temp )
        {

            pRoot = new BinaryTreeNode( pre[0] );
            string tempIn,tempPre;
            int inNum = in.find( pre[0] , 0 );
            tempIn = in.substr( 0 , inNum );
            tempPre = pre.substr( 1 , inNum );
         //   cout<<"tempIn   "<<tempIn<<"   tempPre   "<<tempPre<<endl;
            buildTreePreIn( pRoot , tempPre , tempIn ,true);
            tempPre = pre.substr( inNum+1 , pre.size()-inNum-1 );
            tempIn = in.substr( inNum+1 , in.size()-inNum-1 );
         //   cout<<"tempIn   "<<tempIn<<"   tempPre   "<<tempPre<<endl;
            buildTreePreIn( pRoot , tempPre , tempIn, false );

        }
        else if( pre == "" && in == "" )
        {
            if( bIsLeft )
                temp->pLeftChild = NULL;
            else
                temp->pRightChild = NULL;
        }
        else if( pre != "" || in != "" )
        {
            if( bIsLeft )
                temp = temp->pLeftChild = new BinaryTreeNode( pre[0] );
            else
                temp = temp->pRightChild = new BinaryTreeNode( pre[0] );
            string tempIn,tempPre;

            int inNum = in.find( pre[0] , 0 );
            tempIn = in.substr( 0 , inNum );
            if( pre.size() == 1 )
                tempPre = "";
            else
                tempPre = pre.substr( 1 , inNum );

         //   cout<<"tempIn   "<<tempIn<<"   tempPre   "<<tempPre<<endl;
            buildTreePreIn( temp, tempPre , tempIn ,true);

            if( pre.size() == inNum+1 )
                tempPre = "";
            else
                tempPre = pre.substr( inNum+1 , pre.size()-inNum-1 );

            if( in.size() == inNum+1 )
                tempIn = "";
            else
                tempIn = in.substr( inNum+1 , in.size()-inNum-1 );

           // cout<<"tempIn   "<<tempIn<<"   tempPre   "<<tempPre<<endl;
          //  temp->pRightChild = new BinaryTreeNode( tempPre[0] );
            buildTreePreIn( temp, tempPre , tempIn ,false);

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
};

#endif


//    BinaryTreeNode<T>* preinBuild(string &pre,string in )
//    {
//        if(pre=="" || in=="")
//        {
//            return NULL;
//        }
//        int m=0;
//        BinaryTreeNode<T> *tmp;
//        tmp=new BinaryTreeNode<T>;
//        tmp->info=pre[0];
//        while(pre[0]!=in[m])
//           m++;
//        pre.erase(0,1);
//        tmp->leftChild=preinBuild(pre,in.substr(0,m));
//        tmp->rightChild=preinBuild(pre,in.substr(m+1,in.size()-m-1));
//        return tmp;
//    }





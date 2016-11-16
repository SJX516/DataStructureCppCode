#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;
template <class T>
class BinaryTree;
template <class T>
class BinaryTreeNode  {
friend class BinaryTree<T>;
public:
     T  info;			            // 二叉树结点数据域
     BinaryTreeNode<T> * leftChild;
     BinaryTreeNode<T> * rightChild;
     BinaryTreeNode<T> * parent;
public:
     BinaryTreeNode() {leftChild = NULL; rightChild = NULL;parent = NULL; }  	                         // 缺x`省构造函数
     BinaryTreeNode(const T& ele);         // 给定数据的构造函数
     BinaryTreeNode(const T& ele,BinaryTreeNode<T> *l, BinaryTreeNode<T> *r);     // 子树构造结点
};
template <class T>
class BinaryTree  {
private:
	BinaryTreeNode<T>* root; // 二叉树根结点
public:
int count;
    BinaryTree() {root = NULL;count=0;}		        // 构造函数
    ~BinaryTree() {Destroy(root);}    // 析构函数
    void Destroy(BinaryTreeNode<T> *root)
    {
    }
    bool isEmpty() const// 判定二叉树是否为空树
    {
        if(root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    BinaryTreeNode<T>*   Getroot(){return root;};
    BinaryTreeNode<T>* preinBuild(string &pre,string in)
    {
        if(pre=="" || in=="")
        {
            return NULL;
        }
        int m=0;
        BinaryTreeNode<T> *tmp;
        tmp=new BinaryTreeNode<T>;
        tmp->info=pre[0];
        while(pre[0]!=in[m])
           m++;
        pre.erase(0,1);
        tmp->leftChild=preinBuild(pre,in.substr(0,in.find(in[m],0)));
        tmp->rightChild=preinBuild(pre,in.substr(in.find(in[m],0)+1,in.size()));
        return tmp;
    }
    void buildPreIn(string &pre,string in)
    {
        root=preinBuild(pre,in);
    }
    int Du_1(BinaryTreeNode<T> *root,int &count)
    {
        if(root == NULL)
        {
            return count;
        }
        else
        {
            if((root->leftChild!= NULL && root->rightChild==NULL) || (root->leftChild==NULL && root->rightChild!= NULL) )
               count++;
            Du_1(root->leftChild,count);
            Du_1(root->rightChild,count);
        }
        return count;
    }
    int Du_2(BinaryTreeNode<T> *root,int &count)
    {
        if(root == NULL)
        {
            return count;
        }
        else
        {
            if(root->leftChild != NULL && root->rightChild!=NULL )
               count++;
            Du_2(root->leftChild,count);
            Du_2(root->rightChild,count);
        }
        return count;
    }
    int Du_0(BinaryTreeNode<T> *root,int &count)
    {
        if(root == NULL)
        {
            return count;
        }
        else
        {
            if(root->leftChild == NULL && root->rightChild==NULL )
               count++;
            Du_0(root->leftChild,count);
            Du_0(root->rightChild,count);
        }
        return count;
    }
    int Height(BinaryTreeNode<T> *root)
    {
        int dep1,dep2;
        if(root==NULL)
           return 0;
        else
        {
            dep1=Height(root->leftChild);
            dep2=Height(root->rightChild);
            return dep1>dep2?dep1+1:dep2+1;
        }
    }
    int Width(BinaryTreeNode<T> *root)
    {
        if(root->leftChild==NULL&&root->rightChild==NULL)
            return 1;
        else
        {
            int l=0,r=0;
            if(root->leftChild!=NULL)
                l=Width(root->leftChild);
            if(root->rightChild!=NULL)
                r=Width(root->rightChild);
            return l+r;
        }
    }
    char Max(BinaryTreeNode<T> *root)
    {
        static char temp;
        if(root!=NULL)
        {
            if(root->info>temp)
                temp=root->info;
            Max(root->leftChild);
            Max(root->rightChild);
        }
        return temp;
    }
    int Change(BinaryTreeNode<T> *root)
    {
        BinaryTreeNode<T> *temp = NULL;
        if(root->leftChild == NULL && root->rightChild == NULL)
            return;
        else
        {
            temp = root->leftChild;
            root->leftChild = root->rightChild;
            root->rightChild = temp;
        }
        if(root->leftChild)
           Change(root->leftChild);
        if(root->rightChild)
           Change(root->rightChild);
    }
    void Delete(BinaryTreeNode<T> *root)
    {
        if(root!=NULL)
        {
            Delete(root->leftChild);
            Delete(root->rightChild);
            delete root;
        }
    }
    void preOrder(BinaryTreeNode<T> *root)
    {
        if(root!=NULL)
        {
            cout<<root->info<<" ";
            preOrder(root->leftChild);
            preOrder(root->rightChild);
        }
    }
    int Width1(BinaryTreeNode<T> *root)  //递归求宽度
    {
        int static n[20] = {0};//向量存放各层结点数
        int static i=0;
        int static max=0;//最大宽度
        if(root != NULL)
        {
            i++;
            n[i]++;
            if (n[i] > max) max = n[i];
            Width1(root->leftChild);
            Width1(root->rightChild);
            i--;
            return max;
        }
        return 0;
    }
};
int main()
{
    BinaryTree<char> T;
    string pre,in,pre1,in1;
    pre="ABCDEFHI";
    in="DCEBAHFI";
    pre1="ABDGCEF";
    in1="DGBAECF";
    int count1=0,count2=0,count3=0;
    T.buildPreIn(pre,in);
    cout<<"DU 1:"<<T.Du_1(T.Getroot(),count1);
    cout<<endl<<"DU 2:"<<T.Du_2(T.Getroot(),count2);
    cout<<endl<<"DU 0:"<<T.Du_0(T.Getroot(),count3);
    cout<<endl<<"Height:"<<T.Height(T.Getroot());
    cout<<endl<<"Width:"<<T.Width1(T.Getroot());
    cout<<endl;
    cout<<"Max:"<<T.Max(T.Getroot());
    cout<<endl<<"Delete:";
    T.Delete(T.Getroot());
    cout<<"Delete complete";
    return 0;
}

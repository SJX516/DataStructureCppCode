#ifndef _B_T_N_H
#define _B_T_N_H

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

    BinaryTreeNode(const char& ele, BinaryTreeNode * l,BinaryTreeNode * r);

    BinaryTreeNode * getLeftChild() const;

    BinaryTreeNode * getRightChild() const;

    void setLeftChild(BinaryTreeNode * l);

    void setRightChild(BinaryTreeNode * r);

    char getValue() const
    {
        return data;
    }
    void setValue(const char& val);
    bool isLeaf() const;
};
#endif // _B_T_N_H

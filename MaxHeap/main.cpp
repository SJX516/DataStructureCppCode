#include <iostream>
#include "MaxHeap.h"
using namespace std;



int main()
{
    MaxHeap maxheap(15);
    maxheap.printTree();
    int c = 90;
    maxheap.insertNum(c);
    maxheap.printTree();
    maxheap.removeMax();
    maxheap.printTree();
    maxheap.remove(3,c);
    maxheap.printTree();
    return 0;

}














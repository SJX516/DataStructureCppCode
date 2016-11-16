#include <iostream>
using namespace std;
#include "AdjGraph.h"

int main()
{
    AdjGraph graph(8);
    graph.setEdge(0,1,1);
    graph.setEdge(0,2,1);
    graph.setEdge(1,3,1);
    graph.setEdge(1,4,1);
    graph.setEdge(3,7,1);
    graph.setEdge(4,7,1);
    graph.setEdge(2,5,1);
    graph.setEdge(2,6,1);
    graph.printAdj();
    graph.DFSTraverse();
    graph.BFSTraverse();



}

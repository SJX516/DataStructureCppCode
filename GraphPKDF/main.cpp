#include <iostream>
using namespace std;
#include "AdjGraph.h"

int main()
{
//    AdjGraph graph(6);
//    graph.setNoPositionEdge(0,1,6);
//    graph.setNoPositionEdge(2,0,1);
//    graph.setNoPositionEdge(3,0,5);
//    graph.setNoPositionEdge(2,1,5);
//    graph.setNoPositionEdge(3,2,5);
//    graph.setNoPositionEdge(1,4,3);
//    graph.setNoPositionEdge(2,4,6);
//    graph.setNoPositionEdge(4,5,6);
//    graph.setNoPositionEdge(2,5,4);
//    graph.setNoPositionEdge(3,5,2);
//    graph.printAdj();
//    Edge * m = graph.Prim(0);
//    for(int i = 0; i<graph.iVertexNum-1; i++)
//        m[i].print();

    AdjGraph graph(6);
    graph.setEdge(0,1,2);
    graph.setEdge(0,5,3);
    graph.setEdge(1,2,3);
    graph.setEdge(1,3,2);
    graph.setEdge(2,0,4);
    graph.setEdge(2,4,4);
    graph.setEdge(4,1,1);
    graph.setEdge(4,5,3);
    graph.setEdge(3,0,1);
    graph.setEdge(3,4,1);
    graph.setEdge(5,2,2);
    graph.setEdge(5,3,5);
    graph.printAdj();
    cout<<endl;
    graph.Dijkstra(5);

//
//    AdjGraph graph(3);
//    graph.setEdge(0,1,10);
//    graph.setEdge(1,0,9);
//    graph.setEdge(0,2,5);
//    graph.setEdge(2,0,2);
//    graph.setEdge(1,2,6);
//    graph.setEdge(2,1,13);
//    graph.printAdj();
//    cout<<endl;
//    graph.Floyd();




}

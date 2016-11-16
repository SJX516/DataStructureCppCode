#ifndef _ADJGRAPH_H
#define _ADJGRAPH_H

#include "Graph.h"
#include <iostream>
#include <queue>
using namespace std;

class AdjGraph:public Graph
{
private:
    int ** ppMatrix;   //指向邻接矩阵的指针
public:

    AdjGraph( int num ):Graph( num )
    {
        int i,j;
        ppMatrix = (int **) new int *[num];
        for( i = 0; i < num; i++)
            ppMatrix[i] = new int [num];
        for( i = 0; i < num; i++)
            for( j = 0; j < num; j++)
                ppMatrix[i][j] = 0;
    }
    ~AdjGraph()
    {
        for(int i = 0; i < iVertexNum; i++)
            delete [] ppMatrix[i];
        delete [] ppMatrix;
    }
    Edge getFirstEdge(int oneVertex)
    {
        Edge tempEdge;
        tempEdge.iStart = oneVertex;
        for(int i = 0; i < iVertexNum; i++)
        {
            if( ppMatrix[oneVertex][i] != 0)
            {
                tempEdge.iEnd = i;
                tempEdge.iWeight = ppMatrix[oneVertex][i];
                break;
            }
        }
        return tempEdge;
    }

    Edge getNextEdge( Edge oneEdge )
    {
        Edge tempEdge;
        tempEdge.iStart = oneEdge.iStart;
        for(int i = oneEdge.iEnd+1; i < iVertexNum;i++)
        {
            if(ppMatrix[oneEdge.iStart][i] != 0)
            {
                tempEdge.iEnd = i;
                tempEdge.iWeight = ppMatrix[oneEdge.iStart][i];
                break;
            }
        }
        return tempEdge;
    }

    void setEdge(int start,int end, int weight)
    {
        if( ppMatrix[start][end] == 0)
            iEdgeNum++;
        ppMatrix[start][end] = weight;
    }

    void delEdge( int start ,int end)
    {
        if( ppMatrix[start][end] != 0)
            iEdgeNum--;
        ppMatrix[start][end] = 0;
    }
    void printAdj()
    {
        for(int i = 0; i<iVertexNum; i++ )
        {
            for(int j = 0; j<iVertexNum; j++)
                cout<<ppMatrix[i][j]<<"   ";
            cout<<endl;
        }
    }

    void DFS(int v)
    {
        pVisited[v] = true;
        cout<<v<<" ";
        for( Edge e = getFirstEdge(v); isEdge(e); e = getNextEdge(e) )
        {
            if( !pVisited[getEndVertex(e)] )
                DFS( getEndVertex(e) );
        }
    }

    void DFSTraverse()
    {
        for(int i = 0; i < iVertexNum; i++)
            pVisited[i] = false;
        for(int i = 0; i < iVertexNum; i++)
        {
            if( !pVisited[i] )
                DFS(i);
        }
        cout<<endl;
    }

    void BFS(int v)
    {
        queue<int> Q;
        pVisited[v] = true;
        cout<<v<<" ";
        Q.push(v);
        while( !Q.empty() )
        {
            v = Q.front();
            Q.pop();
            for(Edge e = getFirstEdge(v); isEdge(e); e = getNextEdge(e) )
            {
                if( !pVisited[getEndVertex(e)] )
                {
                    cout<<getEndVertex(e)<<" ";
                    pVisited[getEndVertex(e)] = true;
                    Q.push(getEndVertex(e));
                }
            }
        }
    }

    void BFSTraverse()
    {
        int v;
        for( v = 0; v < iVertexNum; v++)
            pVisited[v] = false;
        for( v = 0; v < iVertexNum; v++)
        {
            if( !pVisited[v] )
                BFS(v);

        }
        cout<<endl;
    }



};

#endif // _ADJGRAPH_H















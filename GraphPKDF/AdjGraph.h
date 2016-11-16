
#ifndef _ADJGRAPH_H
#define _ADJGRAPH_H

#include "Graph.h"
#include <iostream>
#include <iomanip>
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

    void setNoPositionEdge(int a,int b,int weight)
    {
        if( ppMatrix[a][b] == 0)
        {
            iEdgeNum++;
            ppMatrix[a][b] = weight;
        }
        if( ppMatrix[b][a] == 0)
        {
            iEdgeNum++;
            ppMatrix[b][a] = weight;
        }
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
                cout<<setw(4)<<ppMatrix[i][j];
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

    Edge * Prim(int s)
    {
        int i,j;
        Edge * MST;
        int * nearest;  //nearest[i]表示生成树中点到点i的最小边权值
        int * neighbor; //neighbor[i]表示生成树中与i点最近的编号，-1表示i点已在生成树中
        nearest = new int [iVertexNum];
        neighbor = new int [iVertexNum];
        MST = new Edge[iVertexNum-1];
        for( i = 0; i < iVertexNum; i++ )
        {
            neighbor[i] = s;
            nearest[i] = 1000;
        }
        for( Edge e = getFirstEdge(s); isEdge(e); e = getNextEdge(e) )
            nearest[getEndVertex(e)] = e.iWeight;
        neighbor[s] = -1;
        for( i = 1; i < iVertexNum; i++)
        {
            int min = 100;
            int v = -1;
            for( j = 0; j < iVertexNum; j++)
            {
                if( nearest[j] < min && neighbor[j] > -1 )
                {
                    min = nearest[j];
                    v = j;
                }
            }
            if( v >= 0 )
            {
                Edge tempEdge(neighbor[v],v,nearest[v]);
                neighbor[v] = -1;
                MST[i-1] = tempEdge;
                for(Edge e = getFirstEdge(v) ; isEdge(e); e = getNextEdge(e) )
                {
                    int u = e.iEnd;
                    if( neighbor[u] != -1 && nearest[u] > e.iWeight )
                    {
                        neighbor[u] = v;
                        nearest[u] = e.iWeight;
                    }

                }
            }
        }
        delete []neighbor;
        delete []nearest;
        return MST;

    }

    void Dijkstra(int s )
    {
        int i,j;
        int * D = new int[iVertexNum];
        int * Path = new int[iVertexNum];
        for( i = 0; i < iVertexNum; i++)
        {
            pVisited[i] = false;
            D[i] = 1000;
            Path[i] = s;
        }
        pVisited[s] = true;
        D[s] = 0;
        Path[s] = s;
        for( Edge e = getFirstEdge(s); isEdge(e); e = getNextEdge(e) )
            D[e.iEnd] = e.iWeight;
        for( i = 0; i < iVertexNum; i++)
        {
            int min = 1000;
            int k = 0;
            for( j = 1; j < iVertexNum; j++ )
            {
                if( !pVisited[j] && min > D[j] )
                {
                    min = D[j];
                    k = j;
                }
            }
            pVisited[k] = true;
            for( Edge e = getFirstEdge(k); isEdge(e); e = getNextEdge(e) )
            {
                int end = e.iEnd;
                if( !pVisited[end] && D[end] > (D[k] + e.iWeight) )
                {
                    D[end] = D[k] + e.iWeight;
                    Path[end] = k;
                }
            }
        }
        for( j = 0 ; j < iVertexNum; j++)
        {
            int k = j;
            while( Path[k] != k )
            {
                cout<<k+1<<"<-";
                k = Path[k];
            }
            cout<<k+1;
            cout<<endl;
        }
    }

    void Floyd( )
    {
        int i,j,v;
        int Adj[iVertexNum][iVertexNum];
        int Path[iVertexNum][iVertexNum];
        int n = iVertexNum;
        for( i = 0; i < n; i++ )
        {
            for( j = 0; j < n; j++ )
            {
                if( i == j )
                {
                    Adj[i][j] = 0; Path[i][j] = i;
                }
                else
                {
                    Adj[i][j] = 1000; Path[i][j] = i;
                }
            }
        }
        for( v = 0; v < n; v++ )
        {
            for( Edge e = getFirstEdge(v); isEdge(e); e = getNextEdge(e) )
            {
                Adj[v][e.iEnd] = e.iWeight;
            }
        }
        for( v = 0; v < n; v++ )
            for( i = 0; i < n; i++ )
                for( j = 0; j < n; j++ )
                    if( Adj[i][j] > ( Adj[i][v]+Adj[v][j]) )
                    {
                        Adj[i][j] = Adj[i][v]+Adj[v][j];
                        Path[i][j] = v;
                    }

        for( i = 0; i < n; i++)
        {
            for( j = 0; j < n; j++)
                cout<<setw(4)<<Adj[i][j];
            cout<<endl;
        }
        cout<<endl;
        for( i = 0; i < n; i++)
        {
            for( j = 0; j < n; j++)
                cout<<setw(4)<<Path[i][j];
            cout<<endl;
        }
    }

};

#endif // _ADJGRAPH_H















#include<iostream>
#include<queue>
using namespace std;

class Edge
{
public:
    int iStart,iEnd;
    int iWeight;
	Edge()
	{
	    iStart = iEnd = iWeight = -1;
	}
	Edge(int st,int en,int w);  //构造边（st，en），权重为w
	void print()
	{
	    cout<<"Edge from "<<iStart<<" to "<<iEnd<<" weight is "<<iWeight<<endl;
	}
	bool operator > (Edge oneEdge);
	bool operator < (Edge oneEdge);   //通过权重来比较边的大小
	~Edge(){}
};

class Graph
{
public:
    int iVertexNum,iEdgeNum;
    bool * pVisited;     //false代表没有被访问

	Graph(int num)
	{
	    iVertexNum = num;
	    iEdgeNum = 0;
	    pVisited = new bool[iVertexNum];
	    for(int i = 0;i < iVertexNum; i++)
	    {
	        pVisited[i] = false;
	    }
	}
	~Graph()
	{
	    delete [] pVisited;
	}
	virtual Edge getFirstEdge(int oneVertex) = 0;
	virtual Edge getNextEdge( Edge oneEdge ) = 0;
	int getVertexNum(){ return iVertexNum; }
	int getEdgesNum() { return iEdgeNum; }
	bool isEdge( Edge oneEdge )
	{
	    if( oneEdge.iWeight > 0 && oneEdge.iEnd >= 0 )
            return true;
        else
            return false;
	}
	int getStartVertex( Edge oneEdge ) { return oneEdge.iStart; }
	int getEndVertex( Edge oneEdge ) { return oneEdge.iEnd; }
	int getWeight( Edge oneEdge ) { return oneEdge.iWeight; }

	virtual void setEdge( int start,int end,int weight) = 0;
	virtual void delEdge( int start,int end) = 0;

};


class AdjGraph:public Graph
{
private:

public:
    int ** ppMatrix;   //指向邻接矩阵的指针
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
    void delNoPositionEdge(int a,int b)
    {
        if( ppMatrix[a][b] != 0)
        {
            iEdgeNum--;
            ppMatrix[a][b] = 0;
        }
        if( ppMatrix[b][a] != 0)
        {
            iEdgeNum--;
            ppMatrix[b][a] = 0;
        }

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


    int  DFSJudgeHaveLoop(int v,bool judge)
    {
        static int lastVisited = -1;
        pVisited[v] = true;
        //cout<<v<<" ";
        if( judge )
            lastVisited = -1;
        for( Edge e = getFirstEdge(v); isEdge(e); e = getNextEdge(e) )
        {
            if( !pVisited[e.iEnd] )
            {
                lastVisited = v;
                return DFSJudgeHaveLoop( e.iEnd ,false);
            }
            else if( pVisited[e.iEnd] && lastVisited != e.iEnd && lastVisited >= 0)
            {
                return e.iEnd;
            }
        }
        return -1;
    }

    int DFSTraverseJudgeHaveLoop()
    {
        for(int i = 0; i < iVertexNum; i++)
            pVisited[i] = false;
        for(int i = 0; i < iVertexNum; i++)
        {
            if( !pVisited[i] )
            {
                int n = DFSJudgeHaveLoop(i,true);
                if( n >= 0 )
                    return n;
            }
        }
        return -1;
    }
};


void tearCycleMethod(AdjGraph & G)
{
    int n = G.DFSTraverseJudgeHaveLoop();
    while( n >= 0 )
    {
        Edge e;
        queue<Edge> Q;
        bool judge = false;
        for( e = G.getFirstEdge(n); G.isEdge(e); e = G.getNextEdge(e) )
        {
            int last = n;
            for(Edge c = e; G.isEdge(c) ;  )       //找到以n为起点的第一个环
            {
                last = c.iStart;
                if( c.iEnd == n )
                {
                    Q.push( c );
                    judge = true;
                    break;
                }
                else
                {
                    Q.push( c );
                }
                for( c = G.getFirstEdge(c.iEnd) ; G.isEdge(c) &&  c.iEnd == last; c = G.getNextEdge(c) );
            }
            if( !judge )
            {
                while( !Q.empty() )
                    Q.pop();
            }
            else
                break;
        }

        Edge maxEdge;
        while( !Q.empty() )
        {
            if( Q.front().iWeight > maxEdge.iWeight )
                maxEdge = Q.front();
            Q.pop();
        }
        cout<<"del:  ";
        maxEdge.print();
        cout<<endl;
        G.delNoPositionEdge(maxEdge.iStart,maxEdge.iEnd);
        //删除这个环里面权最大的边
        n = G.DFSTraverseJudgeHaveLoop();

    }

}


void printADJ( AdjGraph & G )
{
    for(int i = 0; i < G.iVertexNum; i++ )
    {
        for( int j = i; j < G.iVertexNum; j++)
        {
            if(G.ppMatrix[i][j] != 0 )
            {
                cout<<"Edge from "<<i<<" to "<<j<<" weight is "<<G.ppMatrix[i][j]<<endl;
            }
        }
    }
}

int main()
{
//    AdjGraph G(6);
//    G.setNoPositionEdge(0,1,1);
//    G.setNoPositionEdge(0,2,2);
//    G.setNoPositionEdge(0,3,3);
//    G.setNoPositionEdge(2,1,4);
//    G.setNoPositionEdge(2,4,5);
//    G.setNoPositionEdge(4,3,6);
//    G.setNoPositionEdge(3,5,7);
//    G.setNoPositionEdge(5,4,8);
//    G.printAdj();
//    cout<<endl;
//    tearCycleMethod(G);
//    cout<<"最小生成树：  "<<endl;
//    for(Edge e = G.getFirstEdge(0); G.isEdge(e); e = G.getNextEdge(e) )
//    {
//        int last = 0;
//        for(Edge c = e; G.isEdge(c); )
//        {
//            last = c.iStart;
//            c.print();
//            for( c = G.getFirstEdge(c.iEnd) ; G.isEdge(c) &&  c.iEnd == last; c = G.getNextEdge(c) );
//        }
//    }
//    cout<<endl;

//    AdjGraph G(6);
//    G.setNoPositionEdge(0,1,1);
//    G.setNoPositionEdge(0,2,2);
//    G.setNoPositionEdge(0,3,3);
//    G.setNoPositionEdge(2,1,4);
//    G.setNoPositionEdge(2,4,5);
//    G.setNoPositionEdge(4,3,6);
//    G.setNoPositionEdge(3,5,7);
//    G.setNoPositionEdge(5,4,8);
    AdjGraph G(5);
    G.setNoPositionEdge(0,1,1);
    G.setNoPositionEdge(1,2,1);
    G.setNoPositionEdge(2,3,3);
    G.setNoPositionEdge(3,4,1);
    G.setNoPositionEdge(0,4,1);

    G.printAdj();
    cout<<endl;
    tearCycleMethod(G);
    printADJ(G);
    cout<<endl;


}











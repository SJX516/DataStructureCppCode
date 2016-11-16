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
	Edge(int st,int en,int w);  //����ߣ�st��en����Ȩ��Ϊw
	void print()
	{
	    cout<<"Edge from "<<iStart<<" to "<<iEnd<<" weight is "<<iWeight<<endl;
	}
	bool operator > (Edge oneEdge);
	bool operator < (Edge oneEdge);   //ͨ��Ȩ�����ȽϱߵĴ�С
	~Edge(){}
};

class Graph
{
public:
    int iVertexNum,iEdgeNum;
    bool * pVisited;     //false����û�б�����

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
    int ** ppMatrix;   //ָ���ڽӾ����ָ��
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


void TopsortbyQueue(Graph & G)
{
    int i = 0;
    int n = G.getVertexNum();
    int * Indegree = new int[n];
    Edge e;
    for(i = 0; i < n; i++)
	{
	    Indegree[i] = 0;
	    G.pVisited[i] = false;
    }    //��ʼ���������

    for( i = 0; i < n; i++)
    {
        for(e = G.getFirstEdge(i) ; G.isEdge(e) ; e = G.getNextEdge(e))
            Indegree[e.iEnd]++;
    }

    queue<int> Q;                         //��ʼ������
	for(i = 0; i < n; i++)
	{
        if( Indegree[i] == 0 )
            Q.push(i);                  //ͼ�����Ϊ0�Ķ������
    }

    while( !Q.empty() )
    {      //��������л���ͼ�Ķ���
        int V=Q.front();                         //����Ԫ��
        Q.pop();                                 //һ���������
        G.pVisited[V] = true;

       //��e���յ�����ֵ��1
        for( e = G.getFirstEdge(V); G.isEdge(e); e = G.getNextEdge(e) )
        {
            Indegree[e.iEnd]--;
            if( Indegree[e.iEnd] == 0 )
                Q.push( e.iEnd );                   //���Ϊ0�Ķ������
        }
    }
    for( i = 0; i < n; i++ )
    {
        if(G.pVisited[i] == false )
        {
            cout<<"ͼ�л�:  ";     //ͼ�л�
            cout<<i<<"->";
            for( e = G.getFirstEdge(i); G.isEdge(e); e = G.getFirstEdge(e.iEnd) )
            {
                if( e.iEnd == i )
                    break;
                else
                    cout<<e.iEnd<<"->";
            }
            cout<<i;
            break;
        }
    }
}

int main()
{
    AdjGraph G(6);
    G.setEdge(0,1,1);
    G.setEdge(0,2,1);
    G.setEdge(0,3,1);
    G.setEdge(2,1,1);
    G.setEdge(2,4,1);
    G.setEdge(4,3,1);
    G.setEdge(3,5,1);
    G.setEdge(5,4,1);
    G.printAdj();
    cout<<endl;
    TopsortbyQueue(G);
    cout<<endl;


}

















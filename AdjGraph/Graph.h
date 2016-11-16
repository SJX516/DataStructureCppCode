
#ifndef _GRAPH_H
#define _GRAPH_H

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




#endif // _GRAPH_H










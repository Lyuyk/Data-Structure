#pragma once
const int maxWeight = 1000;	//无穷大的值
const int DefaultVertices = 10;	//最大顶点数
template <class T, class E>
class Graph
{
protected:
	int maxVertices;//图中最大顶点数
	int numEdges;//当前边数
	int numVertices;//当前顶点数
	int getVertexPos(T vertex);//给出顶点vertex在图中位置
public:
	Graph(int sz = DefaultVertices) { maxVertices = sz; numEdges = 0; numVertices = 0; };//构造函数
	~Graph() { ; }//析构函数
	bool GraphEmpty() const//判图空否
	{
		return numEdges == 0;
	}
	int NumberOfVertices() { return numVertices; }
	//返回当前顶点数
	int NumberOfEdges() { return numEdges; }
	//返回当前边数
	/*virtual T getValue(int i);	//取顶点i的值
	virtual E getWeight(int v1, int v2); //取边上权值
	virtual int getFirstNeighbor(int v);//取顶点 v 的第一个邻接顶点
	virtual int getNextNeighbor(int v, int w);//取邻接顶点 w 的下一邻接顶点
	virtual bool insertVertex(const T vertex);//插入一个顶点vertex
	virtual bool insertEdge(int v1, int v2, E cost);//插入边(v1,v2), 权为cost
	virtual bool removeVertex(int v);//删去顶点 v 和所有与相关联边
	virtual bool removeEdge(int v1, int v2);//在图中删去边(v1,v2)*/
};

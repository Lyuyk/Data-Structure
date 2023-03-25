#pragma once

#include<iostream>
#include<queue>
#include"Graph.h"
using namespace std;

template <class T, class E>
class GraphMatrix : public Graph<T, E>
{
	//friend istream& operator >> (istream& in, GraphMatrix<T, E>& G);	//输入
	//friend ostream& operator << (ostream& out, GraphMatrix<T, E>& G);	//输出
private:
	T* VerticesList;//顶点表
	E** Edge;//邻接矩阵
	bool* visited;//辅助数组
	int numVertices;//表示结点个数
	int maxVertices;//表示图中最大顶点数
	int numEdges;//当前边数
	void dfs(int v);
public:
	GraphMatrix(int sz = 10);//构造函数
	~GraphMatrix()//析构函数
	{
		delete[]VerticesList;
		delete[]Edge;
	}
	int NumberOfVertices() { return numVertices; }
	T getValue(int i) //取顶点i的值,i不合理返回0
	{
		return i >= 0 && i < numVertices ? VerticesList[i] : 0;
	}
	E getWeight(int v1, int v2)//取边(v1,v2)上权值
	{
		return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;
	}
	int getVertexPos(T vertex)//给出顶点vertex在图中的位置
	{
		for (int i = 0; i < numVertices; i++)if (VerticesList[i] == vertex) return i;
		return -1;
	}
	int getNumVertices() { return numVertices; }
	int getNumEdges() { return numEdges; }
	int getFirstNeighbor(int v);//取顶点 v 的第一个邻接顶点
	int getNextNeighbor(int v, int w);//取 v 的邻接顶点 w 的下一邻接顶点
	//bool insertVertex(const T vertex);//插入顶点vertex
	bool insertEdge(int v1, int v2, E cost, bool judgement);//插入边(v1, v2),权值为cost
	//bool removeVertex (int v);//删去顶点 v 和所有与它相关联的边
	//bool removeEdge(int v1, int v2);//在图中删去边(v1,v2)
	void CreateEdge(bool judgement);//judgement用于判断是否为有向图
	void dfs();
	void bfs();
};

template<class T, class E>
inline void GraphMatrix<T, E>::dfs(int v)
{
	visited[v] = true;
	cout << VerticesList[v] << " ";//访问v结点
	for (int i = 0; i < numVertices; i++)
	{
		if (Edge[v][i] != maxWeight && !visited[i])dfs(i);
	}
}

template <class T, class E>
GraphMatrix<T, E>::GraphMatrix(int sz)//构造函数
{
	if (sz < 10)sz = 10;
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	int i, j;
	VerticesList = new T[maxVertices];//创建顶点表
	visited = new bool[maxVertices];
	Edge = (E**) new E * [maxVertices];
	for (i = 0; i < maxVertices; i++)
		Edge[i] = new int[maxVertices];//邻接矩阵
	for (i = 0; i < maxVertices; i++)	//矩阵初始
		for (j = 0; j < maxVertices; j++)
			Edge[i][j] = (i == j) ? 0 : maxWeight;
};

template<class T, class E>
inline int GraphMatrix<T, E>::getFirstNeighbor(int v)
{
	//给出顶点位置为v的第一个邻接顶点的位置，如果找不到，则函数返回-1
	if (v != -1)
	{
		for (int column = 0; column < numVertices; column++)
			if (Edge[v][column] > 0 && Edge[v][column] < maxWeight)return column;
	}
	return -1;
}

template<class T, class E>
inline int GraphMatrix<T, E>::getNextNeighbor(int v, int w)
{
	//给出顶点v的某邻接顶点w的下一个邻接顶点
	if (v != -1 && w != -1)
	{
		for (int column = w + 1; column < numVertices; column++)
			if (Edge[v][column] > 0 && Edge[v][column] < maxWeight)return column;
	}
	return -1;
}

template<class T, class E>
inline bool GraphMatrix<T, E>::insertEdge(int v1, int v2, E cost, bool judgement)
{
	if (v1 > -1 && v1<numVertices && v2>-1 && v2 < numVertices && Edge[v1][v2] == maxWeight)
	{
		if (judgement == 0)Edge[v1][v2] = Edge[v2][v1] = cost;
		else Edge[v1][v2] = cost;
		numEdges++;
		return true;
	}
	return false;
}

template<class T, class E>
inline void GraphMatrix<T, E>::CreateEdge(bool judgement)
{
	int n, m;
	T data1, data2;
	int weight;
	cout << "请输入节点个数以及边数：" << endl;
	cin >> n >> m; //结点以及边的个数
	numVertices = n;
	cout << "请依次输入节点值：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> VerticesList[i];
	}
	for (int i = 0; i < m; i++)
	{
		if (judgement == 0)cout << "请输入第" << i + 1 << "条边的权值以及两端点：" << endl;
		else cout << "请输入第" << i + 1 << "条边的权值、尾节点及头节点：" << endl;
		cin >> weight >> data1 >> data2;
		if (getVertexPos(data1) == -1 || getVertexPos(data2) == -1)
		{
			cout << "边两端点信息有误，请重新输入！" << endl;
			i--;
			continue;
		}
		insertEdge(getVertexPos(data1), getVertexPos(data2), weight, judgement);
	}
}

template<class T, class E>
inline void GraphMatrix<T, E>::dfs()
{
	int i;
	for (i = 0; i < numVertices; i++) visited[i] = false;
	cout << "请输入深度优先遍历的出发点：" << endl;
	T dest;
	cin >> dest;//输入深度优先遍历的出发点 
	if (getVertexPos(dest) >= 0)
	{
		dfs(getVertexPos(dest));//调用深度优先的递归函数
	}
}

template<class T, class E>
inline void GraphMatrix<T, E>::bfs()
{
	int i, v0, n = numVertices;
	for (i = 0; i < numVertices; i++) visited[i] = false;
	T dest;
	cout << "请输入广度优先遍历的出发点：" << endl;
	cin >> dest;
	v0 = getVertexPos(dest);
	cout << VerticesList[v0] << " ";
	visited[v0] = true;
	queue<int>q;
	q.push(v0);
	while (!q.empty())
	{
		v0 = q.front();
		q.pop();
		for (int i = 0; i < numVertices; i++)
		{
			if (Edge[v0][i] != maxWeight && !visited[i])
			{
				cout << VerticesList[i] << " ";
				visited[i] = true;
				q.push(i);
			}
		}
	}
}


#pragma once
#pragma once
#include<iostream>
#include<queue>
#include<stack>
#include"Graph.h"
using namespace std;

template <class T, class E>
struct Edge//边结点的定义
{
	int dest;//边的另一顶点位置
	E cost;//边上的权值
	Edge<T, E>* link;//下一条边链指针
	Edge() { dest = 0; cost = 0; link = 0; }
	Edge(int num, E weight) :dest(num), cost(weight), link(0) { }//构造函数
	bool operator != (Edge<T, E>& R) const
	{
		return dest != R.dest;
	}
};

template <class T, class E>
struct Vertex//顶点的定义
{
	T data;//顶点的名字
	Edge<T, E>* adj;//边链表的头指针
};

template <class T, class E>
class GraphLink : public Graph<T, E>
{
	
private:
	Vertex<T, E>* NodeTable;//顶点表 (各边链表的头结点)
	bool* visited;//辅助数组
	int numVertices;//表示结点个数
	int maxVertices;//表示图中最大顶点数
	int numEdges;//当前边数
	int getVertexPos(const T vertx)//给出顶点vertex在图中的位置 
	{
		for (int i = 0; i < numVertices; i++)
			if (NodeTable[i].data == vertx) return i;
		return -1;
	}
	void dfs(int v);
public:
	GraphLink(int sz = DefaultVertices);//构造函数
	~GraphLink();//析构函数
	T getValue(int i)//取顶点 i 的值
	{
		return (i >= 0 && i < numVertices) ? NodeTable[i].data : 0;
	}
	//E getWeight(int v1, int v2);//取边(v1,v2)权值
	//bool insertVertex (const T& vertex);// 插入顶点
	//bool removeVertex (int v);// 删除顶点
	bool insertEdge(int v1, int v2, E cost, bool judgement); //插入边
	//bool removeEdge(int v1, int v2); // 删除边
	int getFirstNeighbor(int v); // 获取v的第一个邻接点
	int getNextNeighbor(int v, int w);  // 获取w后的邻接点
	void CreateNodeTable(bool judgement); // 建立邻接表结构
	void dfs();
	void bfs();
	void TopologicalSort();
};

template<class T, class E>
inline void GraphLink<T, E>::dfs(int v)
{

	visited[v] = true;
	cout << NodeTable[v].data << " ";//访问v结点
	Edge<T, E>* p = NodeTable[v].adj;
	while (p != NULL)// 找出邻接点逐个进行递归调用
	{
		if (!visited[p->dest]) dfs(p->dest);// 对v的尚未访问的邻接顶点递归调用DFS
		p = p->link; // 下一个邻接点
	}
}

template <class T, class E>
GraphLink<T, E>::GraphLink(int sz)//构造函数：建立一个空的邻接表 
{
	maxVertices = sz;
	numEdges = 0;//初始化当前边数
	numVertices = 0;//初始化当前顶点数
	NodeTable = new Vertex<T, E>[maxVertices];//创建顶点表数组
	visited = new bool[maxVertices];//建立辅助数组
	if (NodeTable == 0)
	{
		cerr << "存储分配错！" << endl;;
		exit(1);
	}
	for (int i = 0; i < maxVertices; i++)NodeTable[i].adj = 0;//初始化顶点邻接点
};

template <class T, class E>
GraphLink<T, E>::~GraphLink()//析构函数：删除一个邻接表
{
	for (int i = 0; i < numVertices; i++)
	{
		Edge<T, E>* p = NodeTable[i].adj;
		while (p != 0)
		{
			NodeTable[i].adj = p->link;
			delete p;
			p = NodeTable[i].adj;
		}
	}
	delete[]NodeTable;//删除顶点表数组
};

template<class T, class E>
inline bool GraphLink<T, E>::insertEdge(int v1, int v2, E cost, bool judgement)
{
	if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices)
	{
		Edge<T, E>* q, * p = NodeTable[v1].adj;
		while (p != 0 && p->dest != v2)p = p->link;//查找是否已存在该边
		if (p != 0)return false;
		p = new Edge<T, E>;
		q = new Edge<T, E>;
		p->dest = v2;
		p->cost = cost;
		p->link = NodeTable[v1].adj;//头插入邻接点
		NodeTable[v1].adj = p;
		if (judgement == 0)
		{
			q->dest = v1;
			q->cost = cost;
			q->link = NodeTable[v2].adj;
			NodeTable[v2].adj = q;
		}
		numEdges++;
		return true;
	}
	return false;
}

template<class T, class E>
inline int GraphLink<T, E>::getFirstNeighbor(int v)
{
	//给出顶点位置为v的第一个邻接顶点的位置，如果找不到，则函数返回-1 
	if (v != -1)
	{
		Edge<T, E>* p = NodeTable[v].adj;
		if (p != NULL)return p->dest;
	}
	return -1;
}

template<class T, class E>
inline int GraphLink<T, E>::getNextNeighbor(int v, int w)
{
	//给出顶点v的邻接顶点w的下一个邻接顶点的位置，若没有下一个邻接顶点，则函数返回-1
	if (v != -1)
	{
		Edge<T, E>* p = NodeTable[v].adj;
		while (p != NULL && p->dest != w)p = p->link;
		if (p != NULL && p->link != NULL)return p->link->dest;
	}
	return -1;
}

template <class T, class E>
void GraphLink<T, E>::CreateNodeTable(bool judgement)// 建立邻接表结构
{
	int n, m, weight;
	T dest;
	Edge<T, E>* p;
	cout << "请输入节点个数：" << endl;
	cin >> n; //结点数
	numVertices = n;
	cout << "请依次输入节点值：" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> NodeTable[i].data;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "请输入" << NodeTable[i].data << "的邻接点个数：" << endl;
		NodeTable[i].adj = 0; // 预设为空链
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			p = new Edge<T, E>;
			cout << "请输入" << NodeTable[i].data << "的第" << j + 1 << "个邻接点及边的权值：" << endl;
			cin >> dest >> weight;
			insertEdge(i, getVertexPos(dest), weight, judgement);
		}
	}

}

template<class T, class E>
inline void GraphLink<T, E>::dfs()
{
	int i, v0;
	for (i = 0; i < numVertices; i++) visited[i] = false;
	cout << "请输入深度优先遍历的出发点：" << endl;
	T dest;
	cin >> dest; //输入深度优先遍历的出发点
	v0 = getVertexPos(dest);
	dfs(v0);//调用深度优先的递归函数
}

template<class T, class E>
inline void GraphLink<T, E>::bfs()
{
	int i, v0, n = numVertices;
	for (i = 0; i < numVertices; i++) visited[i] = false;
	T dest;
	cout << "请输入广度优先遍历的出发点：" << endl;
	cin >> dest;
	v0 = getVertexPos(dest);
	cout << NodeTable[v0].data << " ";
	visited[v0] = true;
	queue<int>q;
	q.push(v0);
	while (!q.empty())
	{
		v0 = q.front();
		q.pop();
		Edge<string, int>* p = NodeTable[v0].adj;
		while (p != 0)
		{
			if (!visited[p->dest])
			{
				cout << NodeTable[p->dest].data << " ";
				visited[p->dest] = true;
				q.push(p->dest);
			}
			p = p->link;
		}
	}
}

template<class T, class E>
void GraphLink<T, E>::TopologicalSort()
{
	int* count = new int[numVertices];
	Edge<T, E>* p;
	for (int i = 0; i < numVertices; i++)
		count[i] = 0;
	
	for (int i = 0; i < numVertices; i++)
	{
		p = NodeTable[i].adj;
		while (p != 0)
		{
			count[p->dest]++;
			p = p->link;
		}
	}

	stack<int> s;
	int v;
	int m = 0;
	for (int i = 0; i < numVertices; i++)
	{
		if (count[i] == 0)//找出入度为0的顶点入栈
		{
			s.push(i);
		}
		
	}
	while (!s.empty())
	{
		v = s.top();
		s.pop();//出栈到v
		cout << NodeTable[v].data << " ";
		++m;
		p = NodeTable[v].adj;
		while (p != 0)
		{
			count[p->dest]--;
			if (count[p->dest] == 0)//如果等于零则结点p->dest入栈
				s.push(p->dest);
			p = p->link;
		}
	}
	if (m < numVertices)
	{
		cout << "图中有回路！" << endl;
	}
}



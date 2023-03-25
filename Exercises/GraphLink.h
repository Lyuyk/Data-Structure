#pragma once
#pragma once
#include<iostream>
#include<queue>
#include<stack>
#include"Graph.h"
using namespace std;

template <class T, class E>
struct Edge//�߽��Ķ���
{
	int dest;//�ߵ���һ����λ��
	E cost;//���ϵ�Ȩֵ
	Edge<T, E>* link;//��һ������ָ��
	Edge() { dest = 0; cost = 0; link = 0; }
	Edge(int num, E weight) :dest(num), cost(weight), link(0) { }//���캯��
	bool operator != (Edge<T, E>& R) const
	{
		return dest != R.dest;
	}
};

template <class T, class E>
struct Vertex//����Ķ���
{
	T data;//���������
	Edge<T, E>* adj;//�������ͷָ��
};

template <class T, class E>
class GraphLink : public Graph<T, E>
{
	
private:
	Vertex<T, E>* NodeTable;//����� (���������ͷ���)
	bool* visited;//��������
	int numVertices;//��ʾ������
	int maxVertices;//��ʾͼ����󶥵���
	int numEdges;//��ǰ����
	int getVertexPos(const T vertx)//��������vertex��ͼ�е�λ�� 
	{
		for (int i = 0; i < numVertices; i++)
			if (NodeTable[i].data == vertx) return i;
		return -1;
	}
	void dfs(int v);
public:
	GraphLink(int sz = DefaultVertices);//���캯��
	~GraphLink();//��������
	T getValue(int i)//ȡ���� i ��ֵ
	{
		return (i >= 0 && i < numVertices) ? NodeTable[i].data : 0;
	}
	//E getWeight(int v1, int v2);//ȡ��(v1,v2)Ȩֵ
	//bool insertVertex (const T& vertex);// ���붥��
	//bool removeVertex (int v);// ɾ������
	bool insertEdge(int v1, int v2, E cost, bool judgement); //�����
	//bool removeEdge(int v1, int v2); // ɾ����
	int getFirstNeighbor(int v); // ��ȡv�ĵ�һ���ڽӵ�
	int getNextNeighbor(int v, int w);  // ��ȡw����ڽӵ�
	void CreateNodeTable(bool judgement); // �����ڽӱ�ṹ
	void dfs();
	void bfs();
	void TopologicalSort();
};

template<class T, class E>
inline void GraphLink<T, E>::dfs(int v)
{

	visited[v] = true;
	cout << NodeTable[v].data << " ";//����v���
	Edge<T, E>* p = NodeTable[v].adj;
	while (p != NULL)// �ҳ��ڽӵ�������еݹ����
	{
		if (!visited[p->dest]) dfs(p->dest);// ��v����δ���ʵ��ڽӶ���ݹ����DFS
		p = p->link; // ��һ���ڽӵ�
	}
}

template <class T, class E>
GraphLink<T, E>::GraphLink(int sz)//���캯��������һ���յ��ڽӱ� 
{
	maxVertices = sz;
	numEdges = 0;//��ʼ����ǰ����
	numVertices = 0;//��ʼ����ǰ������
	NodeTable = new Vertex<T, E>[maxVertices];//�������������
	visited = new bool[maxVertices];//������������
	if (NodeTable == 0)
	{
		cerr << "�洢�����" << endl;;
		exit(1);
	}
	for (int i = 0; i < maxVertices; i++)NodeTable[i].adj = 0;//��ʼ�������ڽӵ�
};

template <class T, class E>
GraphLink<T, E>::~GraphLink()//����������ɾ��һ���ڽӱ�
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
	delete[]NodeTable;//ɾ�����������
};

template<class T, class E>
inline bool GraphLink<T, E>::insertEdge(int v1, int v2, E cost, bool judgement)
{
	if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices)
	{
		Edge<T, E>* q, * p = NodeTable[v1].adj;
		while (p != 0 && p->dest != v2)p = p->link;//�����Ƿ��Ѵ��ڸñ�
		if (p != 0)return false;
		p = new Edge<T, E>;
		q = new Edge<T, E>;
		p->dest = v2;
		p->cost = cost;
		p->link = NodeTable[v1].adj;//ͷ�����ڽӵ�
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
	//��������λ��Ϊv�ĵ�һ���ڽӶ����λ�ã�����Ҳ�������������-1 
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
	//��������v���ڽӶ���w����һ���ڽӶ����λ�ã���û����һ���ڽӶ��㣬��������-1
	if (v != -1)
	{
		Edge<T, E>* p = NodeTable[v].adj;
		while (p != NULL && p->dest != w)p = p->link;
		if (p != NULL && p->link != NULL)return p->link->dest;
	}
	return -1;
}

template <class T, class E>
void GraphLink<T, E>::CreateNodeTable(bool judgement)// �����ڽӱ�ṹ
{
	int n, m, weight;
	T dest;
	Edge<T, E>* p;
	cout << "������ڵ������" << endl;
	cin >> n; //�����
	numVertices = n;
	cout << "����������ڵ�ֵ��" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> NodeTable[i].data;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "������" << NodeTable[i].data << "���ڽӵ������" << endl;
		NodeTable[i].adj = 0; // Ԥ��Ϊ����
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			p = new Edge<T, E>;
			cout << "������" << NodeTable[i].data << "�ĵ�" << j + 1 << "���ڽӵ㼰�ߵ�Ȩֵ��" << endl;
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
	cout << "������������ȱ����ĳ����㣺" << endl;
	T dest;
	cin >> dest; //����������ȱ����ĳ�����
	v0 = getVertexPos(dest);
	dfs(v0);//����������ȵĵݹ麯��
}

template<class T, class E>
inline void GraphLink<T, E>::bfs()
{
	int i, v0, n = numVertices;
	for (i = 0; i < numVertices; i++) visited[i] = false;
	T dest;
	cout << "�����������ȱ����ĳ����㣺" << endl;
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
		if (count[i] == 0)//�ҳ����Ϊ0�Ķ�����ջ
		{
			s.push(i);
		}
		
	}
	while (!s.empty())
	{
		v = s.top();
		s.pop();//��ջ��v
		cout << NodeTable[v].data << " ";
		++m;
		p = NodeTable[v].adj;
		while (p != 0)
		{
			count[p->dest]--;
			if (count[p->dest] == 0)//�������������p->dest��ջ
				s.push(p->dest);
			p = p->link;
		}
	}
	if (m < numVertices)
	{
		cout << "ͼ���л�·��" << endl;
	}
}



#pragma once

#include<iostream>
#include<queue>
#include"Graph.h"
using namespace std;

template <class T, class E>
class GraphMatrix : public Graph<T, E>
{
	//friend istream& operator >> (istream& in, GraphMatrix<T, E>& G);	//����
	//friend ostream& operator << (ostream& out, GraphMatrix<T, E>& G);	//���
private:
	T* VerticesList;//�����
	E** Edge;//�ڽӾ���
	bool* visited;//��������
	int numVertices;//��ʾ������
	int maxVertices;//��ʾͼ����󶥵���
	int numEdges;//��ǰ����
	void dfs(int v);
public:
	GraphMatrix(int sz = 10);//���캯��
	~GraphMatrix()//��������
	{
		delete[]VerticesList;
		delete[]Edge;
	}
	int NumberOfVertices() { return numVertices; }
	T getValue(int i) //ȡ����i��ֵ,i��������0
	{
		return i >= 0 && i < numVertices ? VerticesList[i] : 0;
	}
	E getWeight(int v1, int v2)//ȡ��(v1,v2)��Ȩֵ
	{
		return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;
	}
	int getVertexPos(T vertex)//��������vertex��ͼ�е�λ��
	{
		for (int i = 0; i < numVertices; i++)if (VerticesList[i] == vertex) return i;
		return -1;
	}
	int getNumVertices() { return numVertices; }
	int getNumEdges() { return numEdges; }
	int getFirstNeighbor(int v);//ȡ���� v �ĵ�һ���ڽӶ���
	int getNextNeighbor(int v, int w);//ȡ v ���ڽӶ��� w ����һ�ڽӶ���
	//bool insertVertex(const T vertex);//���붥��vertex
	bool insertEdge(int v1, int v2, E cost, bool judgement);//�����(v1, v2),ȨֵΪcost
	//bool removeVertex (int v);//ɾȥ���� v ����������������ı�
	//bool removeEdge(int v1, int v2);//��ͼ��ɾȥ��(v1,v2)
	void CreateEdge(bool judgement);//judgement�����ж��Ƿ�Ϊ����ͼ
	void dfs();
	void bfs();
};

template<class T, class E>
inline void GraphMatrix<T, E>::dfs(int v)
{
	visited[v] = true;
	cout << VerticesList[v] << " ";//����v���
	for (int i = 0; i < numVertices; i++)
	{
		if (Edge[v][i] != maxWeight && !visited[i])dfs(i);
	}
}

template <class T, class E>
GraphMatrix<T, E>::GraphMatrix(int sz)//���캯��
{
	if (sz < 10)sz = 10;
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	int i, j;
	VerticesList = new T[maxVertices];//���������
	visited = new bool[maxVertices];
	Edge = (E**) new E * [maxVertices];
	for (i = 0; i < maxVertices; i++)
		Edge[i] = new int[maxVertices];//�ڽӾ���
	for (i = 0; i < maxVertices; i++)	//�����ʼ
		for (j = 0; j < maxVertices; j++)
			Edge[i][j] = (i == j) ? 0 : maxWeight;
};

template<class T, class E>
inline int GraphMatrix<T, E>::getFirstNeighbor(int v)
{
	//��������λ��Ϊv�ĵ�һ���ڽӶ����λ�ã�����Ҳ�������������-1
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
	//��������v��ĳ�ڽӶ���w����һ���ڽӶ���
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
	cout << "������ڵ�����Լ�������" << endl;
	cin >> n >> m; //����Լ��ߵĸ���
	numVertices = n;
	cout << "����������ڵ�ֵ��" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> VerticesList[i];
	}
	for (int i = 0; i < m; i++)
	{
		if (judgement == 0)cout << "�������" << i + 1 << "���ߵ�Ȩֵ�Լ����˵㣺" << endl;
		else cout << "�������" << i + 1 << "���ߵ�Ȩֵ��β�ڵ㼰ͷ�ڵ㣺" << endl;
		cin >> weight >> data1 >> data2;
		if (getVertexPos(data1) == -1 || getVertexPos(data2) == -1)
		{
			cout << "�����˵���Ϣ�������������룡" << endl;
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
	cout << "������������ȱ����ĳ����㣺" << endl;
	T dest;
	cin >> dest;//����������ȱ����ĳ����� 
	if (getVertexPos(dest) >= 0)
	{
		dfs(getVertexPos(dest));//����������ȵĵݹ麯��
	}
}

template<class T, class E>
inline void GraphMatrix<T, E>::bfs()
{
	int i, v0, n = numVertices;
	for (i = 0; i < numVertices; i++) visited[i] = false;
	T dest;
	cout << "�����������ȱ����ĳ����㣺" << endl;
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


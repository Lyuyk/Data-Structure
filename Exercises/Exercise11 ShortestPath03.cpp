#include<iostream>
#include"GraphMatrix.h"
using namespace std;

template<class T, class E>
void ShortestPath(GraphMatrix<T, E>*& G, T v, E dist[], int path[])
{
	int n = G->getNumVertices();
	bool* S = new bool[n];//���·�����㼯
	int i, j, k;
	E w, min;
	for (i = 0; i < n; i++)
	{
		dist[i] = G->getWeight(G->getVertexPos(v), i);//���·�����ȳ�ʼ��
		S[i] = false;
		if (i != G->getVertexPos(v) && dist[i] < maxWeight)path[i] = G->getVertexPos(v);
		else path[i] = -1;
	}
	S[G->getVertexPos(v)] = true;//����v���붥�㼯��
	dist[G->getVertexPos(v)] = 0;
	for (i = 0; i < n - 1; i++)//ѡ���Դ����ʣ�¶���
	{
		min = maxWeight;
		int u = G->getVertexPos(v);
		for (j = 0; j < n; j++)//ѡ����S�о������·���Ķ���
			if (S[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		S[u] = true;//������u����S
		for (k = 0; k < n; k++)//�޸����·��
		{
			w = G->getWeight(u, k);
			if (S[k] == false && w < maxWeight && dist[u] + w < dist[k])//ѡ�񶥵�δ����S���Ҿ���u��������·������
			{
				dist[k] = dist[u] + w;
				path[k] = u;//�޸ĵ�k�����·��
			}
		}
	}
	printShortestPath(G, v, dist, path);
}
template<class T, class E>
void printShortestPath(GraphMatrix<T, E>*& G, T v, E dist[], int path[])
{
	cout << "�Ӷ���" << v << "��������������·��Ϊ��" << endl;
	int i, j, k, n = G->getNumVertices();
	int* d = new int[n];
	for (i = 0; i < n; i++)
	{
		if (i != G->getVertexPos(v))
		{
			j = i;
			k = 0;
			while (j != G->getVertexPos(v))
			{
				d[k++] = j;
				j = path[j];
			}
			cout << "����" << G->getValue(i) << "�����·��Ϊ��" << v;
			while (k > 0)cout << G->getValue(d[--k]);
			cout << "  ���·������Ϊ��" << dist[i] << endl;
		}
	}
	delete[]d;
}
void main()
{
	GraphMatrix<string, int>* mtx = new GraphMatrix<string, int>(10);//���·��
	mtx->CreateEdge(1);//���������ڽӾ���
	string v;
	cout << "�������γ����·��Դ�㣺" << endl ;
	cin >> v;
	int* dist = new int[mtx->getNumVertices()];
	int* path = new int[mtx->getNumVertices()];
	ShortestPath<string, int>(mtx, v, dist, path);//���·��
}

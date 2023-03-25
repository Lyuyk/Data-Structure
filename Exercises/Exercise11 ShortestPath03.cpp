#include<iostream>
#include"GraphMatrix.h"
using namespace std;

template<class T, class E>
void ShortestPath(GraphMatrix<T, E>*& G, T v, E dist[], int path[])
{
	int n = G->getNumVertices();
	bool* S = new bool[n];//最短路径顶点集
	int i, j, k;
	E w, min;
	for (i = 0; i < n; i++)
	{
		dist[i] = G->getWeight(G->getVertexPos(v), i);//最短路径长度初始化
		S[i] = false;
		if (i != G->getVertexPos(v) && dist[i] < maxWeight)path[i] = G->getVertexPos(v);
		else path[i] = -1;
	}
	S[G->getVertexPos(v)] = true;//顶点v加入顶点集合
	dist[G->getVertexPos(v)] = 0;
	for (i = 0; i < n - 1; i++)//选完除源点外剩下顶点
	{
		min = maxWeight;
		int u = G->getVertexPos(v);
		for (j = 0; j < n; j++)//选择不在S中具有最短路径的顶点
			if (S[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		S[u] = true;//将顶点u加入S
		for (k = 0; k < n; k++)//修改最短路径
		{
			w = G->getWeight(u, k);
			if (S[k] == false && w < maxWeight && dist[u] + w < dist[k])//选择顶点未加入S，且经过u可以缩短路径长度
			{
				dist[k] = dist[u] + w;
				path[k] = u;//修改到k的最短路径
			}
		}
	}
	printShortestPath(G, v, dist, path);
}
template<class T, class E>
void printShortestPath(GraphMatrix<T, E>*& G, T v, E dist[], int path[])
{
	cout << "从顶点" << v << "到其他各点的最短路径为：" << endl;
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
			cout << "顶点" << G->getValue(i) << "的最短路径为：" << v;
			while (k > 0)cout << G->getValue(d[--k]);
			cout << "  最短路径长度为：" << dist[i] << endl;
		}
	}
	delete[]d;
}
void main()
{
	GraphMatrix<string, int>* mtx = new GraphMatrix<string, int>(10);//最短路径
	mtx->CreateEdge(1);//创建有向邻接矩阵
	string v;
	cout << "请输入形成最短路径源点：" << endl ;
	cin >> v;
	int* dist = new int[mtx->getNumVertices()];
	int* path = new int[mtx->getNumVertices()];
	ShortestPath<string, int>(mtx, v, dist, path);//最短路径
}

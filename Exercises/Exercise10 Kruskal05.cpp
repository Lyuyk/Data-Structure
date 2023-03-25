#include<iostream>
#include"minHeap.h"
#include"UFSets.h"
#include"MinSpanTree.h"
#include"GraphMatrix.h"
using namespace std;

void Kruskal(GraphMatrix<string, int>* GMtx, MinSpanTree<string, int>* MST)
{
	MSTEdgeNode<string, int>edge;//边结点
	int u, v, count;//辅助数
	int numVts = GMtx->getNumVertices();//顶点数
	int numEdges = GMtx->getNumEdges();//边数
	Heap<MSTEdgeNode<string, int>> H(numEdges);//建立最小堆
	UFSets F(numVts);//并查集
	for (u = 0; u < numVts; u++)
	{
		for (v = u + 1; v < numVts; v++)
		{
			if (GMtx->getWeight(u, v) != maxValue)
			{
				edge.tail = u;
				edge.head = v;
				edge.cost = GMtx->getWeight(u, v);
				H.Insert(edge);//插入堆
			}
		}
	}
	count = 1;
	while (count < numVts)//取n-1条边
	{
		H.Remove(edge);//最小堆中取出最小权值的边
		u = F.Find(edge.tail);
		v = F.Find(edge.head);//取两个顶点所在的根
		if (u != v)//若不连通
		{
			F.Union(u, v);//合并
			MST->Insert(edge);//将此边加入最小生成树
			count++;
		}
	}
}

int main()
{
	GraphMatrix<string, int>* mtx = new GraphMatrix<string, int>(10);
	mtx->CreateEdge(0);//创建无向邻接矩阵
	MinSpanTree<string, int>* MST = new MinSpanTree<string, int>(mtx->getNumVertices());
	cout << "Kruskal算法生成最小生成树：" << endl;
	Kruskal(mtx, MST);
	for (int i = 0; i < MST->getEdgeSize(); i++)
	{
		cout << mtx->getValue(MST->showEdgevalue(i).tail) << "->" << mtx->getValue(MST->showEdgevalue(i).head) << ":" << MST->showEdgevalue(i).cost << endl;//显示最小生成树的边
	}

}
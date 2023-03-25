#include<iostream>
#include"minHeap.h"
#include"UFSets.h"
#include"MinSpanTree.h"
#include"GraphMatrix.h"
using namespace std;

void Prim(GraphMatrix<string, int>* G, MinSpanTree<string, int>* MST)
{
	MSTEdgeNode<string, int>edge;//边结点辅助单元
	int i, u, v, count;//顶点数
	int numVts = G->getNumVertices();//顶点数
	int numEdges = G->getNumEdges();//边数
	string str;
	cout << "请输入起始点：" << endl;
	cin >> str;
	u = G->getVertexPos(str);//求起始顶点号
	Heap<MSTEdgeNode<string, int>>H(numEdges);//最小堆
	bool* VMst = new bool[numVts];//最小生成树顶点集合
	
	for (int i = 0; i < numVts; i++)
		VMst[i] = false;

	VMst[u] = true;//u加入最小生成树
	count = 1;
	
	do
	{
		v = G->getFirstNeighbor(u);
		while (v != -1)//检测u的所有邻接顶点
		{
			if (VMst[v] == false)//若v不在生成树（u，v）加入堆
			{
				edge.tail = u;
				edge.head = v;
				edge.cost = G->getWeight(u, v);
				H.Insert(edge);
			}
			v = G->getNextNeighbor(u, v);//找u的下一个顶点
		}
		while (H.IsEmpty() == false && count < numVts)
		{
			H.Remove(edge);//从堆中退出最小权值的边edge
			if (VMst[edge.head] == false)
			{
				MST->Insert(edge);//加入最小生成树
				u = edge.head;
				VMst[u] = true;//u加入生成树顶点集合
				count++;
				break;

			}
		}
	} while (count < numVts);
}

int main()
{
	GraphMatrix<string, int>* mtx = new GraphMatrix<string, int>(10);//new初始化
	mtx->CreateEdge(0);//创建无向邻接矩阵

	MinSpanTree<string, int>* mst = new MinSpanTree<string, int>(mtx->getNumVertices());
	cout << "Prim算法生成最小生成树：" << endl;
	Prim(mtx, mst);
	for (int i = 0; i < mst->getEdgeSize(); i++)
	{
		cout << mtx->getValue(mst->showEdgevalue(i).tail) << "->" << mtx->getValue(mst->showEdgevalue(i).head) << ":" << mst->showEdgevalue(i).cost << endl;//显示最小生成树的边
	}
	return 0;

}
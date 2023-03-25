#include<iostream>
#include"minHeap.h"
#include"UFSets.h"
#include"MinSpanTree.h"
#include"GraphMatrix.h"
using namespace std;

void Kruskal(GraphMatrix<string, int>* GMtx, MinSpanTree<string, int>* MST)
{
	MSTEdgeNode<string, int>edge;//�߽��
	int u, v, count;//������
	int numVts = GMtx->getNumVertices();//������
	int numEdges = GMtx->getNumEdges();//����
	Heap<MSTEdgeNode<string, int>> H(numEdges);//������С��
	UFSets F(numVts);//���鼯
	for (u = 0; u < numVts; u++)
	{
		for (v = u + 1; v < numVts; v++)
		{
			if (GMtx->getWeight(u, v) != maxValue)
			{
				edge.tail = u;
				edge.head = v;
				edge.cost = GMtx->getWeight(u, v);
				H.Insert(edge);//�����
			}
		}
	}
	count = 1;
	while (count < numVts)//ȡn-1����
	{
		H.Remove(edge);//��С����ȡ����СȨֵ�ı�
		u = F.Find(edge.tail);
		v = F.Find(edge.head);//ȡ�����������ڵĸ�
		if (u != v)//������ͨ
		{
			F.Union(u, v);//�ϲ�
			MST->Insert(edge);//���˱߼�����С������
			count++;
		}
	}
}

int main()
{
	GraphMatrix<string, int>* mtx = new GraphMatrix<string, int>(10);
	mtx->CreateEdge(0);//���������ڽӾ���
	MinSpanTree<string, int>* MST = new MinSpanTree<string, int>(mtx->getNumVertices());
	cout << "Kruskal�㷨������С��������" << endl;
	Kruskal(mtx, MST);
	for (int i = 0; i < MST->getEdgeSize(); i++)
	{
		cout << mtx->getValue(MST->showEdgevalue(i).tail) << "->" << mtx->getValue(MST->showEdgevalue(i).head) << ":" << MST->showEdgevalue(i).cost << endl;//��ʾ��С�������ı�
	}

}
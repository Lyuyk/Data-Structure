#include<iostream>
#include"minHeap.h"
#include"UFSets.h"
#include"MinSpanTree.h"
#include"GraphMatrix.h"
using namespace std;

void Prim(GraphMatrix<string, int>* G, MinSpanTree<string, int>* MST)
{
	MSTEdgeNode<string, int>edge;//�߽�㸨����Ԫ
	int i, u, v, count;//������
	int numVts = G->getNumVertices();//������
	int numEdges = G->getNumEdges();//����
	string str;
	cout << "��������ʼ�㣺" << endl;
	cin >> str;
	u = G->getVertexPos(str);//����ʼ�����
	Heap<MSTEdgeNode<string, int>>H(numEdges);//��С��
	bool* VMst = new bool[numVts];//��С���������㼯��
	
	for (int i = 0; i < numVts; i++)
		VMst[i] = false;

	VMst[u] = true;//u������С������
	count = 1;
	
	do
	{
		v = G->getFirstNeighbor(u);
		while (v != -1)//���u�������ڽӶ���
		{
			if (VMst[v] == false)//��v������������u��v�������
			{
				edge.tail = u;
				edge.head = v;
				edge.cost = G->getWeight(u, v);
				H.Insert(edge);
			}
			v = G->getNextNeighbor(u, v);//��u����һ������
		}
		while (H.IsEmpty() == false && count < numVts)
		{
			H.Remove(edge);//�Ӷ����˳���СȨֵ�ı�edge
			if (VMst[edge.head] == false)
			{
				MST->Insert(edge);//������С������
				u = edge.head;
				VMst[u] = true;//u�������������㼯��
				count++;
				break;

			}
		}
	} while (count < numVts);
}

int main()
{
	GraphMatrix<string, int>* mtx = new GraphMatrix<string, int>(10);//new��ʼ��
	mtx->CreateEdge(0);//���������ڽӾ���

	MinSpanTree<string, int>* mst = new MinSpanTree<string, int>(mtx->getNumVertices());
	cout << "Prim�㷨������С��������" << endl;
	Prim(mtx, mst);
	for (int i = 0; i < mst->getEdgeSize(); i++)
	{
		cout << mtx->getValue(mst->showEdgevalue(i).tail) << "->" << mtx->getValue(mst->showEdgevalue(i).head) << ":" << mst->showEdgevalue(i).cost << endl;//��ʾ��С�������ı�
	}
	return 0;

}
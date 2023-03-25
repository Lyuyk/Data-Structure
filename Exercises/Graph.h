#pragma once
const int maxWeight = 1000;	//������ֵ
const int DefaultVertices = 10;	//��󶥵���
template <class T, class E>
class Graph
{
protected:
	int maxVertices;//ͼ����󶥵���
	int numEdges;//��ǰ����
	int numVertices;//��ǰ������
	int getVertexPos(T vertex);//��������vertex��ͼ��λ��
public:
	Graph(int sz = DefaultVertices) { maxVertices = sz; numEdges = 0; numVertices = 0; };//���캯��
	~Graph() { ; }//��������
	bool GraphEmpty() const//��ͼ�շ�
	{
		return numEdges == 0;
	}
	int NumberOfVertices() { return numVertices; }
	//���ص�ǰ������
	int NumberOfEdges() { return numEdges; }
	//���ص�ǰ����
	/*virtual T getValue(int i);	//ȡ����i��ֵ
	virtual E getWeight(int v1, int v2); //ȡ����Ȩֵ
	virtual int getFirstNeighbor(int v);//ȡ���� v �ĵ�һ���ڽӶ���
	virtual int getNextNeighbor(int v, int w);//ȡ�ڽӶ��� w ����һ�ڽӶ���
	virtual bool insertVertex(const T vertex);//����һ������vertex
	virtual bool insertEdge(int v1, int v2, E cost);//�����(v1,v2), ȨΪcost
	virtual bool removeVertex(int v);//ɾȥ���� v ���������������
	virtual bool removeEdge(int v1, int v2);//��ͼ��ɾȥ��(v1,v2)*/
};

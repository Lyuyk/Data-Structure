#include<iostream>
#include"GraphLink.h"
using namespace std;
void main()
{
	GraphLink<string, int>* G = new GraphLink<string, int>(10);//��ʼ���ڽӱ�
	G->CreateNodeTable(1);//���������ڽӱ�
	cout << endl;
	G->TopologicalSort();//��������
}

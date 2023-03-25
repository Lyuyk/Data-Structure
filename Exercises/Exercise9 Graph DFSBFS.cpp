#include<iostream>
#include<bitset>
#include"Graph.h"
#include"GraphLink.h"
#include"GraphMatrix.h"

using namespace std;

int main()
{
	GraphLink<string, int>* GLink = new GraphLink<string, int>(10);
	cout << "���������ڽӱ�" << endl;
	GLink->CreateNodeTable(0);//���������ڽӱ�
	cout << "==============================" << endl;
	GLink->dfs();//�����������
	cout << "result======================dfs" << endl;
	GLink->bfs();//�����������
	cout << "result======================bfs" << endl;


	GraphMatrix<string, int>* GMatrix = new GraphMatrix<string, int>(10);
	cout << "���������ھ���" << endl;
	GMatrix->CreateEdge(0);//���������ڽӾ���
	cout << "==============================" << endl;
	GMatrix->dfs();//�����������
	cout << "result======================dfs" << endl;
	GMatrix->bfs();//�����������
	cout << "result======================bfs" << endl;

	return 0;
}
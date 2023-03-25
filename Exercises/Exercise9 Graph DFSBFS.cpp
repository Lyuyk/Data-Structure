#include<iostream>
#include<bitset>
#include"Graph.h"
#include"GraphLink.h"
#include"GraphMatrix.h"

using namespace std;

int main()
{
	GraphLink<string, int>* GLink = new GraphLink<string, int>(10);
	cout << "创建无向邻接表：" << endl;
	GLink->CreateNodeTable(0);//创建无向邻接表
	cout << "==============================" << endl;
	GLink->dfs();//深度优先搜索
	cout << "result======================dfs" << endl;
	GLink->bfs();//广度优先搜索
	cout << "result======================bfs" << endl;


	GraphMatrix<string, int>* GMatrix = new GraphMatrix<string, int>(10);
	cout << "创建无向邻矩阵：" << endl;
	GMatrix->CreateEdge(0);//创建无向邻接矩阵
	cout << "==============================" << endl;
	GMatrix->dfs();//深度优先搜索
	cout << "result======================dfs" << endl;
	GMatrix->bfs();//广度优先搜索
	cout << "result======================bfs" << endl;

	return 0;
}
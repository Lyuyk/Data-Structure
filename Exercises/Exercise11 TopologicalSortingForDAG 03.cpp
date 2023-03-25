#include<iostream>
#include"GraphLink.h"
using namespace std;
void main()
{
	GraphLink<string, int>* G = new GraphLink<string, int>(10);//初始化邻接表
	G->CreateNodeTable(1);//建立有向邻接表
	cout << endl;
	G->TopologicalSort();//拓扑排序
}

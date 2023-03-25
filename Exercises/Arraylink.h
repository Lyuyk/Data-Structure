#pragma once
class Arraylink
{
public:
	Arraylink() { last = -1; arr = new int[20]; len = 20; };//初始化数组
	Arraylink(int length) { arr = new int[length]; len = length - 1; last = -1; }//初始化数组
	
	void addToArrayAtIndex(int index,int value);
	void addToArrayByOrder();//根据顺序插入顺序表
	void init(int x);//输入数组元素（初始化）
	void print()const;

private:
	int* arr;//顺序数组
	int last;//顺序表最后一个数的位置下标
	int len;//顺序表总长度
};


#pragma once
class Arraylink
{
public:
	Arraylink() { last = -1; arr = new int[20]; len = 20; };//��ʼ������
	Arraylink(int length) { arr = new int[length]; len = length - 1; last = -1; }//��ʼ������
	
	void addToArrayAtIndex(int index,int value);
	void addToArrayByOrder();//����˳�����˳���
	void init(int x);//��������Ԫ�أ���ʼ����
	void print()const;

private:
	int* arr;//˳������
	int last;//˳������һ������λ���±�
	int len;//˳����ܳ���
};


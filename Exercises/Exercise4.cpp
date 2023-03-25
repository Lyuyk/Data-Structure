#include<iostream>
using namespace std;

class Node//节点定义
{
public:
	int val;
	Node* next;
};

class CList//循环链表定义
{
public:
	CList();
	void create();//创建链表
	void deleteSmall();//删除最小的节点
	void deleteAtIndex(int index);
	void print();//打印整个链表
private:
	Node* last;
};

CList::CList()
{
	last = 0;
}


void CList::create()
{
	cout << "请输入链表长度：";
	int length;
	cin >> length;
	if (length <= 0)
	{
		cout << "长度非法" << endl;
		return;
	}

	last = new Node;//链表头节点
	Node* temp = last;//保存链表尾节点

	for (int i = 0; i < length; i++)//按给定的数目创建节点插入
	{
		Node* p = new Node;//新节点p
		cin >> p->val;//输入新节点p的值
		temp->next = p;//尾节点的next指向头部
		temp = p;//将虚拟节点前移一位，下次插入next就在上一个节点后面
		p->next = last;//保持最后一个节点的值指向尾节点（尾插，保持顺序）
	}
}

void CList::deleteSmall()
{
	Node* now = new Node;//创建一个新的当前节点
	now = last->next;//now此时为链表第一个节点
	
	int index = 0, targetIndex = 0;//当前下标，删除下标
	
	int min = now->val;//记录目前最小值
	while (now != last)//若未循环一次
	{
		if (now->val < min)//若有值比当前最小值小
		{
			min = now->val;
			targetIndex = index;
		}
		else
		{
			now = now->next;
			index++;
		}
	}
	deleteAtIndex(targetIndex);
}

void CList::deleteAtIndex(int index)
{
	if (index < 0)//下标不能小于0
	{
		cout << "index value illegal!" << endl;
		return;
	}

	Node* p = last;//创建一个节点，保存尾节点
	Node* temp = p->next;//另建一个节点保存p的下一个节点

	for (int i = 0; i <= index ; i++)
	{
		temp = p;//temp 是p前一个节点
		p = p->next;
	}
	temp->next = p->next;
	delete p;
	cout << "删除下标为" << index << "的节点" << endl;
}

void CList::print()
{
	Node* lastt = last;//复制一个last指针
	lastt = last->next;
	while (lastt != last)
	{
		cout << lastt->val<<" ";
		lastt = lastt->next;
	}
	cout << endl;
}

int main()
{
	CList cl;//创建一个链表实例
	cl.create();
	cl.print();
	cout << "初始链表" << endl;
	cl.deleteAtIndex(2);
	cl.print();
	cout << "以下删除数值最小的结点" << endl;
	cl.deleteSmall();//删除数值较小的节点
	cl.print();
	cout << "deleteAtSmall" << endl;
}


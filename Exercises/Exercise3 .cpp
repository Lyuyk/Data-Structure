#include<iostream>
using namespace std;

class Link//链表节点定义
{
public:
	int val;
	Link* next;
};

Link* create()//若输入-1，则停止创建链表
{
	Link* head = new Link;
	Link* last = head, * p;

	while (p = new Link)
	{
		cin >> p->val;
		last->next = p;
		last = p;
		if (p->val == -1)break;
	}
	p->next = 0;

	Link* first = head;
	while (true)//去掉末位的-1结点
	{
		if (first->next->next == 0)
		{
			first->next = 0;
			break;
		}
		first = first->next;
	}
	return head;
}

Link* insert(Link* first, int value)//插入节点
{
	Link* nowLink = new Link;//复制保存待插入节点
	nowLink->val = value;
	nowLink->next = 0;

	Link* head = first;//复制保存一个头指针
	while (first->next != 0 && first->next->val <= value)//使用头指针进行查找并插入
	{
		first = first->next;
	}

	nowLink->next = first->next;
	first->next = nowLink;

	return head;//将保存的头节点返回
}

void print(Link* first)//输出整个链表
{
	first = first->next;
	while (first!=0)
	{
		cout << first->val << " ";
		first = first->next;
	}
	cout << endl;
}

int main()
{
	Link* head = 0;
	head = create();
	print(head);

	int val;
	while (cin >> val)
	{
		if (val == -5555)break;
		insert(head, val);
		print(head);
	}
	return 0;
}
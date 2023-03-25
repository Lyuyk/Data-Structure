#include<iostream>
using namespace std;

class Link//结点定义
{
public:
	int val;
	Link* next;
};

Link* create()//创建节点
{
	Link* head = new Link;
	Link* last = head;
	Link* p;

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

int lengthOfLinklist(Link* head)
{
	if (head->next==0)
	{
		return 0;
	}
	return 1 + lengthOfLinklist(head->next);
}

Link* reverseLinklist(Link* head)
{
	Link* p = head;
	if (p == 0)
		return 0;//空链表，返回空

	Link* q = p->next;
	if (q == 0)
		return p;//只有一个节点，返回
	else
		head = reverseLinklist(q);//记录子序列的头结点
	
	q->next = p;//当前节点与已经逆置的子序列看成前后两个节点p,q，做相应的逆置操作
	p->next = 0;

	return head;//返回新的子序列的头结点
}

void reverse(Link*& head)
{
	if (!head)
		return;
	Link* rest = head->next;
	if (!rest)
		return;
	reverse(rest);

	head->next->next = head;
	head->next = 0;
	head = rest;
}

void print(Link* head)//递归实现
{
	if (head != 0)
	{
		cout << head->val<<" ";
		print(head->next);
	}
	else
		return;
}

void printt(Link* head)//普通实现
{
	head = head->next;
	for (; head; head = head->next)
	{
		cout << head->val<<" ";
	}
}

int main()
{
	Link* head = 0;
	head = create();

	print(head->next);
	cout << endl;
	printt(head);

	cout << endl;
	int l = lengthOfLinklist(head);
	cout << "链表长度:" << l << endl;

	reverse(head->next);
	print(head->next);
	cout << endl;
	printt(head);

	return 0;
}
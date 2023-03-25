#include<iostream>
using namespace std;

class Link//��㶨��
{
public:
	int val;
	Link* next;
};

Link* create()//�����ڵ�
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
	while (true)//ȥ��ĩλ��-1���
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
		return 0;//���������ؿ�

	Link* q = p->next;
	if (q == 0)
		return p;//ֻ��һ���ڵ㣬����
	else
		head = reverseLinklist(q);//��¼�����е�ͷ���
	
	q->next = p;//��ǰ�ڵ����Ѿ����õ������п���ǰ�������ڵ�p,q������Ӧ�����ò���
	p->next = 0;

	return head;//�����µ������е�ͷ���
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

void print(Link* head)//�ݹ�ʵ��
{
	if (head != 0)
	{
		cout << head->val<<" ";
		print(head->next);
	}
	else
		return;
}

void printt(Link* head)//��ͨʵ��
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
	cout << "������:" << l << endl;

	reverse(head->next);
	print(head->next);
	cout << endl;
	printt(head);

	return 0;
}
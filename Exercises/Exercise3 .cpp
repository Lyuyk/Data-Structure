#include<iostream>
using namespace std;

class Link//����ڵ㶨��
{
public:
	int val;
	Link* next;
};

Link* create()//������-1����ֹͣ��������
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

Link* insert(Link* first, int value)//����ڵ�
{
	Link* nowLink = new Link;//���Ʊ��������ڵ�
	nowLink->val = value;
	nowLink->next = 0;

	Link* head = first;//���Ʊ���һ��ͷָ��
	while (first->next != 0 && first->next->val <= value)//ʹ��ͷָ����в��Ҳ�����
	{
		first = first->next;
	}

	nowLink->next = first->next;
	first->next = nowLink;

	return head;//�������ͷ�ڵ㷵��
}

void print(Link* first)//�����������
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
#include<iostream>
using namespace std;

class Link
{
public:
	int val;
	Link* next;
};

Link* create()
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
	while (true)
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

void print(Link* head)//��ͨʵ��
{
	head = head->next;
	for (; head; head = head->next)
	{
		cout << head->val << " ";
	}
}

int length(Link* head)
{	
	if (!head->next)
		return 0;
	Link* first = head->next;
	int len = 0;
	while (first != NULL)
	{
		len++;
		first = first->next;
	}
	return len;
}

Link* straightInsertionSort(Link* head)
{
	Link* first = NULL, * inserted = head;
	while (inserted != NULL) 
	{
		Link* current = first, * last = NULL, * next = inserted->next;
		// ��ͷ�����ҵ���һ������inserted->val��Ԫ��
		while (current != NULL && current->val <= inserted->val) 
		{
			last = current;
			current = current->next;
		}

		if (last == NULL) 
		{
			// ������κ�����������ֶ�ҪС����ô�ͳ�Ϊ�µ�ͷ��
			inserted->next = first;
			first = inserted;
		}
		else {
			// ������뵽last�ĺ���
			inserted->next = last->next;
			last->next = inserted;
		}

		inserted = next;
	}
	return first;
}

int main()
{
	Link* head = create();
	print(head);
	cout << endl;
	cout <<"������" << length(head) << endl;
	print(straightInsertionSort(head));
	return 0;
}
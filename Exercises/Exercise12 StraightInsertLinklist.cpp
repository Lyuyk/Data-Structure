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

void print(Link* head)//普通实现
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
		// 从头往后找到第一个大于inserted->val的元素
		while (current != NULL && current->val <= inserted->val) 
		{
			last = current;
			current = current->next;
		}

		if (last == NULL) 
		{
			// 如果比任何已排序的数字都要小，那么就成为新的头部
			inserted->next = first;
			first = inserted;
		}
		else {
			// 否则插入到last的后面
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
	cout <<"链表长度" << length(head) << endl;
	print(straightInsertionSort(head));
	return 0;
}
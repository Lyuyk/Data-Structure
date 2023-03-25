#include<iostream>
using namespace std;

class Node//�ڵ㶨��
{
public:
	int val;
	Node* next;
};

class CList//ѭ��������
{
public:
	CList();
	void create();//��������
	void deleteSmall();//ɾ����С�Ľڵ�
	void deleteAtIndex(int index);
	void print();//��ӡ��������
private:
	Node* last;
};

CList::CList()
{
	last = 0;
}


void CList::create()
{
	cout << "�����������ȣ�";
	int length;
	cin >> length;
	if (length <= 0)
	{
		cout << "���ȷǷ�" << endl;
		return;
	}

	last = new Node;//����ͷ�ڵ�
	Node* temp = last;//��������β�ڵ�

	for (int i = 0; i < length; i++)//����������Ŀ�����ڵ����
	{
		Node* p = new Node;//�½ڵ�p
		cin >> p->val;//�����½ڵ�p��ֵ
		temp->next = p;//β�ڵ��nextָ��ͷ��
		temp = p;//������ڵ�ǰ��һλ���´β���next������һ���ڵ����
		p->next = last;//�������һ���ڵ��ֵָ��β�ڵ㣨β�壬����˳��
	}
}

void CList::deleteSmall()
{
	Node* now = new Node;//����һ���µĵ�ǰ�ڵ�
	now = last->next;//now��ʱΪ�����һ���ڵ�
	
	int index = 0, targetIndex = 0;//��ǰ�±꣬ɾ���±�
	
	int min = now->val;//��¼Ŀǰ��Сֵ
	while (now != last)//��δѭ��һ��
	{
		if (now->val < min)//����ֵ�ȵ�ǰ��СֵС
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
	if (index < 0)//�±겻��С��0
	{
		cout << "index value illegal!" << endl;
		return;
	}

	Node* p = last;//����һ���ڵ㣬����β�ڵ�
	Node* temp = p->next;//��һ���ڵ㱣��p����һ���ڵ�

	for (int i = 0; i <= index ; i++)
	{
		temp = p;//temp ��pǰһ���ڵ�
		p = p->next;
	}
	temp->next = p->next;
	delete p;
	cout << "ɾ���±�Ϊ" << index << "�Ľڵ�" << endl;
}

void CList::print()
{
	Node* lastt = last;//����һ��lastָ��
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
	CList cl;//����һ������ʵ��
	cl.create();
	cl.print();
	cout << "��ʼ����" << endl;
	cl.deleteAtIndex(2);
	cl.print();
	cout << "����ɾ����ֵ��С�Ľ��" << endl;
	cl.deleteSmall();//ɾ����ֵ��С�Ľڵ�
	cl.print();
	cout << "deleteAtSmall" << endl;
}


#include<iostream>
using namespace std;

typedef struct tree
{
	int data;//������
	struct tree* left;//���ӽ��
	struct tree* right;//���ӽ��
}node, *PNode;

PNode firstLeaf;//��¼Ҷ������ĵ�һ��Ҷ�ӽ��
PNode pcurr;//��¼Ҷ������ĵ�ǰ���

PNode createTreeNode(int data)
{
	PNode n = (PNode)malloc(sizeof(PNode));//�����ڴ�
	n->data = data;//����������
	n->left = 0;//��ʼ������
	n->right = 0;//��ʼ���ҽ��

	return n;//���ظ����
}

void inOrder(PNode p)//�������
{
	if (p == 0)
	{
		return;
	}
	inOrder(p->left);//������ڵ�
	cout << p->data << " ";//���������
	inOrder(p->right);//�����ҽ��
}

void leafLink(PNode root)
{
	if (!root)return;//���ڵ�Ϊ�գ�����
	if (root->left == 0 && root->right == 0)
	{
		if (firstLeaf == 0)
		{
			firstLeaf = root;//�����ҵ��ĵ�һ��Ҷ�ӽ��
			pcurr = firstLeaf;
		}
		else
		{
			pcurr->right = root;
			pcurr = pcurr->right;//��������Ҷ�ӽ���rightChild����ָ��
		}
	}

	if (root->left)
	{
		leafLink(root->left);//����������Ϊ�գ��ݹ������Ҷ��
	}

	if (root->right)
	{
		leafLink(root->right);//����������Ϊ�գ��ݹ����������
	}
}

void printLinkedlist(PNode head)
{
	PNode nowNode = head;//����ͷ���
	nowNode->data = head->data;
	while (nowNode)
	{
		if (nowNode->right)
		{
			cout  << nowNode->data << "-->";
		}
		else
		{
			cout << nowNode->data;
		}
		nowNode = nowNode->right;
	}
}

int main()
{
	//���ɶ�����
	PNode p1 = createTreeNode(1);
	PNode p2 = createTreeNode(2);
	PNode p3 = createTreeNode(3);
	PNode p4 = createTreeNode(4);
	PNode p5 = createTreeNode(5);
	PNode p6 = createTreeNode(6);
	PNode p7 = createTreeNode(7);
	PNode p8 = createTreeNode(8);
	PNode p9 = createTreeNode(9);

	p1->left = p2;
	p1->right = p3;

	p2->left = p4;
	p2->right = p5;

	p3->left = p6;
	p3->right = p7;

	p4->left = p8;
	p4->right = p9;

	cout << "���������";
	inOrder(p1);
	cout << endl;

	leafLink(p1);
	cout << "Ҷ�������";
	while (firstLeaf)//���Ҷ�������
	{
		if (firstLeaf->right)
		{
			cout << firstLeaf->data << "-->";
		}
		else
		{
			cout << firstLeaf->data;
		}
		firstLeaf = firstLeaf->right;
	}
	cout << endl;

	return  0;
}
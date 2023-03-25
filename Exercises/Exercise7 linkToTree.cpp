#include<iostream>
using namespace std;

struct Node
{
	int data;//������
	Node* left, * right;//���Һ���
};

Node* newNode(int data)//�����½��
{
	Node* node = (Node*)malloc(sizeof(Node));//�����ڴ�
	node->data = data;//����������
	node->left = node->right = 0;//��ʼ�������ӽ��
	return node;//���ظ��ڵ�
}

Node* insertLevelOrder(int arr[], Node* root, int i, int n)//���������ʽ������
{
	//�ݹ�Ļ�������
	if (i < n)
	{
		Node* temp = newNode(arr[i]);//newһ����ʱ�ڵ�
		root = temp;//������ڵ�

		//��������
		root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

		//�����Һ���
		root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
	}
	return root;
}

void inOrder(Node* root)//�������һ����
{
	if (root != 0)
	{
		inOrder(root->left);//������ӽ��
		cout << root->data << " ";
		inOrder(root->right);//������ӽ��
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,6,6,6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	Node* root = new Node;//���ɸ��ڵ�
	root=insertLevelOrder(arr, root, 0, n);//���������ʽ���������
	inOrder(root);//��������鿴������

	return 0;
}
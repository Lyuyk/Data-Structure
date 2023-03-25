#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* left, * right;

	Node(int data)
	{	
		this->data = data;
		left = right = 0;
		
	}
};

void binaryTreeCreate(Node*& root)
{
	int data;

	cin >> data;

	if (data == 0)
	{
		root = 0;
	}
	else
	{
		root = new Node(data);
		binaryTreeCreate(root->left);
		binaryTreeCreate(root->right);
	}
}

bool helper(Node* root, long long lower, long long upper)
{
	if (root == nullptr)//�жϸ��ڵ��Ƿ�Ϊ�գ�������
	{
		return true;
	}
	if (root->data <= lower || root->data >= upper)//
	{
		return false;
	}
	return helper(root->left, lower, root->data) && helper(root->right, root->data, upper);
}

bool isBST(Node* root)
{
	return helper(root, LONG_MIN, LONG_MAX);
}

void isOrNotBST(Node* root)
{
	if (isBST(root))
		cout << "����Ϊ����������" << endl;
	else
	{
		cout << "������Ϊ����������" << endl;
	}
}

int main()
{
	/*   3
		/ \
	   2   5
	  / \
	 1   4
			*/
			//���ɶ�����
	/*struct Node* root = new Node(3);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(1);
	root->left->right = new Node(4);
	isOrNotBST(root);
	
	struct Node* root1 = new Node(0);
	isOrNotBST(root1);

	struct Node* root3 = new Node(30);
	root3->right = new Node(20);
	root3->right->right = new Node(10);
	isOrNotBST(root3);*/

	for (int i = 0; i < 36; i++)
	{
		Node* root4 = NULL;
		binaryTreeCreate(root4);
		isOrNotBST(root4);
	}

	return 0;
}
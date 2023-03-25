#include<iostream>
#include<vector>
#include<stack>
using namespace std;



struct Node
{
	int data;
	Node* left, *right;
	
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

void storeInorder(struct Node* root,vector<int> &array)//�ݹ��㷨���붯̬����
{
	if (root == 0)return;
	storeInorder(root->left,array);
	array.push_back(root->data);
	storeInorder(root->right,array);
}

void inOrder(struct Node* root)
{
	stack<Node*> s;
	Node* curr = root;

	while (curr != 0 || s.empty() == false)
	{
		while (curr != 0)//��������˽��
		{
			s.push(curr);//�������������ǰ����һ��ָ���ڽ�㴦
			curr = curr->left;
		}

		curr = s.top();//��ǰ����ڴ˵㴦����Ϊ��
		s.pop();

		cout << curr->data << " ";

		curr = curr->right;//����������
	}
}

int main()
{
	for (int i = 0; i < 36; i++)
	{
		Node* root = NULL;
		binaryTreeCreate(root);

		vector<int> arr;//ȫ������
		int index = 0;//ȫ���±����

		storeInorder(root, arr);
		cout << "���������";
		inOrder(root);
		cout << endl;
		cout << "������ת��Ϊ���飺";
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
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

void storeInorder(struct Node* root,vector<int> &array)//递归算法存入动态数组
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
		while (curr != 0)//到达最左端结点
		{
			s.push(curr);//遍历结点左子树前放置一个指针在结点处
			curr = curr->left;
		}

		curr = s.top();//当前结点在此点处必须为空
		s.pop();

		cout << curr->data << " ";

		curr = curr->right;//遍历右子树
	}
}

int main()
{
	for (int i = 0; i < 36; i++)
	{
		Node* root = NULL;
		binaryTreeCreate(root);

		vector<int> arr;//全局数组
		int index = 0;//全局下标变量

		storeInorder(root, arr);
		cout << "中序遍历：";
		inOrder(root);
		cout << endl;
		cout << "二叉树转换为数组：";
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
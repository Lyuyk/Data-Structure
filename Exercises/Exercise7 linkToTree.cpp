#include<iostream>
using namespace std;

struct Node
{
	int data;//数据域
	Node* left, * right;//左右孩子
};

Node* newNode(int data)//开辟新结点
{
	Node* node = (Node*)malloc(sizeof(Node));//申请内存
	node->data = data;//设置数据域
	node->left = node->right = 0;//初始化左右子结点
	return node;//返回根节点
}

Node* insertLevelOrder(int arr[], Node* root, int i, int n)//层序遍历方式插入结点
{
	//递归的基本情形
	if (i < n)
	{
		Node* temp = newNode(arr[i]);//new一个临时节点
		root = temp;//保存根节点

		//插入左孩子
		root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

		//插入右孩子
		root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
	}
	return root;
}

void inOrder(Node* root)//中序遍历一棵树
{
	if (root != 0)
	{
		inOrder(root->left);//输出左子结点
		cout << root->data << " ";
		inOrder(root->right);//输出右子结点
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,6,6,6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	Node* root = new Node;//生成根节点
	root=insertLevelOrder(arr, root, 0, n);//层序遍历方式插入二叉树
	inOrder(root);//中序遍历查看二叉树

	return 0;
}
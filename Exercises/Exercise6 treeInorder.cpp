#include<iostream>
#include<stack>
using namespace std;

typedef struct Node
{
	int data;//数据域
	struct Node* left;//左结点
	struct Node* right;//右子结点

	Node(int data)//构造函数
	{
		this->data = data;
		left = right = 0;
	}
};

void inOrder(struct Node* root)//中序遍历
{
	stack<Node*> s;//栈
	Node* curr = root;//保存根节点
	
	while (curr != 0 || s.empty() == false)
	{
		while (curr != 0)//到达最左端结点
		{
			s.push(curr);//遍历结点左子树前放置一个指针在结点处
			curr = curr->left;//转到下一个左子结点
		}

		curr = s.top();//当前结点在此点处必须为空
		s.pop();//弹出结点

		cout << curr->data << " ";

		curr = curr->right;//向右遍历右子树
	}
}

int main()
{
	/*   1
		/ \
	   2   3
	  / \
	 4   5
		    */
	//生成二叉树
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	inOrder(root);
	return 0;
}
#include<iostream>
using namespace std;

typedef struct tree
{
	int data;//数据域
	struct tree* left;//左子结点
	struct tree* right;//右子结点
}node, *PNode;

PNode firstLeaf;//记录叶子链表的第一个叶子结点
PNode pcurr;//记录叶子链表的当前结点

PNode createTreeNode(int data)
{
	PNode n = (PNode)malloc(sizeof(PNode));//申请内存
	n->data = data;//复制数据域
	n->left = 0;//初始化左结点
	n->right = 0;//初始化右结点

	return n;//返回根结点
}

void inOrder(PNode p)//中序遍历
{
	if (p == 0)
	{
		return;
	}
	inOrder(p->left);//遍历左节点
	cout << p->data << " ";//输出数据域
	inOrder(p->right);//遍历右结点
}

void leafLink(PNode root)
{
	if (!root)return;//根节点为空，返回
	if (root->left == 0 && root->right == 0)
	{
		if (firstLeaf == 0)
		{
			firstLeaf = root;//保存找到的第一个叶子结点
			pcurr = firstLeaf;
		}
		else
		{
			pcurr->right = root;
			pcurr = pcurr->right;//链接是用叶子结点的rightChild域存放指针
		}
	}

	if (root->left)
	{
		leafLink(root->left);//若左子树不为空，递归查找左叶子
	}

	if (root->right)
	{
		leafLink(root->right);//若右子树不为空，递归查找右子树
	}
}

void printLinkedlist(PNode head)
{
	PNode nowNode = head;//保存头结点
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
	//生成二叉树
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

	cout << "中序遍历：";
	inOrder(p1);
	cout << endl;

	leafLink(p1);
	cout << "叶结点链表：";
	while (firstLeaf)//输出叶结点链表
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
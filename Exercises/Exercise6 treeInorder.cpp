#include<iostream>
#include<stack>
using namespace std;

typedef struct Node
{
	int data;//������
	struct Node* left;//����
	struct Node* right;//���ӽ��

	Node(int data)//���캯��
	{
		this->data = data;
		left = right = 0;
	}
};

void inOrder(struct Node* root)//�������
{
	stack<Node*> s;//ջ
	Node* curr = root;//������ڵ�
	
	while (curr != 0 || s.empty() == false)
	{
		while (curr != 0)//��������˽��
		{
			s.push(curr);//�������������ǰ����һ��ָ���ڽ�㴦
			curr = curr->left;//ת����һ�����ӽ��
		}

		curr = s.top();//��ǰ����ڴ˵㴦����Ϊ��
		s.pop();//�������

		cout << curr->data << " ";

		curr = curr->right;//���ұ���������
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
	//���ɶ�����
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	inOrder(root);
	return 0;
}
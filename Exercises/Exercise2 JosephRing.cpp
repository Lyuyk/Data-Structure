#include<iostream>
#include<string>
using namespace std;

string Name[300];
int killed[300];

void init(int n)//��ʼ������
{
	for (int i = 0; i < n; i++)
	{
		cin >> Name[i];
		killed[i]= i+1;
	}
}

int main()
{
	int n, w, s, t;
	cin >> n;//һ����n����

	init(n);//����n��������
	cout << "init finish." << endl;

	cin >> w >> s;//w ��ʼ, s���

	w--;//�ڼ���ת��Ϊ �����±�
	t = 1;//��ǰ������
	int out = 0;//��̭�ĸ���

	if (s == 1)//����1����̭
	{
		if (w != 0)//����ʼλ�ò�Ϊ0
		{
			for (int i = w; i < n; i++)
			{
				cout << Name[i] << endl;
			}
			for (int i = 0; i < w; i++)
			{
				cout << Name[i] << endl;
			}
		}
		else//����ʼλ��Ϊ0
			for (int i = 0; i < n; i++)
			{
				cout << Name[i] << endl;
			}
		return 0;
	}

	while (out < n)
	{
		/*if (w == n)//n��������
			w = 0;*/
		if (killed[w%n] != -1)//�Ա�����λ��ȡ�࣬��Ϊ�ü�¼��������
		{
			w++;//��ǰ������λ��
			t++;//��ǰ����������
		}
		else
		{
			w++;
		}
		
		if (killed[w%n] != -1 && t == s)
		{
			cout << Name[w%n] << " " << killed[w%n] << endl;//��������̭����������ֲ����
			killed[w%n] = -1;
			w++;
			t = 1;
			out++;
		}
		
	}

	return 0;

}
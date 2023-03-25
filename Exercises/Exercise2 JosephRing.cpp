#include<iostream>
#include<string>
using namespace std;

string Name[300];
int killed[300];

void init(int n)//初始化数组
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
	cin >> n;//一共有n个人

	init(n);//输入n个人姓名
	cout << "init finish." << endl;

	cin >> w >> s;//w 开始, s间隔

	w--;//第几个转换为 对齐下标
	t = 1;//当前报的数
	int out = 0;//淘汰的个数

	if (s == 1)//若报1就淘汰
	{
		if (w != 0)//若开始位置不为0
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
		else//若开始位置为0
			for (int i = 0; i < n; i++)
			{
				cout << Name[i] << endl;
			}
		return 0;
	}

	while (out < n)
	{
		/*if (w == n)//n代表总数
			w = 0;*/
		if (killed[w%n] != -1)//对报到的位置取余，因为该记录数不重置
		{
			w++;//当前报到的位置
			t++;//当前报到的数字
		}
		else
		{
			w++;
		}
		
		if (killed[w%n] != -1 && t == s)
		{
			cout << Name[w%n] << " " << killed[w%n] << endl;//若满足淘汰条件，则出局并输出
			killed[w%n] = -1;
			w++;
			t = 1;
			out++;
		}
		
	}

	return 0;

}
#include "Arraylink.h"
#include<iostream>
using namespace std;

void Arraylink::addToArrayAtIndex(int index, int value)//将数值加插到指定下标，时间复杂度O(n)
{
	if (index == last + 1 && last+1<=len-1)//若下标为last+1
    {
		arr[last + 1] = value;
        last++;//last增1
        return;
    }

	if (index<0 || index>last - 1|| len-last-1<1)//下标不能小于0，不能大于末位下标，线性表满的时候不能插入
		return;
	else
	{
		for (int i = last; i >= index; i--)
		{
			arr[i + 1] = arr[i];
		}
		arr[index] = value;
	}
	last++;
}

void Arraylink::addToArrayByOrder()//按顺序插入元素
{
	int value;
	cout << "请输入要插入的数字：";
	cin >> value;
    int i = 0;
    for (i = 0; i <= last; i++)
    {
        if (arr[i] >= value)
        {
            addToArrayAtIndex(i, value);
			return;
        }
    }
    addToArrayAtIndex(last + 1, value);
}

void Arraylink::init(int x)//初始化顺序表
{
	cout << "请输入" << x << "个数字：" << endl;
	last = x - 1;//末位下标
	for (int i = 0; i <= last; i++)
	{
		cin >> arr[i];
	}	
}

void Arraylink::print() const
{
	for (int i = 0; i <= last; i++)//last为最后一个元素的下标，故小于等于
	{
		cout << arr[i]<<" ";
	}
}

int main()
{
	Arraylink arl1(20);//设置线性表总长度为20
	arl1.init(5);//初始化长度为5
	arl1.addToArrayByOrder();//按顺序插入值15
	arl1.print();//输出排序后结果
}


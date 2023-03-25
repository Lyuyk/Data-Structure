#include "Arraylink.h"
#include<iostream>
using namespace std;

void Arraylink::addToArrayAtIndex(int index, int value)//����ֵ�Ӳ嵽ָ���±꣬ʱ�临�Ӷ�O(n)
{
	if (index == last + 1 && last+1<=len-1)//���±�Ϊlast+1
    {
		arr[last + 1] = value;
        last++;//last��1
        return;
    }

	if (index<0 || index>last - 1|| len-last-1<1)//�±겻��С��0�����ܴ���ĩλ�±꣬���Ա�����ʱ���ܲ���
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

void Arraylink::addToArrayByOrder()//��˳�����Ԫ��
{
	int value;
	cout << "������Ҫ��������֣�";
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

void Arraylink::init(int x)//��ʼ��˳���
{
	cout << "������" << x << "�����֣�" << endl;
	last = x - 1;//ĩλ�±�
	for (int i = 0; i <= last; i++)
	{
		cin >> arr[i];
	}	
}

void Arraylink::print() const
{
	for (int i = 0; i <= last; i++)//lastΪ���һ��Ԫ�ص��±꣬��С�ڵ���
	{
		cout << arr[i]<<" ";
	}
}

int main()
{
	Arraylink arl1(20);//�������Ա��ܳ���Ϊ20
	arl1.init(5);//��ʼ������Ϊ5
	arl1.addToArrayByOrder();//��˳�����ֵ15
	arl1.print();//����������
}


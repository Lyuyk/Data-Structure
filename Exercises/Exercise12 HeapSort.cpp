#include<iostream>
#include<vector>
#include "maxHeap.h"
using namespace std;

int main()
{
	vector<int> arr;
	int val;
	while (true)
	{
		cin >> val;
		if (val == -1)
			break;
		arr.push_back(val);
	}
	int* brr = new int[arr.size()];
	for (int i = 0; i < arr.size(); i++)
	{
		brr[i] = arr[i];
	}

	Heap<int> heapArr=Heap<int>(brr,arr.size());
	heapArr.print();
	heapArr.heapSort();
	heapArr.print();
	return 0;
}
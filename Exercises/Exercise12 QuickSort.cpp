#include<iostream>
#include<vector>
using namespace std;
using std::swap;

int partition_2ways(vector<int>& nums, int left, int right)
{
	int v = nums[left];
	int i = left + 1;
	int j = right;
	while (true)
	{
		while (i < right && nums[i] <= v)
			i++;
		while (j >= left && nums[j] > v)
			j--;

		if (i > j)
			break;

		swap(nums[i++], nums[j--]);
	}
	swap(nums[left], nums[j]);
	return j;
}

void quick_sort_2ways(vector<int>& nums, int left, int right)
{
	if (left >= right)
		return;

	int p = partition_2ways(nums, left, right);
	quick_sort_2ways(nums, left, p - 1);
	quick_sort_2ways(nums, p + 1, right); 
}

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
	quick_sort_2ways(arr, 0, arr.size()-1);
	for (auto p:arr)
	{
		cout << p << " ";
	}
	return 0;
}
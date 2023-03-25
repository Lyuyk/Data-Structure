#pragma once
class UFSets
{
public:
	UFSets(int sz = 10);
	~UFSets() { delete[]parent; }
	UFSets& operator=(UFSets& R);
	void Union(int Root1, int Root2);
	int Find(int x);
	void WeightedUnion(int Root1, int Root2);
private:
	int* parent;
	int size;
};

#pragma once
const int maxValue = 1000;
template<class T, class E>
struct MSTEdgeNode
{
	int tail, head;
	E cost;
	MSTEdgeNode() :tail(-1), head(-1), cost(0) {}
	bool operator <=(MSTEdgeNode<T, E>& R) { return cost <= R.cost; }
	bool operator >(MSTEdgeNode<T, E>& R) { return cost > R.cost; }
};

template<class T, class E>
class MinSpanTree
{
protected:
	MSTEdgeNode<T, E>* edgevalue;
	int maxSize;
	int currentSize;
public:
	MinSpanTree(int sz = 9)
	{
		currentSize = 0;
		if (sz < 9)maxSize = 9;
		edgevalue = new MSTEdgeNode<T, E>[sz];
	}
	void Insert(MSTEdgeNode<T, E>& item)
	{
		edgevalue[currentSize++] = item;
	}
	MSTEdgeNode<T, E>& showEdgevalue(int pos);
	int getEdgeSize() { return currentSize; }
};

template<class T, class E>
inline MSTEdgeNode<T, E>& MinSpanTree<T, E>::showEdgevalue(int pos)
{
	if (pos >= 0 && pos < maxSize)return edgevalue[pos];
}


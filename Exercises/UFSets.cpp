#include "UFSets.h"

UFSets::UFSets(int sz)
{
	size = sz;
	parent = new int[size];
	for (int i = 0; i < size; i++)parent[i] = -1;
}

void UFSets::Union(int Root1, int Root2)
{
	parent[Root2] = Root1;
}

int UFSets::Find(int x)
{
	while (parent[x] > 0)x = parent[x];
	return x;
}



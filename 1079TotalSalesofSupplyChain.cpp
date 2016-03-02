#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

map<int, vector<int>> tree;
map<int, int> leave;

double total = 0;

void DFS(int level, int node, double r)
{
	if (tree.find(node) == tree.end())
	{
		total += leave[node] * pow(1 + r / 100, level);
		return;
	}
	level++;
	for (int child : tree[node])
	{
		DFS(level, child, r);
	}
}

int main()
{
	int N;
	double P, r;
	cin >> N >> P >> r;

	for (int i = 0; i < N;i++)
	{
		int K;
		cin >> K;
		if(K>0)
		while (K--)
		{
			int node;
			cin >> node;
			tree[i].push_back(node);
		}
		else
		{
			int stock;
			cin >> stock;
			leave[i] = stock;
		}
	}
	
	DFS(0, 0, r);
	total *= P;
	printf("%.1f", total);
	system("pause");
}
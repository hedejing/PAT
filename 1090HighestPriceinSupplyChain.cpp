#include <vector>
#include <iostream>
#include <map>
#include <math.h>

using namespace std;

map<int, vector<int>> edges;

void DFS(int node, int length, int &max_path, int &cnt)
{
	if (edges.find(node) == edges.end())
	{
		if (length > max_path)
		{
			max_path = length;
			cnt = 1;
		}
		else if (length == max_path)
			cnt++;
		return;
	}
	length++;
	for (int child : edges[node])
		DFS(child, length, max_path, cnt);
}

int main()
{
	int N;
	double P, r;
	cin >> N >> P >> r;
	for (int i = 0; i < N; i++)
	{
		int sup;
		cin >> sup;
		edges[sup].push_back(i);
	}
	int max_path = 0, cnt = 0;
	DFS(-1, 0, max_path, cnt);
	double res = P*pow(1 + r / 100, max_path-1);
	printf("%.2f %d", res, cnt);
	system("pause");

}
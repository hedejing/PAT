#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
map<int, vector<int>> network;

void NetTra(int level, const vector<int> & nodes, set<int> &has_forwards, int upperbound)
{
	vector<int> newnodes;
	for(int node:nodes)
	{
		for (int child : network[node])
		{
			if (has_forwards.find(child) == has_forwards.end())
			{
				has_forwards.insert(child);
				newnodes.push_back(child);
				if (has_forwards.size() == upperbound)
					return;
			}
		}
	}
	level--;
	if(level > 0)
		NetTra(level, newnodes, has_forwards, upperbound);
}

int main()
{
	int N, L;
	cin >> N >> L;

	for (int i = 1; i <= N; i++)
	{
		int M;
		cin >> M;
		while (M--)
		{
			int node;
			cin >> node;
			network[node].push_back(i);
		}
	}

	int K;
	cin >> K;
	while (K--)
	{
		int id;
		cin >> id;
		set<int> has_forwards;
		has_forwards.insert(id);
		vector<int> nodes;
		nodes.push_back(id);
		NetTra(L, nodes, has_forwards, N);
		cout << has_forwards.size()-1 << endl;
	}
	system("pause");
}
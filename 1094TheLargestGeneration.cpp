#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void levelTravel(int level, const vector<int> & nodes, map<int, vector<int>> & tree, int &maxlevel, int &maxNodeNum)
{
	int thisNodeNum = nodes.size();
	if (thisNodeNum > maxNodeNum)
	{
		maxlevel = level;
		maxNodeNum = thisNodeNum;
	}
	level++;
	vector<int> newnodes;
	for (int node : nodes)
		newnodes.insert(newnodes.end(), tree[node].begin(), tree[node].end());
	if (newnodes.size())
		levelTravel(level, newnodes, tree, maxlevel, maxNodeNum);
	else
		return;
}

int main()
{
	int N, M;
	cin >> N >> M;
	map<int, vector<int>> tree;
	for (int i = 0; i < M; i++)
	{
		int node, childNum;
		cin >> node >> childNum;
		vector<int> childs(childNum, 0);
		for (int j = 0; j < childNum; j++)
			cin >> childs[j];
		tree.insert({node, childs});
	}

	int maxlevel=0, maxNodeNum=0;
	vector<int> nodes;
	nodes.push_back(1); //root
	levelTravel(1, nodes, tree, maxlevel, maxNodeNum);
	cout << maxNodeNum<< " " << maxlevel;
	system("pause");
}
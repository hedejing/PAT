#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


struct Path {
	static vector<int> weight;
	vector<int> nodes;
	Path(const vector<int> &_nodes)
		:nodes(_nodes) {}

	Path AddNode (int node) const
	{
		vector<int> newnodes(nodes);
		newnodes.push_back(node);
		return Path(newnodes);
	}

	void print()
	{
		int cnt = 0;
		for (int i = 0; i < nodes.size(); i++)
		{
			cout << weight[nodes[i]];
			cnt++;
			if (cnt < nodes.size())
				cout << " ";
		}
		cout << endl;
	}

	bool operator<(Path &other) 
	{
		int k = min(nodes.size(), other.nodes.size());
		for (int i = 0; i < k; i++)
		{
			if (weight[nodes[i]] == weight[other.nodes[i]])
				continue;
			else if (weight[nodes[i]] < weight[other.nodes[i]])
				return false;
			else
				return true;
		}
		return false;
	}
};

void DFS(const vector<int> & weight, map<int, vector<int>> & edges, const Path& path, vector<int> & cost, int target, vector<Path> &results)
{
	int node = path.nodes.back();
	if (edges.find(node)==edges.end())//leaf node
		return;
	for (int child : edges[node])
	{
		cost[child] = cost[node] + weight[child];
		if (cost[child] > target)
			continue;
		else
		{
			Path childPath = path.AddNode(child);
			if (cost[child] == target && edges.find(child)==edges.end())//leaf node
				results.push_back(childPath);
			else
				DFS(weight, edges, childPath, cost, target, results);
		}
	}
}

vector<int> Path::weight;

int main()
{
	int N, M, S;
	cin >> N >> M >> S;
	vector<int> weight(N, 0);
	for (int i = 0; i < N; i++)
		cin >> weight[i];
	Path::weight = weight;
	map<int, vector<int>> edges;
	for (int i = 0; i < M; i++)
	{
		int node, childNum;
		cin >> node >> childNum;
		vector<int> childs(childNum, 0);
		for (int j = 0; j < childNum; j++)
			cin >> childs[j];
		edges[node] = childs;
	}
	vector<int> nodes;
	nodes.push_back(0); //root
	Path path(nodes);
	vector<int> cost(N, 0);
	cost[0] = weight[0];
	vector<Path> results;
	if (cost[0] == S)
		results.push_back(path);
	DFS(weight, edges, path, cost, S, results);
	sort(results.begin(), results.end());
	for (auto resultPath : results)
		resultPath.print();
	system("pause");
}
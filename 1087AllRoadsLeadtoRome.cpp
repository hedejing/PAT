#include <iostream>
#include <map>
#include <string>
#include <queue>

using namespace std;

typedef double costype;

struct Node {
	string name;
	costype cost_from_start;
	int hap;
	int cnt;
	Node(string _name, costype _cost, int _hap, int _cnt)
		:name(_name), cost_from_start(_cost), hap(_hap), cnt(_cnt) {}

	bool operator<(const Node &other) const {
		if (cost_from_start == other.cost_from_start)
		{
			if (hap == other.hap)
				return cnt > other.cnt;
			else
				return hap < other.hap;
		}
		return cost_from_start > other.cost_from_start;
	}
};

int main()
{
	int N, K;
	string start;
	cin >> N >> K >> start;

	map<string, int> hap;
	map<string, bool> visit;
	map<string, costype > cost_from_start;
	map<string, int> hap_from_start;
	map<string, double> avg_hap_from_start;
	map<string, int> same_least_cost;
	map<string, vector<string>> route_from_start;
	N--;
	while (N--)
	{
		string s;
		int value;
		cin >> s >> value;
		hap[s] = value;
		visit[s] = false;
		cost_from_start[s] = 99999999999;
		hap_from_start[s] = -99999999999;
		avg_hap_from_start[s] = -99999999999;
		same_least_cost[s] = 1;
		route_from_start[s].clear();
	}
	map<string, map<string, int>> infos;
	while (K--)
	{
		string c1, c2;
		costype cost;
		cin >> c1 >> c2 >> cost;
		infos[c1][c2] = cost;
		infos[c2][c1] = cost;
	}
	priority_queue<Node> q;
	cost_from_start[start] = 0;
	hap_from_start[start] = 0;
	avg_hap_from_start[start] = 0;
	same_least_cost[start] = 1;
	route_from_start[start].push_back(start);

	q.push(Node(start, 0, 0, 0));
	while (!q.empty())
	{
		Node node = q.top();
		q.pop();
		if (visit[node.name])
			continue;
		visit[node.name] = true;
		for (auto i : infos[node.name])
		{
			costype newcost = cost_from_start[node.name] + i.second;
			int newhap = hap_from_start[node.name] + hap[i.first];
			double newavghap = (double)newhap / (node.cnt + 1);
			if (newcost == cost_from_start[i.first])
				same_least_cost[i.first] += same_least_cost[node.name];
			if (newcost < cost_from_start[i.first])
				same_least_cost[i.first] = same_least_cost[node.name];

			if ((newcost < cost_from_start[i.first]) ||
				((newcost == cost_from_start[i.first]) && (newhap > hap_from_start[i.first])) ||
				((newcost == cost_from_start[i.first]) && (newhap == hap_from_start[i.first]) &&
					((route_from_start[i.first].size() - 1) > (node.cnt + 1)))
				)
			{
				cost_from_start[i.first] = newcost;
				hap_from_start[i.first] = newhap;
				avg_hap_from_start[i.first] = newavghap;
				vector<string> newroute(route_from_start[node.name]);
				newroute.push_back(i.first);
				route_from_start[i.first] = newroute;
				Node newnode(i.first, newcost, newhap, node.cnt + 1);
				q.push(newnode);
			}
		}
	}

	cout << same_least_cost["ROM"] << " " << cost_from_start["ROM"] << " " << hap_from_start["ROM"] << " " << (int)avg_hap_from_start["ROM"] << endl;
	bool first = true;
	for (auto city : route_from_start["ROM"])
	{
		if (!first)
			cout << "->";
		first = false;
		cout << city;
	}
	system("pause");

}

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, S, D;
	cin >> N >> M >> S >> D;
	map<int, vector<int>> edges;
	//first--dist second--weight infos between citys
	map<pair<int, int>, pair<int, int>> infos;
	vector<bool> visit(N, false);
	vector<int> minDists(N, 0x0fffffff);
	vector<int> CostWithMinDists(N, 0x0fffffff);
	minDists[S] = CostWithMinDists[S] = 0;
	//fisrt--dist second--index
	typedef pair<int, int> pii;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	vector<int> last(N, 0);
	for (int i = 0; i < M; i++)
	{
		int c1, c2, dist, cost;
		cin >> c1 >> c2 >> dist >> cost;
		infos[{c1, c2}] = { dist, cost };
		infos[{c2, c1}] = { dist, cost };
		edges[c1].push_back(c2);
		edges[c2].push_back(c1);
	}
	q.push({ 0, S });
	while (!q.empty())
	{
		int tovisit = q.top().second;
		q.pop();
		if (visit[tovisit])
			continue;
		visit[tovisit] = true; //visit this city
		//update others
		for (int other : edges[tovisit])
		{
			int updateDist = minDists[tovisit] + infos[{tovisit, other}].first;
			int updateCost = CostWithMinDists[tovisit] + infos[{tovisit, other}].second;
			if (updateDist < minDists[other] || (updateDist == minDists[other] && updateCost < CostWithMinDists[other]))
			{
				minDists[other] = updateDist;
				CostWithMinDists[other] = updateCost;
				q.push({ updateDist , other });
				last[other] = tovisit;
			}
		}
	}
	vector<int> passcitys;
	for (int i = D;; i = last[i])
	{
		passcitys.push_back(i);
		if (i == S)
			break;
	}
	reverse(passcitys.begin(), passcitys.end());
	for (int city : passcitys)
		cout << city << " ";
	cout << minDists[D] <<" "<< CostWithMinDists[D];
	system("pause");
}
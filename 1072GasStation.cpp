#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 1000
#define MAX_M 10
vector<int> graph[MAX_N + 1 + MAX_M + 1];
int info[MAX_N + 1 + MAX_M + 1][MAX_N + 1 + MAX_M + 1];
int N, M, K, Ds;

int id(char name[])
{
	int font = name[0];
	int i = 0;
	if (font == 'G')
		i = 1;
	int value = 0;
	for (; i < strlen(name); i++)
	{
		value *= 10;
		value += name[i] - '0';
	}
	if (font == 'G')
		value += N+1;
	return value;
}

struct Node {
	int id;
	int distance;

	Node(int _id, int _distance)
		:id(_id), distance(_distance) {}
	bool operator<(const Node &n) const {
		if (distance == n.distance)
			return id < n.id;
		return distance > n.distance;
	}
};

struct Data {
	int mindist;
	int total;
	int id;

	bool operator<(const Data & d)const {
		if (mindist == d.mindist)
		{
			if (total == d.total)
				return id < d.id;
			else
				return total < d.total;
		}
		else
			return mindist > d.mindist;
	}
};

Data datas[MAX_M + 1];

int main()
{
	cin >> N >> M >> K >> Ds;
	while (K--)
	{
		char a[6], b[6];
		int len;
		scanf("%s %s %d", a, b, &len);
		int aid = id(a);
		int bid = id(b);
		graph[aid].push_back(bid);
		graph[bid].push_back(aid);
		info[aid][bid] = len;
		info[bid][aid] = len;
	}
	int cnt = 0;
	for (int i = 1; i <= M; i++)
	{
		vector<bool> visit(N + 1 + M + 1, false);
		vector<int> dist(N + 1 + M + 1, 1 << 30);
		priority_queue<Node> q;
		q.push(Node(N + 1 + i, 0));
		while (!q.empty())
		{
			Node n = q.top();
			q.pop();
			if (visit[n.id])
				continue;
			visit[n.id] = true;
			for (int neighbor : graph[n.id])
			{
				int newdist = n.distance + info[n.id][neighbor];
				if (newdist < dist[neighbor])
				{
					dist[neighbor] = newdist;
					q.push(Node(neighbor, newdist));
				}
			}
		}

		long int total = 0;
		bool exist = true;
		int mind = 1<<30-1;
		for (int j = 1; j <= N; j++)
		{
			if ((dist[j] > Ds) || (visit[j] == false))
				exist = false;
			if (dist[j] < mind)
				mind = dist[j];
			total += dist[j];
		}

		if (exist)
		{
			datas[cnt].id = i;
			datas[cnt].mindist = mind;
			datas[cnt].total = total;
			cnt++;
		}
	}

	if(cnt == 0)
		puts("No Solution");
	else
	{
		sort(datas, datas + cnt);
		int best = datas[0].id;
		int minavg = datas[0].total;
		int mindist = datas[0].mindist;
		cout << "G" << best << endl;
		double avg = (double)minavg / N;
		printf("%.1f %.1f", (float)mindist, avg);
	}
	system("pause");
}
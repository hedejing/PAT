#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 501
int C[MAX];
vector<int> graph[MAX];
int T[MAX][MAX];
bool visit[MAX];
int Dist[MAX];
vector<int> Last[MAX];
int Cmax, N, Sp, M;

struct Node {
	int dist;
	int id;
	
	Node(int _dist, int _id)
		:dist(_dist), id(_id) {}

	bool operator<(const Node &other) const {
		return dist > other.dist;
	}
};

int minSend = 0x7fffffff, minBack = 0x7fffffff;
vector<int> minPath;

void calc(const vector<int> &path, int &Send, int &Back)
{
	int send = 0, back = 0;
	for (int i = 1; i < path.size(); i++)
	{
		int use = C[path[i]] - Cmax / 2;
		if (use > 0)
			back += use;
		else
		{
			use = -use;
			if (back >= use)
				back -= use;
			else
			{
				use -= back;
				back = 0;
				send += use;
			}
		}
	}

	Send = send;
	Back = back;
}

void dfs(int node, vector<int> path)
{
	path.push_back(node);
	if (node == 0)
	{
		vector<int> right(path);
		reverse(right.begin(), right.end());
		int send, back;
		calc(right, send, back);
		if (send < minSend || (send == minSend && back < minBack))
		{
			minSend = send;
			minBack = back;
			minPath = right;
		}
	}
	for (int child : Last[node])
	{
		dfs(child, path);
	}
}

int main()
{
	cin >> Cmax >> N >> Sp >> M;

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &(C[i]));
		visit[i] = false;
		Dist[i] = 0x7fffffff;
	}

	while (M--)
	{
		int Si, Sj, Tij;
		scanf("%d %d %d", &Si, &Sj, &Tij);
		graph[Si].push_back(Sj);
		graph[Sj].push_back(Si);
		T[Si][Sj] = Tij;
		T[Sj][Si] = Tij;

	}

	priority_queue<Node> q;
	q.push(Node(0, 0));
	Dist[0] = 0;

	while (!q.empty())
	{
		Node n = q.top();
		q.pop();
		if (visit[n.id])
			continue;
		visit[n.id] = true;

		for (int neighbor : graph[n.id])
		{
			int newdist = Dist[n.id] + T[n.id][neighbor];
			if (newdist < Dist[neighbor])
			{
				Dist[neighbor] = newdist;
				Last[neighbor].clear();
				Last[neighbor].push_back(n.id);

				q.push(Node(newdist, neighbor));
			}
			else if(newdist == Dist[neighbor])
			{
				Last[neighbor].push_back(n.id);
			}
		}
	}
	dfs(Sp, vector<int>());
	cout << minSend << " ";
	bool first = true;
	for (auto p : minPath)
	{
		if (!first)
			cout << "->";
		first = false;
		cout << p;
	}
	cout << " " << minBack;
	system("pause");
}
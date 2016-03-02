#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MAX 10000
vector<int> tree[MAX + 1];
bool acy = false;
vector<bool> visit(MAX + 1, false);

void check(int node, int fa)
{
	if (acy)
		return;

	if (tree[node].size() == 1 && tree[node].front() == fa)
		return;

	for (int child : tree[node])
	{
		if (child != fa)
		{
			if (visit[child])
			{
				acy = true;
				break;
			}
			else
				check(child, node);
			visit[child] = true;
		}
	}

	return;
}

void dfs(int node, int height, int fa, int &maxheight)
{
	if (tree[node].size() == 1 && tree[node].front() == fa)
	{
		if (height >= maxheight)
			maxheight = height;
		return;
	}

	for (int child : tree[node])
	{
		if (child != fa)
			dfs(child, height + 1, node, maxheight);
	}
	return;
}

int height(int root)
{
	int maxheight = 0;
	dfs(root, 0, -1, maxheight);
	return maxheight;
}

int parent[MAX + 1];

int find(int i)
{
	return parent[i] == i ? i : parent[i] = find(parent[i]);
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i <= N; i++)
		parent[i] = i;

	set<int> nodes;
	for (int i = 1; i <= N; i++)
		nodes.insert(i);
	N--;
	if (N == 0)
	{
		puts("1");
		system("pause");
		return 0;
	}
	while (N--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
		//nodes.insert(a);
		//nodes.insert(b);
		int ra = find(a);
		int rb = find(b);
		parent[ra] = rb;
	}

	//check connected
	set<int> component;
	for (int node : nodes)
	{
		int root = find(node);
		component.insert(root);
	}
	if (component.size() > 1)
	{
		printf("Error: %d components", component.size());
		system("pause");
		return 0;
	}
	//check acyclic
	visit[1] = true;
	check(1, -1);
	if (acy)
	{
		printf("Error: 1 components");
		system("pause");
		return 0;
	}

	int maxheight = 0;
	vector<int> roots;
	for (int node : nodes)
	{
		int h = height(node);
		if (h > maxheight)
		{
			maxheight = h;
			vector<int> newroots;
			newroots.push_back(node);
			roots = newroots;
		}
		else if (h == maxheight)
			roots.push_back(node);
	}

	for (int root : roots)
		printf("%d\n", root);
	system("pause");
}
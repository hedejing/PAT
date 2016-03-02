#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

struct Node {
	int key;
	int next;

	Node() {}

	Node(int _key, int _next)
		:key(_key), next(_next) {}

};

#define MAX 100000

int main()
{
	int N, head;
	cin >> N >> head;
	vector<pair<int, Node>> linklist;
	map<int, Node> links;
	for (int i = 0; i < N;i++)
	{
		int addr, key, next;
		cin >> addr >> key >> next;
		links[addr] = Node(key, next);
	}
	for (int node = head; node != -1; node = links[node].next)
		linklist.push_back({ node, links[node] });

	sort(linklist.begin(), linklist.end(), [](const pair<int, Node> &p1, const pair<int, Node> &p2) {
		return p1.second.key < p2.second.key;
	});

	if (linklist.size() == 0)
		printf("0 -1");
	else
	{
		printf("%d %05d\n", linklist.size(), linklist[0].first);
		for (int i = 0; i < linklist.size(); i++)
		{
			printf("%05d %d ", linklist[i].first, linklist[i].second.key);
			if (i < linklist.size() - 1)
				printf("%05d\n", linklist[i + 1].first);
			else
				printf("-1\n");
		}
	}
	
	return 0;
	system("pause");
}
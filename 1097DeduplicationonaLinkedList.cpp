#include <vector>
#include <iostream>

using namespace std;

struct Node {
	int key;
	int next;

	Node() {
		next = -1;
	}
};

Node nodes[100000];
vector<bool> visit(10000, false);

int main()
{
	int head, N;
	scanf("%d %d", &head, &N);
	bool start = false;
	while (N--)
	{
		int node, key, next;
		scanf("%d %d %d", &node, &key, &next);
		if (node == head)
			start = true;
		nodes[node].key = key;
		nodes[node].next = next;
	}

	int dupHead = -1;
	int lastNormal = head;
	int lastDup;
	bool firstDup = true;
	int nextNode;
	int key = nodes[head].key;
	key = key >= 0 ? key : -key;
	visit[key] = true;
	for (int node = nodes[head].next; node != -1; node = nextNode)
	{
		int key = nodes[node].key;
		key = key >= 0 ? key : -key;
		nextNode = nodes[node].next;
		nodes[node].next = -1;
		if (visit[key])
		{
			if (firstDup)
			{
				firstDup = false;
				dupHead = node;
			}
			else
				nodes[lastDup].next = node;
			lastDup = node;
		}
		else
		{
			visit[key] = true;
			nodes[lastNormal].next = node;
			lastNormal = node;
		}
	}
	if (!start)
	{
		system("pause");
		return 0;
	}
	for (int node = head; node != -1; node = nodes[node].next)
		if(nodes[node].next!=-1)
			printf("%05d %d %05d\n", node, nodes[node].key, nodes[node].next);
		else
			printf("%05d %d -1\n", node, nodes[node].key);

	for (int node = dupHead; node != -1; node = nodes[node].next)
		if (nodes[node].next != -1)
			printf("%05d %d %05d\n", node, nodes[node].key, nodes[node].next);
		else
			printf("%05d %d -1\n", node, nodes[node].key);

	system("pause");
}
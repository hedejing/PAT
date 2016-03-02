#include <iostream>
#include <stack>
using namespace std;

struct Node {
	int key;
	int next;
};

const int MAX_N = 100000;

Node nodes[MAX_N];

struct Data {
	int addr;
	int next;

	Data(int _addr, int _next) 
		:addr(_addr), next(_next){}
};

int main()
{
	int head, N, K;
	cin >> head >> N >> K;
	while (N--)
	{
		int addr, key, next;
		scanf("%d %d %d", &addr, &key, &next);
		nodes[addr].key = key;
		nodes[addr].next = next;
	}
	int cnt = 0;
	stack<Data> s;
	int nextone, newhead = head, lastend;
	bool first = true;
	for (int node = head; node != -1; node = nextone)
	{
		cnt++;
		nextone = nodes[node].next;
		s.push(Data(node, nextone));
		if (cnt %K == 0)
		{
			if (first)
			{
				newhead = node;
				first = false;
			}
			else
			{
				nodes[lastend].next = node;
			}

			int head = s.top().addr;
			s.pop();
			while (!s.empty())
			{
				const Data &nextone = s.top();
				s.pop();
				nodes[head].next = nextone.addr;
				head = nextone.addr;
			}
			nodes[head].next = nextone;
			lastend = head;
		}
	}

	for (int node = newhead; node != -1; node = nodes[node].next)
		if (nodes[node].next == -1)
			printf("%05d %d -1\n", node, nodes[node].key);
		else
			printf("%05d %d %05d\n", node, nodes[node].key, nodes[node].next);
	system("pause");
}
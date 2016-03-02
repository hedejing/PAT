#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct Node {
	char key;
	int next;
};

#define MAX 100000

Node list1[MAX];
Node list2[MAX];

int main()
{
	int N, head1, head2;
	cin >> head1 >> head2 >> N;
	Node nodes[MAX];
	while (N--)
	{
		int addr, next;
		char key;
		cin >> addr >> key >> next;
		nodes[addr].key = key;
		nodes[addr].next = next;
	}
	for (int node = head1; node != -1; node = nodes[node].next)
		list1[node] = nodes[node];
	for (int node = head2; node != -1; node = nodes[node].next)
		list2[node] = nodes[node];
	/*int n1 = head1, n2 = head2;
	int start = -1;
	while (n1!=-1 && n2!=-1)
	{
		if (n1 == n2)
		{
			start = n1;
			break;
		}
		n1 = list1[n1].next;
		n2 = list2[n2].next;
	}*/
	vector<bool> visit(MAX, false);
	for (int node = head1; node != -1; node = list1[node].next)
		visit[node] = true;
	int start = -1;
	for (int node = head2; node != -1; node = list2[node].next)
		if (visit[node])
		{
			start = node;
			break;
		}
	if (start != -1)
		printf("%05d", start);
	else
		cout << -1;
	system("pause");
}
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int h(char name[])
{
	int result = 0;
	for (int i = 0; i < 3; i++)
	{
		result *= 26;
		result += (name[i] - 'A');
	}
	return result;
}

void rh(int value, char name[])
{
	name[0] = 'A' + value / 26 / 26;
	name[1] = 'A' + value % (26 * 26) / 26;
	name[2] = 'A' + value % 26;
	name[3] = 0;
}

#define MAX 26 * 26 * 26
int parent[MAX], weight[MAX];

int find(int i)
{
	return parent[i] == i ? i : parent[i] = find(parent[i]);
}

int main()
{
	for (int i = 0; i < MAX; i++)
	{
		parent[i] = i;
		weight[i] = 0;
	}

	int N, K;
	cin >> N >> K;
	set<int> ids;
	while (N--)
	{
		char n1[4], n2[4];
		int w;
		scanf("%s %s %d", n1, n2, &w);
		int id1 = h(n1);
		int id2 = h(n2);
		ids.insert(id1);
		ids.insert(id2);
		int r1 = find(id1);
		int r2 = find(id2);
		parent[r1] = r2;
		weight[id1] += w;
		weight[id2] += w;
	}

	map<int, vector<int>> gangs;
	for (auto id : ids)
	{
		int root = find(id);
		gangs[root].push_back(id);
	}

	map<int, int> head_size;
	for (auto gang : gangs)
	{
		int size = 0, head, max_weight = -1, cnt = 0;
		for (auto member : gang.second)
		{
			int w = weight[member];
			size += w;
			cnt++;
			if (w > max_weight)
			{
				max_weight = w;
				head = member;
			}
		}
		if (size > K * 2 && cnt > 2)
			head_size.insert({ head, cnt});
	}
	cout << head_size.size() << endl;
	for (auto iter : head_size)
	{
		char name[4];
		rh(iter.first, name);
		printf("%s %d\n", name, iter.second);
	}
	system("pause");
}
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int coin;
	map<int, int> occur;
	for (int i = 0; i < N; i++)
	{
		cin >> coin;
		occur[coin]++;
	}
	bool has = false;
	for (auto i:occur)
	{
		int now = i.first;
		int left = M - now;
		auto iter = occur.find(left);
		if ((left != now && iter != occur.end()) || (left == now && iter->second >= 2))
		{
			printf("%d %d\n", now, left);
			has = true;
			break;
		}
	}
	if (!has)
		puts("No Solution");
	system("pause");
}
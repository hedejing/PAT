#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<vector<string>> record(K+1);
	while (N--)
	{
		string name;
		int num;
		cin >> name >> num;
		while (num--)
		{
			int id;
			cin >> id;
			record[id].push_back(name);
		}
	}
	for (int i = 1; i <= K; i++)
	{
		printf("%d %d\n", i, record[i].size());
		sort(record[i].begin(), record[i].end());
		for (auto name : record[i])
			printf("%s\n", name.data());
	}
	system("pause");
}
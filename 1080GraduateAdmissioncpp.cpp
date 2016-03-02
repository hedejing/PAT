#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_M 100

struct Data {
	int id;
	int ge;
	int gi;
	vector<int> prefer;

	bool operator<(Data &other)const
	{
		double fg = ge+gi;
		double ofg = other.ge+other.gi;
		if (fg == ofg)
		{
			return ge > other.ge;
		}
		else
			return fg > ofg;
	}

	bool same(Data &other)
	{
		if (ge == other.ge && gi == other.gi)
			return true;
		else
			return false;
	}
};

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	int quota[MAX_M];
	for (int i = 0; i < M; i++)
		cin >> quota[i];
	vector<Data> datas(N);
	for (int i = 0; i < N; i++)
	{
		cin >> datas[i].ge >> datas[i].gi;
		datas[i].prefer.assign(K, 0);
		for (int j = 0; j < K; j++ )
			cin >> datas[i].prefer[j];
		datas[i].id = i;
	}
	sort(datas.begin(), datas.end());
	vector<vector<int>> results(M);
	for (int i = 0; i < N;)
	{
		vector<Data> ranksame;
		Data d = datas[i];
		ranksame.push_back(datas[i]);
		for (int j = i + 1; j < N; j++)
		{
			if (datas[j].same(d))
				ranksame.push_back(datas[j]);
			else
				break;
		}
		i += ranksame.size();
		vector<int> tochose(ranksame.size(), -1);
		for (int j = 0; j < ranksame.size();j++)
		{
			for (int pre : ranksame[j].prefer)
			{
				if (quota[pre] > 0)
				{
					tochose[j] = pre;
					break;
				}
			}
		}
		for (int j = 0; j < ranksame.size(); j++)
		{
			int chose = tochose[j];
			if (chose >= 0)
			{
				quota[chose]--;
				results[chose].push_back(ranksame[j].id);
			}
		}
	}

	for (auto school : results)
	{
		bool first = true;
		sort(school.begin(), school.end());
		for (int id : school)
		{
			if (!first)
				printf(" ");
			first = false;
			printf("%d", id);
		}
		printf("\n");
	}
	system("pause");
}
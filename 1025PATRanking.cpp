#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

struct Data {
	string reg;
	int score;
	int id;
	bool operator<(Data &d)
	{
		if (score == d.score)
			return reg < d.reg;
		else
			return score > d.score;
	}
};

Data datas[30000];

int main()
{
	int N;
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int K;
		cin >> K;
		for (int j = 0; j < K; j++)
		{
			cin >> datas[cnt].reg >> datas[cnt].score;
			datas[cnt].id = i;
			cnt++;
		}
	}

	sort(datas, datas + cnt);

	int localrank[100];
	int localscore[100];
	int localnum[100];
	memset(localrank, 0, sizeof(int) * 100);
	memset(localnum, 0, sizeof(int) * 100);

	for (int i = 0; i < 100; i++)
		localscore[i] = 0x0fffffff;
	int score = 0x0fffffff;
	int rank = 1;
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
	{
		int this_score = datas[i].score;
		if (this_score < score)
		{
			score = this_score;
			rank = i + 1;
		}
		int id = datas[i].id;
		localnum[id]++;
		if (this_score < localscore[id])
		{
			localscore[id] = this_score;
			localrank[id] = localnum[id];
		}

		printf("%s %d %d %d\n", datas[i].reg.data(), rank, id + 1, localrank[id]);
	}
	system("pause");
}
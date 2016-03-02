#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

struct Data {
	int arrive;
	int process;

	bool operator<(const Data &d) const {
		return arrive < d.arrive;
	}
};

#define MAX 10000
Data datas[MAX];
#include <queue>

int main()
{
	int N, K;
	cin >> N >> K;
	int cnt = 0;
	for (int i = 0; i<N; i++)
	{
		int hour, minute, second, process;
		scanf("%d:%d:%d %d", &hour, &minute, &second, &process);
		int arrive = hour * 60*60 + minute * 60 + second;
		if (arrive >= 17 * 3600 + 1)
			continue;
		datas[cnt].arrive = arrive;
		datas[cnt].process = min(process, 60) * 60;
		cnt++;
	}
	sort(datas, datas + cnt);
	priority_queue<int, vector<int>, greater<int>> wins;
	int time = 8 * 60 *60;
	int wait = 0;
	for (int i = 0; i < cnt;i++)
	{
		auto iter = datas[i];
		if (wins.size() < K)
		{
			if (iter.arrive < time)
				wait += time - iter.arrive;
			time = max(time, iter.arrive);
			int endtime = time + iter.process;
			/*int hour = endtime / 3600;
			int minute = (endtime - hour * 3600) / 60;
			int second = (endtime - hour * 3600 - minute * 60);
			printf("!!%02d:%02d:%02d--\n", hour, minute, second);*/
			wins.push(endtime);
		}
		else
		{
			int endtime = wins.top();
			wins.pop();
			/*int hour = endtime / 3600;
			int minute = (endtime - hour * 3600) / 60;
			int second = (endtime - hour * 3600 - minute * 60);
			printf("--%02d:%02d:%02d--\n", hour, minute, second);*/
			if(endtime > iter.arrive)
				wait += endtime - iter.arrive;
			time = max(iter.arrive, endtime);
			int newend = time + iter.process;
			wins.push(newend);
		}
	}
	printf("%.1f", (double)wait /60/ cnt);
	system("pause");
}

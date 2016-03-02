#include <iostream>
#include <algorithm>

using namespace std;

struct Data {
	int time;
	int play;
	int isVIP;
	bool pass;
	int wait;

	Data() {
		pass = false;
	}

	bool operator<(const Data &d) const {
		return time < d.time;
	}
};

const int MAX = 10000;

Data datas[MAX];

struct Table {
	int id;
	int endtime;
	bool vip;
	int count;

	Table() {
		endtime = 8*3600;
		vip = false;
		count = 0;
	}
};

const int MAX_K = 100;
Table tables[MAX_K];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int hour, minute, second, play, isVIP;
		scanf("%d:%d:%d %d %d", &hour, &minute, &second, &play, &isVIP);
		datas[i].time = hour * 3600 + minute * 60 + second;
		datas[i].play = min(play, 120);
		datas[i].isVIP = isVIP;
	}
	sort(datas, datas + N);

	int K, M;
	cin >> K >> M;
	for (int i = 0; i < K; i++)
		tables[i].id = i;
	while (M--)
	{
		int vip;
		cin >> vip;
		tables[vip - 1].vip = true;
	}

	for (int i = 0; i < N; i++)
	{
		if (datas[i].pass)
			continue;
		int now = datas[i].time;
		while (true)
		{
			auto res = min_element(tables, tables + K, [now](const Table& t1, const Table &t2) {
				int diff1 = max(t1.endtime - now, 0);
				int diff2 = max(t2.endtime - now, 0);
				if (diff1 == diff2)
					return t1.id < t2.id;
				else
					return diff1 < diff2;
			});
			if (res->endtime <= now)
			{
				//find avaliable vip tables
				int find = -1;
				for (int j = 0; j < K; j++)
				{
					if (tables[j].endtime <= now && tables[j].vip)
					{
						find = j;
						break;
					}
				}
				if (datas[i].isVIP && find >= 0)
				{
					if (now < 21 * 3600)
						tables[find].count++;
					tables[find].endtime = now + datas[i].play * 60;
				}
				else
				{
					if (now < 21 * 3600)
						res->count++;
					res->endtime = now + datas[i].play * 60;
				}
				datas[i].wait = 0;
				break;
			}
			else
			{
				now = res->endtime;
				//check if there is a vip now
				bool vip_waiting = false;
				int j;
				for (j = i; j < N; j++)
				{
					if (datas[j].time > now)
						break;
					if (!datas[j].pass && datas[j].isVIP)
					{
						vip_waiting = true;
						break;
					}
				}
				if (res->vip && vip_waiting)
				{
					datas[j].pass = true;
					datas[j].wait = now - datas[j].time;
					if (now < 21 * 3600)
						res->count++;
					res->endtime = now + datas[j].play * 60;
					continue;
				}
				else
				{
					if (now < 21 * 3600)
						res->count++;
					res->endtime = now + datas[i].play * 60;
					datas[i].wait = now - datas[i].time;
					break;
				}
			}
		}
	}

	sort(datas, datas + N, [](const Data &d1, const Data &d2) {
		int s1 = d1.time + d1.wait;
		int s2 = d2.time + d2.wait;
		if (s1 == s2)
			return d1.time < d2.time;
		else
			return s1 < s2;
	});

	for (int i = 0; i < N; i++)
	{
		int hour = datas[i].time / 3600;
		int minute = datas[i].time % 3600 / 60;
		int second = datas[i].time % 3600 % 60;

		int serve = datas[i].time + datas[i].wait;
		int hs = serve / 3600;
		int ms = serve % 3600 / 60;
		int ss = serve % 3600 % 60;
		if (serve < 21 * 3600)
			printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", hour, minute, second, hs, ms, ss, (datas[i].wait + 30) / 60);
	}
	for (int i = 0; i < K; i++)
	{
		if (i != 0)
			printf(" ");
		printf("%d", tables[i].count);
	}
	system("pause");
}
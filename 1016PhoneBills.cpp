#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Time {
	int month;
	int day;
	int hour;
	int minute;

	Time(int mo, int d, int h, int mi)
		:month(mo), day(d), hour(h), minute(mi) {}

	int pass() const {
		return day * 24 * 60 + hour * 60 + minute;
	}

	bool operator<(const Time &t) const {
		return pass() < t.pass();
	}
};

struct Record {
	Time t;
	bool online;

	Record(const Time &_t, bool _online)
		:t(_t), online(_online) {}

	bool operator<(const Record &r) const {
		return t < r.t;
	}
};

int main()
{
	int toll[24];
	for (int i = 0; i < 24; i++)
		cin >> toll[i];
	int N;
	cin >> N;
	map<string, vector<Record>> records;
	int m;
	while (N--)
	{
		string name, state;
		int month, day, hour, minute;
		cin >> name;
		scanf("%d:%d:%d:%d:%d %s", &month, &day, &hour, &minute);
		cin >> state;
		m = month;
		bool s;
		if (state == "on-line")
			s = true;
		else
			s = false;
		records[name].push_back(Record(Time(month, day, hour, minute), s));
	}

	for (auto i = records.begin(); i != records.end(); i++)
		sort(i->second.begin(), i->second.end());
	map<string, bool> toprint;
	for (auto iter : records)
	{
		toprint[iter.first] = false;
		const vector<Record> &rs = iter.second;
		for (int i = 0; i < rs.size() - 1; i++)
		{
			if (rs[i].online && !rs[i + 1].online)
			{
				toprint[iter.first] = true;
				break;
			}
		}
	}
	for (auto i : records)
	{
		if (!toprint[i.first])
			continue;
		printf("%s %02d\n", i.first.data(), m);
		const vector<Record> &rs = i.second;
		int total = 0;
		for (int i = 0; i < rs.size()-1; i++)
		{
			if (rs[i].online && !rs[i+1].online)
			{
				const Time &start = rs[i].t;
				const Time &end = rs[i+1].t;
				int h = start.hour;
				int m = start.minute;
				int fee = 0;
				for (int s = start.pass(); s < end.pass(); s++)
				{
					fee += toll[h];
					m++;
					if (m == 60)
					{
						m = 0;
						h++;
					}
					if (h == 24)
						h = 0;
				}
				int pass = end.pass() - start.pass();
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", start.day, start.hour, start.minute, end.day, end.hour, end.minute, pass, (double)fee/100);
				total += fee;
			}
		}
		printf("Total amount: $%.2f\n", (double)total / 100);
	}
	system("pause");

}
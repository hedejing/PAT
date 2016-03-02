#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;


int pass(int hour, int minute, int second)
{
	return hour * 3600 + minute * 60 + second;
}

struct Data {
	int t;
	bool in;

	Data(int _t, bool _in)
		:t(_t), in(_in) {}
	
	bool operator<(const Data &other) const {
		return t < other.t;
	}
};

int main()
{
	int N, K;
	cin >> N >> K;
	map<string, vector<Data>> records;
	for (int i = 0; i < N; i++)
	{
		char number[8], state[5];
		int hour, minute, second;
		scanf("%s %d:%d:%d %s", number, &hour, &minute, &second, state);
		bool in;
		if (strcmp(state, "in") == 0)
			in = true;
		else
			in = false;
		string v(number, number + 8);
		records[v].push_back(Data(pass(hour, minute, second), in));
	}

	for (auto iter = records.begin(); iter != records.end(); iter++)
		sort(iter->second.begin(), iter->second.end());
	map<string, int> totals;
	vector<pair<string, vector<Data>>> v_rec;
	for (auto iter : records)
	{
		int total = 0;
		auto i = iter.second.begin();
		vector<Data> datas;
		while (i + 1 != iter.second.end())
		{
			if (i->in && !(i + 1)->in)
			{
				int pass = (i + 1)->t - i->t;
				total += pass;
				datas.push_back(*i);
				datas.push_back(*(i+1));
			}
			i++;
		}
		if(total > 0)
			totals[iter.first] = total;
		v_rec.push_back({ iter.first, datas });
	}

	vector<int> begins(v_rec.size(), 0);
	while (K--)
	{
		int hour, minute, second;
		scanf("%d:%d:%d", &hour, &minute, &second);
		Data d(pass(hour, minute, second), false);
		int cnt = 0;
		for (int k = 0; k < v_rec.size();k++)
		{
			const pair<string, vector<Data>> &i = v_rec[k];
			if (begins[k] >= i.second.size())
				continue;
			auto pos = upper_bound(i.second.begin()+begins[k], i.second.end(), d);
			begins[k] = pos- i.second.begin();
			if (pos != i.second.begin())
			{
				if ((pos-1)->in && !pos->in)
					cnt++;
			}
		}
		printf("%d\n", cnt);
	}

	vector<pair<string, int>> vtotals(totals.begin(), totals.end());
	sort(vtotals.begin(), vtotals.end(), [](const pair<string, int> &p1, const pair<string, int> &p2) {
		if (p1.second == p2.second)
			return p1.first < p2.first;
		else
			return p1.second > p2.second;
	});
	int maxvalue = vtotals.front().second;
	for (auto iter : vtotals)
		if (iter.second == maxvalue)
			printf("%s ", iter.first.data());
	int hour = maxvalue / 3600;
	int minute = (maxvalue - 3600 * hour) / 60;
	int second = (maxvalue - 3600 * hour - 60*minute) % 60;
	printf("%02d:%02d:%02d", hour, minute, second);
	system("pause");
}
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_K 5
int score[MAX_K+1];
map<int, int> totals;

int Total(const vector<int> & sc)
{
	int total = 0;
	for (int s : sc)
	{
		if (s >= 0)
			total += s;
	}
	return total;
}

bool show(const vector<int> &sc)
{
	for (int s : sc)
		if (s >= 0)
			return true;
	return false;
}

int perfect(const vector<int> &sc)
{
	int cnt = 0;
	for (int i = 1; i < sc.size(); i++)
	{
		if (sc[i] == score[i])
			cnt++;
	}
	return cnt;
}

bool comp(const pair<int, vector<int>> &p1, const pair<int, vector<int>> &p2) 
{
	int t1 = totals[p1.first];
	int t2 = totals[p2.first];
	if (t1 == t2)
	{
		int pe1 = perfect(p1.second);
		int pe2 = perfect(p2.second);
		if (pe1 == pe2)
			return p1.first < p2.first;
		else
			return pe1 > pe2;
	}
	return t1 > t2;
}

int main()
{
	int N, K, M;
	cin >> N >> K >> M;
	for (int i = 1; i <= K; i++)
		cin >> score[i];
	map<int, vector<int>> record;
	while (M--)
	{
		int id, pid, part;
		cin >> id >> pid >> part;
		if (record[id].size() == 0)
		{
			record[id].assign(K + 1, -2);
			record[id][pid] = part;
		}
		else
		{
			int last = record[id][pid];
			if (part > last)
				record[id][pid] = part;
		}
	}
	for (auto i : record)
		totals[i.first] = Total(i.second);
	vector<pair<int, vector<int>>> v_rec(record.begin(), record.end());
	sort(v_rec.begin(), v_rec.end(), comp);
	int cnt = 1;
	int last_total = -1;
	map<int, int> rank;
	int temp;
	for (auto i:v_rec)
	{
		if (totals[i.first] != last_total)
		{
			last_total = totals[i.first];
			temp = cnt;
		}
		rank[i.first] = temp;
		cnt++;
	}
	for (auto i : v_rec)
	{
		if (!show(i.second))
			break;
		printf("%d %05d %d", rank[i.first], i.first, totals[i.first]);
		for (int k = 1; k <= K;k++)
		{
			int s = i.second[k];
			if (s == -2)
				printf(" -");
			else
				printf(" %d", max(s, 0));
		}
		printf("\n");
	}
	system("pause");
}
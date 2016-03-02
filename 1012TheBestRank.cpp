#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sort_by_grade(const pair<int, int> &p1, const pair<int, int> &p2)
{
	return p1.second > p2.second;
}

bool sort_by_grade_d(const pair<int, double> &p1, const pair<int, double> &p2)
{
	return p1.second > p2.second;
}

void fill_id(vector<int> &ids, const vector<pair<int, int>> & sorted)
{
	int rank = -1;
	int lastgrade = -1;
	for (int i = 0; i < sorted.size(); i++)
	{
		if (sorted[i].second != lastgrade)
		{
			rank = i;
			lastgrade = sorted[i].second;
		}
		ids[sorted[i].first] = rank;
	}
}

void fill_id_d(vector<int> &ids, const vector<pair<int, double>> & sorted)
{
	int rank = -1;
	double lastgrade = -1;
	for (int i = 0; i < sorted.size(); i++)
	{
		if (sorted[i].second != lastgrade)
		{
			rank = i;
			lastgrade = sorted[i].second;
		}
		ids[sorted[i].first] = rank;
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> cs(N), es(N), ms(N);
	vector<pair<int, double>> as(N);
	for (int i = 0; i < N; i++)
	{
		int id, c, m, e;
		cin >> id >> c >> m >> e;
		cs[i] = { id, c };
		ms[i] = { id,m };
		es[i] = { id,e };
		double a = (double)(c + m + e) / 3;
		as[i] = { id, a };
	}
	sort(cs.begin(), cs.end(), sort_by_grade);
	sort(ms.begin(), ms.end(), sort_by_grade);
	sort(es.begin(), es.end(), sort_by_grade);
	sort(as.begin(), as.end(), sort_by_grade_d);
	vector<int> cids(1000000, -1), mids(1000000, -1), eids(1000000, -1), aids(1000000, -1);
	fill_id(cids, cs);
	fill_id(mids, ms);
	fill_id(eids, es);
	fill_id_d(aids, as);

	while (M--)
	{
		int id;
		cin >> id;
		int crank = cids[id];
		if (crank == -1)
		{
			puts("N/A");
			continue;
		}
		int mrank = mids[id];
		int erank = eids[id];
		int arank = aids[id];
		if (arank <= crank && arank <= mrank && arank <= erank)
		{
			printf("%d A\n", arank + 1);
			continue;
		}
		if (crank <= arank && crank <= mrank && crank <= erank)
		{
			printf("%d C\n", crank + 1);
			continue;
		}
		if (mrank <= crank && mrank <= arank && mrank <= erank)
		{
			printf("%d M\n", mrank + 1);
			continue;
		}
		printf("%d E\n", erank + 1);
	}
	system("pause");
}
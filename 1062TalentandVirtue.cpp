#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Data {
	string id;
	int virtue;
	int talent;

	bool operator<(Data &other)
	{
		int total = virtue + talent;
		int o_total = other.virtue + other.talent;
		if (total == o_total)
		{
			if (virtue == other.virtue)
			{
				return id < other.id;
			}
			else
				return virtue > other.virtue;
		}
		else
			return total > o_total;
	}
};
#define MAX 100000
Data sagas[MAX], nobleman[MAX], foolmen[MAX], rest[MAX];

void print(Data data[], int sz)
{
	for (int i = 0; i < sz; i++)
		printf("%s %d %d\n", data[i].id.data(), data[i].virtue, data[i].talent);

}
int main()
{
	int N, L, H;
	cin >> N >> L >> H;
	int s_sz, n_sz, f_sz, r_sz;
	s_sz = n_sz = f_sz = r_sz = 0;
	for (int i = 0; i < N; i++)
	{
		string id;
		int virtue, talent;
		cin >> id >> virtue >> talent;
		if (virtue < L || talent < L)
			continue;
		if (virtue >= H && talent >= H)
		{
			sagas[s_sz].id = id;
			sagas[s_sz].virtue = virtue;
			sagas[s_sz].talent = talent;
			s_sz++;
			continue;
		}
		if (talent < H && virtue >= H)
		{
			nobleman[n_sz].id = id;
			nobleman[n_sz].virtue = virtue;
			nobleman[n_sz].talent = talent;
			n_sz++;
			continue;
		}
		if (talent < H && virtue < H && virtue >= talent)
		{
			foolmen[f_sz].id = id;
			foolmen[f_sz].talent = talent;
			foolmen[f_sz].virtue = virtue;
			f_sz++;
			continue;
		}
		if (talent >= L && virtue >= L)
		{
			rest[r_sz].id = id;
			rest[r_sz].talent = talent;
			rest[r_sz].virtue = virtue;
			r_sz++;
			continue;
		}
	}

	sort(sagas, sagas + s_sz);
	sort(nobleman, nobleman + n_sz);
	sort(foolmen, foolmen + f_sz);
	sort(rest, rest + r_sz);

	cout << s_sz + n_sz + f_sz + r_sz << endl;
	print(sagas, s_sz);
	print(nobleman, n_sz);
	print(foolmen, f_sz);
	print(rest, r_sz);
	system("pause");

}
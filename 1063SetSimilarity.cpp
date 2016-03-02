#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

void SetSimi(const set<int> &a, const set<int> &b)
{
	vector<int> in;
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(in));
	int Nc = in.size();
	int Nt = a.size() + b.size() - Nc;
	double sim = (double)Nc / Nt*100;
	printf("%.1f%%\n", sim);
}


int main()
{
	int N;
	cin >> N;
	vector<set<int>> sets;
	sets.resize(N);
	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> M;
		for (int j = 0; j < M; j++)
		{
			int value;
			cin >> value;
			sets[i].insert(value);
		}
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		SetSimi(sets[a - 1], sets[b - 1]);
	}
	system("pause");
}
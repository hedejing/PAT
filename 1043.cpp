#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Data {
	int need;
	int value;
};

#define MAX_N 500
#define MAX_M 100000
int N, M;

Data datas[MAX_N];
int best[MAX_M + 1];

int get(int budget)
{
	if (best[budget] >= 0)
		return best[budget];
	else
	{
		int mx = 0;
		for (int i = 0; i < N; i++)
			if(budget >= datas[i].need)
				mx = max(mx, get(budget - datas[i].need) + datas[i].value);
		return best[budget] = mx;
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> datas[i].need >> datas[i].value;
	memset(best, -1, sizeof(best));
	cout << get(M) << endl;
}

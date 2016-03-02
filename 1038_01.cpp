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
int best[MAX_M+1];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> datas[i].need >> datas[i].value;
	//memset(best, 0, sizeof(best));
	for (int i = 0; i <= M; i++)
		best[i] = 0;
	for (int i = 0; i < N; i++)
		for (int j = M; j >= datas[i].need; j--)
			best[j] = max(best[j], best[j - datas[i].need] + datas[i].value);
	cout << *max_element(best, best + M+1) << endl;
}

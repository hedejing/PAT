#include <iostream>

using namespace std;

#define MAX_M 1287
#define MAX_N 129
#define MAX_L 61

int d[MAX_L][MAX_M][MAX_N];
int volume[MAX_L*MAX_M*MAX_N];
int p[MAX_L*MAX_M*MAX_N];

int h(int i, int j, int k)
{
	return i *MAX_M*MAX_N + j * MAX_N + k;
}

int parent(int i)
{
	return p[i] == i ? i : p[i] = parent(p[i]);
}

int main()
{
	int M, N, L, T;
	cin >> M >> N >> L >> T;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < M; j++)
			for (int k = 0; k < N; k++)
			{
				scanf("%d", &(d[i][j][k]));
				p[h(i, j, k)] = h(i, j, k);
				volume[h(i, j, k)] = 0;
			}

	for (int i = 0; i < L; i++)
		for (int j = 0; j < M; j++)
			for (int k = 0; k < N; k++)
			{
				/*if (k < N-1 && d[i][j][k] * d[i][j][k + 1])
					p[parent(h(i,j,k + 1))] = parent(h(i,j,k));*/

				if (k >= 1 && d[i][j][k] * d[i][j][k - 1])
					p[parent(h(i, j, k - 1))] = parent(h(i, j, k));


				if (j >= 1 && d[i][j][k] * d[i][j-1][k])
					p[parent(h(i, j-1, k))] = parent(h(i, j, k));


				/*if (j < M-1 && d[i][j][k] * d[i][j+1][k])
					p[parent(h(i, j+1, k))] = parent(h(i, j, k));*/


				if (i >= 1 && d[i][j][k] * d[i-1][j][k])
					p[parent(h(i-1, j, k))] = parent(h(i, j, k));


			/*	if (i < L-1 && d[i][j][k] * d[i+1][j][k])
					p[parent(h(i+1, j, k))] = parent(h(i, j, k));*/
			}

	for (int i = 0; i < L; i++)	
		for (int j = 0; j < M; j++)
			for (int k = 0; k < N; k++)
			{
				int root = parent(h(i, j, k));
				volume[root]++;
			}

	long int total = 0;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < M; j++)
			for (int k = 0; k < N; k++)
			{
				if (d[i][j][k] && volume[h(i, j, k)] >= T)
					total += volume[h(i, j, k)];
			}

	cout << total;
	system("pause");
}
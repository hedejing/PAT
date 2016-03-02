#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1000

int best[MAX][MAX], coupon[MAX][MAX];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i + 1; j++)
		{
			scanf("%d", &(coupon[i][j]));
			best[i][j] = -1;
		}
	for (int i = 0; i < n; i++)
	{
		best[i][0] = best[i - 1][0] + coupon[i][0];
		for (int j = 1; j < i; j++)
			best[i][j] = max(best[i - 1][j - 1], best[i - 1][j]) + coupon[i][j];
		best[i][i] = best[i - 1][i - 1] + coupon[i][i];
	}

	cout << *max_element(best[n - 1], best[n - 1] + n) << endl;
}
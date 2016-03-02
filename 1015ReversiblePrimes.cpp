#include <string>
#include <sstream>
#include <iostream>
#include <math.h>
#include <vector>

#define MAX 1000000

using namespace std;

int main()
{
	vector<bool> visit(MAX+1, false);
	int T = sqrt(MAX + 0.5);
	visit[1] = true;
	visit[0] = true;
	for (int i = 2; i <= T; i++)
	{
		if (!visit[i])
		{
			for (int j = i*i; j <= MAX; j += i)
				visit[j] = true;
		}
	}
	int N, D;
	while (cin >> N)
	{
		if (N < 0)
			break;
		cin >> D;
		if (visit[N])
		{
			cout << "No" << endl;
			continue;
		}

		string s;
		while (N)
		{
			int left = N%D;
			s.push_back(left + '0');
			N = N / D;
		}
		int res = 0;
		for (int i = 0; i < s.length(); i++)
		{
			res *= D;
			int digit = s[i] - '0';
			res += digit;
		}
		if (visit[res])
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	system("pause");
}
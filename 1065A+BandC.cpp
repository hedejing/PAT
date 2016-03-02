#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	long long int A, B, C;
	int cnt = 0;
	while (T--)
	{
		cnt++;
		cin >> A >> B >> C;
		bool res;
		if (A >= 0 && B >= 0)
		{
			if (C >= 0)
			{
				long long int diff = C - B;
				if (A > diff)
					res = true;
				else
					res = false;
			}
			else
				res = true;
		}
		else if (A <= 0 && B <= 0 )
		{
			if (C >= 0)
				res = false;
			else
			{
				long long int diff = C - B;
				if (A > diff)
					res = true;
				else
					res = false;
			}
		}
		else
		{
			if (A + B > C)
				res = true;
			else
				res = false;
		}
		if (res)
			printf("Case #%d: true\n", cnt);
		else
			printf("Case #%d: false\n", cnt);
	}
	system("pause");
}
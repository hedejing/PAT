#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	long long p, pa, pat;
	p = pa = pat = 0;
	string s;
	cin >> s;
	for (char c : s)
	{
		if (c == 'P')
			p++;
		else if (c == 'A')
			pa += p;
		else
			pat = (pat + pa) % 1000000007;
	}
	cout << pat;
	system("pause");
}
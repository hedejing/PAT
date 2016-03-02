#include <iostream>
#include <string>
#include <vector>

using namespace std;

string check(const vector<string> &strs, vector<int> &ends, int N)
{
	string s;
	while (true)
	{
		bool same = true;
		char c = strs[0][ends[0]];
		for (int i = 0; i < N; i++)
		{
			if (ends[i] <0 || strs[i][ends[i]] != c)
			{
				same = false;
				break;
			}
			ends[i]--;
		}
		if (same)
			s = c + s;
		else
			return s;
	}
}

int main()
{
	int N;
	cin >> N;
	vector<string> strs;
	strs.resize(N);
	vector<int> ends(N, 0);
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		getline(cin, strs[i]);
		ends[i] = strs[i].length() - 1;
	}
	string res = check(strs, ends, N);
	if (res.size() > 0)
		cout << res;
	else
		cout << "nai";
	system("pause");
}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include <vector>

int pa(string s)
{
	string ns(2 * s.length() + 1, '#');
	for (int i = 0; i < s.length(); i++)
		ns[2 * i + 1] = s[i];
	vector<int> p(ns.length(), 0);
	int id, mx;
	mx = id = 0;
	for (int i = 1; i < ns.length(); i++)
	{
		p[i] = i < mx ? min(p[2 * id - i], mx - i) : 1;
		while ((i + p[i] < ns.length()) && (i - p[i]>= 0 )
			&& (ns[i + p[i]] == ns[i - p[i]]))
			p[i]++;
		if (p[i] + i > mx)
		{
			mx = p[i] + i;
			id = i;
		}
	}
	auto maxlen = max_element(p.begin(), p.end());
	int pos = maxlen - p.begin();
	if (pos % 2 == 0)
		return *maxlen / 2 * 2;
	else
		return (*maxlen+1)/2*2-1;
}

int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		string s;
		cin >> s;
		cout << pa(s) << endl;
	}
	system("pause");
}
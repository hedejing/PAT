#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define MAX 10010

int main()
{
	int Ms, N;
	cin >> Ms >> N;
	vector<bool> visit(MAX + 1, false);
	int T = sqrt(MAX + 0.5);
	visit[0] = visit[1] = true;
	for (int i = 2; i <= T; i++)
		if (!visit[i])
			for (int j = i*i; j <= MAX; j += i)
				visit[j] = true;

	for (; Ms <= MAX; Ms++)
		if (!visit[Ms])
			break;

	vector<bool> has(Ms, false);

	int q_T = sqrt(MAX + 0.5);
	vector<int> qs;
	qs.push_back(0);
	for (int i = 1; i <= q_T; i++)
		qs.push_back(i*i);

	bool first = true;
	while (N--)
	{
		int value;
		cin >> value;
		int pos = value % Ms;
		bool place = false;
		for (int i = 0; i < Ms;i++)
		{
			int probe = i*i;
			if (!has[(pos + probe) % Ms])
			{
				pos = (pos + probe) % Ms;
				place = true;
				break;
			}
		}
		if (place)
		{
			has[pos] = true;
			if (!first)
				cout << " ";
			cout << pos;
		}
		else
			cout << " " << "-";
		first = false;
	}
	system("pause");
}
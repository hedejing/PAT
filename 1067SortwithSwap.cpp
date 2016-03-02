#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> origin(N, 0);
	vector<int> inv(N, 0);
	set<int> errs;
	for (int i = 0; i < N; i++)
	{
		cin >> origin[i];
		inv[origin[i]] = i;
		if (origin[i] != 0 && i != origin[i])
			errs.insert(origin[i]);
	}
	int cnt = 0;
	while (true)
	{
		int zero_pos = inv[0];
		if (zero_pos == 0)
		{
			if (errs.empty())
				goto HERE;
			int first_err = inv[*errs.begin()];
			errs.erase(*errs.begin());
			cnt++;
			int value = origin[first_err];
			inv[value] = 0;
			inv[0] = first_err;
			origin[first_err] = 0;
			origin[0] = value;
			zero_pos = first_err;
		}
		cnt++;
		//swap(0,value)
		int value = zero_pos;
		int value_pos = inv[value];
		inv[0] = value_pos;
		inv[value] = zero_pos;
		origin[zero_pos] = value;
		origin[value_pos] = 0;
		errs.erase(value);
	}
HERE:
	cout << cnt;
	system("pause");
}
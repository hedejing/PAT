#include <string>
#include <iostream>
#include <map>

using namespace std;

map<char, int> getCount(string input)
{
	map<char, int> count;
	for (int i = 0; i < input.length(); i++)
	{
		auto res = count.find(input[i]);
		if (res != count.end())
			res->second++;
		else
			count[input[i]] = 1;
	}
	return count;
}

int main()
{
	string have, need;
	cin >> have >> need;
	map<char, int> have_cnt = getCount(have);
	map<char, int> need_cnt = getCount(need);
	
	int left = 0;
	for (auto iter : need_cnt)
	{
		//cout << iter.first << " " << iter.second << endl;
		auto res = have_cnt.find(iter.first);
		if (res == have_cnt.end())
			left += iter.second;
		else
		{
			int has = have_cnt[iter.first];
			if (iter.second > has)
				left += iter.second - has;
			else
				continue;
		}
	}
	if (left == 0)
	{
		cout << "Yes ";
		cout << have.length() - need.length() << endl;
	}
	else
	{
		cout << "No ";
		cout << left << endl;
	}

	system("pause");
}
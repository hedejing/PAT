#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#define MAX 500000

using namespace std;
vector<int> res[MAX];
vector<bool> is_sort(MAX, false);

int H(char name[])
{
	int result = 0;
	for (int i = 0; i <= 2; i++)
	{
		result *= 26;
		result += name[i] - 'A';
	}
	result *= 26;
	result += name[3] - '0';
	return result;
}

int main()
{
	int N, K;
	cin >> N >> K;
	//map<string, vector<int>> record;
	set<int> keys;
	while (K--)
	{
		int id, num;
		cin >> id >> num;
		while (num--)
		{
			//string name;
			char name[4];
			//cin >> name;
			scanf("%s", name);
			//	record[name].push_back(id);
			int key = H(name);
			res[key].push_back(id);
			keys.insert(key);
		}
	}

	/*for (auto iter = record.begin(); iter != record.end();iter++)
	{
		vector<int> &r = iter->second;
		sort(r.begin(), r.end());
	}*/


	while (N--)
	{
		//string name;
		char name[4];
		//cin >> name;
		scanf("%s", name);
		//vector<int> &r = record[name];
		int key = H(name);
		vector<int> &r = res[key];
		if (!is_sort[key])
		{
			sort(r.begin(), r.end());
			is_sort[key] = true;
		}

		printf("%s %d", name, r.size());
		for (auto s : r)
			printf(" %d", s);
		printf("\n");
	}
	//system("pause");
	return 0;
}
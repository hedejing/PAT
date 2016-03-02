#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> datas(N,0);
	map<int, int> record;
	for (int i = 0; i < N; i++)
	{
		cin >> datas[i];
		record[datas[i]]++;
	}
	bool has = false;
	for (int i = 0; i < N; i++)
	{
		if (record[datas[i]] == 1)
		{
			has = true;
			cout << datas[i];
			break;
		}
	}

	if (!has)
		cout << "None" << endl;

	system("pause");

}
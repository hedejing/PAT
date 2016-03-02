#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool need(string input)
{
	for (char c : input)
		if (c == '1' || c == '0' || c == 'l'|| c == 'O')
			return true;
	return false;
}
int main()
{
	int N;
	cin >> N;
	int cnt = 0;
	vector<string> names;
	vector<string> pwds;
	names.resize(N);
	pwds.resize(N);
	if (N == 1)
	{
		cout << "There is 1 account and no account is modified" << endl;
		system("pause");
		return 0;
	}

	for (int i = 0; i < N; i++)
	{
		string name, pwd;
		cin >> name >> pwd;
		if (!need(pwd))
			continue;
		for (int i = 0; i < pwd.length(); i++)
		{
			if (pwd[i] == '1')
				pwd[i] = '@';
			if (pwd[i] == '0')
				pwd[i] = '%';
			if (pwd[i] == 'l')
				pwd[i] = 'L';
			if (pwd[i] == 'O')
				pwd[i] = 'o';
		}
		names[cnt] = name;
		pwds[cnt] = pwd;
		cnt++;
	}
	if (cnt == 0)
	{
		cout << "There are " << N << " accounts and no account is modified";
		system("pause");
		return 0;
	}

	cout << cnt << endl;

	for (int i = 0; i < cnt; i++)
		cout << names[i] << " " << pwds[i] << endl;
	system("pause");
}
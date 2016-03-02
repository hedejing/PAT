#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	set<char> subs;
	for (char c : s2)
		subs.insert(c);
	string s3;
	for (char c : s1)
	{
		if (subs.find(c) == subs.end())
			s3.push_back(c);
	}
	cout << s3;
	system("pause");

}
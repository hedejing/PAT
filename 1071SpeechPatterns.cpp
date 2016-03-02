#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool an(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	if (c >= 'A' && c <= 'Z')
		return true;
	if (c >= 'a'&& c <= 'z')
		return true;
	return false;
}

int main()
{
	string input;
	getline(cin, input);
	for (int i = 0; i < input.length(); i++)
	{
		if (!an(input[i]))
			input[i] = ' ';
		if (input[i] >= 'A' && input[i] <= 'Z')
			input[i] = input[i] + 'a' - 'A';
	}
	stringstream ss;
	ss << input;
	map<string, int> words;
	while (ss.good())
	{
		string word;
		ss >> word;
		if (word.length() == 0)
			continue;
		words[word]++;
	}
	vector<pair<string, int>> record(words.begin(), words.end());
	sort(record.begin(), record.end(), [](const pair<string, int> &p1, const pair<string, int> &p2) {
		if (p1.second == p2.second)
			return p1.first < p2.first;
		else
			return p1.second > p2.second;
	});
	cout << record.front().first << " " << record.front().second;
	system("pause");
	
}
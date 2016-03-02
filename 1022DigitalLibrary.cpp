#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>


using namespace std;

int main()
{
	int N;
	cin >> N;
	cin.ignore();
	vector<map<string, vector<string>>> maps(6);
	while (N--)
	{
		string id, title, author, keywords, publisher, year;
		getline(cin, id);
		getline(cin, title);
		maps[1][title].push_back(id);
		getline(cin, author);
		maps[2][author].push_back(id);
		getline(cin, keywords);
		stringstream ss;
		ss << keywords;
		while (ss.good())
		{
			string word;
			ss >> word;
			maps[3][word].push_back(id);
		}
		getline(cin, publisher);
		maps[4][publisher].push_back(id);
		getline(cin, year);
		maps[5][year].push_back(id);
	}
	int M;
	cin >> M;
	cin.ignore();
	while (M--)
	{
		string query;
		getline(cin, query);
		printf("%s\n", query.data());
		auto pos = query.find(':');
		int start = pos + 1;
		for (int i = pos + 1; i < query.length(); i++)
			if (query[i] != ' ')
			{
				start = i;
				break;
			}
		string q = query.substr(start, query.length() - start);
		int kind = query[0] - '0';
		auto res = maps[kind].find(q);
		if (res == maps[kind].end())
			puts("Not Found");
		else
		{
			vector<string> ids = res->second;
			sort(ids.begin(), ids.end());
			for (auto id : ids)
				printf("%s\n", id.data());
		}
	}
	system("pause");
}
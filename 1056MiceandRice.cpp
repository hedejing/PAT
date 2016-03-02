#include <iostream>
#include <vector>

using namespace std;

vector<bool> game(const vector<int> & group, const vector<int> &weight)
{
	int winner, maxsize = -1;
	vector<bool> result(group.size(), false);
	for (int i = 0; i < group.size(); i++)
	{
		if (weight[group[i]] > maxsize)
		{
			maxsize = weight[group[i]];
			winner = i;
		}
	}
	result[winner] = true;
	return result;
}

int levelTravel(const vector<int> & weight, const vector<int> & order, int level, vector<int> & record, int groupSize)
{
	vector<int> neworder;
	for (auto iter = order.begin();; iter+=groupSize)
	{
		int trueSize = groupSize;
		bool leave = false;
		if (iter - order.begin() + groupSize > order.size())
		{
			trueSize = order.end() - iter;
			leave = true;
		}
		vector<int> group(iter, iter+trueSize);
		vector<bool> result = game(group, weight);
		for (int i = 0; i < result.size(); i++)
		{
			if (result[i]) // winner
			{
				record[group[i]] = level + 1;
				neworder.push_back(group[i]);
			}
		}

		if (leave)
			break;
	}
	//last winner
	if (neworder.size() == 1)
		return level+1;
	//continue game
	level++;
	return levelTravel(weight, neworder, level, record, groupSize);
}

int main()
{
	int p, g;
	cin >> p >> g;
	vector<int> weight(p, 0);
	for (int i = 0; i < p; i++)
		cin >> weight[i];
	vector<int> order(p, 0);
	for (int i = 0; i < p; i++)
		cin >> order[i];
	vector<int> record(p, 0);
	int final_level = levelTravel(weight, order, 0, record, g);
	vector<int> levelNum(final_level+1, 0);
	for (int i = 0; i < p; i++)
		levelNum[record[i]]++;
	vector<int> levelrank(final_level+1, 1);
	for (int i = 0; i < final_level; i++)
	{
		for (int j = i+1; j < final_level+1; j++)
			levelrank[i] += levelNum[j];
	}
	for (int i = 0; i < p; i++)
	{
		cout << levelrank[record[i]];
		if (i < p - 1)
			cout << " ";
	}
	system("pause");
}
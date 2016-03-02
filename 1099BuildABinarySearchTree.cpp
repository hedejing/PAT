#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void levelorder(int count, const vector<pair<int, int>> &nodes, const vector<int> &datas, const vector<int> &orders, const vector<int> &levelnodes)
{
	vector<int> newlevelnodes;
	for (int levelnode : levelnodes)
	{
		cout << datas[orders[levelnode]];
		const pair<int, int> node = nodes[levelnode];
		if (node.first != -1)
			newlevelnodes.push_back(node.first);
		if (node.second != -1)
			newlevelnodes.push_back(node.second);

		count++;
		if (count < nodes.size())
			cout << " ";
		else
		{
			system("pause");
			return;
		}
	}

	levelorder(count, nodes, datas, orders, newlevelnodes);
}

pair<int, int> LeftRightSize(const vector<pair<int, int>> &nodes, vector<pair<int, int>> &sizes, int currentidx)
{
	int leftsize, rightsize;
	if (nodes[currentidx].first == -1)
		leftsize = 0;
	else
	{
		const pair<int, int> &leftrightsizeOnLeft = LeftRightSize(nodes, sizes, nodes[currentidx].first);
		leftsize = leftrightsizeOnLeft.first + leftrightsizeOnLeft.second + 1;
	}

	if (nodes[currentidx].second == -1)
		rightsize = 0;
	else
	{
		const pair<int, int> &leftrightsizeOnRight = LeftRightSize(nodes, sizes, nodes[currentidx].second);
		rightsize = leftrightsizeOnRight.first + leftrightsizeOnRight.second + 1;
	}

	sizes[currentidx].first = leftsize;
	sizes[currentidx].second = rightsize;

	return sizes[currentidx];
}

int getOrder(const vector<pair<int, int>> &nodes, const vector<pair<int, int>> &sizes, int currentidx, vector<int> &orders, int begin)
{
	int order = sizes[currentidx].first + begin;
	orders[currentidx] = order;
	int left = nodes[currentidx].first;
	if (left != -1)
		orders[left] = getOrder(nodes, sizes, left, orders, begin);
	
	int right = nodes[currentidx].second;
	if (right != -1)
		orders[right] = getOrder(nodes, sizes, right, orders, order+1);

	return order;
}

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> nodes;
	vector<int> datas;
	datas.resize(N);
	nodes.resize(N);
	for (int i = 0; i < N; i++)
		cin >> nodes[i].first >> nodes[i].second;
	for (int i = 0; i < N; i++)
		cin >> datas[i];

	sort(datas.begin(), datas.end());
	
	vector<pair<int, int>> leftrightsizes;
	leftrightsizes.resize(N);
	LeftRightSize(nodes, leftrightsizes, 0);

	vector<int> orders;
	orders.resize(N);
	getOrder(nodes, leftrightsizes, 0, orders, 0);

	//test
	/*for (int order : orders)
		cout << order << " ";
	system("pause");
	return 0;*/

	vector<int> levelnodes;
	levelnodes.push_back(0);
	levelorder(0, nodes, datas, orders, levelnodes);
}
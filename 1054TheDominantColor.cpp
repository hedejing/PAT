#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;
	map<int, int> record; //first:occur second:pixel value
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			int pixel;
			cin >> pixel;
			record[pixel]++;
		}
	vector<pair<int, int>> rec_vec(record.begin(), record.end());
	sort(rec_vec.begin(), rec_vec.end(), [](const pair<int, int>&p1, const pair<int, int>&p2) {
		return p1.second > p2.second;
	});
	cout << rec_vec.front().first;
	system("pause");

}
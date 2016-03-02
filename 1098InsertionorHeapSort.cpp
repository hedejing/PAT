#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool isInsertSorted(const vector<int> &origin, const vector<int> & sorted, int &pos)
{
	pos = 0;
	if (sorted.size() >= 2)
	{
		for (int i = 1; i < sorted.size(); i++)
		{
			if (sorted[i] < sorted[i - 1])
			{
				pos = i;
				break;
			}
		}
	}
	for (int i = pos; i < sorted.size(); i++)
	{
		if (sorted[i] != origin[i])
			return false;
	}
	return true;
}

void print(const vector<int> &datas)
{
	bool first = true;
	for (auto i : datas)
	{
		if (!first)
			cout << " ";
		first = false;
		cout << i;
	}
}

int main()
{
	int N;
	cin >> N;
	vector<int> origin(N), sorted(N);
	for (int i = 0; i < N; i++)
		cin >> origin[i];
	for (int i = 0; i < N; i++)
		cin >> sorted[i];
	int pos;
	if (isInsertSorted(origin, sorted, pos))
	{
		cout << "Insertion Sort" << endl;
		sort(sorted.begin(), sorted.begin() + pos + 1);
		print(sorted);
	}
	else
	{
		cout << "Heap Sort" << endl; 
		vector<int> copy(origin);
		sort(copy.begin(), copy.end());
		int p = copy.size();
		for (int i = copy.size() - 1; i >= 0; i--)
		{
			if (copy[i] != sorted[i])
			{
				p = i;
				break;
			}
		}
		int cnt = copy.size() - p;
		make_heap(origin.begin(), origin.end());
		int k = 0;
		while (cnt--)
		{
			pop_heap(origin.begin(), origin.end()-k);
			k++;
		}
		print(origin);
	}
	system("pause");
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100

bool isSorted(const vector<int> & v)
{
	if (v.size() >= 2)
	{
		for (int i = 1; i < v.size(); i++)
			if (v[i] < v[i - 1])
				return false;
	}
	return true;
}

bool isInsertSort(const vector<int> &digits, const vector<int> & origin, int &pos)
{
	pos = 0;
	if (digits.size() >= 2)
	{
		for (int i = 1; i < digits.size(); i++)
			if (digits[i] < digits[i - 1])
			{
				pos = i;
				break;
			}
	}
	for (int i = pos; i < digits.size(); i++)
		if (origin[i] != digits[i])
			return false;
	return true;
}

int isMergeSort(const vector<int> & digits)
{
	int result = 0;
	for (int width = 2; width <= digits.size(); width = width * 2)
	{
		for (int i = 0; i <= digits.size() - width; i += width)
		{
			vector<int> tocheck(digits.begin() + i, digits.begin() + i + width);
			if (!isSorted(tocheck))
				return result;
		}
		result = width;
	}
	return result;
}

int main()
{
	int N;
	cin >> N;
	vector<int> origin(N);
	vector<int> digits(N);
	for (int i = 0; i < N; i++)
		cin >> origin[i];
	for (int i = 0; i < N; i++)
		cin >> digits[i];

	int pos;
	bool res = isInsertSort(digits, origin, pos);
	if (!res) // merge sort
	{
		cout << "Merge Sort" << endl;
		int width = 2 * isMergeSort(digits);
		for (int i = 0;; i += width)
		{
			if (i+width <= digits.size())
				sort(digits.begin() + i, digits.begin() + i + width);
			else
			{
				sort(digits.begin() + i, digits.end());
				break;
			}
		}
	}
	else
	{
		cout << "Insertion Sort" << endl;
		sort(digits.begin(), digits.begin() + pos+1);
	}
	bool first = true;
	for (auto i : digits)
	{
		if (!first)
			cout << " ";
		first = false;
		cout << i;
	}
	system("pause");
}
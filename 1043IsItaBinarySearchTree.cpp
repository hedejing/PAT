#include <iostream>
#include <vector>

using namespace std;

bool check(const vector<int> &values)
{
	//if (values.size() <= 3)
	//	return true;
	if (values.size() <= 1)
		return true;

	int mid = values.front();
	int change = 0;
	bool less = true;
	int dividepos = 1;
	for (int i = 1; i < values.size(); i++)
	{
		if (values[i] < mid && less)
		{
			dividepos++;
			continue;
		}
		if (values[i] >= mid && !less)
			continue;

		less = !less;
		change++;
		if (change >= 2)
			return false;
	}
	vector<int> sub1(values.begin() + 1, values.begin() + dividepos);
	vector<int> sub2(values.begin() + dividepos, values.end());

	bool r1 = check(sub1);
	bool r2 = check(sub2);
	if (r1&&r2)
		return true;
	else
		return false;
}

bool checkM(const vector<int> &values)
{
	//if (values.size() <= 3)
	//	return true;
	if (values.size() <= 1)
		return true;

	int mid = values.front();
	int change = 0;
	bool less = false;
	int dividepos = 1;
	for (int i = 1; i < values.size(); i++)
	{
		if (values[i] < mid && less)
			continue;

		if (values[i] >= mid && !less)
		{
			dividepos++;
			continue;
		}

		less = !less;
		change++;
		if (change >= 2)
			return false;
	}
	vector<int> sub1(values.begin() + 1, values.begin() + dividepos);
	vector<int> sub2(values.begin() + dividepos, values.end());

	bool r1 = checkM(sub1);
	bool r2 = checkM(sub2);
	if (r1&&r2)
		return true;
	else
		return false;
}

void postorder(const vector<int> &values, int &cnt, int sz)
{
	if (values.size() == 1)
	{
		cout << values.front();
		cnt++;
		if (cnt < sz)
			cout << " ";
		return;
	}

	if (values.size() == 0)
		return;

	int mid = values.front();
	int dividepos = 1;
	for (int i = 1; i < values.size(); i++)
	{
		if (values[i] < mid)
		{
			dividepos++;
			continue;
		}
		else
			break;
	}

	vector<int> sub1(values.begin() + 1, values.begin() + dividepos);
	vector<int> sub2(values.begin() + dividepos, values.end());

	postorder(sub1, cnt, sz);
	postorder(sub2, cnt, sz);
	cout << values.front();
	cnt++;
	if (cnt < sz)
		cout << " ";
}

void postorderM(const vector<int> &values, int &cnt, int sz)
{
	if (values.size() == 1)
	{
		cout << values.front();
		cnt++;
		if (cnt < sz)
			cout << " ";
		return;
	}

	if (values.size() == 0)
		return;

	int mid = values.front();
	int dividepos = 1;
	for (int i = 1; i < values.size(); i++)
	{
		if (values[i] >= mid)
		{
			dividepos++;
			continue;
		}
		else
			break;
	}

	vector<int> sub1(values.begin() + 1, values.begin() + dividepos);
	vector<int> sub2(values.begin() + dividepos, values.end());

	postorderM(sub1, cnt, sz);
	postorderM(sub2, cnt, sz);
	cout << values.front();
	cnt++;
	if (cnt < sz)
		cout << " ";
}


int main()
{
	int N;
	cin >> N;
	vector<int> values(N, 0);
	for (int i = 0; i < N; i++)
		cin >> values[i];
	bool r1 = check(values);
	bool r2 = checkM(values);
	if (!r1 && !r2)
	{
		cout << "NO";
		system("pause");
		return 0;
	}
	int cnt = 0;
	cout << "YES" << endl;
	if (r1)
	{
		postorder(values, cnt, values.size());
		system("pause");
		return 0;
	}

	if (r2)
	{
		postorderM(values, cnt, values.size());
		system("pause");
		return 0;
	}

}
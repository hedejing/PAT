#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Data {
	string name;
	string id;
	int grade;
	Data() {}
	bool operator<(Data &other) {
		return this->grade > other.grade;
	}
};

int main()
{
	int N;
	cin >> N;
	vector<Data> datas;
	datas.resize(N);
	for (int i = 0; i < N; i++)
	{
		string name,id;
		int grade;
		cin >> name >> id >> grade;
		datas[i].name = name;
		datas[i].id = id;
		datas[i].grade = grade;
	}
	sort(datas.begin(), datas.end());

	int lower, upper;
	cin >> lower >> upper;
	int l = min(lower, upper);
	int u = max(lower, upper);
	lower = l;
	upper = u;
	bool isNone = true;
	for (int i = 0; i < N; i++)
	{
		if (datas[i].grade >= lower && datas[i].grade <= upper)
		{
			cout << datas[i].name << " " << datas[i].id << endl;
			isNone = false;
		}
	}

	if (isNone)
		cout << "NONE" << endl;

	system("pause");
}
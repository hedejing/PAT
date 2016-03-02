#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Data {
	string id;
	string name;
	int grade;
};

int main()
{
	int N, C;
	cin >> N >> C;
	vector<Data> datas(N);
	for (int i = 0; i < N; i++)
		cin >> datas[i].id >> datas[i].name >> datas[i].grade;
	switch (C) {
	case 1:
	{
		sort(datas.begin(), datas.end(), [](const Data &a, const Data&b) {
			return a.id < b.id;
		});
		break;
	}
	case 2: {
		sort(datas.begin(), datas.end(), [](const Data &a, const Data&b) {
			if (a.name == b.name)
				return a.id < b.id;
			else
				return a.name < b.name;
		});
		break;
	}
	case 3: {
		sort(datas.begin(), datas.end(), [](const Data &a, const Data&b) {
			if (a.grade == b.grade)
				return a.id < b.id;
			else
				return a.grade < b.grade;
		});
		break;
	}
	}
	for (auto i : datas)
		printf("%s %s %d\n", i.id.data(), i.name.data(), i.grade);
	system("pause");
}

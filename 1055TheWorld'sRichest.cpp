#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Data {
	int age;
	int worth;
	char name[10];

	bool operator<(const Data &other) const {
		if (worth == other.worth)
		{
			if (age == other.age)
				return strcmp(name, other.name) < 0;
			else
				return age < other.age;
		}
		else
			return worth > other.worth;
	}
};

#define MAX_N 100000
Data datas[MAX_N];

int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N;i++)
		scanf("%s %d %d", datas[i].name, &(datas[i].age), &(datas[i].worth));
	sort(datas, datas + N);
	int cnt = 1;
	while (K--)
	{
		int M, Amin, Amax;
		scanf("%d %d %d", &M, &Amin, &Amax);
		printf("Case #%d:\n", cnt);
		bool found = false;
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			if (datas[i].age >= Amin && datas[i].age <= Amax)
			{
				found = true;
				printf("%s %d %d\n", datas[i].name, datas[i].age, datas[i].worth);
				count++;
				if (count == M)
					break;
			}
		}
		if (!found)
			puts("None");
		cnt++;
	}
	system("pause");
}
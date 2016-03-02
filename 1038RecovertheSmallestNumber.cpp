#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Inte {
	char s[10];

	bool operator<(const Inte &other) const {
		char front[20];
		strcpy(front, s);
		strcat(front, other.s);
		char back[20];
		strcpy(back, other.s);
		strcat(back, s);
		long long int fv, bv;
		sscanf(front, "%lld", &fv);
		sscanf(back, "%lld", &bv);
		return fv < bv;
	}
};

const int MAX = 10000;
Inte ints[MAX];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%s", ints[i].s);
	sort(ints, ints + N);	
	char res[MAX * 8];
	res[0] = 0;
	for (int i = 0; i < N; i++)
		strcat(res, ints[i].s);
	bool allzero = true;
	int i = 0;
	int len = strlen(res);
	for (; i < len; i++)
		if (res[i] != '0')
		{
			allzero = false;
			break;
		}
	if (allzero)
		puts("0");
	else
	{
		for (; i < len; i++)
			printf("%c", res[i]);
	}
	system("pause");
}
#include <iostream>

using namespace std;

#define MAX 1000001

long int a[MAX], b[MAX];
long int c[MAX * 2];

int main()
{
	int sza, szb;
	scanf("%d", &sza);
	for (int i = 0; i < sza; i++)
		scanf("%ld", &(a[i]));

	scanf("%d", &szb);
	for (int i = 0; i < szb; i++)
		scanf("%ld", &(b[i]));

	int ai = 0, bi = 0, ci = 0;
	while (ai < sza && bi < szb)
	{
		if (a[ai] < b[bi])
			c[ci++] = a[ai++];
		else
			c[ci++] = b[bi++];
	}
	while(ai < sza)
	{
		c[ci++] = a[ai++];
	}
	while (bi < szb)
	{
		c[ci++] = b[bi++];
	}
	printf("%ld", c[(ci-1) / 2]);
	system("pause");
}
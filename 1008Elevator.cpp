#include <iostream>
#include <stdlib.h>

int calcTime(int level, int lastlevel)
{
	if (level > lastlevel)
		return (level - lastlevel) * 6;
	else
		return (lastlevel - level) * 4;
}

int main()
{
	int N;
	scanf("%d", &N);
	int lastlevel = 0;
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		int level;
		scanf("%d", &level);
		int passtime, staytime=5;
		if (level > lastlevel)
			passtime = (level - lastlevel) * 6;
		else if (level < lastlevel)
			passtime = (lastlevel - level) * 4;
		else //same level
		{
			passtime = 0;
			staytime = 0;
		}

		total += passtime+5;
		//if (i < N - 1)
		//	total += 5;

		lastlevel = level;
	}

	printf("%d\n", total);

	system("pause");
}
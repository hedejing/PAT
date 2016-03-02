#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	double result = 1;
	char bets[] = "WTL";
	for (int i = 0; i < 3; i++)
	{
		double odds[3];
		for (int j = 0; j < 3; j++)
		{
			scanf("%lf", &odds[j]);
		}
		double *max_one = max_element(odds, odds + 3);
		int max_idx = (int)(max_one - odds);
		printf("%c ", bets[max_idx]);
		double choose = *max_one;
		result *= choose;
	}
	result = (result*0.65 - 1) * 2;
	//cout /*<< fixed << setprecision(2) */<< result;
	printf("%.2f", roundf(result*100)/100);
	system("pause");
	return 0;
}
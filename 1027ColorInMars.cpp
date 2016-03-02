#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string radix13str(int digit)
{
	if (digit == 10)
		return "A";
	else if (digit == 11)
		return "B";
	else if (digit == 12)
		return "C";
	else
	{
		stringstream ss;
		string s;
		ss << digit;
		ss >> s;
		return s;
	}
}

int main()
{
	int input[3];
	scanf("%d %d %d", &input[0], &input[1], &input[2]);
	printf("#");
	for (int i = 0; i < 3; i++)
	{
		int first = input[i] / 13;
		int second = input[i] % 13;
		cout << radix13str(first) << radix13str(second);
	}

	system("pause");
	return 0;
}
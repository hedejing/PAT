#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getSymLenOdd(string input, int pos)
{
	int result = 0;
	for (int i = 0; (pos - i >= 0 )&& (pos + i < input.length()); i++)
	{
		if (input[pos - i] != input[pos + i])
			break;
		else
			result = 2 * i + 1;
	}
	return result;
}

int getSymLenEven(string input, int pos)
{
	int result = 0;
	for (int i = 0; (pos - i >= 0) && (pos + i + 1 < input.length()); i++)
	{
		if (input[pos - i] != input[pos + 1 + i])
			break;
		else
			result = 2 * i + 2;
	}
	return result;
}

int main()
{
	string input;
	getline(cin, input);
	int maxSymLen = 0;
	for (int i = 0; i < input.length(); i++)
	{
		int oddlen = getSymLenOdd(input, i);
		int evenlen = getSymLenEven(input, i);
		maxSymLen = max(max(oddlen, evenlen), maxSymLen);
	}
	cout << maxSymLen;
	system("pause");
}
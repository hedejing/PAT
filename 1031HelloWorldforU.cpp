#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string input;
	cin >> input;
	int N = input.length();
	int dmin = (float)(N + 2+2) / 3;
	dmin = min(max(dmin, 3), N);
	
	if ((N - dmin) % 2 != 0)
		dmin++;

	int h = (N - dmin) / 2;
	for (int i = 0; i < h; i++)
	{
		cout << input[i];
		for (int j = 0; j < dmin-2; j++)
			cout << " ";

		cout << input[N - 1 - i] << endl;
	}
	for (int i = 0; i < dmin; i++)
		cout << input[i + h];
	cout << endl;

	system("pause");
}
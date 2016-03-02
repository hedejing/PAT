#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int a, b;
	string input;
	while (getline(cin, input))
	{
		if (input.empty())
			break;
		stringstream ss(input);
		ss >> a >> b;
		cout << a + b << endl;
	}
}
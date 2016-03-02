#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Float {
	string s;
	int k;
	bool iszero;
	Float(string input, int N) {
		int dotpos = -1, start = -1;
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == '0' && start == -1)
				continue;
			else if (input[i] == '.')
			{
				dotpos = i;
				continue;
			}
			else
			{
				if (start == -1)
					start = i;
				s.push_back(input[i]);
			}
		}
		if (dotpos == -1)
			dotpos = input.length();
		k = dotpos - start;
		if (k < 0)
			k++;
		if (s.length() == 0)
		{
			s = string(N, '0');
			k = 0;
		}
	}

	void print(int N) {
		if (!iszero)
			cout << "0." << s.substr(0, N) << "*10^" << k;
		else
			cout << "0" << "*10^0";
	}
};

bool Equal(int N, const Float &f1, const Float &f2)
{
	if (f1.k != f2.k)
		return false;

	for (int i = 0; i < N; i++)
		if (f1.s[i] != f2.s[i])
			return false;
	return true;
}

int main()
{
	int N;
	string A, B;
	cin >> N >> A >> B;
	Float fa(A, N), fb(B, N);
	if (Equal(N, fa, fb))
		cout << "YES " << "0." << fa.s.substr(0, N) << "*10^" << fa.k;
	else
		cout << "NO " << "0." << fa.s.substr(0, N) << "*10^" << fa.k  << " 0." << fb.s.substr(0, N) << "*10^" << fb.k;
	system("pause");
}
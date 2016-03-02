#include <iostream>
//#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int M, int N, const vector<int> & sequence)
{
	vector<int> stack;
	vector<int> elements(N, 0);
	for (int i = 0; i < N; i++)
		elements[i] = N - i;
	for (int i = 0; i < sequence.size(); i++)
	{
		int digit = sequence[i];
		auto res = find(stack.begin(), stack.end(), digit);
		if (res == stack.end()) //not found
		{
			while (true)
			{
				if (elements.empty())
					return false;
				stack.push_back(elements.back());
				if (stack.size() > M)
					return false;
				elements.pop_back();
				if (stack.back() == digit)
					break;
			}
			stack.pop_back();
		}
		else
		{
			while (true)
			{
				int back = stack.back();
				stack.pop_back();
				if (back == digit)
					break;
			}
		}
	}

	return true;
}

int main() 
{
	int M, N, K;
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		vector<int> sequence(N, 0);
		for (int j = 0; j < N; j++)
			cin >> sequence[j];
		bool res = check(M, N, sequence);
		if (res)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	system("pause");
	return 0;
}
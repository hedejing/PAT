#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <cstring>

using namespace std;

#define MAX 100000

int C[MAX + 1];

inline int lowbit(int i)
{
	return i&(-i);
}

inline void add(int i, int x)
{
	while (i <= MAX)
	{
		C[i] += x;
		i += lowbit(i);
	}
}

inline int sum(int i)
{
	int total = 0;
	while (i)
	{
		total += C[i];
		i -= lowbit(i);
	}
	return total;
}

int Find(int target, int begin, int end)
{
	if (begin == end)
	{
		if (sum(begin) < target)
			return begin + 1;
		else
			return begin;
	}

	int mid = (begin + end) / 2;
	if (target <= sum(mid))
		return Find(target, begin, mid);
	else/* if (target > sum(mid))*/
		return Find(target, mid + 1, end);
}

int main()
{
	memset(C, 0, sizeof(C));

	int N;
	cin >> N;
	cin.ignore();
	stack<int> st;
	int max_value = -1;
	while (N--)
	{
		//string s;
		char s[11];
		//cin >> s;
		scanf("%s", s);
		//if (s == "Pop")
		if(strcmp(s, "Pop")==0)
		{
			if (st.empty())
				puts("Invalid");
			else
			{
				int value = st.top();
				add(value, -1);
				st.pop();
				printf("%d\n", value);
			}
		}
		else if(strcmp(s, "PeekMedian")==0)
		//if (s == "PeekMedian")
		{
			if (st.empty())
				puts("Invalid");
			else
			{
				int target = (st.size() + 1) / 2;
				int value = Find(target, 0, max_value);
				printf("%d\n", value);
			}
		}
		else//Push
		{
			int value;
			cin >> value;
			st.push(value);
			add(value, 1);
			if (value > max_value)
				max_value = value;
		}
	}

	system("pause");
}
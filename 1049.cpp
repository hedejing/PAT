#include <iostream>
#include <string>

using namespace std;

string Post(string pre, string in)
{
	if (pre.length() <= 1)
		return pre;

	char root = pre.front();
	int pos = in.find(root);
	string left_in = in.substr(0, pos);
	string right_in = in.substr(pos + 1, in.length() - pos - 1);
	int div = 1;
	string left_pre;
	while (left_in.find(pre[div]) != string::npos)
	{
		left_pre.push_back(pre[div]);
		div++;
	}
	string right_pre;
	while (div < pre.length())
	{
		right_pre.push_back(pre[div]);
		div++;
	}
	string re = Post(left_pre, left_in) + Post(right_pre, right_in) + root;
	return re;
}

int main()
{
	string pre, in;
	cin >> pre >> in;
	cout << Post(pre, in) << endl;
}

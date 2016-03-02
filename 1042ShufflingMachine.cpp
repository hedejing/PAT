#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string idx2str(int index)
{
	int type = (index - 1) / 13;
	int number = (index - 1) % 13 + 1;
	string typestr;
	switch (type)
	{
	case 0:
		typestr = "S";
		break;
	case 1:
		typestr = "H";
		break;
	case 2:
		typestr = "C";
		break;
	case 3:
		typestr = "D";
		break;
	case 4:
		typestr = "J";
		break;
	default:
		break;
	}
	stringstream ss;
	ss << number;
	string numberstr;
	ss >> numberstr;
	return typestr + numberstr;
}

int main()
{
	int index[55];
	int order[55];
	int k;
	cin >> k;
	for (int i = 0; i < 54; i++)
	{
		cin >> order[i + 1];
		index[i + 1] = i + 1;
	}
	for (int i = 0; i < k; i++)
	{
		int newindexs[55];
		for (int j = 1; j < 55; j++)
			newindexs[order[j]] = index[j];
		for (int j = 1; j < 55; j++)
			index[j] = newindexs[j];
	}
	for (int i = 1; i < 55; i++)
	{
		cout << idx2str(index[i]);
		if (i < 54)
			cout << " ";
	}

	system("pause");
}
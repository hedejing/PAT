#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct GSK {
	int galleon;
	int sickle;
	int knut;
	GSK(string input) {
		replace(input.begin(), input.end(), '.', ' ');
		stringstream ss;
		ss << input;
		ss >> galleon >> sickle >> knut;
	}
	GSK(int _galleon, int _sickle, int _knut)
		:galleon(_galleon), sickle(_sickle), knut(_knut){}

	GSK operator+(const GSK &other) {
		int kplus = knut + other.knut;
		int splus = sickle + other.sickle;
		int gplus = galleon + other.galleon;
		if (kplus >= 29)
		{
			kplus -= 29;
			splus++;
		}
		if (splus >= 17)
		{
			splus -= 17;
			gplus++;
		}

		return GSK(gplus, splus, kplus);
	}
};

int main()
{
	string Astr, Bstr;
	cin >> Astr >> Bstr;
	GSK A(Astr), B(Bstr);
	GSK C = A + B;
	cout << C.galleon << "." << C.sickle << "." << C.knut << endl;
	system("pause");
}
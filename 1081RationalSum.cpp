#include <iostream>

using namespace std;

long int gcd(long int a, long int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

struct Ration {
	long int num;
	long int den;
	Ration(long int _num, long int _den)
	{
		long int g = gcd(_num, _den);
		num = _num / g;
		den = _den / g;
		if (den < 0)
		{
			num = -num;
			den = -den;
		}
	}

	Ration operator+(const Ration & other) const {
		long int newden = den*other.den;
		long int newnum = num*other.den + other.num*den;
		return Ration(newnum, newden);
	}
};

ostream& operator<<(ostream& os, const Ration& r) {
	long int num = r.num;
	long int den = r.den;
	if (r.num < 0)
	{
		os << "(-";
		num = -num;
	}
	if (num > den)
	{
		int inte = num / den;
		num = num %den;
		os << inte;
		if(num!=0)
			os << " " << num << "/" << den;
	}
	else
	{
		if (num == 0)
			os << 0;
		else
			os << num << "/" << den;
	}
	return os;
}

int main()
{
	int N;
	cin >> N;
	long int num, den;
	scanf("%ld/%ld", &num, &den);
	N--;
	Ration r(num, den);
	while (N--)
	{
		scanf("%ld/%ld", &num, &den);
		Ration other(num, den);
		r = r + other;
	}
	cout << r;
	system("pause");
}
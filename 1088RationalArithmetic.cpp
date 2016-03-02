#include <iostream>

using namespace std;

long int gcd(long int a, long int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

struct Ration {
	long int num;
	long int den;
	Ration(long int _num, long int _den) {
		long int g = gcd(_num, _den);
		num = _num / g;
		den = _den / g;
		if (den < 0)
		{
			den = -den;
			num = -num;
		}
	}

	Ration operator+(const Ration &r) const {
		long int newden = den*r.den;
		long int newnum = num*r.den + r.num*den;
		Ration newR(newnum, newden);
		return newR;
	}

	Ration operator-(const Ration &r)const {
		long int newden = den*r.den;
		long int newnum = num*r.den - r.num*den;
		Ration newR(newnum, newden);
		return newR;
	}

	Ration operator*(const Ration &r)const {
		long int newden = den*r.den;
		long int newnum = num*r.num;
		Ration newR(newnum, newden);
		return newR;
	}

	Ration operator/(const Ration &r)const {
		long int newden = den*r.num;
		long int newnum = num*r.den;
		Ration newR(newnum, newden);
		return newR;
	}
	friend ostream&operator<<(ostream &os, const Ration&r);
};


ostream& operator<<(ostream& os, const Ration &r)
{
	Ration rr(r);
	if (r.num < 0)
	{
		os << "(-";
		rr.num = -rr.num;
	}
	if (rr.den != 0)
	{
		if (rr.den == 1)
			os << rr.num;
		else
		{
			if (rr.num > rr.den)
			{
				long int k = rr.num / rr.den;
				long int left = rr.num % rr.den;
				os << k << " " << left << "/" << rr.den;
			}
			else
				os << rr.num << "/" << rr.den;
		}
	}
	else
		os << "Inf";
	if (r.num < 0)
		os << ")";
	return os;
}


int main()
{
	long int a, b, c, d;
	scanf("%ld/%ld %ld/%ld", &a, &b, &c, &d);
	Ration r1(a, b), r2(c, d);
	cout << r1 << " + " << r2 << " = " << r1 + r2 << endl;
	cout << r1 << " - " << r2 << " = " << r1 - r2 << endl;
	cout << r1 << " * " << r2 << " = " << r1 * r2 << endl;
	cout << r1 << " / " << r2 << " = " << r1 / r2 << endl;
	system("pause");
}
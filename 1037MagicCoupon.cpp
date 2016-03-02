#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int NC, NP;
	cin >> NC;
	vector<int> pos_coupons, neg_coupons, pos_values, neg_values;
	pos_coupons.reserve(NC);
	neg_coupons.reserve(NC);
	for (int i = 0; i < NC; i++)
	{
		int coupon;
		cin >> coupon;
		if (coupon>0)
			pos_coupons.push_back(coupon);
		else
			neg_coupons.push_back(coupon);
	}
	cin >> NP;
	pos_values.reserve(NP);
	neg_values.reserve(NP);
	for (int i = 0; i < NP; i++)
	{
		int value;
		cin >> value;
		if (value>0)
			pos_values.push_back(value);
		else
			neg_values.push_back(value);
	}
	sort(pos_coupons.begin(), pos_coupons.end(), [](int a, int b) {
		return a > b;
	});
	sort(neg_coupons.begin(), neg_coupons.end());
	sort(pos_values.begin(), pos_values.end(), [](int a, int b) {
		return a > b;
	});
	sort(neg_values.begin(), neg_values.end());
	long long sum = 0;
	int pos_sz = min(pos_coupons.size(), pos_values.size());
	for (int i = 0; i < pos_sz; i++)
		sum += pos_coupons[i] * pos_values[i];
	int neg_sz = min(neg_coupons.size(), neg_values.size());
	for (int i = 0; i < neg_sz; i++)
		sum += neg_coupons[i] * neg_values[i];
	cout << sum;
	system("pause");
}
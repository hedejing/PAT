#include <iostream>
#include <algorithm>

using namespace std;

struct Data {
	double inventory;
	double price;

	double per() {
		return price / inventory;
	}

	bool operator<(Data &other) {
		return (price / inventory)>(other.price / other.inventory);
	}
};
#define MAX 1000
int main()
{
	int N;
	double D;
	cin >> N >> D;
	Data data[MAX];
	for (int i = 0; i < N; i++)
		cin >> data[i].inventory;
	for (int i = 0; i < N; i++)
		cin >> data[i].price;

	sort(data, data + N);

	double result = 0;
	for (int i = 0; i < N; i++)
	{
		if (D <= data[i].inventory)
		{
			result += D*data[i].per();
			break;
		}
		else
		{
			D -= data[i].inventory;
			result += data[i].price;
		}
	}
	printf("%.2f", result);
	system("pause");
}
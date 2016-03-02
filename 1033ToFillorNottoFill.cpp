#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef double DistT;

struct Data {
	double price;
	DistT dist;

	bool operator<(const Data & other) const {
		return dist < other.dist;
	}
};

int main()
{
	int Cm, D, Davg, N;
	cin >> Cm >> D >> Davg >> N;
	vector<Data> datas(N);
	for (int i = 0; i < N; i++)
		cin >> datas[i].price >> datas[i].dist;
	sort(datas.begin(), datas.end());
	double tank = 0;
	double fee = 0;
	int i = 0;
	if (datas.front().dist>0)
	{
		cout << "The maximum travel distance = 0.00" << endl;
		return 0;
	}
	while(true)
	{
		DistT reach = Cm * Davg;
		int target = -1;
		bool nonext = true;
		for (int j = i + 1; j < N; j++)
		{
			if (datas[j].dist - datas[i].dist > reach)
				break;

			nonext = false;
			if (datas[j].price < datas[i].price)
			{
				target = j;
				break;
			}
		}

		if (nonext)
		{
			if (Cm * Davg >= D - datas[i].dist)
			{
				double need = (D - datas[i].dist)/Davg;
				if(need > tank)
					fee += (need-tank) * datas[i].price;
				printf("%.2f", fee);
			}
			else
			{
				DistT maxdist = datas[i].dist + Cm*Davg;
				printf("The maximum travel distance = %.2f", maxdist);
			}
			system("pause");
			return 0;
		}

		if (target != -1)
		{
			double need = (datas[target].dist - datas[i].dist) / Davg;
			if (need > tank)
			{
				fee += (need - tank)*datas[i].price;
				//cout << "---" << (datas[target].dist - datas[i].dist) << " " << datas[i].price << endl;
				tank = 0;
			}
			else
				tank -= need;
			i = target;
			continue;
		}
		else
		{
			if (Cm * Davg >= D - datas[i].dist)
			{
				double need = (D - datas[i].dist) / Davg;
				if (need > tank)
					fee += (need - tank) * datas[i].price;
				printf("%.2f", fee);
				return 0;
			}
			fee += (Cm - tank)*datas[i].price;
			//cout << "---" << (Cm - tank) << " " << datas[i].price << endl;
			double need = (datas[i+1].dist - datas[i].dist) / Davg;
			tank = Cm-need;
			i++;
		}
	}
}
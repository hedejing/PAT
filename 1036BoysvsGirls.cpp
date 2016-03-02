#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Data {
	string name;
	string id;
	int grade;

	Data(string _name, string _id, int _grade):
		name(_name), id(_id), grade(_grade){}

	bool operator <(Data &other) {
		return grade < other.grade;
	}
};


int main()
{
	int N;
	cin >> N;
	vector<Data> males, females;
	for (int i = 0; i < N; i++)
	{
		string name, id;
		char gender;
		int grade;
		cin >> name >> gender >> id >> grade;
		if (gender == 'M')
			males.push_back(Data(name, id, grade));
		else
			females.push_back(Data(name, id, grade));
	}

	sort(males.begin(), males.end());
	sort(females.begin(), females.end());

	if (females.size() != 0)
		cout << females.back().name << " " << females.back().id << endl;
	else
		cout << "Absent" << endl;
	
	if (males.size() != 0)
		cout << males.front().name << " " << males.front().id << endl;
	else
		cout << "Absent" << endl;

	if (females.size() != 0 && males.size() != 0)
		cout << females.back().grade - males.front().grade << endl;
	else
		cout << "NA" << endl;
	system("pause");
}
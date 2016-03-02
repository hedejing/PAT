#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

struct Time {
	int hour;
	int minute;
	int second;

	Time() {}

	Time(string input) {
		replace(input.begin(), input.end(), ':', ' ');
		stringstream ss;
		ss << input;
		int hour, minute, second;
		ss >> hour >> minute >> second;
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}

	int passtime() const {
		return hour * 3600 + minute * 60 + second;
	}

	bool operator<(Time &other) {
		return passtime() < other.passtime();
	}
};

struct Data {
	string id;
	Time time;

	Data(){}

	bool operator<(Data &data) {
		return time < data.time;
	}
};

int main()
{
	int M;
	cin >> M;
	vector<Data> ins, outs;
	ins.resize(M);
	outs.resize(M);
	for (int i = 0; i < M; i++)
	{
		string id, in_time, out_time;
		cin >> id >> in_time >> out_time;
		ins[i].id = outs[i].id = id;
		ins[i].time = in_time;
		outs[i].time = out_time;
	}
	sort(ins.begin(), ins.end());
	sort(outs.begin(), outs.end());
	cout << ins.front().id << " " << outs.back().id << endl;

	system("pause");
	return 0;
}
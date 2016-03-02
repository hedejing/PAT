#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX_K 1000
int process[MAX_K];
int done[MAX_K];

struct Data {
	queue<int> q;
	//int id;
	Data() {}
	/*Data(int _id)
		:id(_id){}*/
};

bool full_comp(const Data &d1, const Data &d2)
{
	//if (d1.q.front() == d2.q.front())
	//	return d1.id < d2.id;
	//else
		return d1.q.front() < d2.q.front();
}

int main()
{
	int N, M, K, Q;
	cin >> N >> M >> K >> Q;
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &(process[i]));
		done[i] = 9999999;
	}

	int time = 8 * 60;
	vector<Data> qs(N);
	/*for (int i = 0; i < N; i++)
		qs[i] = Data(i);*/

	int i;
	for (i = 0; i < N*M; i++)
	{
		int qid = i%N;
		if (qs[qid].q.empty())
			done[i] = time + process[i];
		else
			done[i] = qs[qid].q.back() + process[i];
		qs[qid].q.push(done[i]);
	}
	for (; i < K; i++)
	{
		auto first = min_element(qs.begin(), qs.end(), full_comp);
		//if (first->q.back() <= 17 * 60)
		//{
			done[i] = first->q.back() + process[i];
			first->q.pop();
			first->q.push(done[i]);
//		}
	}

	while (Q--)
	{
		int id;
		scanf("%d", &id);
		int d = done[id - 1];
		if (done[id - 1]-process[id-1] >= 17*60)
			puts("Sorry");
		else
			printf("%02d:%02d\n", d / 60, d % 60);
	}
	system("pause");
}
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

#define MAX 1000
//calcuate number of left child's nodes
int leftNodeNum(int n)
{
	int level = log2(n);
	int fullNodeNum = pow(2, level) - 1;
	//check if remained nodes overlap left and right
	int nextFullNodeNum = pow(2, level + 1) - 1;
	int leftchildlevel = level - 1;
	if (n <= (fullNodeNum + nextFullNodeNum) / 2)
	{
		// remained nodes are in left tree
		int remain = n - fullNodeNum;
		return remain + pow(2, leftchildlevel) - 1;
	}
	else
	{
		// remained nodes overlap left child and right child
		return pow(2, leftchildlevel + 1) - 1;
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	int a[MAX], b[MAX];
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	sort(a, a + N);
	int level = log2(N);
	vector<pair<int, int>> ranges;
	ranges.push_back(pair<int, int>(0, N - 1));
	int cnt = 0;
	for (int i = 0; i < level + 1; i++)
	{
		vector<pair<int, int>> newranges;
		for (int j = 0; j < ranges.size(); j++)
		{
			pair<int, int> range = ranges[j];
			int pivot = leftNodeNum(range.second - range.first + 1) + range.first;
			//cout << "pair(" << range.first << " " << range.second << ")" << "---" << pivot << endl;
			printf("%d", a[pivot]);
			cnt++;
			if (cnt == N)
			{
				system("pause");
				return 0;
			}
			printf(" ");
			newranges.push_back(pair<int, int>(range.first, pivot - 1));
			newranges.push_back(pair<int, int>(pivot + 1, range.second));
		}
		//cout << "new level" << endl;
		ranges = newranges;
	}

}
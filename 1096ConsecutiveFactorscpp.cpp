#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool is_prime(int N)
{
	int T = sqrt(N + 0.5);
	for (int i = 2; i <= T; i++)
		if (N%i == 0)
			return false;
	return true;
}

int main()
{
	int N;
	cin >> N;
	if (is_prime(N))
	{
		cout << 1 << endl;
		cout << N;
		system("pause");
		return 0;
	}
	int start = 2;
	int len = 0;
	long int pro = 1;
	int maxstart;
	int maxlen = 0;


	for(;;start++)
	{
		pro = pro * (start + len - 1) / (start - 1);
		//cout << pro << "--" << endl;
		if (N%pro != 0)
			continue;
		int end;
		for (end = start + len;; end++)
		{
			len = end - start;
			if (len > maxlen)
			{
				maxlen = len;
				maxstart = start;
			}
			pro *= end;
			//cout << pro << "----" << endl;
			if (pro > N)
			{
				printf("%d\n", maxlen);
				for (int i = 0; i < maxlen; i++)
				{
					if (i != 0)
						printf("*");
					printf("%d", i + maxstart);
				}
				system("pause");

				return 0;
			}
			if (N % pro != 0)
			{
				pro /= end;
				break;
			}
		}
	}

}
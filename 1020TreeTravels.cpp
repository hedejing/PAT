#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void levelTravel(int count, int N, const vector<vector<int>> &posts, const vector<vector<int>> &ins)
{
	int sz = posts.size();
	vector<vector<int>> newposts, newins;
	for (int i = 0; i < sz; i++)
	{
		const vector<int> &post = posts[i];
		const vector<int> &in = ins[i];
		int thisnode = post.back();
		cout << thisnode;
		count++;
		if (count == N)
		{
			//system("pause");
			return;
		}
		else
			cout << " ";

		if (post.size() == 1)
		{
			//if (count == N)
			//{
			//	//system("pause");
			//}
			continue;
		}

		auto idx = find(in.begin(), in.end(), thisnode);
		vector<int> left_in(in.begin(), idx); //inorder of left child
		vector<int> right_in(idx + 1, in.end());  //inorder of right child

		if (left_in.size() == 0)
		{
			vector<int> right_post(post.begin(), post.end() - 1);
			newposts.push_back(right_post);
			newins.push_back(right_in);
			continue;
		}

		if (right_in.size() == 0)
		{
			vector<int> left_post(post.begin(), post.end() - 1);
			newposts.push_back(left_post);
			newins.push_back(left_in);
			continue;
		}

		vector<int> left_post(post.begin(), post.begin()+left_in.size());
		vector<int> right_post(post.begin() + left_in.size(), post.end() - 1);

		newposts.push_back(left_post);
		newins.push_back(left_in);

		newposts.push_back(right_post);
		newins.push_back(right_in);
	}

	levelTravel(count, N, newposts, newins);
}

int main()
{
	int N;
	cin >> N;

	vector<int> post, in;
	post.resize(N);
	in.resize(N);

	for (int i = 0; i < N; i++)
		cin >> post[i];
	for (int i = 0; i < N; i++)
		cin >> in[i];

	vector<vector<int>> posts, ins;
	posts.push_back(post);
	ins.push_back(in);
	levelTravel(0, N, posts, ins);
}
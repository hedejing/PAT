#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Node {
	int key;
	Node *left;
	Node *right;
	Node(int _key) {
		key = _key;
		left = NULL;
		right = NULL;
	}
};

void postorder(int &count, int N, Node *node)
{
	if (node->left)
		postorder(count, N, node->left);
	if (node->right)
		postorder(count, N, node->right);
	cout << node->key;
	count++;
	if (count < N)
		cout << " ";
}

int main()
{
	int N;
	cin >> N;
	vector<Node*> stack;
	Node *lastnode = NULL;
	Node *root = NULL;
	for (int i = 0; i < 2*N; i++)
	{
		string actionkey;
		cin >> actionkey;
		if (actionkey != "Pop") //Push
		{
			int key;
			cin >> key;
			Node *node = new Node(key);
			if (lastnode)
			{
				if (lastnode->left == NULL)
					lastnode->left = node;
				else
					lastnode->right = node;
			}
			else
				root = node;
			stack.push_back(node);
			lastnode = node;
		}
		else// Pop
		{
			lastnode = stack.back();
			stack.pop_back();
		}
	}
	int count = 0;
	postorder(count, N, root);
	system("pause");
}
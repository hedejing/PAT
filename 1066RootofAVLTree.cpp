#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;

	Node(int _key)
		:key(_key), left(NULL), right(NULL) {}
};

struct Tree {
	Node* root;

	Tree(Node *_root)
		:root(_root){}

	void add(Node *node)
	{
		AddNode(root, node);
		Node *res = detect(root);
		if(res)
			root = res;
	}

	void InOrderTravel()
	{
		inorder(root);
	}


private:
	void inorder(Node *node)
	{
		if (node->left)
			inorder(node->left);
		cout << node->key << " ";
		if (node->right)
			inorder(node->right);
	}

	int getHeight(Node *node)
	{
		if (!node)
			return -1;
		int height = max(getHeight(node->left), getHeight(node->right)) + 1;
		return height;
	}

	void AddNode(Node* thisnode, Node *newnode)
	{
		if (newnode->key > thisnode->key)
		{
			if (thisnode->right == NULL)
				thisnode->right = newnode;
			else
			{
				AddNode(thisnode->right, newnode);
				Node* rightRes = detect(thisnode->right);
				if (rightRes)
					thisnode->right = rightRes;
			}
		}
		else
		{
			if (thisnode->left == NULL)
				thisnode->left = newnode;
			else
			{
				AddNode(thisnode->left, newnode);
				Node* leftRes = detect(thisnode->left);
				if (leftRes)
					thisnode->left = leftRes;
			}
		}
		
	}

	Node* detect(Node *thisnode)
	{
		int leftHeight = getHeight(thisnode->left);
		int rightHeight = getHeight(thisnode->right);
		if (leftHeight - rightHeight > 1)
		{
			int llh = getHeight(thisnode->left->left);
			int lrh = getHeight(thisnode->left->right);
			if (llh > lrh)
				return LL(thisnode);
			else
				return LR(thisnode);
		}
		if (rightHeight - leftHeight > 1)
		{
			int rlh = getHeight(thisnode->right->left);
			int rrh = getHeight(thisnode->right->right);
			if (rrh > rlh)
				return RR(thisnode);
			else
				return RL(thisnode);
		}
		return NULL;
	}

	Node* LL(Node *node)
	{
		Node *left = node->left;
		Node *rightofleft = left->right;
		left->right = node;
		node->left = rightofleft;
		return left;
	}

	Node* LR(Node *node)
	{
		Node *rightofleft = node->left->right;
		node->left->right = rightofleft->left;
		rightofleft->left = node->left;
		node->left = rightofleft->right;
		rightofleft->right = node;
		return rightofleft;
	}

	Node* RL(Node *node)
	{
		Node *leftofright = node->right->left;
		node->right->left = leftofright->right;
		leftofright->right = node->right;
		node->right = leftofright->left;
		leftofright->left = node;
		return leftofright;
	}

	Node* RR(Node *node)
	{
		Node* right = node->right;
		Node* leftofright = right->left;
		node->right = leftofright;
		right->left = node;
		return right;
	}
};

int main()
{
	int N;
	cin >> N;
	int key;
	cin >> key;
	Node *root = new Node(key);
	Tree tree(root);
	for (int i = 1; i < N; i++)
	{
		cin >> key;
		Node *node = new Node(key);
		tree.add(node);
	}
	cout << tree.root->key;
	system("pause");
}
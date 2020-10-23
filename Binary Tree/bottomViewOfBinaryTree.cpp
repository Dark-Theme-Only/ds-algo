#include <iostream>
#include <map>
using namespace std;

struct Node
{
	int val;
	Node *left, *right;

	Node(int val)
	{
		this->val = val;
		this->left = this->right = NULL;
	}
};

void bottomview(Node* root, int dist, int lv, map<int,pair<int,int> > m)
{
	if(!root)
		return;

	if(lv>=m[dist].second || m.find(dist)==m.end())
		m[dist]={root->val,lv};
	bottomview(root->left,dist-1,lv+1,m);
	bottomview(root->right,dist+1,lv+1,m);
}

void printBottom(Node* root)
{
	map<int,pair<int,int> > m;
	bottomview(root,0,0,m);
	for(auto it:map)
	{
		cout<<it.second.first;
	}
}

int main()
{
	Node* root = NULL;

	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

	printBottom(root);

	return 0;
}
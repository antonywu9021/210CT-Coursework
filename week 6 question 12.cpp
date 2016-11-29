#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *left;
	Node *right;
	Node()
	{
		data = -1;
		left = NULL;
		right = NULL;
	};
};
class SortTree
{
private:
	Node *root;
public:
	SortTree()
	{
		root = NULL;
	};
	void Mid(Node * t)
	{
		if(t!=NULL)
		{
			Mid(t->left);
			cout << t->data << " ";
			Mid(t->right);
		}
	};
	void Insert( int data)
	{
		Node *t;
		t = root;
		Node * p = new Node();
		p->data = data;
		if (t == NULL)
		{
			t = p;
			root = p;
			return;
		}
		Node *q = t, *parent;
		do {
			parent = q;
			if (parent->data > data)
				q = parent->left;
			else
				q = parent->right;
		} while (q != NULL);
		if (parent->data > data)
			parent->left = p;
		else
			parent->right = p;
	};
	void Middle() 
	{
		Mid(root);
	}
};
int main()
{
	int a[] = { 0,5,8,4,2,3,10 };
	int len = sizeof(a) / sizeof(int);
	SortTree sort;
	for (int i = 0; i<len; i++)
	{
		sort.Insert(a[i]);
	}
	sort.Middle();
	return 0;
}


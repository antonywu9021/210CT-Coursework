#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
class Node
{
public:
	int data;
	Node*left;
	Node*right;
	Node()
	{
		data = -1;
		left = NULL;
		right = NULL;
	}
	Node(int d,Node*L=NULL,Node*R=NULL)
	{
		data = d;
		left = L;
		right = R;
	}
};
Node *root = NULL;
void insert(int data)
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
}
Node* find_parent(Node *parent, int data)
{
	Node *res = NULL;
	if (parent != NULL)
	{
		if (data < parent->data && parent->left != NULL) 
		{
			if (data == parent->left->data)
				res = parent;
			else
			{
				res = find_parent(parent->left, data);
				if (res == NULL)
					res = find_parent(parent->right, data);
			}
		}
		if (data > parent->data && parent->right != NULL) 
		{
			if (data == parent->right->data)
				res = parent;
			else
			{
				res = find_parent(parent->left, data);
				if (res == NULL)
					res = find_parent(parent->right, data);
			}
		}
	}
	return res;
}
Node* find(Node*node,int data)
{
	Node *res = NULL;
	if (node != NULL)
	{
		if (data == node->data)
			res = node;
		else if (data < node->data)
			res = find(node->left, data);
		else
			res = find(node->right, data);
	}
	return res;
};
void del(int value)
{
	Node *parent = find_parent(root, value); 
	Node *node = find(root, value); 
	if (node == NULL) 
		printf("delete the node does not exist\n");
	else
	{
		if (node->left == NULL && node->right == NULL) 
		{
			if (parent == NULL) 
				root = NULL;
			else
			{
				if (node == parent->left)
					parent->left = NULL;
				else
					parent->right = NULL;
			}
		}
		else if (node->right == NULL) 
		{
			if (parent == NULL) 
				root = node->left;
			else
			{
				if (node == parent->left)
					parent->left = node->left;
				else
					parent->right = node->left;
			}
		}
		else if (node->left == NULL) 
		{
			if (parent == NULL) 
				root = node->right;
			else
			{
				if (node == parent->left)
					parent->left = node->right;
				else
					parent->right = node->right;
			}
		}
		else 
		{
			Node *new_node = node->right; 
			Node *new_node_parent = NULL;
			while (new_node->left != NULL)
			{
				new_node_parent = new_node;
				new_node = new_node->left;
			}
			if (new_node != node->left)
				new_node->left = node->left;
			if (new_node != node->right)
				new_node->right = node->right;
			if (parent == NULL)
				root = new_node;
			else
			{
				if (node == parent->left) 
					parent->left = new_node;
				else 
					parent->right = new_node;
			}
			if (new_node_parent != NULL)
				new_node_parent->left = NULL;
		}
	}
}
void show(Node *node) 
{
	if (node != NULL)
	{
		show(node->left);
		cout << node->data << " ";
		show(node->right);
	}
}
int main()
{
	for (int i = 0; i < 10; i++)
	{
		insert(i);
	};
	cout << "before delete:" << endl;
	show(root);
	cout << endl;
	cout << "after delete" << endl;
	del(3);
	show(root);
}


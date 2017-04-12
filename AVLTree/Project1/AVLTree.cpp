#include "AVLNode.cpp"
#include <iostream>
class AVLTree
{
private:
	AVLNode *root;

	void insertRec(int i, AVLNode * & r)
	{
		if (r == nullptr)
		{
			AVLNode *temp = new AVLNode(i);
			r = temp;
		}
		else
		{
			if (r->data > i)
			{
				insertRec(i, r->left);
			}
			else
			{
				insertRec(i, r->right);
			}
		}

		balance(r);
	}
	void printTreeRec(AVLNode * r)
	{
		if (r == nullptr)
		{
			//Do Nothing
		}
		else 
		{
			//In Order
			printTreeRec(r->left);
			std::cout << " " << r->data << " ";
			printTreeRec(r->right);
		}
	}

	void balance(AVLNode * & r)
	{
		if (r == nullptr)
		{
			//balanced so stop
			return;
		}

		//Left subtree to big
		if (height(r->left) - height(r->right) > 1)
		{
			//left left is imbalanced
			if (height(r->left->left) >= height(r->left->right))
			{
				singleRotateLeft(r);
			}
			else
			{
				doubleRotateLeft(r);
			}
		}
		//right subtree is to big
		else if (height(r->right) - height(r->left) > 1)
		{
			if (height(r->right->right) >= height(r->right->left))
			{
				singleRotateRight(r);
			}
			else
			{
				doubleRotateRight(r);
			}
		}

		r->height = max(height(r->left),height(r->right)) + 1;
	}

	int max(int a, int b)
	{
		if (a > b)
		{
			return a;
		}
		else
		{
			return b;
		}
	}

	void singleRotateLeft(AVLNode * & r)
	{
		AVLNode *newNode = r->left;
		AVLNode *b = newNode->right;
		newNode->right = r;
		r->left = b;
		r->height = max(height(r->left),height(r->right)) + 1;
		newNode->height = max(height(newNode->left), height(newNode->right)) + 1;
		r = newNode;
	}

	void doubleRotateLeft(AVLNode * & r)
	{
		singleRotateLeft(r->left);
		singleRotateRight(r);
	}

	void singleRotateRight(AVLNode * & r)
	{
		AVLNode *newNode = r->right;
		AVLNode *b = newNode->left;
		newNode->left = r;
		r->right = b;
		r->height = max(height(r->right), height(r->left)) + 1;
		newNode->height = max(height(newNode->right), height(newNode->left)) + 1;
		r = newNode;
	}

	void doubleRotateRight(AVLNode * & r)
	{
		singleRotateRight(r->right);
		singleRotateLeft(r);
	}

	int height(AVLNode * t)
	{
		if (t == nullptr)
		{
			return -1;
		}
		else
		{
			return t->height;
		}
	}

public:
	AVLTree()
	{
		root = nullptr;
	}
	~AVLTree()
	{
		//to do
	}

	void insert(int i)
	{
		insertRec(i, root);
	}

	void printTree()
	{
		printTreeRec(root);
	}
};
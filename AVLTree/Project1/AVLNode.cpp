class AVLNode
{
public:
	AVLNode *right;
	AVLNode *left;
	int data;
	int height;

	AVLNode(int d)
	{
		data = d;
		height = 0;
		right = nullptr;
		left = nullptr;
	}
};
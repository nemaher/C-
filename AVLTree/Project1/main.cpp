#include "AVLTree.cpp"

int main()
{
	AVLTree t = AVLTree();
	t.insert(3);
	t.insert(2);
	t.insert(5);
	t.insert(4);

	t.printTree();

	int x;
	std::cin >> x;
}
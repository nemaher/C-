
template <typename T>
class Node
{

public:
	T data;
	Node *next;
	Node *back;

	//Constructor
	Node(T d)
	{
		data = d;
		next = nullptr;
	}
};
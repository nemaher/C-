#include "Node.cpp"
#include <string>
#include <iostream>


template <typename T>
class List
{
private:
	Node<T> *front;
	void printRec(Node<T>* n)
	{

		if (n == nullptr)
		{

		}
		else
		{
			cout << n->data << " ";
			printRec(n->next);

		}
	}
public:
	List()
	{
		front = nullptr;
	}

	//Deconstructor
	~List()
	{
		while (front != nullptr)
			remove();
	}

	List(T i)
	{
		front = new Node<T>(i);
		
	}

	void add(T i)
	{
		Node<T> *temp = new Node<T>(i);
		temp->next = front;
		front->back;
		
		
		front = temp;
		
	}

	T remove()
	{
		if (front != nullptr)
		{
			Node<T> *temp = front;
			front = front->next;
			T d = temp->data;
			delete temp;
			return d;
		}
	}

	void print()
	{
		printRec(front);
	}


};
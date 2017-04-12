#include <iostream>
#include <vector>

using namespace std;

bool isMixSort;

void quicksort(vector<int> & items)
{
	if (items.size() > 1)
	{
		vector<int> small;
		vector<int> same;
		vector<int> large;

		int pivot = items[0];
		for (int i = 0; i < items.size(); i++)
		{
			if (items[i] < pivot)
			{
				small.push_back(items[i]);
			}
			else if (items[i] > pivot)
			{
				large.push_back(items[i]);
			}
			else
			{
				same.push_back(items[i]);
			}
		}

		if (isMixSort == false) //checks to see if mixsort is what called quick sort
		{
			quicksort(small);
			quicksort(large);
		}

		move(begin(small), end(small), begin(items)); //take memmory at starting and end of small and put into begining of items
		move(begin(same), end(same), begin(items) + small.size());
		move(begin(large), end(large), end(items) - large.size());

	}
	else
	{
		//do nothing
	}
}

int leftChild(int i)
{
	return 2 * i + 1;
}

void percDown(vector<int> & v, int i, int n)
{
	int child;
	//int leftChild;
	int temp;

	for (temp = v[i]; leftChild(i) < n; i = child)
	{
		child = leftChild(i);
		if (child != n - 1 && v[child] < v[child + 1]) //compare left and right child
		{
			child++; //We want our right child
		}
		if (temp < v[child])
		{
			v[i] = v[child]; //Swapping the greater child
			v[child] = temp;
		}
		else
		{
			break;
		}
	}
}

void heapsort(vector<int> & v)
{
	for (int i = v.size() / 2 - 1; i >= 0; --i)
	{
		percDown(v, i, v.size()); //Building the heap
	}
	for (int j = v.size() - 1; j > 0; --j)
	{
		swap(v[0], v[j]);
		percDown(v, 0, j); //Removing the max from the heap
	}

}

void mixSort(vector<int> & v, int d) //worse case runtime would be if d is the size of the array. 
									 //This is becasue that means that there is a straight tree with one node on each branch
{
	isMixSort = true;	//tells quicksort mixsort is happening

	while (d >= 0)
	{
		quicksort(v); //calls quicksort d times
		d--;
	}

	heapsort(v); //finishes what quicksord did not

	isMixSort = false;
}

int main()
{
	int a[] = { 1,7,12,5,99 };

	vector<int> v(a, a + sizeof(a) / sizeof(int));

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	cout << endl << "Sorted " << endl;

	heapsort(v);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	cout << endl;

	int b[] = { 4,5,2,6,10 };
	vector<int> v2(b, b + sizeof(b) / sizeof(int));

	quicksort(v2);
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}

	cout << endl;

	int c[] = { 1,3,8,4,10,12,14 };//
	vector<int> v3(c, c + sizeof(c) / sizeof(int));

	mixSort(v3, 0);
	for (int i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}

	int x;
	cin >> x;
}
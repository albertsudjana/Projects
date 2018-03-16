#ifndef HEAP_H_
#define HEAP_H_


#include <iterator>
#include "Order.h"
#include "Customer.h"
#include <vector>

using namespace std;

class Heap
{
private:
	vector <Order> heap;
	int size;
	int left(int parentIndex);
	int right(int parentIndex);
	int parent(int childIndex);
	void HeapIncreaseKey(int index, Order key);

public:
	Heap();
	// Instantiates a new Heap
	// post: a new Heap object

	~Heap();
	// frees the memory of the Heap object
	// All memory has been deallocated

	int getSize();
	// Returns the size of the heap vector.

	void addOrder(Order key);
		// Insert the value at the bottom of the heap, as far left as possible
		// Compares the new key to its parent and swap if necessary
		// Keeps swapping the new key with its parent until the heap property is restored.
		// Calls the helper function heapInsertKey to swap the key with its parent if necessary

	void deleteFirstOrder();
	// Removes the value at the top of the heap, the root node

	void maxHeapify(int size, int index);
	// Will reaarange a specific node and its descendants to satisfy the max-heap property
	// Pre: left index and right index are both valid max heaps

	void buildHeap();
	// Takes an un-ordered binary tree and turns it into a valid Heap
	// Swaps nodes where the parents are smaller than the children until the nodes
	// have reached their correct locations.
	// Calls the maxHeapify helper function to bubble the values down

	void displayOrders(ostream & os);
	// Displays the vector in priority order from first to last.

	void findOrder(string first_name, string last_name);

	void printFirstOrder();

	bool searchData(string first_name, string last_name);

	void setShipped(Heap heap);

	Order peekFirstOrder();

	void heapSort();

};

#endif /* HEAP_H_ */

Heap::Heap()
{
	size = 0;
}

Heap::~Heap(){}

int Heap::left(int parentIndex)
{
	return 2*parentIndex + 1;
}

int Heap::right(int parentIndex)
{
	return 2*parentIndex + 2;
}

int Heap::parent(int childIndex)
{
	return childIndex/2; // A[floor[i/2]]
}

int Heap::getSize()
{
	return size;
}
void Heap::addOrder(Order key)
{
	heap.push_back(key);
	heap[size] = key;
	HeapIncreaseKey(size, key);
	size++;
}

void Heap::HeapIncreaseKey(int index, Order key) {
	int parentIndex;
	Order temp("", "", "", "", "", "", "", 0.0, 0.0);

	if (index != 0) {
		parentIndex = parent(index);
		if (heap[parentIndex] < heap[index]) {
			temp = heap[index];
			heap[index] = heap[parentIndex];
			heap[parentIndex] = temp;
			HeapIncreaseKey(parentIndex, key);

		}
	}

}

void Heap::heapSort()
{
	for (int i = size / 2 - 1; i >= 0; i--) {
		maxHeapify(size,i);
	}
	for (int i = size - 1; i >= 0; i--) {
		Order temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		maxHeapify (i,0);
	}
}
void Heap::deleteFirstOrder()
{
	if(size == 0)
	{
		cout << "There is nothing to remove!\n" << endl;
		return;
	}
	else
	{
		heap[0] = heap[size - 1];
		size--;
		if(size > 0)
			maxHeapify(size, 0);
	}
}
Order Heap::peekFirstOrder()
{
	return heap[0];
}
void Heap:: printFirstOrder()
{
	cout << heap[0];
}
void Heap::maxHeapify(int size, int index)
{
	int largest = index;
	int l = left(index); //get the index of the left child of A[i] and store as l
	int r = right(index); //get the index of the right child of A[i] and store r
	//cout << "l child of index " << index << ": "<< l << endl;
	//cout << "r child of index " << index << ": "<< r << endl;

	if (l < size && heap[l] > heap[largest])
		largest = l;
	else
		largest = index;

	if (r <size && heap[r] > heap[largest])
		largest = r;

	if (index != largest) {
		Order temp = heap[index];
		heap[index] = heap[largest];
		heap[largest] = temp;
		maxHeapify(size,largest); // restore heap property after performing the swap on trees
	}
}

void Heap::buildHeap()
{
	int n = size;
	for(int i = (n-1)/2; i == 1; i--)
	{
		maxHeapify(size, i);
	}
}

void Heap::displayOrders(ostream &s)
{
	for(int i = 0; i < size; i++){
		s << heap[i] << endl;
	}
	s << endl;
}

void Heap::findOrder(string first_name, string last_name)
{
	string full_name = first_name + " " + last_name;
	string temp;
	for(int i = 0; i<heap.size(); i++)
	{
		string temp = heap[i].getCustomerDetails();
		if(full_name == temp)
		{
			cout << endl << "Order History" << endl;
			cout << heap[i];
		}
	}
}

bool Heap::searchData(string first_name, string last_name)
{
	string full_name = first_name + " " + last_name;
	string temp;
	for(int i = 0; i<heap.size(); i++)
	{
		string temp = heap[i].getCustomerDetails();
		if(full_name == temp)
		{
			return true;
		}
	}
	return false;
}

void Heap::setShipped(Heap heap2)
{
	Order order = heap2.peekFirstOrder();
	for(int i = 0; i<heap.size(); i++)
	{
		if(heap[i] == order)
		{
			heap[i].setDelivery("Shipped");
		}
	}
}


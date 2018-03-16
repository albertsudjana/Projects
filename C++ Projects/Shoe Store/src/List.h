/*
 * List.h
 *
 *  Created on: Mar 8, 2017
 *      Author: Aaron_2
 */
#ifndef LIST_H_
#define LIST_H_
//typedef Node* Nodeptr;
#include <cstddef> //for NULL
#include <assert.h>
#include <iostream>
using namespace std;

template<class listdata> //list stores generic listdata, not any specific C++ type
class List {
private:

	struct Node {
		listdata data;
		Node* next;
		Node* previous;

		//constructor
		Node(listdata data) :
				data(data), next(NULL), previous(NULL) {
		}

	};

	//typedef struct Node* Nodeptr;

	//A linked list data structure will also have a first node, last node, and a size
	Node* first; //a "first node" with no data(based off of constructor) will point to the first node
	Node* last; //a "last node" with no data(based off of constructor) will point to the last node
	Node* iterator; //an "iterator node" that will point to a node on the list and will have its own set of functions
	int size;

	void reverse(Node*);
	//Helper function for the public printReverse() function.
	//Recursively prints the data in a List in reverse.

	bool isSorted(Node*);
	//Helper function for the public isSorted() function.
	//Recursively determines whether a list is sorted in ascending order.

	int binarySearch(int, int, listdata);
	//Recursively searchs the list by dividing the search space in half
	//Returns the index of the element, if it is found in the List
	//Returns -1 if the element is not in the List
public:

	/**Constructors and Destructors*/

	List();
	//Default constructor; initializes an empty list
	//Pre: N/A
	//Postcondition: sets default values for the three variables: first, last, and size

	List(const List &);

	~List();
	//Destructor. Frees memory allocated to the list
	//Pre:Iterator node is not pointing to null
	//Postcondition: prevents memory leakage (frees up used space)

	/**Accessors*/

	listdata getFirst();
	//Returns the first element in the list
	//Precondition: checks if list is empty
	//Post: first element data is returned

	listdata getLast();
	//Returns the last element in the list
	//Precondition: checks if list is empty
	//Post: last element data is returned

	bool isEmpty();
	//Determines whether a list is empty.
	//Pre: n/a
	//Post: returns true if size of list is 0

	int getSize();
	//Returns the size of the list
	//Pre: N/A
	//Post: Returns size of list

	/**Manipulation Procedures*/

	void removeLast();
	//Removes the value of the last element in the list
	//Precondition: checks if list is empty (size = 0?)
	//Postcondition: the last pointer now points to the former 2nd to last node

	void removeFirst();
	//Removes the value of the first element in the list
	//Precondition: checks if list is empty (size = 0?)
	//Postcondition: the first pointer now points to the former 2nd node

	void insertLast(listdata data);
	//Inserts a new element at the end of the list
	//If the list is empty, the new element becomes both first and last
	//Pre: checks if list has any existant nodes
	//Postcondition: the last pointer now points to a new node at the end of the list

	void insertFirst(listdata data);
	//Inserts a new element at the start of the list
	//If the list is empty, the new element becomes both first and last
	//Pre: checks if list has any existant nodes
	//Postcondition: the first pointer now points to a new node at the front of the list

	/**Additional List Operations*/

	void printList(ostream&);
	//void printList();
	//Prints to the console the value of each element in the list sequentially
	//and separated by a blank space
	//Prints nothing if the list is empty
	//Pre: iterator node does not point to null
	//Post: print the info

	//Iterator prototypes
	void startIterator();
	//Start iterator at front of list
	//Pre: list isn't empty
	listdata getIterator();
	//Get the data from where the iterator is pointing at
	void advanceIterator();
	//Move iterator down one on the list
	//Pre: if iterator is already pointing to NULL
	bool offEnd();
	//checks if iterator is pointing to NULL
	void removeIterator();
	//remove node to where the iterator is currently pointing
	//Pre: checks list size (if zero, nothing to remove, if one, set everypointer to NULL after deletion)
	void insertIterator(listdata data);
	//add a node to where the iterator is currently pointing at
	//Pre: check for size/ if iterator is pointing to NULL

	bool operator==(const List&);

	void printReverse();
	//Wrapper function that calls the reverse helper function to print a list in reverse
	//prints nothing if the List is empty

	bool isSorted();
	//Wrapper function that calls the isSorted helper function to determine whether
	//a list is sorted in ascending order.
	//We will consider that a list is trivially sorted if it is empty.
	//Therefore, no precondition is needed for this function

	int getIndex();
	//Indicates the index of the Node where the iterator is currently pointing
	//Nodes are numbered from 1 to size of the list
	//Pre: size != 0
	//Pre: !off_end()


	void advanceToIndex(int);
	//Moves the iterator to the node whose index number is specified in the parameter
	//Pre: size != 0


	int linearSearch(listdata);
	//Searchs the list, element by element, from the start of the List to the end of the List
	//Returns the index of the element, if it is found in the List
	//Calls the above indexing functions in its implementation
	//Returns -1 if the element is not in the List
	//Pre: size != 0


	int binarySearch(listdata);
	//Returns the index where data is located in the List
	//Calls the private helper function binarySearch to perform the search
	//Pre: size != 0
	//Pre: List is sorted (must test on a sorted list)


};
//typedef Node* Nodeptr;

//constructor
template <class listdata>
List<listdata>::List() : first(NULL), last(NULL), iterator(NULL), size(0) {}


//copy constructor
template<class listdata>
List<listdata>::List(const List &list) :
		size(list.size) {
	if (list.first == NULL) //If the original list is empty, make an empty list for this list
	{
		first = last = iterator = NULL;
	} else {
		first = new Node(list.first->data); //calling Node constructor
		Node*temp = list.first; //set a temporary node pointer to point at the first of the original list
		iterator = first; //set iterator to point to first node of the new list

		while (temp->next != NULL) {

			temp = temp->next; //advance up to the next node in the original list
			iterator->next = new Node(temp->data); //using node constructor to create a new node with copy of data
			iterator = iterator->next; //advance to this new node
		}
		last = iterator; //Why do I need this line of code?
		iterator = NULL;
	}
}

//destructor
//temp node is needed in order to be a placeholder for the new node (a basic iterator, a third pointer to move through the list)
template<class listdata>
List<listdata>::~List() {
	Node* cursor = first;
	Node* temp;
	while (cursor != NULL) {
		temp = cursor->next;
		delete cursor;
		cursor = temp;
	}
}

template<class listdata>
listdata List<listdata>::getFirst() {
	assert(!isEmpty());
	return first->data;
}

template<class listdata>
listdata List<listdata>::getLast() {
	assert(!isEmpty());
	return last->data;
}

template<class listdata>
int List<listdata>::getSize() {
	return size;
}

template<class listdata>
bool List<listdata>::isEmpty() {
	return (size == 0);
}

template<class listdata>
void List<listdata>::insertLast(listdata data) {
	if (size == 0) {
		last = new Node(data);
		first = last;
	} else {
		Node* newLast = new Node(data); //new node to insert
		last->next = newLast; //former last now points to new last
		newLast->previous = last;
		last = newLast; //set last equal to newLast
	}
	size++;
}

template<class listdata>
void List<listdata>::insertFirst(listdata data) //step 2 & 3: List is templated and takes in a generic param
		{
	if (size == 0) {
		first = new Node(data); //note that although data is of a generic type, we use it as before.
		last = first;

	} else {
		Node* newFirst = new Node(data);
		newFirst->next = first;
		first->previous = newFirst;
		first = newFirst;
	}

	size++;

}
template<class listdata>
void List<listdata>::removeFirst() {
	assert(!isEmpty());
	 if (size == 1) {
		delete first;
		first = last = NULL;
		size = 0;
	} else {
		Node* temp = first; //store pointer to first so we don't lose access to it
		first = first->next; //advance the pointer
		delete temp; //free the memory for the original first node
		first->previous = NULL;
		size--;
	}
}

template<class listdata>
void List<listdata>::removeLast() {
	assert(!isEmpty());
	if (size == 1) {
		delete last;
		last = first = NULL;
		size = 0;

	} else {
		Node* temp = first;
		while (temp->next != last) {
			temp = temp->next; //move temp pointer to second to last
		}
		delete last; //free the memory for the original last node
		last = temp; //last equals former second to last node
		last->next = NULL; //so last->next is not pointing at freed memory
		size--;
	}

}

template<class listdata>
void List<listdata>::printList(ostream& fout) {
	Node* temp = first; //create a temporary iterator, start at the first
	while (temp != NULL) {
		cout << temp->data << " ";
		fout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;

}

//Iterator Functions
template<class listdata>
void List<listdata>::startIterator() {
assert(!isEmpty());
iterator = first;
}

template<class listdata>
void List<listdata>::advanceIterator() {
assert(!offEnd());
iterator = iterator->next;
}

template<class listdata>
void List<listdata>::removeIterator() {
	assert(!isEmpty());
	if (size == 1) {
		removeFirst();
	} else if ((iterator->next) == NULL) {
		removeLast();
		iterator = last;

	} else {
		Node* temp = iterator;	//create new temporary node at iterator position
		//update the pointers of the iterator first
		iterator->previous->next = iterator->next;
		iterator->next->previous = iterator->previous;
		advanceIterator();	//keep iterator "running"
		delete temp;	//delete the node iterator was previously pointing to
		//iterator = temp;
		//iterator =  NULL;

		size--;
	}
}

template<class listdata>
listdata List<listdata>::getIterator() {
	assert(!offEnd());
	assert(!isEmpty());
	return iterator->data;
}

template<class listdata>
bool List<listdata>::offEnd() {
	return iterator == NULL;
}

template<class listdata>
void List<listdata>::insertIterator(listdata data) {
	assert(!offEnd());
	assert(!isEmpty());
	if (iterator == last) {
		insertLast(data);
	} else {
		Node* newINode = new Node(data);
		newINode->next = iterator->next;
		newINode->previous = iterator;
		iterator-> next-> previous = newINode;
		iterator->next = newINode;
		size++;

	}

}
template <class listdata>
bool List<listdata>::operator==(const List& list)
 {
	if (size != list.size)
		return false;
	Node* temp1 = first;
	Node* temp2 = list.first;
	while (temp1 != NULL) {
		if (temp1->data != temp2->data)
			return false;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return true;
}

//needs to be start at first due to how recursion does operations in a stack
//public function
template<class listdata>
void List<listdata>::printReverse() {
	Node* temp = first;
	if (isEmpty())
		cout << "";
	reverse(temp);
}

//private function
template<class listdata>
void List<listdata>::reverse(Node* temp) {
	if (temp == NULL)
		return;
	else {
		reverse(temp -> next);
		cout << temp -> data << " ";
	}
}

//public function
template<class listdata>
bool List<listdata>::isSorted() {
	Node* temp = first;
	return isSorted(temp);
}

//private function
template<class listdata>
bool List<listdata>::isSorted(Node* temp) {
	if (temp -> next == NULL) { //the entire list has been checked, it is sorted
		cout << "List is sorted" << endl;
		return true;
	} else if (temp -> data <= temp -> next-> data) {
		return isSorted(temp -> next);
	}
	cout << "List is not sorted" << endl;
	return false;
}

//check where the iterator is
template<class listdata>
int List<listdata>::getIndex() {
	assert(!isEmpty());
	assert(!offEnd());
	Node* temp = first;
	int index = 1;
	while (temp != iterator) {
		temp = temp->next;
		index++;
	}
	return index;
}

//advance iterator to a specified position on the list
template<class listdata>
void List<listdata>::advanceToIndex(int index) {
	assert(!isEmpty());
	assert(!offEnd());
	Node* temp = first;
	int counter = 1;
	while (counter != index) {
		temp = temp->next;
		counter++;
	}
	iterator = temp;
}

//public - keep searching until you find the data, or return -1 if never found
template<class listdata>
int List<listdata>::linearSearch(listdata data) {
	assert(!isEmpty());
	assert(!offEnd());
	Node* temp = first;
	int index = 1;
	while (temp->data != data) {
		index++;
		//return temp-> data;
		temp = temp->next;
		if (temp == NULL)
			return -1;
	}
	return index;
}

//public
template<class listdata>
int List<listdata>::binarySearch(listdata data) {
	assert(isSorted());
	assert(!isEmpty());
	int low = 1;
	int high = getSize();
	return binarySearch(low, high, data);
}

//private
template<class listdata>
int List<listdata>::binarySearch(int low, int high, listdata data) {
	if (high < low) //the list has been thoroughly searched for, the value does not exist
		return -1;
	int mid = (low + (high - low) / 2); //the midpoint formula

	Node* midPosition = first;
	//We need to somehow move the node pointer to point to the middle node
	int counter = 1;
	while (counter != mid) {
		midPosition = midPosition->next;
		counter++;
	}
	if (midPosition -> data == data) //if at any point, mid refers to the data, return the index
		return counter;
		//return midPosition->data;
	else if (data < midPosition -> data ) //search the left half
		return binarySearch(low, mid - 1, data);
	else
		//search the right half
		return binarySearch(mid + 1, high, data);
	return -1;
}

#endif /* LIST_H_ */

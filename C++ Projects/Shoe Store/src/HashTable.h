#define HASHTABLE_H_
#include "Customer.h"
#include "Heap.h"
#include <string>

using namespace std;

class HashTable {
public:
    /**Constructors*/

    HashTable();
    //constructor

    ~HashTable();
    //destructor


    HashTable(const HashTable& ht);
    //copy constructor

    /**Access Functions*/

    int hash(string key);
    //returns the hash value for the given key
    //the hash value is the sum of
    //of the ASCII values of each char in the key
    //% the size the of the table
    //Key for this table: brand+productName

    int countBucket(int index);
    //counts the number of Customers at this index
    //returns the count
    //pre: 0<= index < SIZE

    int search(Customer s);
    //Searches for s in the table
    //returns the index at which s is located
    //returns -1 if s is not in the table

    Customer searchCustomer(int i, string last_name, string first_name);

    /**Manipulation Procedures*/

    void insert(Customer s);
    //inserts a new Customers into the table
    //calls the hash function on the key to determine
    //the correct bucket

    void remove(Customer s);
    //removes s from the table
    //calls the hash function on the key to determine
    //the correct bucket

    /**Additional Functions*/

    void printBucket(int index, ostream& os);
    //Prints all the Customers at index
    //pre: 0<= index < SIZE
    //Should print according to the following formula:
    //"Printing index <index#>
    //skips two lines
    //Next, prints each Customers at that index in the format:
    // Brand: <brand>
    // Product Name: <product name>
    // Type: <type>
    // Color: <color>
    // Size: <size>
    // Price: $<price>

    //followed by a blank line

    void printTable(ostream& os);
    //Prints the first Customers at each index
    //along with a count of the total Customers
    //at each index by calling count_bucket
    //as a helper function
    //Prints in the format:
    //<----------------------->
    //Bucket: <index>
    // Brand: <brand>
    // Product Name: <product name>
    // Type: <type>
    // Color: <color>
    // Size: <size>
    // Price: $<price>
    //Number of Customers at this bucket: <number of elements at this index>
    //<----------------------->

    void printEveryCustomer(ostream& os, Heap heap);

private:
    static const int SIZE = 10;
    List<Customer> Table[SIZE];
};

HashTable::HashTable(){}

HashTable::~HashTable(){}

HashTable::HashTable(const HashTable& ht)
{
	for(int i = 0; i < SIZE ; i++)
	{
		List<Customer> *temp= new List<Customer>(ht.Table[i]);
		Table[i] = *temp;
	}
}
int HashTable::hash(string key)
{
	int index, sum = 0;
	for(int i = 0; i<key.length();i++)
	{
		sum += (int)key[i];
	}
	index = sum % SIZE;
	return index;
}


int HashTable::countBucket(int index)
{
	assert(0 <= index < SIZE);
	int counter = 0;
	if(!Table[index].isEmpty())
	{
		Table[index].startIterator();
		while(!Table[index].offEnd())
		{
			counter++;
			Table[index].advanceIterator();
		}
	}
	return counter++;
}

int HashTable::search(Customer b)
{
	int index = hash(b.get_first_name() + b.get_last_name());
	if(!Table[index].isEmpty())
	{
		Table[index].startIterator();
		while(!Table[index].offEnd())
		{
			if(Table[index].getIterator().get_last_name() == b.get_last_name())
			{
				return index;
			}
			Table[index].advanceIterator();
		}
	}
	return -1;
}

Customer HashTable::searchCustomer(int i, string last_name, string first_name)
{
	Table[i].startIterator();
	while(!Table[i].offEnd())
	{
		if(last_name == Table[i].getIterator().get_last_name() && first_name == Table[i].getIterator().get_first_name())
		{
			return Table[i].getIterator();
		}
		Table[i].advanceIterator();
	}
}


void HashTable::insert(Customer b)
{
	int index = hash(b.get_first_name() + b.get_last_name());
	Table[index].insertLast(b);
}

void HashTable::remove(Customer b)
{
	int index = hash(b.get_first_name() + b.get_last_name());
	if(!Table[index].isEmpty())
	{
		Table[index].startIterator();
		while(!Table[index].offEnd())
		{
			if(Table[index].getIterator() == b)
			{
				Table[index].removeIterator();
				cout << "Customer has been removed!";
				return;
			}
			Table[index].advanceIterator();
		}
		cout << "Customer is not found in the table";
	}
	else
	{
		cout << "Customer is not found in the table";
	}
}

void HashTable::printBucket(int index, ostream& os)
{
	assert(0 <= index < SIZE);
	Customer temp;
	Table[index].startIterator();
	while(!Table[index].offEnd())
	{
		temp = Table[index].getIterator();
		os << temp;

		Table[index].advanceIterator();
	}
}

void HashTable::printEveryCustomer(ostream& os, Heap heap)
{
	Customer temp;
	for(int i = 0; i<SIZE; i++)
	{
		if(!Table[i].isEmpty())
		{
			Table[i].startIterator();
			assert(0 <= i < SIZE);
			Customer temp;
			Table[i].startIterator();
			while(!Table[i].offEnd())
			{
				temp = Table[i].getIterator();
				os << endl << endl << temp;
				heap.findOrder(temp.get_first_name(), temp.get_last_name());
				Table[i].advanceIterator();
			}
		}
	}
}
void HashTable::printTable(ostream &os)
{
	Customer temp;
	for(int i = 0; i<SIZE; i++)
	{
		if(!Table[i].isEmpty())
		{
			Table[i].startIterator();
			printBucket(i, os);
		}
	}
}

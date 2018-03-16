#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include "List.h"
#include <iostream>

class Customer {

private:
    string first_name;
    string last_name;
    string address;
    string city;
    string state;
    string zip;
    string phone_number;


public:
    Customer();
    ~Customer();
    Customer(string fn, string ln, string a, string c, string s, string z, string p);
    string get_first_name ();
    string get_last_name ();
    string get_address();
    string get_city ();
    string get_state ();
    string get_zip ();
    string get_phone_number();
    //List get_orders();

    void set_first_name(string fn);
    void set_last_name(string ln);
    void set_address(string a);
    void set_city(string c);
    void set_state(string s);
    void set_zip(int z);
    void set_phone_number(string p);

    //Additional Functions
    void printCustomer(string s);
    friend ostream& operator<<(ostream& os, const Customer& customer);
    bool operator==(const Customer& customer);
    //compares two books to determine if they are the same book

    bool operator<(const Customer& customer);
    //compares two books to determine if one comes before the other
    //alphabetically by title and secondarily by author if the two
    //books contain the same title
    //returns false if the two books are the same

    bool operator>(const Customer& customer);
    //compares two books to determine if one comes after the other
    //alphabetically by title and secondarily by author if the two
    //books contain the same title
    //returns false if the two books are the same
};

Customer::Customer(){}
Customer::Customer(string fn, string ln, string a, string c, string s, string z, string p)
{
	first_name = fn;
	last_name = ln;
	address = a;
	city = c;
	state = s;
	zip = z;
	phone_number = p;
}
Customer::~Customer(){}

string Customer:: get_first_name(){
	return first_name;
}

string Customer:: get_last_name(){
	return last_name;
}

string Customer:: get_address()
{
	return address;
}

string Customer:: get_city()
{
	return city;
}

string Customer:: get_state()
{
	return state;
}

string Customer:: get_zip()
{
	return zip;
}

string Customer::get_phone_number()
{
	return phone_number;
}
/*Order Customer:: get_orders()
{

} */
void Customer:: set_first_name(string fn){
	first_name = fn;
}

void Customer:: set_last_name(string ln)
{
	last_name = ln;
}

void Customer:: set_city(string c){
	city =c;
}

void Customer:: set_state(string s){
	state =s;
}
void Customer:: set_zip(int z)
{
	zip = z;
}

void Customer:: set_phone_number(string p)
{
	phone_number = p;
}
void Customer::printCustomer(string last_name)
{
	cout << "Customer Name: " << first_name << last_name << endl;
	cout << "Customer Address: " << address << ", " << city << ", " << state << ", " << zip;
}

ostream& operator<<(ostream& os, const Customer& Customer)
{
	return os << Customer.first_name << endl << Customer.last_name << endl << Customer.address << endl << Customer.city << endl << Customer.state << endl << Customer.zip << endl << Customer.phone_number << endl << endl;
}

bool Customer::operator==(const Customer& Customer) {
    return (last_name == Customer.last_name && first_name==Customer.first_name);
}

bool Customer::operator<(const Customer& Customer)
{
	if(last_name == Customer.last_name)
	{
		if(first_name == Customer.first_name)
		{
			return false;
		}
	}
	return(last_name < Customer.last_name);
}

bool Customer::operator>(const Customer& Customer)
{
	if(last_name == Customer.last_name)
	{
		if(first_name == Customer.first_name)
		{
			return false;
		}
	}
	return(last_name > Customer.last_name);
}
#endif /* CUSTOMER_H_ */

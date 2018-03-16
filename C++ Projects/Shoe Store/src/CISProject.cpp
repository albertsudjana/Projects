//============================================================================
// Name        : CISProject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include "Customer.h"
#include "Hashtable.h"
#include "Order.h"
#include "BST.h"



#include <fstream>
#include <sstream>
using namespace std;

int main() {
	int exit = 0;
	while(exit == 0)
	{
		string status, customerChoice, employeeChoice;
		int index;
		Shoe shoe1;
		Shoe2 shoe2;
		Heap heap, heap2;
		string line, first_name, last_name, full_name, address, city, state, zip, phone_number, type, customerDetails, color, date, shoe;
		string product_name, brand, shoe_type, shoe_color, shoe_size, deliveryType, orderNumber;
		int order = 0;
		double price, size,id;
		HashTable customerTable;
		cout << "Hi welcome to Shoe Shop 1.0" << endl;
		cout << "Please enter if you are a customer or an employee" << endl;
		cout << "1) Customer" << endl;
		cout << "2) Employee" << endl;
		cout << "Enter choice here: ";
		cin >> status;
		int counter = 0;
		ifstream fin;
		fin.open("CustomerData.txt");
		while(fin.fail())
			{
				cout << "File not found";
			}
			while(getline(fin, line))
			{
				counter ++;
				if(counter == 1)
				{
					first_name = line;
				}
				if(counter == 2)
				{
					last_name = line;
				}
				if(counter == 3)
				{
					address = line;
				}
				if(counter == 4)
				{
					city = line;
				}
				if(counter == 5)
				{
					state = line;
				}
				if(counter == 6)
				{
					zip = line;
				}
				if(counter == 7)
				{
					phone_number = line;
				}
				if(counter == 8)
				{
					Customer customer(first_name, last_name, address, city, state, zip, phone_number);
					customerTable.insert(customer);
					counter = 0;
				}
			}
			ifstream fin2;
			fin2.open("OrderData.txt");
			while(fin2.fail())
			{
				cout << "File not found";
			}

			while(getline(fin2, line))
			{
				counter ++;
				if(counter == 1)
				{
					if(line == "Delivery Overnight")
					{
						type = "1";
					}
					else if(line == "Delivery Rush")
					{
						type = "2";
					}
					else if(line == "Shipped")
					{
						type = "4";
					}
					else
					{
						type = "3";
					}
				}
				if(counter == 2)
				{
					customerDetails = line;
				}
				if(counter == 3)
				{
					address = line;
				}
				if(counter == 4)
				{
					line.erase(0, 14);
					date = line;
				}
				if(counter == 5)
				{
					color = line;
				}
				if(counter == 6)
				{
					shoe = line;
				}
				if(counter == 7)
				{
					line.erase(0, 6);
					size = atof(line.c_str());
				}
				if(counter == 8)
				{
					line = line.substr(1).append(line.substr(0,1));
					price = atof(line.c_str());
				}
				if(counter == 9)
				{
					line.erase(0, 14);
					orderNumber = line;
					if(order < atof(orderNumber.c_str()))
					{
						order = atof(orderNumber.c_str());
					}
				}
				if(counter == 10)
				{
					Order order(type, customerDetails, color, date, address, shoe, orderNumber, size, price);
					heap.addOrder(order);
					counter = 0;
				}
			}
			heap.heapSort();
			counter = 0;
			ifstream fin4;
			fin4.open("OrderData2.txt");
			while(fin4.fail())
			{
				cout << "File not found";
			}
			while(getline(fin4, line))
			{
				counter ++;
				if(counter == 1)
				{
					if(line == "Delivery Overnight")
					{
						type = "1";
					}
					else if(line == "Delivery Rush")
					{
						type = "2";
					}
					else if(line == "Shipped")
					{
						type = "4";
					}
					else
					{
						type = "3";
					}
				}
				if(counter == 2)
				{
					customerDetails = line;
				}
				if(counter == 3)
				{
					address = line;
				}
				if(counter == 4)
				{
					line.erase(0, 14);
					date = line;
				}
				if(counter == 5)
				{
					color = line;
				}
				if(counter == 6)
				{
					shoe = line;
				}
				if(counter == 7)
				{
					line.erase(0, 6);
					size = atof(line.c_str());
				}
				if(counter == 8)
				{
					line = line.substr(1).append(line.substr(0,1));
					price = atof(line.c_str());
				}
				if(counter == 9)
				{
					line.erase(0, 14);
					orderNumber = line;
				}
				if(counter == 10)
				{
					Order order(type, customerDetails, color, date, address, shoe, orderNumber, size, price);
					heap2.addOrder(order);
					counter = 0;
				}
			}
			heap2.heapSort();
			ifstream fin3;
			fin3.open("ShoeData.txt");
			while(fin3.fail())
			{
				cout << "File not found";
			}
			BST<Shoe> tree;
			BST<Shoe2> tree2;
			counter = 0;
			while(getline(fin3, line))
			 {
				counter++;
				if(counter == 1)
				{
					product_name = line;
				}
				if(counter == 2)
				{
					brand = line;
				}
				if(counter == 3)
				{
					shoe_type = line;
				}
				if(counter == 4)
				{
					shoe_color = line;
				}
				if(counter == 5)
				{
					shoe_size = line;
				}
				if(counter == 6)
				{
					line = line.substr(1).append(line.substr(0,1));
					price = atof(line.c_str());
				}
				if(counter == 7)
				{
					id = atof(line.c_str());
				}
				if(counter == 8)
				{
					Shoe s1(brand, product_name, shoe_type, shoe_color, shoe_size, price, id);
					Shoe2 s2(brand, product_name, shoe_type, shoe_color, shoe_size, price, id);
					tree.insert(s1);
					tree2.insert(s2);
					counter = 0;
				}
			 }
			if (status == "1") {
			cout << endl << "What would you like to do?" << endl;
			cout << "1)Search Shoe" << endl;
			cout << "2)Display all shoes" << endl;
			cout << "3)Place Order" << endl;
			cout << "4)View Purchases" << endl;
			cout << "0)Exit" << endl;

			cout << "Enter your choice: ";
			cin >> customerChoice;
			if(customerChoice == "1")
			{
				string searchChoice, tempShoeName, tempShoeId;
				double tempShoeId2;
				cout << endl << endl << "Search for a product by: " << endl;
				cout << "1)Product Name" << endl;
				cout << "2)Product ID" << endl << endl;
				cout << "Enter your choice: ";
				cin >> searchChoice;
				if(searchChoice == "1")
				{
					cout << "Please enter shoe name: ";
					cin.ignore();
					getline(cin, tempShoeName);
					shoe2 = Shoe2("", tempShoeName, "", "", "", 0, 0);
					if(!tree2.find(shoe2))
					{
						cout << "Shoe not found";
					}
				}
				if(searchChoice == "2")
				{
					cout << "Please enter shoe id: ";
					cin.ignore();
					getline(cin, tempShoeId);
					tempShoeId2 = atof(tempShoeId.c_str());
					shoe1 = Shoe("", "", "", "", "", 0, tempShoeId2);
					if(!tree.find(shoe1))
					{
						cout << "Shoe not found";
					}
				}
				cout << endl << endl << "What would you like to do next?" << endl;
				cout << "Enter 0 to exit" << endl;
				cout << "Enter 1 to return to main menu" << endl;
				cout << "Enter choice here: ";
				cin >> customerChoice;
				if (customerChoice == "0") {
					exit = 1;
				}
				if (customerChoice == "1") {
					exit = 0;
				}
			}

			if(customerChoice == "2")
			{
				cout << "Displaying all shoes" << endl << endl;
				tree2.inOrderPrint();
				cout << "What would you like to do next?" << endl;
				cout << "Enter 0 to exit" << endl;
				cout << "Enter 1 to return to main menu" << endl;
				cout << "Enter choice here: ";
				cin >> customerChoice;
				if (customerChoice == "0") {
					exit = 1;
				}
				if (customerChoice == "1") {
					exit = 0;
				}
			}
			if (customerChoice == "0") {
				exit = 1;
			}
			if (customerChoice == "3") {
				cout << "Please enter your first name: ";
				cin >> ws;
				getline(cin, first_name);
				cout << "Please enter your last name: ";
				getline(cin, last_name);
				Customer temp(first_name, last_name, "", "", "", "", "");
				Customer orderCustomer;
				if (customerTable.search(temp) == -1) {
					cout << "Please enter your street address" << endl;
					cout << "Please enter street number and name: ";
					getline(cin, address);
					cout << "Please enter city: ";
					getline(cin, city);
					cout << "Please enter state: ";
					getline(cin, state);
					cout << "Please enter zip code: ";
					getline(cin, zip);
					cout << "Please enter phone number: ";
					getline(cin, phone_number);
					Customer newCustomer(first_name, last_name, address, city,
							state, zip, phone_number);
					customerTable.insert(newCustomer);
					orderCustomer = newCustomer;
				} else {
					index = customerTable.search(temp);
					orderCustomer = customerTable.searchCustomer(index,
							last_name, first_name);
					cout << "Customer found!";
				}
				cout << "What should you like you buy?" << endl;
				cout << "Name: ";
				getline(cin, shoe);
				shoe2 = Shoe2("", shoe, "", "", "", 0, 0);
				if(tree2.find(shoe2))
				{
					cout << "Shoe found displayed above" << endl;
					cout << "Size: ";
					cin >> size;
					cout << "Color: ";
					cin >> color;
					cout << "Delivery type(1: Overnight, 2: Rush,  3: Standard): ";
					cin >> deliveryType;
					time_t rawtime;
					struct tm * timeinfo;
					char buffer[80];
					time (&rawtime);
					timeinfo = localtime(&rawtime);
					strftime(buffer,sizeof(buffer),"%m/%d/%Y",timeinfo);
					string todayDate(buffer);
					string fullAddress;
					fullAddress = orderCustomer.get_address() + ", " + orderCustomer.get_city() + ", " + orderCustomer.get_state() + ", " + orderCustomer.get_zip();
					order++;
					full_name = first_name + " " + last_name;
					orderNumber = to_string(order);
					Order customerOrder(deliveryType,full_name, color, todayDate, fullAddress, shoe, orderNumber, size, tree2.findPrice(shoe2));
					heap.addOrder(customerOrder);
					heap2.addOrder(customerOrder);
					heap.heapSort();
					heap2.heapSort();
					cout << endl << "Order has been placed" << endl;
				}
				else
				{
					cout << "Shoe not found" << endl;
				}
				cout << "What would you like to do next?" << endl;
				cout << "Enter 0 to exit" << endl;
				cout << "Enter 1 to return to main menu" << endl;
				cout << "Enter choice here: ";
				cin >> customerChoice;
				if (customerChoice == "0") {
					exit = 1;
				}
				if (customerChoice == "1") {
					exit = 0;
				}
			}
			if (customerChoice == "0") {
				exit = 1;
			}
		}
		if(customerChoice == "4")
		{
			string temp_first_name, temp_last_name;
			cout << "Please enter your first name: ";
			cin >> temp_first_name;
			cout << "Please enter your last name: ";
			cin >> temp_last_name;
			if(heap2.searchData(temp_first_name, temp_last_name))
			{
				cout << "Printing your order history" << endl;
				heap2.findOrder(temp_first_name, temp_last_name);
			}
			else
			{
				cout << "No order history" << endl;
			}
			cout << endl << endl << "What would you like to do next?" << endl;
			cout << "Enter 0 to exit" << endl;
			cout << "Enter 1 to return to main menu" << endl;
			cout << "Enter choice here: ";
			cin >> customerChoice;
			if (customerChoice == "0") {
				exit = 1;
			}
			if (customerChoice == "1") {
				exit = 0;
			}
		}
		if(status == "2")
		{
			cout << endl << "1)Search Customer" << endl;
			cout << "2)Display Customer" << endl;
			cout << "3)View Orders" << endl;
			cout << "4)Ship an order" << endl;
			cout << "5)List Database" << endl;
			cout << "6)Add a product" << endl;
			cout << "7)Remove a product" << endl;
			cout << "0)Exit" << endl << endl;
			cout << "Enter choice here: ";
			cin >> employeeChoice;
			if(employeeChoice == "1")
			{
				cout << "Enter customer last name: ";
				cin >> last_name;
				cout << "Enter customer first name: ";
				cin >> first_name;
				Customer employeeSearch(first_name, last_name, "", "", "","","");
				if(customerTable.search(employeeSearch) != -1)
				{
					cout << endl << "Customer found!" << endl;
					index = customerTable.search(employeeSearch);
					employeeSearch = customerTable.searchCustomer(index, last_name, first_name);
					cout << employeeSearch;
				}
				else
				{
					cout << "Customer does not exist!" << endl << endl;
				}
				cout << "What would you like to do next?" << endl;
				cout << "Enter 0 to exit" << endl;
				cout << "Enter 1 to return to main menu" << endl;
				cout << "Enter choice here: ";
				cin >> customerChoice;
				if (customerChoice == "0")
				{
					exit = 1;
				}
				if (customerChoice == "1")
				{
					exit = 0;
				}
			}
			if(employeeChoice == "2")
			{
				customerTable.printEveryCustomer(cout, heap2);
				cout << "What would you like to do next?" << endl;
				cout << "Enter 0 to exit" << endl;
				cout << "Enter 1 to return to main menu" << endl;
				cout << "Enter choice here: ";
				cin >> customerChoice;
				if (customerChoice == "0")
				{
					exit = 1;
				}
				if (customerChoice == "1")
				{
					exit = 0;
				}
			}
			if(employeeChoice == "3")
			{
				heap.displayOrders(cout);
				cout << "What would you like to do next?" << endl;
				cout << "Enter 0 to exit" << endl;
				cout << "Enter 1 to return to main menu" << endl;
				cout << "Enter choice here: ";
				cin >> customerChoice;
				if (customerChoice == "0")
				{
					exit = 1;
				}
				if (customerChoice == "1")
				{
					exit = 0;
				}
			}
			if(employeeChoice == "4")
			{
				cout << "Latest Order has been shipped: " << endl;
				heap2.setShipped(heap);
				heap.printFirstOrder();
				heap.deleteFirstOrder();
				cout << "What would you like to do next?" << endl;
				cout << "Enter 0 to exit" << endl;
				cout << "Enter 1 to return to main menu" << endl;
				cout << "Enter choice here: ";
				cin >> customerChoice;
				if (customerChoice == "0")
				{
					exit = 1;
				}
				if (customerChoice == "1")
				{
					exit = 0;
				}
			}

			if(employeeChoice == "5")
			{
				string listDatabase;
				cout << "List database in which order?" << endl;
				cout << "1)By name" << endl;
				cout << "2)By product ID" << endl << endl;
				cout << "Enter choice here:";
				cin >> listDatabase;
				if(listDatabase == "1")
				{
					tree2.inOrderPrint(cout);
				}
				if(listDatabase == "2")
				{
					tree.inOrderPrint(cout);
				}
				cout << "What would you like to do next?" << endl;
				cout << "Enter 0 to exit" << endl;
				cout << "Enter 1 to return to main menu" << endl;
				cout << "Enter choice here: ";
				cin >> customerChoice;
				if (customerChoice == "0")
				{
					exit = 1;
				}
				if (customerChoice == "1")
				{
					exit = 0;
				}
			}

			if(employeeChoice == "6")
			{
				cout << "Enter product name: ";
				cin >> ws;
				getline(cin, product_name);
				cout << "Enter brand name: ";
				getline(cin, brand);
				cout << "Enter shoe type: ";
				getline(cin, shoe_type);
				cout << "Enter shoe colors(separate with commas): ";
				getline(cin, shoe_color);
				cout << "Enter available sizes(separate with commas): ";
				getline(cin, shoe_size);
				cout << "Enter product price: $";
				cin >> price;
				cout << "Enter product id: ";
				cin >> id;
				shoe1 = Shoe(brand, product_name, shoe_type, shoe_color, shoe_size, price, id);
				shoe2 = Shoe2(brand, product_name, shoe_type, shoe_color, shoe_size, price, id);
				tree.insert(shoe1);
				tree2.insert(shoe2);
				cout << "Shoe has been added to database!" << endl << endl;
				cout << "What would you like to do next?" << endl;
				cout << "Enter 0 to exit" << endl;
				cout << "Enter 1 to return to main menu" << endl;
				cout << "Enter choice here: ";
				cin >> customerChoice;
				if (customerChoice == "0")
				{
					exit = 1;
				}
				if (customerChoice == "1")
				{
					exit = 0;
				}
			}
			if(employeeChoice == "7")
			{
				cout << "Enter name of product to remove: ";
				cin >> ws;
				getline(cin, product_name);
				shoe2 = Shoe2(brand, product_name, shoe_type, shoe_color, shoe_size, price, id);
				id = tree2.findId(shoe2);
				if(tree2.findToRemove(shoe2))
				{
				tree2.remove(shoe2);
				shoe1 = Shoe(brand, product_name, shoe_type, shoe_color, shoe_size, price, id);
				tree.remove(shoe1);
				cout << "Product has been removed from the database" << endl << endl;}
				else
				{
					cout << "Product not found";
				}
				cout << endl << "What would you like to do next?" << endl;
				cout << "Enter 0 to exit" << endl;
				cout << "Enter 1 to return to main menu" << endl;
				cout << "Enter choice here: ";
				cin >> customerChoice;
				if (customerChoice == "0")
				{
					exit = 1;
				}
				if (customerChoice == "1")
				{
					exit = 0;
				}
			}
			if(employeeChoice == "0")
			{
				exit = 1;
			}
		}
		heap.heapSort();
		heap2.heapSort();
		cout << endl << endl;
		ofstream fout("CustomerData.txt");
		customerTable.printTable(fout);
		ofstream fout2("OrderData.txt");
		heap.displayOrders(fout2);
		ofstream fout4("OrderData2.txt");
		heap2.displayOrders(fout4);
		ofstream fout3("ShoeData.txt");
		tree2.inOrderPrint(fout3);
	}

}


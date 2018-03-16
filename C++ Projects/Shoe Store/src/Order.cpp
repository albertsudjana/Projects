#include "Order.h"
#include <iostream>
#include <iomanip>

Order::Order():type(""), customerDetails(""), orderNumber(""), date(""), address(""), shoe(""), size(0.0), price(0.0){};

Order::Order(string t, string c, string o, string d, string a, string sh, string co, double s, double p) {
	type = t;
	customerDetails = c;
	color = o;
	date = d;
	address = a;
	shoe = sh;
	size = s;
	price = p;
	orderNumber = co;

	if(type == "1")
	{
		delivery = "Delivery Overnight";
	}
	else if(type == "2")
	{
		delivery = "Delivery Rush";
	}
	else if(type == "4")
	{
		delivery = "Shipped";
	}
	else
	{
		delivery = "Delivery Standard";
	}
}

/**Access Functions*/

string Order::getType() {
	return type;
}

string Order::getCustomerDetails() {
	return customerDetails;
}

string Order::getOrderNumber() {
	return orderNumber;
}

string Order::getDate() {
	return date;
}

string Order::getAddress() {
	return address;
}

string Order::getShoe() {
	return shoe;
}

string Order::getColor(){
	return color;
}

double Order::getSize() {
	return size;
}

double Order::getPrice() {
	return price;
}

/**Manipulation Procedures*/

void Order::setType(string t){
	type = t;
}

void Order::setCustomerDetails(string c) {
	customerDetails = c;
}

void Order::setOrderNumber(string o) {
	orderNumber = o;
}

void Order::setDate(string d) {
	date = d;
}

void Order::setAddress(string a) {
	address = a;
}

void Order::setShoe(string sh) {
	shoe = sh;
}

void Order::setSize(double s) {
	size = s;
}

void Order::setPrice(double p) {
	price = p;
}

void Order::setDelivery(string p)
{
	delivery = p;
}

void Order::setColor(string co)
{
	color = co;
}
/**Additional Functions*/

bool Order::operator == (const Order& order) {
	return (shoe ==order.shoe && customerDetails == order.customerDetails );
}

bool Order::operator < (const Order& order) {
	if (type < order.type)
		return true;
	else if((type == order.type) && (orderNumber < order.orderNumber) ) {
		return true;
	}else {
		return false;
	}
}

bool Order::operator > (const Order& order) {
	if (type > order.type)
		return true;
	else if((type == order.type) && (orderNumber > order.orderNumber) ) {
		return true;
	} else {
		return false;
	}
}

ostream& operator<<(ostream& os, const Order& order) {
	os <<  order.delivery << endl << order.customerDetails << endl << order.address << endl <<  "Date Ordered: " << order.date << endl << order.color << endl << order.shoe << endl << setprecision(1) << fixed << "Size: " << order.size << setprecision(2) << fixed << endl << "$" << order.price << endl << "Order Number: " << order.orderNumber << endl;
	return os;
}






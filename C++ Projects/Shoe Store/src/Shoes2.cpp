/*
 * Shoe2s22.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: Nadya Audrey
 */

#include "Shoes2.h"
#include <iostream>
#include <iomanip>

Shoe2::Shoe2():brand(""), productName(""), type(""), color(""), size(""), price(0.0), idNum(0){};

Shoe2::Shoe2(string b, string pn, string t, string c, string s, double p, int id) {
    brand = b;
    productName = pn;
    type = t;
    color = c;
    size = s;
    price = p;
    idNum = id;
}

/**Access Functions*/

string Shoe2::get_brand() {
    return brand;
}

string Shoe2::get_productName() {
    return productName;
}

string Shoe2::get_type(){
	return type;
}
string Shoe2::get_color(){
	return color;
}
string Shoe2::get_size() {
    return size;
}

double Shoe2::get_price() {
    return price;
}
int Shoe2::get_idNum()
{
	return idNum;
}
/**Manipulation Procedures*/

void Shoe2::set_brand(string b){
    brand = b;
}

void Shoe2::set_productName(string pn) {
    productName = pn;
}

void Shoe2::set_type(string t) {
    type = t;
}

void Shoe2::set_color(string c) {
    color = c;
}
void Shoe2::set_size(string s){
	size = s;
}
void Shoe2::set_price(double p){
	price = p;
}
void Shoe2::set_idNum(int id)
{
	idNum = id;
}
/**Additional Functions*/


bool Shoe2::operator==(const Shoe2& shoes) {
    return (productName==shoes.productName);
}

//To-do: Add <, > and << here

ostream& operator<<(ostream& os, const Shoe2& shoes)
{
	os << shoes.productName << endl;
	os << shoes.brand << endl;
	os << shoes.type << endl;
	os << shoes.color << endl;
	os << shoes.size << endl;
	os << "$" << fixed << setprecision(2) <<shoes.price << endl;
	os << shoes.idNum << endl;
	return os;
}

bool Shoe2::operator<(const Shoe2& shoes)
{
	if(productName != shoes.productName)
	return(productName < shoes.productName);
else if(productName == shoes.productName)
	return(brand < shoes.brand);
else
	return false;
}
bool Shoe2::operator>(const Shoe2& shoes)
{
	if(productName != shoes.productName)
		return(productName > shoes.productName);
	else if(productName == shoes.productName)
		return(brand > shoes.brand);
	else
		return false;
}

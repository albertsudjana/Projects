/*
 * Shoes.cpp
 *
 *  Created on: Mar 18, 2017
 *      Author: Nadya Audrey
 */
/*
 * Nadya Audrey Salim
 * CIS 22C, Winter 2017
 */
#include "Shoes.h"
#include <iostream>
#include <iomanip>

Shoe::Shoe():brand(""), productName(""), type(""), color(""), size(""), price(0.0), idNum(0){};

Shoe::Shoe(string b, string pn, string t, string c, string s, double p, int id) {
    brand = b;
    productName = pn;
    type = t;
    color = c;
    size = s;
    price = p;
    idNum = id;
}

/**Access Functions*/

string Shoe::get_brand() {
    return brand;
}

string Shoe::get_productName() {
    return productName;
}

string Shoe::get_type(){
	return type;
}
string Shoe::get_color(){
	return color;
}
string Shoe::get_size() {
    return size;
}

double Shoe::get_price() {
    return price;
}
int Shoe::get_idNum()
{
	return idNum;
}
/**Manipulation Procedures*/

void Shoe::set_brand(string b){
    brand = b;
}

void Shoe::set_productName(string pn) {
    productName = pn;
}

void Shoe::set_type(string t) {
    type = t;
}

void Shoe::set_color(string c) {
    color = c;
}
void Shoe::set_size(string s){
	size = s;
}
void Shoe::set_price(double p){
	price = p;
}
void Shoe::set_idNum(int id)
{
	idNum = id;
}
/**Additional Functions*/


bool Shoe::operator==(const Shoe& shoes) {
    return (idNum == shoes.idNum);
}

//To-do: Add <, > and << here

ostream& operator<<(ostream& os, const Shoe& shoes)
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
bool Shoe::operator<(const Shoe& shoes)
{
	return (idNum < shoes.idNum);
}
bool Shoe::operator>(const Shoe& shoes)
{
	return (idNum > shoes.idNum);
}

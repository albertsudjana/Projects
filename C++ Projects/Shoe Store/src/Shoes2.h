/*
 * Shoes2.h
 *
 *  Created on: Mar 25, 2017
 *      Author: Nadya Audrey
 */

#ifndef SHOES2_H_
#define SHOES2_H_

#include <string>
#include <ostream>
using namespace std;

class Shoe2 {
private:
    string brand;
    string productName;
    string type;
    string color;
    string size;
    double price;
    int idNum;


public:

/**Constructors*/
    Shoe2();
    Shoe2(string b, string pn, string t, string c, string s, double p, int id);

    /**Access Functions*/
    string get_brand();
    string get_productName();
    string get_type();
    string get_color();
    string get_size();
    double get_price();
    int get_idNum();

    /**Manipulation Procedures*/
    void set_brand(string b);
    void set_productName(string pn);
    void set_type(string t);
    void set_color(string c);
    void set_size(string s);
    void set_price(double p);
    void set_idNum(int id);



/**Additional Functions*/

    friend ostream& operator<<(ostream& os, const Shoe2& shoes);
    //prints out a shoes to the designated stream in the following format
    // Brand: <brand>
    // Product Name: <product name>
    // Type: <type>
    // Color: <color>
    // Size: <size>
    // Price: $<price>
    //note that the << is required to be a friend function, not a member function
    //note2: do not print out the <> as part of the output

    bool operator==(const Shoe2& shoes);
    //compares two shoes to determine if they are the same shoes

    bool operator<(const Shoe2& shoes);
    //compares two shoes to determine if one comes before the other
    //alphabetically by brand and secondarily by product name if the two
    //shoes has the same brand
    //returns false if the two shoes are the same

    bool operator>(const Shoe2& shoes);
    //compares two shoes to determine if one comes after the other
    //alphabetically by brand and secondarily by product name if the two
    //shoes has the same brand
    //returns false if the two shoes are the same

};

#endif /* SHOES2_H_ */

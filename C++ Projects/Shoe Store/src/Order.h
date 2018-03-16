#ifndef ORDER_H_
#define ORDER_H_

#include <string>
#include <ostream>
using namespace std;

class Order {
private:
	string type;
	string customerDetails;
	string orderNumber;
	string date;
	string address;
	string shoe;
	string delivery;
	string color;
	double size;
	double price;

public:

/**Constructors*/
	Order();
	Order(string t, string c, string o, string d, string a, string shoe, string co, double s, double p);


/**Access Functions*/
	string getType();
	string getCustomerDetails();
	string getOrderNumber();
	string getDate();
	string getAddress();
	string getShoe();
	string getColor();
	double getSize();
	double getPrice();

	/**Manipulation Procedures*/
	void setType(string t);
	void setCustomerDetails(string c);
	void setOrderNumber(string o);
	void setDate(string d);
	void setAddress(string a);
	void setShoe(string sh);
	void setSize(double s);
	void setPrice(double p);
	void setDelivery(string d);
	void setColor(string co);


/**Additional Functions*/

	friend ostream& operator << (ostream& os, const Order& order);

	bool operator == (const Order& order);

	bool operator < (const Order& order);

	bool operator > (const Order& order);
};

#endif /* ORDER_H_ */

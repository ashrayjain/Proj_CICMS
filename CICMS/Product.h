/***************************************************************************************
//
//  class Product
//
//  Description: The Product class defines a Product in CICMS, with all its attributes. It also provides the API for
//  accessing various attributes of a given Product for further processing and updating the sale value and the stock
//  value. Furthermore, it also allows comparison of two Product objects using overloaded relational operators that 
//  compare the objects' barcodes.
//  
//  API:
//  Product(std::string, std::string, std::string, unsigned, double, unsigned _no_in_stock = 0, unsigned _no_sold = 0);
//  std::string getName();
//  std::string getCategory();
//  std::string getManufacturer();
//  unsigned getBarcode();
//  unsigned getNoInStock();
//  unsigned getNoSold();
//  double getPrice();
//  bool updateSale(unsigned);
//  void updateStock(unsigned);
//  bool operator==(Product& rhs);
//  bool operator!=(Product& rhs);
//  bool operator< (Product& rhs);
//  bool operator> (Product& rhs);
//  bool operator<=(Product& rhs);
//  bool operator>=(Product& rhs);
//
//  Main authors: ASHRAY JAIN(A0105199B)
//
****************************************************************************************/

#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>

class Product
{
private:
	std::string _name, _category, _manufacturer;
	unsigned _barcode, _no_in_stock, _no_sold;
	double _price;

public:
	// Constructor
	Product(std::string, std::string, std::string, unsigned, double, unsigned _no_in_stock = 0, unsigned _no_sold = 0);

	// Getter Functions
	std::string getName();
	std::string getCategory();
	std::string getManufacturer();
	unsigned getBarcode();
	unsigned getNoInStock();
	unsigned getNoSold();
	double getPrice();

	// Modify sale and stock values
	bool updateSale(unsigned);
	void updateStock(unsigned);

	// Overloaded operators
	inline bool operator==(Product& rhs){ return this->_barcode == rhs._barcode; }
	inline bool operator!=(Product& rhs){ return !(this->operator==(rhs)); }
	inline bool operator< (Product& rhs){ return this->_barcode < rhs._barcode; } 
	inline bool operator> (Product& rhs){return  rhs.operator<(*this);} 
	inline bool operator<=(Product& rhs){return !(this->operator> (rhs));} 
	inline bool operator>=(Product& rhs){return !(this->operator< (rhs));}
};

#endif
/***************************************************************************************
//
//  class logic: Product.h
//
//  Description: Product.h containg the specification of the class Product. class Product
//  defines a Product in CICMS, with all its attributes. It also provides the API for
//  accessing various attributes of a given Product for further processing.
//  
//  API:
//  Product(std::string, std::string, std::string, unsigned, unsigned, unsigned, double);
//	std::string getName();
//  std::string getCategory();
//  std::string getManufacturer();
//  unsigned getBarcode();
//  unsigned getNoInStock();
//  unsigned getNoSold();
//  double getPrice();
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
	Product(std::string, std::string, std::string, unsigned, double, unsigned, unsigned);
	std::string getName();
	std::string getCategory();
	std::string getManufacturer();
	unsigned getBarcode();
	unsigned getNoInStock();
	unsigned getNoSold();
	double getPrice();
	bool updateSale(unsigned);
	void updateStock(unsigned);
	inline bool operator==(Product& rhs) { return this->getBarcode()==rhs.getBarcode(); }
	inline bool operator!=(Product& rhs){return !(this->operator==(rhs));}
};

#endif
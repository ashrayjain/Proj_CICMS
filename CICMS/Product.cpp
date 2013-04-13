/***************************************************************************************
//
//  class Product: Product.cpp
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

#include "stdafx.h"
#include "Product.h"
#include <string>

using namespace std;

Product::Product(std::string name, std::string category, std::string manufacturer, unsigned barcode, double price, unsigned no_in_stock, unsigned no_sold)
{
	_name = name;
	_category = category;
	_manufacturer = manufacturer;
	_barcode = barcode;
	_no_in_stock = no_in_stock;
	_no_sold = no_sold;
	_price = price;
}

string Product::getName()
{
	return _name;
}

string Product::getCategory()
{
	return _category;
}

string Product::getManufacturer()
{
	return _manufacturer;
}

unsigned Product::getBarcode()
{
	return _barcode;
}

unsigned Product::getNoSold()
{
	return _no_sold;
}

unsigned Product::getNoInStock()
{
	return _no_in_stock;
}

double Product::getPrice()
{
	return _price;
}

bool Product::updateSale(unsigned sale)
{
	if(_no_in_stock < sale)
		return false;
	_no_sold += sale;
	_no_in_stock -= sale;
	return true;
}

void Product::updateStock(unsigned stock)
{
	_no_in_stock += stock;
}
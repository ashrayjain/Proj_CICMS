/***************************************************************************************
//
//  class logic: Product.cpp
//
//  Description: Product.cpp containg the implementation of the class Product. class Product
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

#include "stdafx.h"
#include "Product.h"
#include <string>

using namespace std;

Product::Product(std::string name, std::string category, std::string manufacturer, unsigned barcode, double price)
{
	_name = name;
	_category = category;
	_manufacturer = manufacturer;
	_barcode = barcode;
	_no_in_stock = 0;
	_no_sold = 0;
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

void Product::updateSale(unsigned sale)
{
	_no_sold += sale;
	updateStock(_no_in_stock-sale);
}

void Product::updateStock(unsigned stock)
{
	_no_in_stock = stock;
}
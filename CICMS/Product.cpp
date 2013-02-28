#include "stdafx.h"
#include "Product.h"
#include <string>

using namespace std;

Product::Product(std::string name, std::string category, std::string manufacturer, unsigned barcode, unsigned no_in_stock, unsigned no_sold, double price)
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
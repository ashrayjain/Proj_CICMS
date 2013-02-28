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
	Product(std::string, std::string, std::string, unsigned, unsigned, unsigned, double);
	std::string getName();
	std::string getCategory();
	std::string getManufacturer();
	unsigned getBarcode();
	unsigned getNoInStock();
	unsigned getNoSold();
	double getPrice();
};

#endif
#ifndef _DB_PROCESSING_H_
#define _DB_PROCESSING_H_

#include "List_v1.h"
#include <sstream>
using namespace std;

class DB_Processing
{
private:
	List_v1<Product>* _db;
	List_v1<Product>* searchByName(string);
	List_v1<Product>* searchByCategory(string);
	List_v1<Product>* searchByManufacturer(string);
	List_v1<Product*>* searchByBarcode(string);
	int edit_distance(string a, string b);
	int count_occurences(string a, char b);

public:
	DB_Processing(List_v1<Product>& db) { _db = &db; }
	bool addProduct(Product);
	bool delProduct(Product);
	List_v1<Product>* search(string, int);
	bool updateStock(Product, int);
	bool updateSale(Product, unsigned);
	List_v1<Product> generateStats(int);
};

#endif
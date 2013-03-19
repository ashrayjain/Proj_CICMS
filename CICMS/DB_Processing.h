#ifndef _DB_PROCESSING_H_
#define _DB_PROCESSING_H_

#include "List_v1.h"
#include "Search.h"
#include <list>
using namespace std;

class DB_Processing
{
private:
	list_adt<Product>* _db;
	search s;
	Product* getProduct(unsigned barcode);
	void ins_sort(list<pair<int, list<Product>>>*, Product, int);
	
public:
	DB_Processing(list_adt<Product>& db): _db(&db), s(&db) {}
	bool addProduct(Product);
	bool delProduct(Product);
	vector<Product>* search(string, int);
	bool updateStock(Product, int);
	bool updateSale(Product, unsigned);
	vector<Product>* generatePrd(int X = 1);
	vector<Product>* generatePrd(string cat);
	vector<string>* generateManu();
};

#endif
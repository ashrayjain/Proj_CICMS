#ifndef _DB_PROCESSING_H_
#define _DB_PROCESSING_H_

#include "List_v1.h"
#include "Search.h"
using namespace std;

class DB_Processing
{
private:
	List_v1<Product>* _db;
	search s;
	Product* getProduct(unsigned barcode);
	
public:
	DB_Processing(List_v1<Product>& db): _db(&db), s(&db) {}
	bool addProduct(Product);
	bool delProduct(Product);
	vector<Product>* search(string, int);
	bool updateStock(Product, int);
	bool updateSale(Product, unsigned);
	vector<Product>* generatePrd(int X);
	vector<Product>* generatePrd(string cat);
	vector<string>* generateManu();
};

#endif
/*************************************************************************************************/
//
//  class DB_Processing: DB_Processing.h
//
//  Description: DB_Proceesing implements features like adding a product to the database,
//  deleting a product from the database, update the stock or the sale of a product, generate
//  various statistics using the database and searching the database. It utilizes function
//  overloading for the function generatePrd(), where a string parameter generated the best
//  product in a given category while an int parameter generates the top X products in the database.
//
//  API:
//  DB_Processing(list_adt<Product>& db);
//	bool addProduct(Product);
//	bool delProduct(Product);
//	vector<Product>* search(string, int);
//	bool updateStock(Product, int);
//	bool updateSale(Product, unsigned);
//	vector<Product>* generatePrd(int X = 1);
//	vector<Product>* generatePrd(string);
//	vector<string>* generateManu();
//
//  Main authors: ASHRAY JAIN (A0105199B)
//
/*************************************************************************************************/

#ifndef _DB_PROCESSING_H_
#define _DB_PROCESSING_H_

#include "List_v1.h"
//#include "List_v2.h"
//#include "List_v3.h"

#include "Search.h"
#include <list>
#include <xutility>
#include <fstream>

using namespace std;

class DB_Processing
{
private:
	list_adt<Product>* _db;
	Search s;
	Product* getProduct(unsigned barcode);
	void ins_sort(list<pair<int, list<Product>>>*, Product, int);
	
public:
	DB_Processing(list_adt<Product>& db): _db(&db), s(&db) {}
	bool addProduct(Product);
	bool delProduct(Product);
	bool delProduct(unsigned);
	vector<Product>* search(string, int);
	bool updateProduct(Product);
	bool updateStock(Product, unsigned);
	bool updateSale(Product, unsigned);
	bool updateStock(unsigned, unsigned);
	bool updateSale(unsigned, unsigned);
	vector<vector<Product>>* generatePrd(int X = 1);
	vector<Product>* generatePrd(string cat);
	vector<string>* generateManu();
};

#endif
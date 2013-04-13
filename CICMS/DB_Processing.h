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
//  *** Constructor that takes in a database to work on and also initializes the search ***
//  DB_Processing(list_adt<Product>& db): _db(&db), s(&db) {}
//
//  *** Adds the given Product to the database ***
//	bool addProduct(Product);
//
//  *** Deletes the given Product from the database ***
//	bool delProduct(Product);
//
//  *** OVERLOADED DELETE: Deletes the Product in the database with the given barcode ***
//	bool delProduct(unsigned);
//
//  *** Searches for the given string using the given method of search in the database  *** 
//	vector<Product>* search(string, int);
//
//  *** Updates the Product in the database with the given Product (using the barcode)  *** 
//	bool updateProduct(Product);
//
//  *** Updates the stock of a given product by the given amount  *** 
//	bool updateStock(Product, unsigned);
//
//  *** OVERLOADED STOCK: Updates the stock by the given amount of the Product with the given barcode *** 
//	bool updateStock(unsigned, unsigned);
//
//  *** Updates the sale of a given product by the given amount  *** 
//	bool updateSale(Product, unsigned);
//
//  *** OVERLOADED SALE: Updates the sale by the given amount of the Product with the given barcode *** 
//	bool updateSale(unsigned, unsigned);
//
//  *** Generates the top X Best selling Products in the database (Note: Default value = 1, i.e., the Best selling product) ***
//	vector<vector<Product>>* generatePrd(int X = 1);
//
//  *** Generates the Best selling product in the given category, in the database ***
//	vector<Product>* generatePrd(string cat);
//   
//  *** Generates the Manufacturer from the database with the Highest sales ***
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

using namespace std;

class DB_Processing
{
private:
	// pointer to the database
	list_adt<Product>* _db;
	// provides API for search functions
	Search s;
	// returns pointer to a Product with a given barcode, from the database
	Product* getProduct(unsigned barcode);
	// inserts a product into the list, ensuring that its sorted
	// in descending order and its size is X at max
	void ins_sort(list<pair<int, list<Product>>>*, Product, int);
	
public:
	// PUBLIC API
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
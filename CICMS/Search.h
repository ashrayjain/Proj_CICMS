/******************************************************************************************************/
//
//  class search
//
//  Description: The search class implements all the search related features, like searching products
//  from the database with respect to their name, barcode, category or manufacturer.
//
//  API:
//  search(list_adt<Product> * db);
//	vector<Product>* searchByName(string);
//	vector<Product>* searchByCategory(string);
//	vector<Product>* searchByManufacturer(string);
//	vector<Product>* searchByBarcode(string);
//
//  Main authors: ASHRAY JAIN (A0105199B)
//
/******************************************************************************************************/

#ifndef _SEARCH_H_
#define _SEARCH_H_


#include "stdafx.h"
#include "Product.h"
#include "List_v1.h"
//#include "List_v2.h"
//#include "List_v1.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class search
{
public:
	search(list_adt<Product> * db): _db(db) {}
	vector<Product>* searchByName(string);
	vector<Product>* searchByCategory(string);
	vector<Product>* searchByManufacturer(string);
	vector<Product>* searchByBarcode(string);
	
private:
	list_adt<Product>* _db;
	int min(int, int);
	int max(int, int);
	string convertToLower(string);
	void smartSearch(Product, string, string, vector<Product>* &, vector<Product> &, vector<vector<Product>> &, vector<vector<Product>> &, int);
	void search::getConsolidatedResults(vector<Product>* &, vector<Product> &, vector<vector<Product>> &, vector<vector<Product>> &, int);
	int substring_search(string, string);
	int editDistance(string, string, int);
	int countOccurrences(string, char);
};

#endif
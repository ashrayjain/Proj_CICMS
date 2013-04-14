/******************************************************************************************************/
//
//  class Search: Search.h
//
//  Description: The Search class implements all the Search related features, like searching products
//  from the database with respect to their name, barcode, category or manufacturer.
//
//  API:
//  *** Constructor that takes in a pointer to the database ***
//  Search(list_adt<Product> * db): _db(db) {}
//  
//  *** Search for the string in the database using Product names ***
//	vector<Product>* searchByName(string);
//  
//  *** Search for the string in the database using Product categories ***
//	vector<Product>* searchByCategory(string);
//  
//  *** Search for the string in the database using Product manufacturers ***
//	vector<Product>* searchByManufacturer(string);
//  
//  *** Search for the string in the database using Product barcodes ***
//	vector<Product>* searchByBarcode(string);
//  
//  *** Static function to convert given string to lowercase ***
//	static string convertToLower(string);
//
//  Main authors: ASHRAY JAIN (A0105199B)
//
/******************************************************************************************************/

#ifndef _SEARCHCLASS_H_
#define _SEARCHCLASS_H_


#include "stdafx.h"
#include "Product.h"

//#include "List_v1.h"
//#include "List_v2.h"
#include "List_v3.h"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Search
{
public:
	Search(list_adt<Product> * db): _db(db) {}
	vector<Product>* searchByName(string);
	vector<Product>* searchByCategory(string);
	vector<Product>* searchByManufacturer(string);
	vector<Product>* searchByBarcode(string);
	static string convertToLower(string);
	
private:
	// Pointer the database
	list_adt<Product>* _db;
	// Return lesser element
	int Min(int, int);
	// Return greater element 
	int Max(int, int);
	// Search for given string in the database and get results of different accuracy levels
	void smartSearch(Product, string, string, vector<Product>* &, vector<Product> &, vector<vector<Product>> &, vector<vector<Product>> &, int);
	// Consolidate the different types of results into one
	void getConsolidatedResults(vector<Product>* &, vector<Product> &, vector<vector<Product>> &, vector<vector<Product>> &, int);
	// Get the number of occurrences of each part of the query in the given string
	int substring_search(string, string);
	// Get closeness of one string to another (i.e. the edit distance)
	int editDistance(string, string, int);
};

#endif
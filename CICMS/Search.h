#ifndef _SEARCH_H_
#define _SEARCH_H_


#include "stdafx.h"
#include "Product.h"
#include "List_v1.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class search
{
public:
	search(List_v1<Product> * db): _db(db) {}
	vector<Product>* searchByName(string);
	vector<Product>* searchByCategory(string);
	vector<Product>* searchByManufacturer(string);
	vector<Product>* searchByBarcode(string);
	int min(int a, int b);
	int max(int a, int b);
private:
	List_v1<Product>* _db;
	string convertToLower(string);
	void smartSearch(Product, string, string, vector<Product>*, vector<vector<Product>> &, vector<Product> &, bool &, int);
	void search::getFilteredResults(vector<Product>*, vector<vector<Product>> &, vector<Product> &, int);
	int substring_search(string, string);
	int editDistance(string a, string b, int k);
	int countOccurrences(string a, char b);
};

#endif
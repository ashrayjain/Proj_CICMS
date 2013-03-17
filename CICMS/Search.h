#ifndef _SEARCH_H_
#define _SEARCH_H_


#include "stdafx.h"
#include "Product.h"
#include "List_v1.h"
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class search
{
public:
	search(List_v1<Product> * db): _db(db) {}
	vector<Product>* searchByName(string);
	vector<Product>* searchByCategory(string);
	vector<Product>* searchByManufacturer(string);
	vector<Product>* searchByBarcode(string);
private:
	List_v1<Product>* _db;
	int edit_distance(string a, string b);
	int count_occurrences(string a, char b);
};

#endif
/*************************************************************************************************/
//
//  class DB_Processing
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


#include "stdafx.h"
#include "DB_Processing.h"


// Searches for the given string using the given method of search in the database
vector<Product>* DB_Processing::search(string query, int method)
{
	switch(method)
	{
		case 0: return s.searchByName(query);
		case 1: return s.searchByBarcode(query);
		case 2: return s.searchByCategory(query);
		case 3: return s.searchByManufacturer(query);
		default: return &vector<Product>();
	}
}

// returns pointer to a Product with a given barcode, from the database
Product* DB_Processing::getProduct(unsigned barcode)
{
	Product* p = NULL;
	for(unsigned i = 0; i<_db->size() && !p; i++)
		if((*_db)[i].getBarcode() == barcode)
			p = &(*_db)[i];
	return p;
}

// Adds the given Product to the database
bool DB_Processing::addProduct(Product p)
{
	Product* result = getProduct(p.getBarcode());
	if(result)
		return false;
	return _db->add(p);
}

// Deletes the given Product from the database
bool DB_Processing::delProduct(Product p)
{
	return _db->del(p);
}

// OVERLOADED DELETE: Deletes the Product in the database with the given barcode
bool DB_Processing::delProduct(unsigned barcode)
{
	Product* p = getProduct(barcode);
	if(p)
		return _db->del(*(p));
	return false;
}

// Updates the stock of a given product by the given amount
bool DB_Processing::updateStock(Product p, unsigned stock)
{
	Product* result = getProduct(p.getBarcode());
	if(!result)
		return false;
	result->updateStock(stock);
	return true;
}

// OVERLOADED STOCK: Updates the stock by the given amount of the Product with the given barcode
bool DB_Processing::updateStock(unsigned barcode, unsigned stock)
{
	Product* result = getProduct(barcode);
	if(!result)
		return false;
	result->updateStock(stock);
	return true;
}

// Updates the sale of a given product by the given amount
bool DB_Processing::updateSale(Product p, unsigned sale)
{
	Product* result = getProduct(p.getBarcode());
	if(result)
		return result->updateSale(sale);
	return false;
}

// OVERLOADED SALE: Updates the sale by the given amount of the Product with the given barcode
bool DB_Processing::updateSale(unsigned barcode, unsigned sale)
{
	Product* result = getProduct(barcode);
	if(result)
		return result->updateSale(sale);
	return false;
}

// Updates the Product in the database with the given Product (using the barcode)
bool DB_Processing::updateProduct(Product newPrd)
{
	Product* temp = getProduct(newPrd.getBarcode());
	if(temp)
	{
		*temp = newPrd;
		return true;
	}
	return false;
}

// inserts a product into the list, ensuring that its sorted
// in descending order and its size is X at max
void DB_Processing::ins_sort(list<pair<int, list<Product>>>* arr, Product p, int x)
{
	int item = p.getNoSold();
	// item is greater or equal to last element
	if(arr->back().first <= item)
	{
		//traverse till item is smaller ir equal to current element
		for(list<pair<int, list<Product>>>::iterator i = arr->begin(); i != arr->end(); i++)
			// found element smaller or equal to item
			if(i->first <= item)
			{
				// smaller element, insert a new list
				if(i->first < item)
					arr->insert(i, pair<int, list<Product>>(item, list<Product>(1, p))); 
				// equal element, add to existing list
				else if(i->first == item)
					i->second.push_back(p);
				// insertion complete, break out
				break;
			}
		// resize to X
		arr->resize(x);
	}
}

// Generates the top X Best selling Products in the database (Note: Default value = 1, i.e., the Best selling product)
vector<vector<Product>>* DB_Processing::generatePrd(int X)
{
	list<pair<int, list<Product>>> prd_list(1, pair<int, list<Product>>(-1, list<Product>()));
	
	// traverse through database to get Top X in sorted order!
	for(unsigned i = 0; i < _db->size(); i++)
		ins_sort(&prd_list, (*_db)[i], X);
	
	// copy to the format of API for GUI to handle
	vector<vector<Product>>* results = new vector<vector<Product>>();
	for(list<pair<int, list<Product>>>::iterator i = prd_list.begin(); i != prd_list.end(); i++)
	{
		results->push_back(vector<Product>());
		for(list<Product>::iterator j = i->second.begin(); j != i->second.end(); j++)
			results->back().push_back(*j);
	}
	return results;
}

// Generates the Best selling product in the given category, in the database
vector<Product>* DB_Processing::generatePrd(string cat)
{
	vector<Product>* results = new vector<Product>();
	int max_sale = -1;
	// for case-insensitive search
	cat = Search::convertToLower(cat);
	// traverse through the database
	for(unsigned i = 0; i < _db->size(); i++)
	{
		Product p = (*_db)[i];
		int temp = p.getNoSold();
		if(temp >= max_sale && Search::convertToLower(p.getCategory()) == cat)
			// new max_sale
			if(temp > max_sale)
			{
				// new max_sale found, throw away prev results
				// and start afresh
				max_sale = temp;
				delete results;
				results = new vector<Product>();
				results->push_back(p);
			}
			// same as before
			else
				// add to results
				results->push_back(p);
	}
	return results;
}

// Generates the Manufacturer from the database with the Highest sales
vector<string>* DB_Processing::generateManu()
{
	struct manufacturer
	{
		string name;
		int sales;
	};

	// get cumulative sale values of all manufacturers
	vector<manufacturer> results;
	for(unsigned i = 0; i < _db->size(); i++)
	{
		Product p = (*_db)[i];
		bool alreadyExists = false;
		for(unsigned i = 0; i < results.size() && !alreadyExists; i++)
			if(p.getManufacturer() == results[i].name)
			{
				results[i].sales += p.getNoSold();
				alreadyExists = true;
			}
		if(!alreadyExists)
		{
			manufacturer temp;
			temp.name = p.getManufacturer();
			temp.sales = p.getNoSold();
			results.push_back(temp);
		}
	}

	// sort the values to get top manufacturer
	vector<string>* top_manu = new vector<string>();
	int max_sales = -1;
	for(unsigned i = 0; i < results.size(); i++)
		if(results[i].sales > max_sales)
		{
			max_sales = results[i].sales;
			delete top_manu;
			top_manu = new vector<string>();
			top_manu->push_back(results[i].name);
		}
		else if (results[i].sales == max_sales)
			top_manu->push_back(results[i].name);
	return top_manu;
}

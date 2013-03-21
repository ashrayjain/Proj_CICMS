#include "stdafx.h"
#include <list>
#include <xutility>
#include <fstream>
#include "DB_Processing.h"


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

Product* DB_Processing::getProduct(unsigned barcode)
{
	Product* p = NULL;
	for(unsigned i = 0; i<_db->size() && !p; i++)
		if((*_db)[i].getBarcode() == barcode)
			p = &(*_db)[i];
	return p;
}

bool DB_Processing::addProduct(Product p)
{
	Product* result = getProduct(p.getBarcode());
	if(result)
		return false;
	return _db->add(p);
}

bool DB_Processing::delProduct(Product p)
{
	return _db->del(p);
}

bool DB_Processing::updateStock(Product p, int stock)
{
	Product* result = getProduct(p.getBarcode());
	if(!result)
		return false;
	result->updateStock(stock);
	return true;
}

bool DB_Processing::updateSale(Product p, unsigned sale)
{
	Product* result = getProduct(p.getBarcode());
	if(result)
		return result->updateSale(sale);
	return false;
}



void DB_Processing::ins_sort(list<pair<int, list<Product>>>* arr, Product p, int x)
{
	int item = p.getNoSold();
	if(arr->back().first <= item)
	{
		for(list<pair<int, list<Product>>>::iterator i = arr->begin(); i != arr->end(); i++)
			if(i->first <= item)
			{
				if(i->first < item)
					arr->insert(i, pair<int, list<Product>>(item, list<Product>(1, p))); 
				else if(i->first == item)
					i->second.push_back(p);
				break;
			}
		arr->resize(x);
	}
}


vector<Product>* DB_Processing::generatePrd(int X)
{
	list<pair<int, list<Product>>> prd_list(1, pair<int, list<Product>>(-1, list<Product>()));
	
	for(unsigned i = 0; i < _db->size(); i++)
		ins_sort(&prd_list, (*_db)[i], X);
	
	vector<Product>* results = new vector<Product>();
	for(list<pair<int, list<Product>>>::iterator i = prd_list.begin(); i != prd_list.end(); i++)
		for(list<Product>::iterator j = i->second.begin(); j != i->second.end(); j++)
			results->push_back(*j);
	return results;
}


vector<Product>* DB_Processing::generatePrd(string cat)
{
	vector<Product>* results = new vector<Product>();
	vector<int>* result_idx = new vector<int>();
	int max_sale = -1;
	for(unsigned i = 0; i < _db->size(); i++)
	{
		Product p = (*_db)[i];
		if(p.getCategory() == cat)
		{
			int temp = p.getNoSold();
			if(temp > max_sale)
			{
				max_sale = temp;
				delete result_idx;
				result_idx = new vector<int>();
				result_idx->push_back(i);
			}
			else if(temp == max_sale)
				result_idx->push_back(i);
		}
	}
	for(unsigned i = 0; i < result_idx->size(); i++)
		results->push_back((*_db)[(*result_idx)[i]]);
	delete result_idx;
	return results;
}


vector<string>* DB_Processing::generateManu()
{
	struct manufacturer
	{
		string name;
		int sales;
	};
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
#include "stdafx.h"
#include <list>
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


/*
bool DB_Processing::ins_sort(list<int>* arr, unsigned item, int x)
{
	if(arr->back() >= item)
		return false;
	else
		for(list<int>::iterator i = arr->begin(); i != arr->end(); i++)
			if(*i < item)
			{
				arr->insert(i, item); 
				arr->remove(*i);
			}


vector<Product>* DB_Processing::generatePrd(int X = 1)
{
	list<list<Product>> prd_list;
	list<int> top_sales(1, -1);
	for(unsigned i = 0; i < _db->size(); i++)
	{
		Product p = (*_db)[i];
		if(top_sales.size() < X)
		{

			if(p.getNoSold() > max_sale)
			{
				max_sale = temp;
				result_idx.add(i);
			}
			else if(temp == max_sale)
				result_idx.add(i);
		}
	}
	for(unsigned i = 0; i < result_idx->size(); i++)
		results.add((*_db)[i]);
	delete result_idx;
	return results;
}
*/

vector<Product>* DB_Processing::generatePrd(string cat)
{
	vector<Product>* results = new vector<Product>();
	vector<int>* result_idx = NULL;
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
		else if (results[i].sales > max_sales)
			top_manu->push_back(results[i].name);
	return top_manu;
}
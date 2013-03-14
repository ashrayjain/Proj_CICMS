#include "stdafx.h"
#include "DB_Processing.h"

List_v1<Product>* DB_Processing::searchByName(string query)
{
	List_v1<Product>* results = new List_v1<Product>();
	for(unsigned i = 0; i < _db->size(); i++)
		if((*_db)[i].getName()==query)
			results->add((*_db)[i]);
	return results;
}

List_v1<Product>* DB_Processing::searchByCategory(string query)
{
	List_v1<Product>* results = new List_v1<Product>();
	for(unsigned i = 0; i < _db->size(); i++)
		if((*_db)[i].getCategory()==query)
			results->add((*_db)[i]);
	return results;
}

List_v1<Product>* DB_Processing::searchByManufacturer(string query)
{
	List_v1<Product>* results = new List_v1<Product>();
	for(unsigned i = 0; i < _db->size(); i++)
		if((*_db)[i].getManufacturer()==query)
			results->add((*_db)[i]);
	return results;
}

List_v1<Product*>* DB_Processing::searchByBarcode(string query)
{
	List_v1<Product*>* results = new List_v1<Product*>();
	for(unsigned i = 0; i < _db->size(); i++)
		if(to_string((*_db)[i].getBarcode())==query)
			results->add(&(*_db)[i]);
	return results;
}

List_v1<Product>* DB_Processing::search(string query, int method)
{
	List_v1<Product*>* results_p = NULL;
	List_v1<Product>* results = NULL;
	switch(method)
	{
		case 0: return searchByName(query);
		case 1: 
			 results = new List_v1<Product>();
			results_p = searchByBarcode(query);
			for(unsigned i = 0; i < results_p->size(); i++)
				results->add(*(*results_p)[i]);
			return results;
		case 2: return searchByCategory(query);
		case 3: return searchByManufacturer(query);
		default: return &List_v1<Product>();
	}

}

bool DB_Processing::addProduct(Product p)
{
	List_v1<Product*>* results = searchByBarcode(to_string(p.getBarcode()));
	if(results->isEmpty())
	{
		delete results;
		return _db->add(p);
	}
	else
	{
		delete results;
		return false;
	}
}

bool DB_Processing::delProduct(Product p)
{
	return _db->del(p);
}

bool DB_Processing::updateStock(Product p, int stock)
{
	List_v1<Product*>* results = searchByBarcode(to_string(p.getBarcode()));
	if(results->size() != 1)
		return false;
	else
		(*results)[0]->updateStock(stock);
	return true;
}

bool DB_Processing::updateSale(Product p, unsigned sale)
{
	List_v1<Product*>* results = searchByBarcode(to_string(p.getBarcode()));
	if(results->size() == 1)
		return (*results)[0]->updateSale(sale);
	return false;
}

List_v1<Product> DB_Processing::generateStats(int method)
{
	return List_v1<Product>();
}
#include "stdafx.h"
#include "DB_Processing.h"

int DB_Processing::count_occurences(string a, char b)
{
	int count = 0;
	for(unsigned i=0; i<a.size(); i++)
		if(a[i]==b)
			count++;
	return count;
}
int DB_Processing::edit_distance(string a, string b)
{ 
	
	string replace = "r", ins = "i", del = "d";
	int l1 = a.size(), l2 = b.size();

	// make L1 greater
    if(l1 < l2)
	{
		int temp = l1;
		l1 = l2;
		l2 = temp;
		string temp_s = a;
		a = b;
		b = temp_s;
	}

	vector<string> models;
    if(l1 - l2 == 0)
	{
		models.push_back(ins+del);
		models.push_back(del+ins);
		models.push_back(replace+replace);
	}
	else if(l1 - l2 == 1)
	{
		models.push_back(del+replace);
		models.push_back(replace+del);
	}
	else if(l1 - l2 == 2)
		models.push_back(del+del);
	else
	{
		istringstream iss(b);
		string word;
		while(iss>>word)
		{
			int temp = a.find(word);
			if(temp!=-1)
			{
				if(a.find(b)==-1)
					return 3;
				else
					return 4;
			}	
		}
		return -1;
	}

    int res = 3;
    for(unsigned z = 0; z < models.size(); z++)
	{
		int i, j, c = 0;
		i = j = c;
		while ((i < l1) && (j < l2))
		{
			if(a[i] != b[j])
			{
				c = c+1;
                if(2 < c)
                    break;
                char cmd = models[z][c-1];
                if(cmd == del[0])
                    i = i+1;
				else if(cmd == ins[0])
                    j = j+1;
                else
				{
                    i++;
					j++;
				}
			}
            else
			{
				i++;
				j++;
			}
		}
        if(2 < c)
			continue;
		else if(i < l1)
        {
			if(l1-i <= count_occurences(models[z].substr(c, models[z].size()), del[0]))
                c = c + (l1-i);
            else
                continue;
		}
        else if(j < l2)
		{
            if(l2-j <= count_occurences(models[z].substr(c, models[z].size()), ins[0]))
                c = c + (l2-j);
            else
                continue;
		}
        if(c < res)
            res = c;
	}
    if(res == 3)
        res = -1;
	if(res==2)
		res = -1;
    return res;
}
List_v1<Product>* DB_Processing::searchByName(string query)
{
	List_v1<Product>* results = new List_v1<Product>();
	for(unsigned i = 0; i < _db->size(); i++)
		if(edit_distance((*_db)[i].getName(),query) != -1)
			results->add((*_db)[i]);
	return results;
}

List_v1<Product>* DB_Processing::searchByCategory(string query)
{
	List_v1<Product>* results = new List_v1<Product>();
	for(unsigned i = 0; i < _db->size(); i++)
		if(edit_distance((*_db)[i].getCategory(),query) != -1)
			results->add((*_db)[i]);
	return results;
}

List_v1<Product>* DB_Processing::searchByManufacturer(string query)
{
	List_v1<Product>* results = new List_v1<Product>();
	for(unsigned i = 0; i < _db->size(); i++)
		if(edit_distance((*_db)[i].getManufacturer(),query) != -1)
			results->add((*_db)[i]);
	return results;
}

List_v1<Product*>* DB_Processing::searchByBarcode(string query)
{
	List_v1<Product*>* results = new List_v1<Product*>();
	for(unsigned i = 0; i < _db->size(); i++)
		if(edit_distance(to_string((*_db)[i].getBarcode()),query) != -1)
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
			delete results_p;
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
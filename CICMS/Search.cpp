#include "stdafx.h"
#include "Search.h"

int search::count_occurrences(string a, char b)
{
	int count = 0;
	for(unsigned i=0; i<a.size(); i++)
		if(a[i]==b)
			count++;
	return count;
}
int search::edit_distance(string a, string b)
{ 
	
	string replace = "r", ins = "i", del = "d";

	// make L1 greater
    if(a.size() < b.size())
	{
		string temp_s = a;
		a = b;
		b = temp_s;
	}
	int l1 = a.size(), l2 = b.size();

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
		int i, j, c;
		i = j = c = 0;
		for(; (i < l1) && (j < l2); i++, j++)
		{
			if(a[i] != b[j])
			{
				c = c+1;
                if(2 < c)
                    break;
                char cmd = models[z][c-1];
                if(cmd == del[0])
                    j--;
				else if(cmd == ins[0])
                    i--;
			}
		}

        if(2 < c)
			continue;
		else if(i < l1)
        {
			if(l1-i <= count_occurrences(models[z].substr(c, models[z].size()), del[0]))
                c = c + (l1-i);
            else
                continue;
		}
        else if(j < l2)
		{
            if(l2-j <= count_occurrences(models[z].substr(c, models[z].size()), ins[0]))
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
vector<Product>* search::searchByName(string query)
{
	vector<Product>* results = new vector<Product>();
	for(unsigned i = 0; i < _db->size(); i++)
		if(edit_distance((*_db)[i].getName(),query) != -1)
			results->push_back((*_db)[i]);
	return results;
}

vector<Product>* search::searchByCategory(string query)
{
	vector<Product>* results = new vector<Product>();
	for(unsigned i = 0; i < _db->size(); i++)
		if(edit_distance((*_db)[i].getCategory(),query) != -1)
			results->push_back((*_db)[i]);
	return results;
}


vector<Product>* search::searchByManufacturer(string query)
{
	vector<Product>* results = new vector<Product>();
	for(unsigned i = 0; i < _db->size(); i++)
		if(edit_distance((*_db)[i].getManufacturer(),query) != -1)
			results->push_back((*_db)[i]);
	return results;
}

vector<Product>* search::searchByBarcode(string query)
{
	vector<Product>* results = new vector<Product>();
	for(unsigned i = 0; i < _db->size(); i++)
		if(edit_distance(to_string((*_db)[i].getBarcode()),query) != -1)
			results->push_back((*_db)[i]);
	return results;
}

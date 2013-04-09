/******************************************************************************************************/
//
//  class search
//
//  Description: The search class implements all the search related features, like searching products
//  from the database with respect to their name, barcode, category or manufacturer.
//
//  API:
//  Search(list_adt<Product> * db);
//	vector<Product>* searchByName(string);
//	vector<Product>* searchByCategory(string);
//	vector<Product>* searchByManufacturer(string);
//	vector<Product>* searchByBarcode(string);
//
//  Main authors: ASHRAY JAIN (A0105199B)
//
/******************************************************************************************************/

#include "stdafx.h"
#include "Search.h"

string Search::convertToLower(string s)
{
	for(unsigned int i = 0; i < s.length(); ++i) 
		s[i] = tolower(s[i]);
	return s;
}

int Search::substring_search(string name, string query)
{
	istringstream iss(query);
	string word;
	int count = 0;
	while(iss>>word)
		if(word.size() >= 2 && name.find(word)!=-1)
			count++;
	return count;
}
int Search::countOccurrences(string a, char b)
{
	int count = 0;
	for(unsigned i=0; i<a.size(); i++)
		if(a[i]==b)
			count++;
	return count;
}

int Search::Min(int a, int b)
{
	return a>b?b:a;
}

int Search::Max(int a, int b)
{
	return a>b?a:b;
}

int Search::editDistance(string a, string b, int k)
{
	//Wagner-Fischer Algorithm with memory and complexity optimizations

	int l1 = a.length(), l2 = b.length();
	if(l1 > l2)
	{
		string temp = a;
		a = b;
		b = temp;
		l1 = l2;
		l2 = b.length();
	}

	int* curr = new int[l1+1];
	int* prev = new int[l1+1];

	int boundary = Min(k, l1);
	for(int i = 0; i<=boundary; i++)
		prev[i] = i;
	for(int i = boundary+1; i<=l1; i++)
		prev[i] = 999;
	for(int i = 0; i<=l1; i++)
		curr[i] = 999;
	
	for(int i = 1; i<=l2; i++)
	{
		curr[0] = i;
		
		int min_idx, max_idx;
		min_idx = Max(1, i-k);
		max_idx = Min(l1, i+k);
		
		if(min_idx > max_idx)
		{
			delete [] curr;
			delete [] prev;
			return -1;
		}
		if(min_idx != 1)
			curr[min_idx-1] = 99;
		
		for(int j = min_idx; j <= max_idx; j++)
			if(a[j-1]==b[i-1])
				curr[j] = prev[j-1];
			else
				curr[j] = 1 + Min(Min(prev[j], curr[j-1]), prev[j-1]);

		int* temp = prev;
		prev = curr;
		curr = temp;
	}
	int ret_val = prev[l1];
	delete [] curr;
	delete [] prev;
	return (ret_val <= k)?ret_val:-1;
 }


void Search::getConsolidatedResults(vector<Product>* &results, 
	vector<Product> &close_results,
	vector<vector<Product>> &substring_matches,
	vector<vector<Product>> &edit_distance_matches, int count)
{
	results->insert(results->end(), close_results.begin(), close_results.end());
	for(int j =  substring_matches.size()-1; j >= 0 ; j--)
		results->insert(results->end(), substring_matches[j].begin(), substring_matches[j].end());
	for(unsigned i = 0; i < edit_distance_matches.size(); i++)
		results->insert(results->end(), edit_distance_matches[i].begin(), edit_distance_matches[i].end());
}


void Search::smartSearch(Product p, string str_p, string _query, vector<Product>* &results, 
	vector<Product> &close_results, vector<vector<Product>> &substring_matches,
	vector<vector<Product>> &edit_distance_matches, int threshold)
{

	if(str_p.find(_query) == 0)
	{
		if(str_p.size() == _query.size())
			results->push_back(p);
		else
			close_results.push_back(p);
	}
	else
	{
		int temp = substring_search(str_p, _query)-1;
		if(temp != -1)
			substring_matches[temp].push_back(p);
		else
		{
			temp = editDistance(str_p, _query, threshold)-1;
			if(temp>=0)
				edit_distance_matches[temp].push_back(p);
		}
	}
}
vector<Product>* Search::searchByName(string query)
{
	vector<Product>* results = new vector<Product>();
	string _query = convertToLower(query);
	istringstream iss(query);
	string word;
	int count = 0;
	while(iss>>word)
		count++;

	vector<vector<Product>> substring_matches(count, vector<Product>()), edit_distance_matches(2, vector<Product>());
	vector<Product> close_results;
	

	for(unsigned i = 0; i < _db->size(); i++)
	{
		string name = convertToLower((*_db)[i].getName());
		smartSearch((*_db)[i], name, _query, results, close_results, substring_matches, edit_distance_matches, 2);
	}

	getConsolidatedResults(results, close_results, substring_matches, edit_distance_matches, count);
	return results;
}

vector<Product>* Search::searchByCategory(string query)
{
	vector<Product>* results = new vector<Product>();
	string _query = convertToLower(query);
	istringstream iss(query);
	string word;
	int count = 0;
	while(iss>>word)
		count++;
	
	vector<vector<Product>> substring_matches(count, vector<Product>()), edit_distance_matches(2, vector<Product>());
	vector<Product> close_results;
	

	for(unsigned i = 0; i < _db->size(); i++)
	{
		string cat = convertToLower((*_db)[i].getCategory());
		smartSearch((*_db)[i], cat, _query, results, close_results, substring_matches, edit_distance_matches, 2);
	}
	getConsolidatedResults(results, close_results, substring_matches, edit_distance_matches, count);
	return results;
}


vector<Product>* Search::searchByManufacturer(string query)
{
	vector<Product>* results = new vector<Product>();
	string _query = convertToLower(query);
	istringstream iss(query);
	string word;
	int count = 0;
	while(iss>>word)
		count++;
	
	vector<vector<Product>> substring_matches(count, vector<Product>()), edit_distance_matches(2, vector<Product>());
	vector<Product> close_results;
	

	for(unsigned i = 0; i < _db->size(); i++)
	{
		string manu = convertToLower((*_db)[i].getManufacturer());
		smartSearch((*_db)[i], manu, _query, results, close_results, substring_matches, edit_distance_matches, 2);
	}
	getConsolidatedResults(results, close_results, substring_matches, edit_distance_matches, count);
	return results;
}

vector<Product>* Search::searchByBarcode(string query)
{
	vector<Product>* results = new vector<Product>();
	string _query = convertToLower(query);
	istringstream iss(query);
	string word;
	int count = 0;
	while(iss>>word)
		count++;
	
	vector<vector<Product>> substring_matches(count, vector<Product>()), edit_distance_matches(1, vector<Product>());
	vector<Product> close_results;

	for(unsigned i = 0; i < _db->size(); i++)
	{
		string barcode = convertToLower(to_string((*_db)[i].getBarcode()));
		smartSearch((*_db)[i], barcode, _query, results, close_results, substring_matches, edit_distance_matches, 1);
	}
	getConsolidatedResults(results, close_results, substring_matches, edit_distance_matches, count);
	return results;
}

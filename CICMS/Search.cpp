/******************************************************************************************************/
//
//  class Search: Search.cpp
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

#include "stdafx.h"
#include "Search.h"

// Static function to convert given string to lowercase
string Search::convertToLower(string s)
{
	for(unsigned int i = 0; i < s.length(); ++i) 
		s[i] = tolower(s[i]);
	return s;
}

// Get the number of occurrences of each part of the query in the given string
int Search::substring_search(string name, string query)
{
	istringstream iss(query);
	string word;
	int count = 0;
	// break up the query into words
	while(iss>>word)
		if(word.size() >= 2 && name.find(word)!=-1)
			count++;
	return count;
}

// Return lesser element
int Search::Min(int a, int b)
{
	return a>b?b:a;
}

// Return greater element
int Search::Max(int a, int b)
{
	return a>b?a:b;
}

// Get closeness of one string to another (i.e. the edit distance)
int Search::editDistance(string a, string b, int k)
{
	// Utilizing Wagner-Fischer Algorithm
	// memory and complexity optimizations to suit our
	// application

	int l1 = a.length(), l2 = b.length();
	if(abs(l1-l2) > k)
		return -1;
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
			curr[min_idx-1] = 999;
		
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

// Consolidate the different types of results into one
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

// Search for given string in the database and get results of different accuracy levels
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


// NOTE: For all searchBy.. functions, type of results in
// decreasing order of accuracy are,
// results				  --> 	exact matches
// close_results		  -->	start matches
// substring_matches	  -->	part of query matches
// edit_distance_matches  -->	matches after considering error in typing

// Search for the string in the database using Product names
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

// Search for the string in the database using Product categories
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

// Search for the string in the database using Product manufacturers
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

// Search for the string in the database using Product barcodes
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

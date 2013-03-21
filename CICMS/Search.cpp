#include "stdafx.h"
#include "Search.h"

string search::convertToLower(string s)
{
	for(unsigned int i = 0; i < s.length(); ++i) 
		s[i] = tolower(s[i]);
	return s;
}

int search::substring_search(string name, string query)
{
	istringstream iss(query);
	string word;
	int count = 0;
	while(iss>>word)
		if(word.size() > 2 && name.find(word)!=-1)
			count++;
	return count;
}
int search::countOccurrences(string a, char b)
{
	int count = 0;
	for(unsigned i=0; i<a.size(); i++)
		if(a[i]==b)
			count++;
	return count;
}

int search::min(int a, int b)
{
	return a>b?b:a;
}

int search::max(int a, int b)
{
	return a>b?a:b;
}

int search::editDistance(string a, string b, int k)
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

	int boundary = min(k, l1);
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
		min_idx = max(1, i-k);
		max_idx = min(l1, i+k);
		
		if(min_idx > max_idx)
			return -1;
		
		if(min_idx != 1)
			curr[min_idx-1] = 99;
		
		for(int j = min_idx; j <= max_idx; j++)
			if(a[j-1]==b[i-1])
				curr[j] = prev[j-1];
			else
				curr[j] = 1 + min(min(prev[j], curr[j-1]), prev[j-1]);

		int* temp = prev;
		prev = curr;
		curr = temp;
	}
	int ret_val = prev[l1];
	delete [] curr;
	delete [] prev;
	return (ret_val <= k)?ret_val:-1;
 }


void search::getFilteredResults(vector<Product>* results, 
	vector<Product> &close_results,
	vector<vector<Product>> &substring_matches,
	vector<Product> &edit_distance_matches, int count)
{
	results->insert(results->end(), close_results.begin(), close_results.end());
	if(!results->size())
	{
		int counter = 0;
		for(int i = count-1 ; i >= 0 && counter < 30; i--)
		{
			unsigned temp = substring_matches[i].size();
			for(unsigned j = 0; j < temp; j++)
			{
				results->push_back(substring_matches[i][j]);
				counter++;
			}
		}
		if(!counter)
			results->insert(results->end(), edit_distance_matches.begin(), edit_distance_matches.end());
	}
}


void search::smartSearch(Product p, string str_p, string _query, vector<Product>* results, 
	vector<Product> &close_results, vector<vector<Product>> &substring_matches,
	vector<Product> &edit_distance_matches, bool &edit_req, int threshold)
{

	if(str_p.find(_query) == 0)
	{
		if(str_p.size() == _query.size())
			results->push_back(p);
		else
			close_results.push_back(p);
	}
	else if(substring_matches.back().size() < 30)
	{
		int temp = substring_search(str_p, _query)-1;
		if(temp != -1)
		{
			substring_matches[temp].push_back(p);
			edit_req = false;
		}
		if(edit_req && editDistance(str_p, _query, threshold) != -1)
			edit_distance_matches.push_back(p);
	}
}
vector<Product>* search::searchByName(string query)
{
	vector<Product>* results = new vector<Product>();
	string _query = convertToLower(query);
	istringstream iss(query);
	string word;
	int count = 0;
	while(iss>>word)
		count++;

	vector<vector<Product>> substring_matches(count, vector<Product>());
	vector<Product> close_results;
	vector<Product> edit_distance_matches;
	bool edit_req = true;

	for(unsigned i = 0; i < _db->size(); i++)
	{
		string name = convertToLower((*_db)[i].getName());
		smartSearch((*_db)[i], name, _query, results, close_results, substring_matches, edit_distance_matches, edit_req, 2);
	}

	getFilteredResults(results, close_results, substring_matches, edit_distance_matches, count);
	return results;
}

vector<Product>* search::searchByCategory(string query)
{
	vector<Product>* results = new vector<Product>();
	string _query = convertToLower(query);
	istringstream iss(query);
	string word;
	int count = 0;
	while(iss>>word)
		count++;
	
	vector<vector<Product>> substring_matches(count, vector<Product>());
	vector<Product> close_results;
	vector<Product> edit_distance_matches;
	bool edit_req = true;

	for(unsigned i = 0; i < _db->size(); i++)
	{
		string cat = convertToLower((*_db)[i].getCategory());
		smartSearch((*_db)[i], cat, _query, results, close_results, substring_matches, edit_distance_matches, edit_req, 2);
	}
	getFilteredResults(results, close_results, substring_matches, edit_distance_matches, count);
	return results;
}


vector<Product>* search::searchByManufacturer(string query)
{
	vector<Product>* results = new vector<Product>();
	string _query = convertToLower(query);
	istringstream iss(query);
	string word;
	int count = 0;
	while(iss>>word)
		count++;
	
	vector<vector<Product>> substring_matches(count, vector<Product>());
	vector<Product> close_results;
	vector<Product> edit_distance_matches;
	bool edit_req = true;

	for(unsigned i = 0; i < _db->size(); i++)
	{
		string manu = convertToLower((*_db)[i].getManufacturer());
		smartSearch((*_db)[i], manu, _query, results, close_results, substring_matches, edit_distance_matches, edit_req, 2);
	}
	getFilteredResults(results, close_results, substring_matches, edit_distance_matches, count);
	return results;
}

vector<Product>* search::searchByBarcode(string query)
{
	vector<Product>* results = new vector<Product>();
	string _query = convertToLower(query);
	istringstream iss(query);
	string word;
	int count = 0;
	while(iss>>word)
		count++;
	
	vector<vector<Product>> substring_matches(count, vector<Product>());
	vector<Product> close_results;
	vector<Product> edit_distance_matches;
	bool edit_req = true;

	for(unsigned i = 0; i < _db->size(); i++)
	{
		string barcode = convertToLower(to_string((*_db)[i].getBarcode()));
		smartSearch((*_db)[i], barcode, _query, results, close_results, substring_matches, edit_distance_matches, edit_req, 3);
	}
	getFilteredResults(results, close_results, substring_matches, edit_distance_matches, count);
	return results;
}

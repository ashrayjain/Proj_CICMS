/******************************************************************************************************/
//
//  class Processing
//
//  Description: Processing is an entry point into the logic component of CICMS. It provided access to 
//  both, File_Processing features and DB_Processing features through objects of the respective types.
//  Although, the File_Processing features are handled automatically in the current version of CICMS.
//
//  API:
//  Processing();
//	~Processing();
//	inline int size() { return _database.size(); }
//  inline bool Processing::addProduct(Product t);
//  inline bool Processing::delProduct(Product t);
//  inline vector<Product>* Processing::search(string s, int i);
//  inline bool Processing::updateStock(Product t, int i);
//  inline bool Processing::updateSale(Product t, unsigned i);
//  inline vector<Product>* Processing::generatePrd(int X);
//  inline vector<Product>* Processing::generatePrd(string s);
//  inline vector<string>* Processing::generateManu();
//
//  Main authors: ASHRAY JAIN (A0105199B)
//
/******************************************************************************************************/

#include "stdafx.h"
#include "Processing.h"
#include <fstream>
#include <time.h>

Processing::Processing()
{
	file = new File_processing(_database, "product.txt", "$temp.cicms", "log.txt");
	db = new DB_Processing(_database);
	file->load(_database); 
}

Processing::~Processing()
{
	file->save(_database);
	delete file;
	delete db;
}

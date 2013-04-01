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
//  inline bool Processing::addProduct(Product t);
//  inline bool Processing::delProduct(Product t);
//  inline vector<Product>* Processing::search(string s, int i);
//  inline bool Processing::updateStock(Product t, int i);
//  inline bool Processing::updateSale(Product t, unsigned i);
//  inline vector<Product>* Processing::generatePrd(int X);
//  inline vector<Product>* Processing::generatePrd(string s);
//  inline vector<string>* Processing::generateManu();
//	inline int size() { return _database.size(); }
//
//  Main authors: ASHRAY JAIN (A0105199B)
//
/******************************************************************************************************/


#ifndef _PROCESSING_H_
#define _PROCESSING_H_

#include "List_v1.h"
//#include "List_v2.h"
//#include "List_v1.h"
#include "File_processing.h"
#include "DB_Processing.h"


class Processing
{
private:
	list_adt<Product> _database;
	File_processing *file;
	DB_Processing *db;

public:
	Processing();
	~Processing();
	inline bool Processing::addProduct(Product t) { return db->addProduct(t); }
	inline bool Processing::delProduct(Product t) { return db->delProduct(t); }
	inline vector<Product>* Processing::search(string s, int i) { return db->search(s, i); }
	inline bool Processing::updateStock(Product t, int i) { return db->updateStock(t, i); }
	inline bool Processing::updateSale(Product t, unsigned i) { return db->updateSale(t, i); }
	inline vector<Product>* Processing::generatePrd(int X) { return db->generatePrd(X); }
	inline vector<Product>* Processing::generatePrd(string s) { return db->generatePrd(s); }
	inline vector<string>* Processing::generateManu() { return db->generateManu(); }
	inline int size() { return _database.size(); }
};

#endif
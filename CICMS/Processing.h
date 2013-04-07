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
//  bool Processing::addProduct(Product t);
//  bool Processing::delProduct(Product t);
//  vector<Product>* Processing::search(string s, int i);
//  bool Processing::updateStock(Product t, int i);
//  bool Processing::updateSale(Product t, unsigned i);
//  vector<Product>* Processing::generatePrd(int X);
//  vector<Product>* Processing::generatePrd(string s);
//  vector<string>* Processing::generateManu();
//	int size() { return _database.size(); }
//
//  Main authors: ASHRAY JAIN (A0105199B)
//
/******************************************************************************************************/


#ifndef _PROCESSING_H_
#define _PROCESSING_H_

#include "List_v1.h"
//#include "List_v2.h"
//#include "List_v3.h"

#include "File_processing.h"
#include "DB_Processing.h"
#include "batch_processing.h"

class Processing
{
private:
	list_adt<Product> _database;
	File_processing *file;
	DB_Processing *db;
	batch_processing *bp;
	bool changed;

public:
	Processing();
	~Processing();
	void clearDatabase();
	bool isSaved();
	bool isEmptyFilename();
	bool writeTemp(Product, string);
	bool writeTemp(Product, string, int);
	bool loadFile(string);
	bool saveFile();
	bool saveFileAs(string);
	bool chkTmpFile();
	void recover(bool);
	int size();
	bool addProduct(Product);
	bool delProduct(Product);
	vector<Product>* search(string, int);
	bool updatePrd(Product);
	bool updateStock(Product, unsigned);
	bool updateSale(Product, unsigned);
	int batchProcessing(string);
	vector<Product>* generatePrd(int);
	vector<Product>* generatePrd(string);
	vector<string>* generateManu();
};
#endif
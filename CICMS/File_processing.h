/******************************************************************************************************/
//
//  class File_Processing
//
//  Description: File_Proceesing implements features related to data persistence, like loading products
//  from a text file into the database and saving the current state of the database into a text file.
//
//  API:
//  File_processing(list_adt<Product>& db);
//  bool load();
//	bool save();
//
//  Main authors: ASHRAY (A0105199B)
//
/******************************************************************************************************/

#ifndef _FILE_PROCESSING_H_
#define _FILE_PROCESSING_H_

#include "Product.h"
#include "List_v3.h"
#include <fstream>
#include <string>

using namespace std;

class File_processing
{
private:
	string filename;
	list_adt<Product>* _db;
public:
	File_processing(list_adt<Product>& db) : filename("product.txt") { _db = &db; }
	bool load();
	bool save();
};

#endif
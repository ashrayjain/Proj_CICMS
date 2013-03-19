#ifndef _FILE_PROCESSING_H_
#define _FILE_PROCESSING_H_

#include "Product.h"
#include "List_v1.h"
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
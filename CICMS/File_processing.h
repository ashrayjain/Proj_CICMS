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
	List_v1<Product>* _db;
public:
	File_processing(List_v1<Product>& db) : filename("product.txt") { _db = &db; }
	bool load();
	bool save();
};

#endif
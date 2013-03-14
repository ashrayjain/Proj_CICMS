#ifndef _PROCESSING_H_
#define _PROCESSING_H_

#include "List_v1.h"
#include "File_processing.h"
#include "DB_Processing.h"


class Processing
{
private:
	List_v1<Product> _database;
public:
	Processing();
	~Processing();
	inline int size() { return _database.size(); }
	File_processing *file;
	DB_Processing *db;
};

#endif
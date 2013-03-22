#ifndef _PROCESSING_H_
#define _PROCESSING_H_

#include "List_v3.h"
#include "File_processing.h"
#include "DB_Processing.h"


class Processing
{
private:
	list_adt<Product> _database;
	File_processing *file;
public:
	Processing();
	~Processing();
	DB_Processing *db;
	inline int size() { return _database.size(); }
};

#endif
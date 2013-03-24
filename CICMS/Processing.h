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
//	DB_Processing *db;
//	inline int size() { return _database.size(); }
//
//  Main authors: ASHRAY (A0105199B)
//
/******************************************************************************************************/


#ifndef _PROCESSING_H_
#define _PROCESSING_H_

//#include "List_v1.h"
//#include "List_v2.h"
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
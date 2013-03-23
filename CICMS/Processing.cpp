******************************************************************************************************/
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

#include "stdafx.h"
#include "Processing.h"

Processing::Processing()
{
	file = new File_processing(_database);
	db = new DB_Processing(_database);
	file->load(); 
}

Processing::~Processing()
{
	file->save();
	delete file;
	delete db;
}
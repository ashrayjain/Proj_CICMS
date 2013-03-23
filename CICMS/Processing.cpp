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
#include <ctime> // to use C library function clock()


Processing::Processing()
{
	file = new File_processing(_database);
	db = new DB_Processing(_database);
	ofstream fout("log.txt", ios::app);
	int start, end;
	start = clock(); // record starting time

	file->load(); 

	end = clock(); // record ending time
	fout << "Elapsed time:" << (end-start) << " ms" << endl;
	fout.close();

}

Processing::~Processing()
{
	file->save();
	delete file;
	delete db;
}
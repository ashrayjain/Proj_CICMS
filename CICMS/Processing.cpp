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
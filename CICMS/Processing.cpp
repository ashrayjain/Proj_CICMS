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
//	int size() { return _database.size(); }
//  bool Processing::addProduct(Product t);
//  bool Processing::delProduct(Product t);
//  vector<Product>* Processing::search(string s, int i);
//  bool Processing::updateStock(Product t, int i);
//  bool Processing::updateSale(Product t, unsigned i);
//  vector<Product>* Processing::generatePrd(int X);
//  vector<Product>* Processing::generatePrd(string s);
//  vector<string>* Processing::generateManu();
//
//  Main authors: ASHRAY JAIN (A0105199B)
//
/******************************************************************************************************/

#include "stdafx.h"
#include "Processing.h"
#include <fstream>
#include <time.h>

Processing::Processing():changed(false), file(NULL), bp(NULL) { db = new DB_Processing(_database); }
Processing::~Processing() { delete file;delete db; }

void Processing::clearDatabase()
{
	while(!_database.isempty())
		_database.del(_database[_database.size()-1]);
}

bool Processing::loadFile(string filename)
{
	clearDatabase();
	if(file)
		delete file;
	file = new File_processing(filename, _database);
	changed = false;
	return file->loadPrds();
}

void Processing::newFile()
{
	delete file;
	file = NULL;
	clearDatabase();
}

bool Processing::saveFileAs(string filename)
{
	if(file)
		delete file;
	file = new File_processing(filename, _database);
	if(file->savePrds()){ changed = false; return true; }
	return false;
}

bool Processing::saveFile()
{
	if(file->savePrds()){ changed = false; return true; }
	return false;
}

void Processing::recover(bool tof)
{
	if(tof)
		batchProcessing(file->recoveryAddress());
	file->initializeTemp();
}

int Processing::batchProcessing(string filename)
{
	bp = new batch_processing(db);
	int temp =  bp->bp_execute(filename);
	delete bp;
	bp = NULL;
	changed = true;
	return temp;
}

bool Processing::writeTemp(Product t,string func)	{ return (!file)?true:file->writeTemp(t, func); }
bool Processing::writeTemp(Product t,string f,int i){ return (!file)?true:file->writeTemp(t, f, i); }
bool Processing::chkTmpFile()						{ return file->tempExists(); }
bool Processing::addProduct(Product t)				{ changed = true; return db->addProduct(t) && writeTemp(t, "ADD"); }
bool Processing::delProduct(Product t)				{ changed = true; return db->delProduct(t) && writeTemp(t, "DELETE"); }
vector<Product>* Processing::search(string s, int i){ return db->search(s, i); }
bool Processing::updatePrd(Product t)				{ return db->updateProduct(t) && writeTemp(t, "DELETE") && writeTemp(t, "ADD"); }
bool Processing::updateStock(Product t, unsigned i)	{ changed = true; return db->updateStock(t, i) && writeTemp(t, "RESTOCK", i); }
bool Processing::updateSale(Product t, unsigned i)	{ changed = true; return db->updateSale(t, i) && writeTemp(t, "SALE", i); }
vector<Product>* Processing::generatePrd(int X)		{ return db->generatePrd(X); }
vector<Product>* Processing::generatePrd(string s)	{ return db->generatePrd(s); }
vector<string>* Processing::generateManu()			{ return db->generateManu(); }
int Processing::size()								{ return _database.size(); }
bool Processing::isSaved()							{ return !changed; }
bool Processing::isEmptyFilename()					{ return (file)?false:true; }
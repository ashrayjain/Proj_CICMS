/******************************************************************************************************/
//
//  class Processing: Processing.cpp
//
//  Description: Processing is an entry point into the logic component of CICMS. It provided access to 
//  both, File_Processing features and DB_Processing features through objects of the respective types.
//  Although, the File_Processing features are handled automatically in the current version of CICMS.
//
//  API:
//  *** Default Constructor that creates a new Database of Products ***
//  Processing();
//  
//  *** Default Destructor ***
//	~Processing();
//  
//  *** Returns whether the current state of the database is saved ***
//	bool isSaved();
//  
//  *** Returns whether a filename and address has been assigned for the database ***
//	bool isEmptyFilename();
//  
//  *** Write temporary file ***
//	bool writeTemp(Product, string, int i = 0);
//  
//  *** Load product file into database at the given address ***
//	bool loadFile(string);
//  
//  *** Save the database into the file ***
//	bool saveFile();
//  
//  *** Save the database into a new file at the given address ***
//	bool saveFileAs(string);
//  
//  *** Create a new empty database ***
//	void newFile();
//  
//  *** Returns whether recovery is needed ***
//	bool chkTmpFile();
//  
//  *** Initialize the temporary file and recover if parameter is true ***
//	void recover(bool);
//  
//  *** Returns the size of the database ***
//	int size();
//  
//  *** Add the given Product to the database ***
//	bool addProduct(Product);
//  
//  *** Delete the given Product to the database ***
//	bool delProduct(Product);
//  
//  *** Search for the given string in the database using the given method ***
//	vector<Product>* search(string, int);
//  
//  *** Update the Product with the given Product ***
//	bool updatePrd(Product);
//  
//  *** Update the stock of the given Product by the given value ***
//	bool updateStock(Product, unsigned);
//  
//  *** Update the sale of the given Product with the given value ***
//	bool updateSale(Product, unsigned);
//  
//  *** Batch Process the given file and return the number of errors ***
//	int batchProcessing(string);
//  
//  *** Return the Top X Best selling Product(s) in the database ***
//	vector<vector<Product>>* generatePrd(int);
//  
//  *** Return the Best selling Product(s) in the given category ***
//	vector<Product>* generatePrd(string);
//  
//  *** Return the Best selling manufacturer(s) in the database ***
//	vector<string>* generateManu();
//  
//  Main authors: ASHRAY JAIN (A0105199B)
//
/******************************************************************************************************/

#include "stdafx.h"
#include "Processing.h"

// Default Constructor that creates a new Database of Products
Processing::Processing():changed(false), file(NULL), bp(NULL)	{ db = new DB_Processing(_database); }
// Default Destructor
Processing::~Processing()										{ delete file;delete db; }
// Write temporary file
bool Processing::writeTemp(Product t, string f, int i)			{ return (!file)?true:file->writeTemp(t, f, i); }
// Returns whether recovery is needed
bool Processing::chkTmpFile()									{ return file->tempExists(); }
// Add the given Product to the database
bool Processing::addProduct(Product t)							{ return db->addProduct(t) && writeTemp(t, "ADD") && (changed = true); }
// Delete the given Product to the database
bool Processing::delProduct(Product t)							{ return db->delProduct(t) && writeTemp(t, "DELETE") && (changed = true); }
// Search for the given string in the database using the given method
vector<Product>* Processing::search(string s, int i)			{ return db->search(s, i); }
// Update the stock of the given Product by the given value
bool Processing::updateStock(Product t, unsigned i)				{ return db->updateStock(t, i) && writeTemp(t, "RESTOCK", i) && (changed = true); }
// Update the sale of the given Product with the given value
bool Processing::updateSale(Product t, unsigned i)				{ return db->updateSale(t, i) && writeTemp(t, "SALE", i) && (changed = true); }
// Return the Top X Best selling Product(s) in the database
vector<vector<Product>>* Processing::generatePrd(int X)			{ return db->generatePrd(X); }
// Return the Best selling Product(s) in the given category
vector<Product>* Processing::generatePrd(string s)				{ return db->generatePrd(s); }
// Return the Best selling manufacturer(s) in the database
vector<string>* Processing::generateManu()						{ return db->generateManu(); }
// Returns the size of the database
int Processing::size()											{ return _database.size(); }
// Returns whether the current state of the database is saved
bool Processing::isSaved()										{ return !changed; }
// Returns whether a filename and address has been assigned for the database
bool Processing::isEmptyFilename()								{ return (file)?false:true; }

// Clear the database
void Processing::clearDatabase()
{
	while(!_database.isempty())
		_database.del(_database[_database.size()-1]);
}

// Load product file into database at the given address
bool Processing::loadFile(string filename)
{
	clearDatabase();
	if(file)
		delete file;
	file = new File_processing(filename, _database);
	changed = false;
	return file->loadPrds();
}

// Create a new empty database
void Processing::newFile()
{
	delete file;
	file = NULL;
	clearDatabase();
	changed = false;
}

// Save the database into a new file at the given address
bool Processing::saveFileAs(string filename)
{
	if(file)
		delete file;
	file = new File_processing(filename, _database);
	if(file->savePrds()){ changed = false; return true; }
	return false;
}

// Save the database into the file
bool Processing::saveFile()
{
	if(file->savePrds()){ changed = false; return true; }
	return false;
}

// Initialize the temporary file and recover if parameter is true
void Processing::recover(bool tof)
{
	if(tof)
		batchProcessing(file->recoveryAddress());
	remove(file->recoveryAddress().c_str());
}

// Batch Process the given file and return the number of errors
int Processing::batchProcessing(string filename)
{
	bp = new batch_processing(db);
	int temp =  bp->bp_execute(filename);
	delete bp;
	bp = NULL;
	changed = true;
	return temp;
}

// Update the Product with the given Product
bool Processing::updatePrd(Product t)
{
	int tmpSale = t.getNoSold();
	bool updated = db->updateProduct(t) && writeTemp(t, "DELETE");
	t.updateStock(tmpSale);
	return updated && writeTemp(t, "ADD") && writeTemp(t, "SALE", tmpSale) && (changed = true);
}

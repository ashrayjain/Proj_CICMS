/******************************************************************************************************/
//
//  class Processing: Processing.h
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


#ifndef _PROCESSING_H_
#define _PROCESSING_H_

//#include "List_v1.h"
//#include "List_v2.h"
#include "List_v3.h"

#include "File_processing.h"
#include "DB_Processing.h"
#include "batch_processing.h"

class Processing
{
private:
	// THE DATABASE!
	list_adt<Product> _database;
	// File Processing object
	File_processing *file;
	// Database Processing object
	DB_Processing *db;
	// Batch Processing object
	batch_processing *bp;
	// Keep track if any unsaved changes exist in the database
	bool changed;
	// Clear the database
	void clearDatabase();

public:
	Processing();
	~Processing();
	bool isSaved();
	bool isEmptyFilename();
	bool writeTemp(Product, string, int i = 0);
	bool loadFile(string);
	bool saveFile();
	bool saveFileAs(string);
	void newFile();
	bool chkTmpFile();
	void recover(bool);
	int size();
	bool addProduct(Product);
	bool delProduct(Product);
	vector<Product>* search(string, int);
	bool updatePrd(Product);
	bool updateStock(Product, unsigned);
	bool updateSale(Product, unsigned);
	int batchProcessing(string);
	vector<vector<Product>>* generatePrd(int);
	vector<Product>* generatePrd(string);
	vector<string>* generateManu();
};

#endif
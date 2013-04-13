/******************************************************************************************************/
// 
//  class File_Processing: File_Processing.h
//
//  Description: File_Proceesing implements features related to data persistence, like loading products
//  from a text file into the database and saving the current state of the database into a text file.
//  
//  API:
//	*** Constructor that accepts a filename and a database ***
//  File_processing(string file, list_adt<Product>& db);
//  
//	*** Destructor ***
//	~File_processing();
//  
//  *** Load all Products from the file (object's filename attribute) into the database ***
//	bool loadPrds();
//  
//  *** Save all the Products from the database to the file (object's filename attribute) ***
//	bool savePrds();
//  
//  *** Write event with given function to the recovery file  ***
//	bool writeTemp(Product t, string function, int i = 0);
//  
//  *** Return whether temporary file exists already ***
//	bool tempExists();
//  
//  *** Deletes previous temproray file and initializes new one ***
//	void initializeTemp();
//  
//  *** Getter function for the address of the temporary file ***
//	string recoveryAddress();
//  
//  *** Static function that loads a batch processing file into a stack ***
//	static void loadBp(stack<Transaction>&, string);
//
//  *** Static function that writes the given string into the log file ***
//	static void writeLog(string);
//
//  Main authors: ASHRAY JAIN (A0105199B)
//
/******************************************************************************************************/

#ifndef _FILE_PROCESSING_H_
#define _FILE_PROCESSING_H_

#include "Product.h"
#include "List_v1.h"
//#include "List_v2.h"
//#include "List_v3.h"

#include <fstream>
#include <string>
#include <cstdio>
#include <Windows.h>
#include <stack>
#include "Transaction.h"

using namespace std;

class File_processing
{
private:
	// Product list file and the temporary file for recovery
	string filename, tempfile;
	// The Database
	list_adt<Product>& _db;
	// Filestream object for tempfile
	ofstream tempOut;
	// Toggle for previous recovery file existence
	bool failedPreviously;
	// Determines whether crash occured previously
	void init();
	// Static function to read in a Job for batch processing
	static void readJob(ifstream&, Transaction&);
	// Static function to load a recovery file
	static void recoveryLoad(ifstream&, Transaction&);

public:
	File_processing(string file, list_adt<Product>& db): filename(file), tempfile(file.substr(0, file.size()-3)+"cicms"),
		failedPreviously(false), _db(db)
	{ init(); }
	~File_processing();
	bool loadPrds();
	bool savePrds();
	bool writeTemp(Product t, string function, int i = 0);
	bool tempExists();
	void initializeTemp();
	string recoveryAddress();
	static void loadBp(stack<Transaction>&, string);
	static void writeLog(string);
};

#endif
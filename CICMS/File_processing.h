/******************************************************************************************************/
//
//  class File_Processing
//
//  Description: File_Proceesing implements features related to data persistence, like loading products
//  from a text file into the database and saving the current state of the database into a text file.
//
//  API:
//  File_processing(list_adt<Product>& db);
//  bool load();
//	bool save();
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
	string filename, tempfile;
	list_adt<Product>& _db;
	ofstream tempOut;
	bool failedPreviously;
	void init();
	static void readJob(ifstream&, Transaction&);
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
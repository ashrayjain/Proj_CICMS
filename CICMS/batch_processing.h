/*************************************************************************************************/
//	class batch_processing: batch_processing.h
//
//	Description: batch_processing.h contains the specification of batch_processing.cpp, which
//	processes a stack of Transactions and writes/modifies the database according to each Job in the 
//	Transaction.
//
//
//	API:
//	bp_execute(string BatchJobsPath); // Calls File_processing::loadBp to read in all transactions and jobs from file, then uses DB_Processing
//	to update the database accordingly
//	ErrorReport(); //Calls File_processing::writeLog(logline) to write a compiled error log message consisting of 
//	transaction id, job type, and barcode.
//	Main author: BOB WONG (A0094718U)
/*************************************************************************************************/
#ifndef _BPROCESSING_H_
#define _BPROCESSING_H_

#include "stdafx.h"
#include <stack>
#include "Transaction.h"
#include "DB_Processing.h"
#include "File_processing.h"

using namespace std;

class batch_processing 
{
private:
stack<Transaction> MainStack;
DB_Processing *_dbstuff;

public:
	batch_processing(DB_Processing *dbstuff); 
	int bp_execute(string BatchJobsPath);
	void errorReport();
};

#endif
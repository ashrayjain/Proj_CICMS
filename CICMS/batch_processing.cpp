/*************************************************************************************************/
//class batch_processing: batch_processing.cpp
//
//	Description: batch_processing.cpp contains the implementation of batch_processing.h, which
//	processes a stack of Transactions and writes/modifies the database according to each Job in the 
//	Transaction.
//
//
//	API:
//	bp_execute(string BatchJobsPath); // Calls File_processing::loadBp to read in all transactions and jobs from file, then uses DB_Processing
//	to update the database accordingly
//	ErrorReport(); //Calls File_processing::writeLog(logline) to write a compiled error log message consisting of 
//	transaction id, job type, and barcode.
//	Main authors: BOB WONG (A0094718U)
/*************************************************************************************************/
#include "stdafx.h"
#include "batch_processing.h"

using namespace std;


batch_processing::batch_processing(DB_Processing *dbstuff)  //Constructor
{
	_dbstuff=dbstuff;
}

void batch_processing::errorReport()												  //Puts ID, jobtype and barcode together into a string, then passes it to file_processing::writelog to write it into a log file
{
	string id=MainStack.top().ReturnId();
	string jobtype=MainStack.top().ReturnJobType(); 
	unsigned barcode=MainStack.top().ReturnBarcode();
	string stringbarcode;
	ostringstream convert;															  //Convert unsigned into string
	convert<<barcode;
	stringbarcode=convert.str();
	string logline=id+ " " + jobtype +" " + stringbarcode + "\n";
	File_processing::writeLog(logline);
}


int batch_processing::bp_execute(string BatchJobsPath)								  //Process the stack commands and errorcheck
{
	int errCount = 0;
	File_processing::loadBp(MainStack, BatchJobsPath);								  //Load user's batch file into the stack
	while(!MainStack.empty())
	{
	while(!MainStack.top().QueueEmpty())
		{
			if(MainStack.top().ReturnJobType()=="ADD")
			{
				if(!_dbstuff->addProduct(MainStack.top().ReturnProduct()))
				{
					errCount++;
					errorReport();
				}
			}
			else if (MainStack.top().ReturnJobType()=="SALE")
			{
				if(!_dbstuff->updateSale(MainStack.top().ReturnBarcode(), MainStack.top().ReturnNumber()))
				{
					errCount++;
					errorReport();
				}
			}
			else if (MainStack.top().ReturnJobType()=="DELETE")
			{
				if(!_dbstuff->delProduct(MainStack.top().ReturnBarcode()))
				{
					errCount++;
					errorReport();
				}
			}
			else if(MainStack.top().ReturnJobType()=="RESTOCK")
			{
				if(!_dbstuff->updateStock(MainStack.top().ReturnBarcode(), MainStack.top().ReturnNumber()))
				{
					errCount++;
					errorReport();
				}
			}
			MainStack.top().popJob();
		}

		MainStack.pop();
	
	}
	return errCount;
}
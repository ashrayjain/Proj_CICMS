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
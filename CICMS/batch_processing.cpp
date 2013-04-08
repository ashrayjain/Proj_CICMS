#include "stdafx.h"
#include "batch_processing.h"
using namespace std;


batch_processing::batch_processing(DB_Processing *dbstuff, File_processing *fpstuff)  //Constructor
{
	_dbstuff=dbstuff;
	_fpstuff=fpstuff;
}


void batch_processing::bp_read(string BatchJobsPath)
{
	//_fpstuff->load_bp(MainStack, BatchJobsPath);
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
	//_fpstuff->writelog(logline);
}


void batch_processing::bp_execute(string BatchJobsPath)								  //Process the stack commands and errorcheck
{
	bp_read(BatchJobsPath);															  //Load user's batch file into the stack

	while(!MainStack.empty())
	{
	while(!MainStack.top().QueueEmpty())
		{
			if(MainStack.top().ReturnJobType()=="ADD")
			{
				if(!_dbstuff->addProduct(MainStack.top().ReturnProduct()))
					errorReport();
			}
			else if (MainStack.top().ReturnJobType()=="SALE")
			{
				if(!_dbstuff->updateSale(MainStack.top().ReturnBarcode(), MainStack.top().ReturnNumber()))
					errorReport();
			}
			else if (MainStack.top().ReturnJobType()=="DELETE")
			{
				if(!_dbstuff->delProduct(MainStack.top().ReturnBarcode()))
					errorReport();
			}
			else if(MainStack.top().ReturnJobType()=="RESTOCK")
			{
				if(!_dbstuff->updateStock(MainStack.top().ReturnBarcode(), MainStack.top().ReturnNumber()))
					errorReport();
			}


			MainStack.top().popJob();
		}

		MainStack.pop();
	
	}
	
}
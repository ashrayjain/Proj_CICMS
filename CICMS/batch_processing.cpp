#include "batch_processing.h"

using namespace std;

batch_processing::batch_processing(DB_Processing *dbstuff, File_processing *fpstuff)
{
	_*dbstuff=*dbstuff;
	_*fpstuff=*fpstuff;
}

void batch_processing::bp_read(string BatchJobsPath)
{
	*_fpstuff->load_bp(MainStack, BatchJobsPath);
}

void batch_processing::bp_execute(string BatchJobsPath)
{
	bp_read(BatchJobsPath);

	while(!MainStack.empty())
	{
	while(!MainStack.top().QueueEmpty())
	{
		if(MainStack.top().ReturnJobType()=="ADD")
		{
			_dbstuff->addProduct(MainStack.top().ReturnProduct());
		}
		else if (MainStack.top().ReturnJobType()=="SALE")
		{
			_dbstuff->updateSale(MainStack.top().ReturnBarcode(), MainStack.top().ReturnNumber());
		}
		else if (MainStack.top().ReturnJobType()=="DELETE")
		{
			_dbstuff->delProduct(MainStack.top().ReturnBarcode());
		}
		else if(MainStack.top().ReturnJobType()=="RESTOCK")
		{
			_dbstuff->updateStock(MainStack.top().ReturnBarcode(), MainStack.top().ReturnNumber());
		}


		MainStack.top().popJob();
	}

	MainStack.pop();
	
	}


	
	
	
}
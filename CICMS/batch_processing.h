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
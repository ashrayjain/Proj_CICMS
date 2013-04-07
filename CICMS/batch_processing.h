#include<stack>
#include "DB_Processing.h"
#include "File_processing.h"
#include "Transaction.h"

using namespace std;

class batch_processing 
{
private:
stack<Transaction> MainStack; 
void bp_read(string BatchJobsPath);
DB_Processing *_dbstuff;
File_Processing *_fpstuff;

public:
	batch_processing(DB_Processing *dbstuff, File_processing *fpstuff);
	void bp_execute(string BatchJobsPath);
};
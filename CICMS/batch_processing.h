#include<stack>
#include "DB_Processing.h"
#include "File_processing.h"
#include "Transaction.h"

using namespace std;

class batch_processing 
{
private:
stack<Transaction> MainStack; 

public:
	batch_processing(DB_Processing dbstuff, File_processing fpstuff);
	void bp_read(string BatchJobsPath);
	void bp_execute();
};
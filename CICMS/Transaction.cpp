#include "Transaction.h"

using namespace std;

Transaction::Transaction(string id)
{
	_id=id;
}

void Transaction::pushJob(Job newJob)
{
	MainQueue.push(newJob);
}

void Transaction::popJob()
{
	MainQueue.pop();
}

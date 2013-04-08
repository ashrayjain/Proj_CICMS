#include "stdafx.h"
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

string Transaction::ReturnJobType()
{
	MainQueue.front.ReturnJobType();
}

Product Transaction::ReturnProduct()
{
	return MainQueue.front.ReturnProduct();
}

unsigned Transaction::ReturnBarcode()
{
	return MainQueue.front.ReturnBarcode();
}

unsigned Transaction::ReturnNumber()
{
	return MainQueue.front.ReturnNumber();
}


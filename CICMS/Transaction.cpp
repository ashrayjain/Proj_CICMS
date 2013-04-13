/*************************************************************************************************/
//	class Transaction: Transaction.cpp
//	
//	Description: Transaction.cpp contains the implementation of Transaction.h, which contains a queue to store
//	its jobs, as well as functions to specifically access and manipulate the front job on the queue.
//	
// 
//
//	API:
//	void pushJob(Job);		 //Add a job to the queue
//	void popJob();			 //Remove a job from the queue
//	Product ReturnProduct(); //Call the ReturnProduct function of the front Job
//	unsigned ReturnBarcode();//Call the ReturnBarcode function of the front Job
//	unsigned ReturnNumber(); //Call the ReturnNumber function of the front Job
//	string ReturnJobType();  //Call the ReturnJobType function of the front Job
//	bool QueueEmpty();		 //Check if the Transaction has no jobs left
//	string ReturnId();		 //Call the ReturnId function of the front Job
//	Main authors: BOB WONG (A0094718U)
/*************************************************************************************************/
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
	return MainQueue.front().ReturnJobType();
}

Product Transaction::ReturnProduct()
{
	return MainQueue.front().ReturnProduct();
}

unsigned Transaction::ReturnBarcode()
{
	return MainQueue.front().ReturnBarcode();
}

unsigned Transaction::ReturnNumber()
{
	return MainQueue.front().ReturnNumber();
}

bool Transaction::QueueEmpty()
{
	return MainQueue.empty();
}

string Transaction::ReturnId()
{
	return _id;
}

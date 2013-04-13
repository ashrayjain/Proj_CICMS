/*************************************************************************************************/
//	class Transaction: Transaction.h
//	
//	Description: Transaction.h contains the specification of Transaction.cpp, which contains a queue to store
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
#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_

#include "stdafx.h"
#include <queue>
#include "Job.h"

using namespace std;

class Transaction {
private:
	queue<Job> MainQueue;
	string _id;
public:
	Transaction(string id);
	void pushJob(Job);
	void popJob();
	Product ReturnProduct();
	unsigned ReturnBarcode();
	unsigned ReturnNumber();
	string ReturnJobType();
	bool QueueEmpty();
	string ReturnId();
};

#endif

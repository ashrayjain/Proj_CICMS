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
};
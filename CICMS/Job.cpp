/*************************************************************************************************/
//	class Job: Job.cpp
//
//	Description: Job.cpp contains the implementation of Job.h, which
//	possesses a number of variables which store the essential information pertinent to a job, as well as
//	a function for converting these variables into a unified product for adding to the database
//
//
//	API:
//	Product ReturnProduct();  //Returns a Product from the data in the Job
//	unsigned ReturnBarcode(); //Returns barcode
//	unsigned ReturnNumber();  //Returns the relevant number to add, delete, or restock
//	string ReturnJobType();   //Returns what kind of job it is
//	Main authors: BOB WONG (A0094718U)
/*************************************************************************************************/

#include "stdafx.h"
#include "Job.h"

using namespace std;

Job::Job(string jobtype, string name, string category, unsigned barcode, double price, string manufacturer, unsigned number)
{
	_jobtype=jobtype;
	_name=name;
	_category=category;
	_barcode=barcode;
	_price=price;
	_manufacturer=manufacturer;
	_number=number;
}

Product Job::ReturnProduct()
{
	return Product(_name, _category, _manufacturer, _barcode, _price, _number, 0);
}

unsigned Job::ReturnBarcode()
{
	return _barcode;
}

unsigned Job::ReturnNumber()
{
	return _number;
}

string Job::ReturnJobType()
{
	return _jobtype;
}


/*************************************************************************************************/
//	class Job: Job.h
//
//	Description: Job.h contains the specification of Job.cpp, which
//	possesses a number of variables which store the essential information pertinent to a job, as well as
//  a function for converting these variables into a unified product for adding to the database.
//
//
//	API:
//	Product ReturnProduct();  //Returns a Product from the data in the Job
//	unsigned ReturnBarcode(); //Returns barcode
//	unsigned ReturnNumber();  //Returns the relevant number to add, delete, or restock
//	string ReturnJobType();   //Returns what kind of job it is
//	Main authors: BOB WONG (A0094718U)
/*************************************************************************************************/
#ifndef _JOB_H_
#define _JOB_H_

#include "stdafx.h"
#include <string>
#include "Product.h"

using namespace std;

class Job {
private:
	string _jobtype;
	string _name;
	string _category;
	unsigned _barcode;
	double _price;
	string _manufacturer;
	unsigned _number;

public:
	Job(string jobtype, string name, string category, unsigned barcode, double price, string manufacturer, unsigned number);
	Product ReturnProduct();
	unsigned ReturnBarcode();
	unsigned ReturnNumber();
	string ReturnJobType();
};

#endif
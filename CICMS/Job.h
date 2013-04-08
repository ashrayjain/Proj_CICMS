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
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


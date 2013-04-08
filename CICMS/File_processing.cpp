/******************************************************************************************************/
//
//  class File_Processing
//
//  Description: File_Proceesing implements features related to data persistence, like loading products
//  from a text file into the database and saving the current state of the database into a text file.
//
//  API:
//  File_processing(list_adt<Product>& db);
//  bool load();
//	bool save();
//
//  Main authors: ASHRAY JAIN (A0105199B)
//
/******************************************************************************************************/

#include "stdafx.h"
#include <Windows.h>
#include "File_Processing.h"

void File_processing::init()
{
	ifstream fin(tempfile);
	if(fin)
		failedPreviously = true;
	else
		initializeTemp();
	fin.close();
}

File_processing::~File_processing()
{
	remove(tempfile.c_str());
}

bool File_processing::tempExists() { return failedPreviously; }

void File_processing::initializeTemp()
{
	tempOut.open(tempfile);
	SetFileAttributes(wstring(tempfile.begin(), tempfile.end()).c_str(), FILE_ATTRIBUTE_HIDDEN);
	tempOut<<to_string(1);
	tempOut<<"\n\nRecovery\n";
	tempOut.close();
	failedPreviously = false;
}

bool File_processing::writeTemp(Product t, string function, int i)
{
	tempOut.open(tempfile, ios::app);
	tempOut<<function<<"\n";
	if(function == "ADD")
		tempOut<<t.getName()<<"\n"
			<<t.getCategory()<<"\n"
			<<to_string(t.getBarcode())<<"\n"
			<<to_string(t.getPrice())<<"\n"
			<<t.getManufacturer()<<"\n"
			<<to_string(t.getNoInStock())<<"\n";
	else
		tempOut<<to_string(t.getBarcode())<<"\n";

	if(i)
		tempOut<<to_string(i)<<"\n";
	tempOut<<"\n\n";
	tempOut.close();
	return true;
}
bool File_processing::loadPrds()
{
	ifstream fin(filename);
	if(!fin)
		return false;
	
	string temp, noProducts;

	getline(fin, noProducts);
	getline(fin, temp);
	
	string name, category, manufacturer, price, barcode, noInStock, noSold;
	for(int i = 0; i<atoi(noProducts.c_str()); i++)
	{
		getline(fin, name);
		getline(fin, category);
		getline(fin, barcode);
		getline(fin, price);
		getline(fin, manufacturer);
		getline(fin, noInStock);
		getline(fin, noSold);
		_db.add(Product(name, category, manufacturer, atoi(barcode.c_str()),
			atof(price.c_str()), atoi(noInStock.c_str()), atoi(noSold.c_str())));
		getline(fin, temp);
	}

	fin.close();
	return true;
}

bool File_processing::savePrds()
{
	ofstream fout(filename);
	if(!fout)
		return false;

	fout<<to_string(_db.size())+"\n\n";
	for(unsigned i = 0; i < _db.size(); i++)
	{
		fout<<_db[i].getName()+"\n";
		fout<<_db[i].getCategory()+"\n";
		fout<<to_string(_db[i].getBarcode())+"\n";
		fout<<to_string(_db[i].getPrice())+"\n";
		fout<<_db[i].getManufacturer()+"\n";
		fout<<to_string(_db[i].getNoInStock())+"\n";
		fout<<to_string(_db[i].getNoSold())+"\n";
		fout<<"\n";
	}
	fout.close();
	initializeTemp();
	return true;
}

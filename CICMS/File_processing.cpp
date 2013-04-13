/******************************************************************************************************/
//
//  class File_Processing: File_Processing.cpp
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
	remove(tempfile.c_str());
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
	tempOut<<"\n";
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

void File_processing::writeLog(string line)
{
	ofstream fout("log.txt", ios::app);
	fout<<line;
	fout.close();
}

void File_processing::readJob(ifstream& fin, Transaction& t)
{
	string function = "",
		name = "", 
		cat = "", 
		barcode = "", 
		price = "", 
		manu = "", 
		num = "",
		temp;
	getline(fin, function);
	if(function=="ADD")
	{
		getline(fin, name);
		getline(fin, cat);
		getline(fin, barcode);
		getline(fin, price);
		getline(fin, manu);
		getline(fin, num);
	}
	else
	{
		getline(fin, barcode);
		if(function!="DELETE")
			getline(fin, num);
	}
	getline(fin, temp);
	
	t.pushJob(Job(function, name, cat, atoi(barcode.c_str()),
			atof(price.c_str()), manu, atoi(num.c_str())));
}

void File_processing::recoveryLoad(ifstream& fin, Transaction& t)
{	
	readJob(fin, t);
	while(!fin.eof())
		readJob(fin, t);
}

string File_processing::recoveryAddress()
{
	return tempfile;
}

void File_processing::loadBp(stack<Transaction>& s, string BPlocation)
{
	ifstream fin(BPlocation);
	if(fin)
	{
		int noOfTransactions = 0;
		fin>>noOfTransactions;
		string transID;
		for(int i = 0; i < noOfTransactions; i++)
		{
			fin>>transID;
			Transaction tempTransaction(transID);
			string temp;
			if(transID == "Recovery")
			{
				getline(fin, temp);
				recoveryLoad(fin, tempTransaction);
			}
			else
			{
				int noOfJobs;
				fin>>noOfJobs;
				getline(fin, temp);
				getline(fin, temp);
				for(int j = 0; j < noOfJobs; j++)
					readJob(fin, tempTransaction);
			}
			s.push(tempTransaction);
		}
		fin.close();
	}
}
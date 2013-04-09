/*************************************************************************************************/
//
//  class Bridge: Bridge.h
//
//  Description: A wrapper class (managed class) for the native class Processing (logic) that only converts the data type
//	(C++\CLI <-----> std C++)
//
//  API:
//	*** search according to a keyword and a method (int) ***
//  array<System::Windows::Forms::ListViewItem^>^ Search(System::String^, int);
//	*** add a new product ***
//	bool Add(System::Windows::Forms::ListViewItem^);
//	*** restock a product ***
//	bool Restock(System::Windows::Forms::ListViewItem^, unsigned);
//	*** specify the sale for a product ***
//	bool Sell(System::Windows::Forms::ListViewItem^, unsigned);
//  *** scrap/delete a product ***
//	bool Del(System::Windows::Forms::ListViewItem^);
//	*** generate the report for the Best-Selling manufacturer(s) ***
//	System::String^ Bridge::Gen_BSmanu();
//	*** generate the report for the Top X products ***
//	*** generate the report for the Best-Selling product(s), when x = 1 ***
//	array<System::Windows::Forms::ListViewItem^>^ Bridge::Gen_TopXpd(int x);
//	*** generate the report for the Best-Selling product(s) in a given category (string)
//	array<System::Windows::Forms::ListViewItem^>^ Bridge::Gen_BSpdCate(System::String^ s);
//
//  Main authors: XIE KAI(A0102016E)
//
/*************************************************************************************************/
#ifndef _GUARD_Bridge
#define _GUARD_Bridge

#include "stdafx.h"
#include "Product.h"
#include <string>
#include "Processing.h"

ref class Bridge{
private:
	Processing* Handler;
	//Type converting
	static Product toProduct(System::Windows::Forms::ListViewItem^);
	static System::Windows::Forms::ListViewItem^ toLvItem(Product);
	static double toDouble(System::String^);
	static int toUInt(System::String^);
	static std::string toStdString(System::String^);
	static System::String^ toSysString(double);
	static System::String^ toSysString(unsigned);
	static System::String^ toSysString(std::string);
	//Finalizer: deallocate the unmanaged class here
	!Bridge(){
		delete this->Handler;
		this->Handler = NULL;
	}

public:
	Bridge(){
		this->Handler = new Processing;
	}
	//Destructor: deallocate both unmanaged and managed class (if have)
	~Bridge(){
		this->!Bridge();
	}
	//Communication to class Processing
	array<System::Windows::Forms::ListViewItem^>^ Search(System::String^, int);//return type shall be an array of ListViewItem
	bool Add(System::Windows::Forms::ListViewItem^);
	bool Restock(System::Windows::Forms::ListViewItem^, unsigned);
	bool Sell(System::Windows::Forms::ListViewItem^, unsigned);
	bool Del(System::Windows::Forms::ListViewItem^);
	System::String^ Bridge::Gen_BSmanu();
	cli::array<cli::array<System::Windows::Forms::ListViewItem^>^>^ Bridge::Gen_TopXpd(int x);
	array<System::Windows::Forms::ListViewItem^>^ Bridge::Gen_BSpdCate(System::String^ s);
	//new staff in phase 3
	bool CheckRecovery();
	void Recover(bool yesOrNo);
	bool Load(System::String^);
	bool Save();
	bool SaveAs(System::String^);
	int Batch_processing(System::String^);
	void Modify(System::Windows::Forms::ListViewItem^);
	void Create_newPrdList();
	bool isSaved();
	bool isEmptyFilename();
};

#endif
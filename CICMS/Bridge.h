//middle layer between GUI and Processing
#ifndef _GUARD_Bridge
#define _GUARD_Bridge

#include "stdafx.h"
#include "Product.h"
#include <string>
#include "Processing.h"
#include <cliext/vector>

class Bridge{
private:
	Processing Handler;
	//Type converting
	static Product toProduct(System::Windows::Forms::ListViewItem^);
	static System::Windows::Forms::ListViewItem^ toLvItem(Product);
	static double toDouble(System::String^);
	static int toUInt(System::String^);
	static std::string toStdString(System::String^);
	static System::String^ toSysString(double);
	static System::String^ toSysString(unsigned);
	static System::String^ toSysString(std::string);

public:
	//Communication to class Processing
	cliext::vector<System::Windows::Forms::ListViewItem^>^ Search(System::String^, int);//return type shall be an array of ListViewItem
	bool Add(System::Windows::Forms::ListViewItem^);
	bool Restock(System::Windows::Forms::ListViewItem^, unsigned);
	bool Sell(System::Windows::Forms::ListViewItem^, unsigned);
	bool Del(System::Windows::Forms::ListViewItem^);
	System::String^ Bridge::Gen_BSpd();
	System::String^ Bridge::Gen_BSmanu();
	System::String^ Bridge::Gen_TopXpd(int x);
};

#endif
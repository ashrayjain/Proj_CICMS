//middle layer between GUI and Processing
#ifndef _GUARD_Bridge
#define _GUARD_Bridge

#include "stdafx.h"
#include "Product.h"
#include <list>//temporary
#include <string>

class Bridge{
private:
	//Processing Handler;
public:
	//Communication to class Processing
	std::list<Product> Search(System::String^, int);
	bool Add(System::Windows::Forms::ListViewItem^);
	bool Restock(System::Windows::Forms::ListViewItem^, unsigned^);
	bool Sell(System::Windows::Forms::ListViewItem^, unsigned^);
	bool Del(System::Windows::Forms::ListViewItem^);
	//Input checking
	static bool is_number(System::String^);
	static bool lessThan_zero(System::String^);
	static bool is_empty(System::String^);
	//Type converting
	static Product toProduct(System::Windows::Forms::ListViewItem^);
	static System::Windows::Forms::ListViewItem^ toLvItem(Product);
	static double toDouble(System::String^);
	static int toInt(System::String^);
	static std::string toStdString(System::String^);
	static System::String^ toSysString(double);
	static System::String^ toSysString(unsigned);
	static System::String^ toSysString(std::string);
};

#endif
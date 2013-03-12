#include "stdafx.h"
#include "Bridge.h"
#include <msclr\marshal_cppstd.h>

//**************************************************
//
//Communication to class Processing
//
std::list<Product> Bridge::Search(System::String^ s, int i)
{
	enum BYMETHOD { byName, byBarcode, byCategory, byStock, byManuf };
	std::list<Product> *r = new std::list<Product>;
	//if(i == byBarcode)
	//	r = Handler.Search(toInt(s), i);
	//else
	//	r = Handler.Search(toStdString(s), i);
	return std::list<Product>();
};
bool Bridge::Add(System::Windows::Forms::ListViewItem^ item)
{
	//if(Handler.Add(toProduct(item)))
	//	return true;
	return false;
};
bool Bridge::Restock(System::Windows::Forms::ListViewItem^ item, unsigned^ i)
{
	//if(Handler.Restock(toProduct(item), i))
	//	return true;
	return false;
};
bool Bridge::Sell(System::Windows::Forms::ListViewItem^ item, unsigned^ i)
{
	//if(Handler.Sell(toProduct(item), i))
	//	return ture;
	return false;
};
bool Bridge::Del(System::Windows::Forms::ListViewItem^ item)
{
	//if(Handler.Del(toProduct(item)))
	//	return true;
	return false;
};
//**************************************************
//
//Input checking
//
//Check whether a string is number or not
bool Bridge::is_number(System::String^ s)
{
	try{
		System::Convert::ToDouble(s);
	} catch(System::FormatException^){
		return false;
	}
	return true;
};
//Check whether a number (represented in System::String) is less than 0 or not
bool Bridge::lessThan_zero(System::String^ s)
{
	return toInt(s) < 0;
};
//Check whether a string is empty or not
bool Bridge::is_empty(System::String^ s)
{
	return s->Length == 0;
};
//**************************************************
//
//Type converting
//
//Conversion from ListViewItem to Product
Product Bridge::toProduct(System::Windows::Forms::ListViewItem^ item)
{
	return Product(
		toStdString(item->SubItems[0]->Text),
		toStdString(item->SubItems[1]->Text),
		toStdString(item->SubItems[2]->Text),
		toInt(item->SubItems[3]->Text),
		toDouble(item->SubItems[4]->Text)
		);
};
//Conversion from Product to ListViewItem
System::Windows::Forms::ListViewItem^ Bridge::toLvItem(Product pd)
{
	return gcnew System::Windows::Forms::ListViewItem(gcnew cli::array<System::String^>(7) {
		toSysString(pd.getName()), 
			toSysString(pd.getCategory()),
			toSysString(pd.getBarcode()), 
			toSysString(pd.getPrice()), 
			toSysString(pd.getManufacturer()),
			toSysString(pd.getNoInStock()),
			toSysString(pd.getNoSold())
	});
};
//Conversion from System::String to double
double Bridge::toDouble(System::String^ s)
{
	return System::Convert::ToDouble(s);
};
//Conversion from System::String to int
int Bridge::toInt(System::String^ s)
{
	return System::Convert::ToInt32(s);
};
//Conversion from System::String to std::string
std::string Bridge::toStdString(System::String^ s)
{
	return msclr::interop::marshal_as<std::string>(s);
};
//Conversion from double to System::String
System::String^ Bridge::toSysString(double i)
{
	return System::Convert::ToString(i);
};
//Conversion from unsigned to System::String
System::String^ Bridge::toSysString(unsigned i)
{
	return System::Convert::ToString(i);
};
//Conversion from std::string to System::String
System::String^ Bridge::toSysString(std::string s)
{
	return gcnew System::String(s.c_str());
};
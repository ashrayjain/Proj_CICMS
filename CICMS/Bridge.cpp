#include "stdafx.h"
#include "Bridge.h"
#include <msclr\marshal_cppstd.h>
#include <cliext/vector>

//**************************************************
//
//Communication to class Processing
//
cliext::vector<System::Windows::Forms::ListViewItem^>^ Bridge::Search(System::String^ s, int i)
{
	enum BYMETHOD { byName, byBarcode, byCategory, byStock, byManuf };
	std::list<Product> *r = new std::list<Product>;//no need new ... here
	//return a list of product, but here i shall convert them into listViewItem
	//if(i == byBarcode)
	//	r = Handler.Search(toUInt(s), i);
	//else
	//	r = Handler.Search(toStdString(s), i);
	cliext::vector<System::Windows::Forms::ListViewItem^>^ items = gcnew cliext::vector<System::Windows::Forms::ListViewItem^>;
	for(std::list<Product>::iterator i = r->begin(); i != r->end(); i++){
		items->push_back(toLvItem(*i));
	}
	return items;
}
bool Bridge::Add(System::Windows::Forms::ListViewItem^ item)
{
	//if(Handler.Add(toProduct(item)))
	//	return true;
	return false;
}
bool Bridge::Restock(System::Windows::Forms::ListViewItem^ item, unsigned^ i)
{
	//if(Handler.Restock(toProduct(item), i))
	//	return true;
	return false;
}
bool Bridge::Sell(System::Windows::Forms::ListViewItem^ item, unsigned^ i)
{
	//if(Handler.Sell(toProduct(item), i))
	//	return ture;
	return false;
}
bool Bridge::Del(System::Windows::Forms::ListViewItem^ item)
{
	//if(Handler.Del(toProduct(item)))
	//	return true;
	return false;
}
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
		toUInt(item->SubItems[3]->Text),
		toDouble(item->SubItems[4]->Text)
		);
}
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
}
//Conversion from System::String to double
double Bridge::toDouble(System::String^ s)
{
	return System::Convert::ToDouble(s);
}
//Conversion from System::String to int
int Bridge::toUInt(System::String^ s)
{
	return System::Convert::ToUInt32(s);
}
//Conversion from System::String to std::string
std::string Bridge::toStdString(System::String^ s)
{
	return msclr::interop::marshal_as<std::string>(s);
}
//Conversion from double to System::String
System::String^ Bridge::toSysString(double i)
{
	return System::Convert::ToString(i);
}
//Conversion from unsigned to System::String
System::String^ Bridge::toSysString(unsigned i)
{
	return System::Convert::ToString(i);
}
//Conversion from std::string to System::String
System::String^ Bridge::toSysString(std::string s)
{
	return gcnew System::String(s.c_str());
}
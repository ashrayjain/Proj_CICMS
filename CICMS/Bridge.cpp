#include "stdafx.h"
#include "Bridge.h"
#include "List_v1.h"
#include <msclr\marshal_cppstd.h>

//**************************************************
//
//Communication to class Processing
//
array<System::Windows::Forms::ListViewItem^>^ Bridge::Search(System::String^ s, int i)
{
	enum BYMETHOD { byName, byBarcode, byCategory, byStock, byManuf };
	vector<Product> *r = Handler.db->search(toStdString(s), i);
	array<System::Windows::Forms::ListViewItem^>^ items = gcnew array<System::Windows::Forms::ListViewItem^>(r->size());
	for(unsigned i = 0; i < r->size(); i++)
		items[i] = toLvItem((*r)[i]);
	delete r;
	return items;
}
bool Bridge::Add(System::Windows::Forms::ListViewItem^ item)
{
	if(Handler.db->addProduct(toProduct(item)))
		return true;
	return false;
}
bool Bridge::Restock(System::Windows::Forms::ListViewItem^ item, unsigned i)
{
	if(Handler.db->updateStock(toProduct(item), i))
		return true;
	return false;
}
bool Bridge::Sell(System::Windows::Forms::ListViewItem^ item, unsigned i)
{
	if(Handler.db->updateSale(toProduct(item), i))
		return true;
	return false;
}
bool Bridge::Del(System::Windows::Forms::ListViewItem^ item)
{
	if(Handler.db->delProduct(toProduct(item)))
		return true;
	return false;
}
System::String^ Bridge::Gen_BSmanu(){
	vector<std::string> *r = NULL;
	r = Handler.db->generateManu();
	System::String^ s = "";
	for(unsigned i = 0; i < r->size(); i++)
		s += toSysString((*r)[i]) + "\n";
	delete r;
	return s;
}
array<System::Windows::Forms::ListViewItem^>^ Bridge::Gen_BSpdCate(System::String^ s){
	vector<Product> *r = Handler.db->generatePrd(toStdString(s));
	array<System::Windows::Forms::ListViewItem^>^ items = gcnew array<System::Windows::Forms::ListViewItem^>(r->size());
	for(unsigned i = 0; i < r->size(); i++)
		items[i] = toLvItem((*r)[i]);
	delete r;
	return items;
}
//combine Gen_TopXpd and Gen_BSpd
array<System::Windows::Forms::ListViewItem^>^ Bridge::Gen_TopXpd(int x){
	vector<Product> *r = Handler.db->generatePrd(x);
	array<System::Windows::Forms::ListViewItem^>^ items = gcnew array<System::Windows::Forms::ListViewItem^>(r->size());
	for(unsigned i = 0; i < r->size(); i++)
		items[i] = toLvItem((*r)[i]);
	delete r;
	return items;
}
//**************************************************
//
//Type converting
//
//Conversion from ListViewItem to a new Product
Product Bridge::toProduct(System::Windows::Forms::ListViewItem^ item)
{
	return Product(
		toStdString(item->SubItems[0]->Text),
		toStdString(item->SubItems[1]->Text),
		toStdString(item->SubItems[4]->Text),
		toUInt(item->SubItems[2]->Text),
		toDouble(item->SubItems[3]->Text)
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
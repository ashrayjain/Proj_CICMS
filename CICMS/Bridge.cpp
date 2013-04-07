/*************************************************************************************************/
//
//  class Bridge: Bridge.cpp
//
//  Description: A middle layer between GUI and Processing (logic) that only converts the data type
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
#include "stdafx.h"
#include "Bridge.h"
#include <msclr\marshal_cppstd.h>

//**************************************************
//
//Communication to class Processing
//
//
array<System::Windows::Forms::ListViewItem^>^ Bridge::Search(System::String^ s, int i)
{
	enum BYMETHOD { byName, byBarcode, byCategory, byStock, byManuf };
	vector<Product> *r = Handler->search(toStdString(s), i);
	array<System::Windows::Forms::ListViewItem^>^ items = gcnew array<System::Windows::Forms::ListViewItem^>(r->size());
	for(unsigned i = 0; i < r->size(); i++)
		items[i] = toLvItem((*r)[i]);
	delete r;
	return items;
}
bool Bridge::Add(System::Windows::Forms::ListViewItem^ item)
{
	if(Handler->addProduct(toProduct(item)))
		return true;
	return false;
}
bool Bridge::Restock(System::Windows::Forms::ListViewItem^ item, unsigned i)
{
	if(Handler->updateStock(toProduct(item), i))
		return true;
	return false;
}
bool Bridge::Sell(System::Windows::Forms::ListViewItem^ item, unsigned i)
{
	if(Handler->updateSale(toProduct(item), i))
		return true;
	return false;
}
bool Bridge::Del(System::Windows::Forms::ListViewItem^ item)
{
	if(Handler->delProduct(toProduct(item)))
		return true;
	return false;
}
System::String^ Bridge::Gen_BSmanu(){
	vector<std::string> *r = Handler->generateManu();
	System::String^ s = "";
	for(unsigned i = 0; i < r->size(); i++)
		s += toSysString((*r)[i]) + "\n";
	delete r;
	return s;
}
array<System::Windows::Forms::ListViewItem^>^ Bridge::Gen_BSpdCate(System::String^ s){
	vector<Product> *r = Handler->generatePrd(toStdString(s));
	array<System::Windows::Forms::ListViewItem^>^ items = gcnew array<System::Windows::Forms::ListViewItem^>(r->size());
	for(unsigned i = 0; i < r->size(); i++)
		items[i] = toLvItem((*r)[i]);
	delete r;
	return items;
}
//combine Gen_TopXpd and Gen_BSpd
array<System::Windows::Forms::ListViewItem^>^ Bridge::Gen_TopXpd(int x){
	vector<Product> *r = Handler->generatePrd(x);
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
///////////////////////////////////////////////////////////////////////new staff
//Check whether a recovery is needed
bool Bridge::CheckRecovery(){
	//return Handler->chkTmpFile();
	return true;//can recover
}
//Recover the product list operations
void Bridge::Recover(bool yesOrNo){
	//Handler->recover(yesOrNo);
}
//Load a product list

bool Bridge::Load(System::String^ filename){
	//return Handler->Load(this->toStdString(filename));
	return true;
}
//save into current product list
bool Bridge::Save(){
	//return Handler->Save();
	return true;
}
//Save into a .txt file
bool Bridge::SaveAs(System::String^ filename){
	//return Handler->SaveAs(this->toStdString(filename));
	return true;
}
//Execute the batchProcessing
int Bridge::Batch_processing(System::String^ filename){
	//return Handler->Batch_processing(this->toStdString(filename));
	return 3;
}
//Modify products details
void Bridge::Modify(System::Windows::Forms::ListViewItem^ item){
	//Handler->updatePrd(this->toProduct(item));
}
//create a new product list
void Bridge::Create_newPrdList(){
	//Handler->clear_database();
}
//whether the current file is !changed/saved or not
bool Bridge::isSaved(){
	//return Handler->isSaved();
	return false;
}
bool Bridge::isEmptyFilename(){
	//return Handler->isEmptyFilename();
	return true;
}
/*************************************************************************************************/
//
//  ListViewItemComparer.cpp
//
//  Description: [for MainForm's ListView components] A simple class that implements the manual sorting of items by columns. 
//
//  API:
//  CICMS_UI::ListViewItemComparer::ListViewItemComparer(int column, bool sortOrder);
//	CICMS_UI::ListViewItemComparer::Compare(Object^ x, Object^ y);
//
//  Main authors: XIE KAI(A0102016E)
//
/*************************************************************************************************/

#include "stdafx.h"
#include "ListViewItemComparer.h"

using namespace CICMS_UI;

ListViewItemComparer::ListViewItemComparer(int column, bool sortOrder, bool is_num){
	_col = column;
	_sort = sortOrder;
	_is_num = is_num;
}
//Function: compare two objects
int ListViewItemComparer::Compare(Object^ x, Object^ y)
{
	System::String^ x_t = (dynamic_cast<System::Windows::Forms::ListViewItem^>(x))->SubItems[_col]->Text;
	System::String^ y_t = (dynamic_cast<System::Windows::Forms::ListViewItem^>(y))->SubItems[_col]->Text;
	if(_sort/*Ascending*/)
		return Compare_s(x_t, y_t);
	else/*Descending*/
		return Compare_s(y_t, x_t);
}

//Function: compare two string; there are two cases - (can be converted into) number and string
int ListViewItemComparer::Compare_s(System::String^ s1, System::String^ s2){
	if(_is_num)
		return System::Convert::ToDouble(s1) > System::Convert::ToDouble(s2);
	return System::String::Compare(s1, s2);
}
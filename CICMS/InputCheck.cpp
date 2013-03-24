/*************************************************************************************************/
//
//  class InputCheck: inputCheck.cpp
//
//  Description: Input Checking only.
//
//  API:
//	*** check whether a string is number or not ***
//  static bool is_number(System::String^);
//	*** check whether a string is less than zero or not ***
//	static bool lessThan_zero(System::String^);
//	*** check whether a string is empty or not ***
//	static bool is_empty(System::String^);
//	*** check whether a number, represented by a string, is large (>100) or not ***
//	static bool is_large(System::String^);
//	*** check whether a string is integer or not ***
//	static bool is_int(System::String^ s);
//
//  Main authors: XIE KAI(A0102016E)
//
/*************************************************************************************************/

#include "stdafx.h"
#include "InputCheck.h"


//**************************************************
//
//Input checking
//
//Check whether a string is number or not
bool InputCheck::is_number(System::String^ s)
{
	try{
		System::Convert::ToDouble(s);
	} catch(System::FormatException^){
		return false;
	}
	return true;
}
//Check whether a number (represented in System::String) is less than 0 or not
bool InputCheck::lessThan_zero(System::String^ s)
{
	return System::Convert::ToDouble(s) <= 0;
}
//Check whether a string is empty or not
bool InputCheck::is_empty(System::String^ s)
{
	return System::String::IsNullOrWhiteSpace(s);
}
//Check whether a number (represented in System::String) is large or not
bool InputCheck::is_large(System::String^ s){
	enum {Large = 100};
	return System::Convert::ToDouble(s) > Large;
}
//Check whether a number (represented in System::String) is a float or not
bool InputCheck::is_int(System::String^ s){
	try{
		System::Convert::ToInt32(s);
	} catch(System::FormatException^){
		return false;
	}
	return true;
}
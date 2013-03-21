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
	enum {Large = 10000};
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
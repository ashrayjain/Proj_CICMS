/*************************************************************************************************/
//
//  class InputCheck: inputCheck.h
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
#ifndef _GUARD_InputCheck
#define _GUARD_InputCheck

#include "stdafx.h"

class InputCheck{
public:
	static bool is_number(System::String^);
	static bool lessThan_zero(System::String^);
	static bool is_empty(System::String^);
	static bool is_large(System::String^);
	static bool is_int(System::String^ s);
};

#endif
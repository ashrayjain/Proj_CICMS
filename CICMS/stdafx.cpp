// stdafx.cpp : source file that includes just the standard includes
// CICMS.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

bool is_number(System::String^ s){
	try{
		System::Convert::ToDouble(s);
	} catch(System::FormatException^){
		return false;
	}
	return true;
}

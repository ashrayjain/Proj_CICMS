#include "stdafx.h"

class InputCheck{
public:
	static bool is_number(System::String^);
	static bool lessThan_zero(System::String^);
	static bool is_empty(System::String^);
	static bool is_large(System::String^);
	static bool is_int(System::String^ s);
};
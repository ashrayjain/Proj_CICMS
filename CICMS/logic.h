#ifndef _LOGIC_H_
#define _LOGIC_H_

#include "stdafx.h"
#include <stdlib.h>
#include "Product.h"
#include <msclr\marshal_cppstd.h>

using namespace std;

class logic
{
public:
	logic();
	vector<Product> DB_search(string, int);
	bool DB_add(System::Windows::Forms::ListViewItem^);
	bool DB_del(System::Windows::Forms::ListViewItem^);
	bool DB_sell(System::Windows::Forms::ListViewItem^, unsigned^);
	bool DB_restock(System::Windows::Forms::ListViewItem^, unsigned^);
	Product ListToProduct(System::Windows::Forms::ListViewItem^);

private:
	vector<Product> _db;

};

#endif
/***************************************************************************************
//
//  class logic: logic.cpp
//
//  Description: logic.cpp containg the implementation of the class logic. class logic
//  provides the API for all the processing and managing of the products required by 
//  CICMS. The API provides functions like adding a new product, deleting a product,
//  processing the sale or restocking of products and finally searching for products in
//  the database.
//
//  API:
//  logic::logic()
//  logic::DB_search(string, int)
//  bool logic::DB_add(System::Windows::Forms::ListViewItem^);
//  bool logic::DB_del(System::Windows::Forms::ListViewItem^);
//  bool logic::DB_sell(System::Windows::Forms::ListViewItem^, unsigned^);
//  bool logic::DB_restock(System::Windows::Forms::ListViewItem^, unsigned^);
//
//  Main authors: ASHRAY JAIN(A0105199B)
//
****************************************************************************************/


#include "stdafx.h"
#include "logic.h"
#include <iostream>
#include <msclr\marshal_cppstd.h>

using namespace System;

logic::logic(){}

vector<Product> logic::DB_search(System::String^ search_string, int method)
{
	return vector<Product>();
}

bool logic::DB_add(System::Windows::Forms::ListViewItem^ t)
{
	return false;
}

bool logic::DB_del(System::Windows::Forms::ListViewItem^ t)
{
	return false;
}

bool logic::DB_restock(System::Windows::Forms::ListViewItem^ t, unsigned^ amt)
{
	return false;
}

bool logic::DB_sell(System::Windows::Forms::ListViewItem^ t, unsigned^ sale)
{
	return false;
}

Product logic::ListToProduct(System::Windows::Forms::ListViewItem^ t)
{
	return Product(
		msclr::interop::marshal_as<std::string>(t->SubItems[0]->Text),
		msclr::interop::marshal_as<std::string>(t->SubItems[1]->Text),
		msclr::interop::marshal_as<std::string>(t->SubItems[2]->Text),
		atoi(msclr::interop::marshal_as<std::string>(t->SubItems[3]->Text).c_str()),
		atoi(msclr::interop::marshal_as<std::string>(t->SubItems[4]->Text).c_str()),
		atoi(msclr::interop::marshal_as<std::string>(t->SubItems[5]->Text).c_str()),
		atof(msclr::interop::marshal_as<std::string>(t->SubItems[6]->Text).c_str())
		);
}

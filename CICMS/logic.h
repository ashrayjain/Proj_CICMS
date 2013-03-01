/***************************************************************************************
//
//  class logic: logic.h
//
//  Description: logic.h containg the specification of the class logic. class logic
//  provides the API for all the processing and managing of the products required by 
//  CICMS. The API provides functions like adding a new product, deleting a product,
//  processing the sale or restocking of products and finally searching for products in
//  the database.
//
//  API:
//  logic::logic()
//  vector<System::Windows::Forms::ListViewItem^> logic::DB_search(string, int)
//  bool logic::DB_add(System::Windows::Forms::ListViewItem^);
//  bool logic::DB_del(System::Windows::Forms::ListViewItem^);
//  bool logic::DB_sell(System::Windows::Forms::ListViewItem^, unsigned^);
//  bool logic::DB_restock(System::Windows::Forms::ListViewItem^, unsigned^);
//
//  Main authors: ASHRAY JAIN(A0105199B)
//
****************************************************************************************/


#ifndef _LOGIC_H_
#define _LOGIC_H_

#include "stdafx.h"
#include "Product.h"
#include <stdlib.h>
#include <msclr\marshal_cppstd.h>

using namespace std;

class logic
{
public:
	// Constructor
	logic();
	// Search and return a vector of ListViewItems
	vector<Product> DB_search(System::String^, int);
	// Add new product
	bool DB_add(System::Windows::Forms::ListViewItem^);
	// Delete a product
	bool DB_del(System::Windows::Forms::ListViewItem^);
	// Process sale of a product
	bool DB_sell(System::Windows::Forms::ListViewItem^% t, unsigned^);
	// Process restocking of a product
	bool DB_restock(System::Windows::Forms::ListViewItem^% t, unsigned^);
	// Checkes if string is a number
	static bool is_number(System::String^ s);

private:
	// Store all the products currently in the store
	vector<Product> _db;
	// Converts a ListViewItem as passed by the GUI to Product
	Product ListToProduct(System::Windows::Forms::ListViewItem^);
};

#endif
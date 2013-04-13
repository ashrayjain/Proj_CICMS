/*************************************************************************************************/
//
//  class statForm: statForm.h
//
//  Description:statForm.h contains the specification of statForm.cpp, a form that displays the statistics report
//	for the application.

//  API:
//	*** constructor ***
//	statForm(void)
//	*** set the group title ***
//  void Set_grpTitle(System::String^ s)
//	*** send in the report data ***
//	void Set_listData(array<System::Windows::Forms::ListViewItem^>^ r)
//
//  Main authors: XIE KAI(A0102016E), BOB WONG(A0094718U)
//
/*************************************************************************************************/

#ifndef _GUARD_UI_statForm
#define _GUARD_UI_statForm

#include "stdafx.h"
#include "InputCheck.h"
#include "ListViewItemComparer.h"
#include <cliext\vector>

using namespace CICMS_UI;

namespace CICMS_UI {

	/// <summary>
	/// Summary for statForm
	/// </summary>
	public ref class statForm : public System::Windows::Forms::Form
	{
	public:
		statForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~statForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  list_grp;
	protected: 
	private: System::Windows::Forms::ListView^  list_lv;
	private: System::Windows::Forms::ColumnHeader^  list_col_name;
	private: System::Windows::Forms::ColumnHeader^  list_col_category;
	private: System::Windows::Forms::ColumnHeader^  list_col_barcode;
	private: System::Windows::Forms::ColumnHeader^  list_col_price;
	private: System::Windows::Forms::ColumnHeader^  list_col_manuf;
	private: System::Windows::Forms::ColumnHeader^  list_col_stock;
	private: System::Windows::Forms::ColumnHeader^  list_col_sold;
	private: System::Windows::Forms::Button^  button1;
	private: System::Int32 list_sortColumn;
	private: bool list_sort;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void);		
	private: void statForm_KeyPress(Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: void list_lv_ColumnClick(System::Object^, System::Windows::Forms::ColumnClickEventArgs^ e);
	private: void Sort_list_lv(System::Windows::Forms::ColumnClickEventArgs^ e, bool t, bool is_num);
	public: void Set_grpTitle(System::String^ s);
	public: void Set_listData_grp(cli::array<cli::array<System::Windows::Forms::ListViewItem^>^>^ r);
	public: void Set_listData(array<System::Windows::Forms::ListViewItem^>^ r);

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void list_lv_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
};
}

#endif
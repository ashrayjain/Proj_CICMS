
/*************************************************************************************************/
//
//  class mainForm: mainForm.h
//
//  Description: mainForm.h contains the specification part of class mainForm. class mainForm is 
//  the main window for CICMS. When CICMS runs, mainForm shows. In our top-down design, mainForm 
//  is the top, exactly. It contains 5 main regions: search (s), list, menu 
//  and statusBar. Within each region, there are components, like buttons, that call/create/interact 
//  with other classes.
//
//  API:
//  CICMS_UI::mainForm::mainForm(); //create a mainForm object
//
//  Main authors: XIE KAI(A0102016E), 
//
/*************************************************************************************************/
//
//  Naming Rule for variables
//
//  for variables, we name them as follow:
//  [abbreviation for grp]_[abbreviation for type of components/its parent in menu]_[name of component]
//  E.g.
//  "list_b_delete" means a button for deletion in list group
//  "list_l_name" means a label for name in list group
////////////////////////////////////
//
//  options for [abbreviation for grp] (grp, or group/groupBox, is where the components locate)
//
//  menu;
//  list;
//  s, for search;
//  other: whatever :)
////////////////////////////////////
//
//  options for [abbreviation for type of components/its parent in menu]
//
//  f, for file;
//  b, for button;
//  tB, for textBox;
//  lv, for listview;
//  selectedList;
//  grp, for groupBox;
//  l, for label;
//  rB, for radioBox;
//  col, for column;
//  other: whatever :)
//  But if that component is in menu and it has no parent, then this part is no need
////////////////////////////////////
//
//  options for [name of component]
//
//  you decide :) be meaningful
//
/*************************************************************************************************/
//
//  Naming Rule for functions
//
//  for functions, we name them as follow:
//  [Verb]_[abbreviation for grp]_[abbreviation for kind of components/its parent in menu]_[name of component]_[Objective]
//  or
//  [Verb]_[name of component/name of class]_[Objective]
//  or
//  whatever you like :) be meaningful
//  E.g.
//  "Update_selectedList_Sell" means update all selected listItems's sold property.
//
/*************************************************************************************************/
//
//  Naming Rule for events
//
//  for event, we name them as follow:
//  [abbreviation for grp]_[abbreviation for kind of components/its parent in menu]_[name of component]_[Verb]
//  or
//  [name of component/name of class]_[Verb]
//  or
//  whatever you like :) be meaningful
//  E.g.
//  "menu_about_Click" means the event - when user clicks the about item in the menu.
//
/*************************************************************************************************/
#ifndef _GUARD_UI_mainForm
#define _GUARD_UI_mainForm

#include "Bridge.h"

namespace CICMS_UI {

	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		mainForm()
		{
			InitializeComponent();
			Bridging = new Bridge;
		}

		~mainForm(){
			delete Bridging;
		}
	//********************************************************
	//*************MEMBER FUNCTION DECLEARATION***************
	//********************************************************

	//**********MENU COMPONENTS FUNCTION***********
	private: void menu_f_addNewProducts_Click(System::Object^  sender, System::EventArgs^  e);
	private: void menu_f_quit_Click(System::Object^  sender, System::EventArgs^  e);
	private: void menu_about_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Create_addPdForms();

	//**********SEARCH COMPONENTS FUNCTION***********
	private: void s_rB_byName_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: void s_rB_byCategory_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: void s_b_submit_Click(System::Object^  sender, System::EventArgs^  e);
	private: void s_rB_byBarcode_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: int Get_byMethod();
	private: void Search_product(System::String^ s, int m);

	//**********LIST DETAILS COMPONENTS FUNCTION***********
	private: void list_b_delete_Click(System::Object^  sender, System::EventArgs^  e);
	private: void list_b_sell_Click(System::Object^  sender, System::EventArgs^  e);
	private: void list_b_restock_Click(System::Object^  sender, System::EventArgs^  e);
	private: void list_lv_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: double Create_inputForm(System::String^ formTitle, System::String^ pdDescript, System::String^ inputDescript, System::String^ stringInTB);
	private: void Create_sellForm();
	private: void Create_restockForm();
	private: void Create_deleteForm();
	private: void Clear_selectedList(int index);
	private: void list_lv_ColumnClick(System::Object^, System::Windows::Forms::ColumnClickEventArgs^ e);
	private: void Toggle_list_b(bool tof);
	private: void Sort_list_lv(System::Windows::Forms::ColumnClickEventArgs^ e, bool t, bool is_num);
	private: int Get_sBarcode(int index);
	private: System::String^ Get_sName(int index);

	//**********STATUSBAR COMPONENTS FUNCTION***********
	void Update_statusBar(int i);
	void Set_statusBar(System::String^ s, System::Drawing::Color c);

	//**********OTHER COMPONENTS FUNCTION***********
	private: System::Windows::Forms::DialogResult Create_messageBox(System::String^ typeMB, System::String^ s);
	private: void InitializeComponent();

	//********************************************************
	//*****************PROPERTIES DECLEARATION****************
	//********************************************************

	//**********MENU COMPONENTS DECLEARATION***********
	private: System::Windows::Forms::MenuStrip^  menu;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_f;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_f_quit;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_about;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_f_addNewProducts;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog;

	//**********SEARCH COMPONENTS DECLEARATION***********
	private: System::Windows::Forms::TextBox^  s_tB_input;
	private: System::Windows::Forms::Button^  s_b_submit;
	private: System::Windows::Forms::GroupBox^  s_grp;
	private: System::Windows::Forms::Label^  s_l_by;
	private: System::Windows::Forms::RadioButton^  s_rB_byCategory;
	private: System::Windows::Forms::RadioButton^  s_rB_byBarcode;
	private: System::Windows::Forms::RadioButton^  s_rB_byName;

	//**********LIST COMPONENTS DECLEARATION***********
	private: System::Windows::Forms::ListView^  list_lv;
	private: System::Windows::Forms::ColumnHeader^  list_col_name;
	private: System::Windows::Forms::ColumnHeader^  list_col_category;
	private: System::Windows::Forms::ColumnHeader^  list_col_barcode;
	private: System::Windows::Forms::ColumnHeader^  list_col_price;
	private: System::Windows::Forms::ColumnHeader^  list_col_manuf;
	private: System::Windows::Forms::ColumnHeader^  list_col_stock;
	private: System::Windows::Forms::ColumnHeader^  list_col_sold;
	private: System::Windows::Forms::GroupBox^  list_grp;
	private: System::Windows::Forms::Button^  list_b_delete;
	private: System::Windows::Forms::Button^  list_b_sell;
	private: System::Windows::Forms::Button^  list_b_restock;
	private: System::Int32 list_sortColumn;
	private: bool list_sort;

	//**********STATUS COMPONENTS DECLEARATION***********
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_stat;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_stat_genStat;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_stat_BSpd;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_stat_BSmanu;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_stat_top10pd;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	//**********BRIDGE HANDLER DECLEARATION***********
	private: Bridge *Bridging;
};
}
#endif
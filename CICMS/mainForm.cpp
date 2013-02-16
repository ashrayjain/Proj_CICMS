/*************************************************************************************************/
//
//  class mainForm: mainForm.cpp
//
//  Description: mainForm.h contains the implementation part of class mainForm.
//
//  API:
//  CICMS_UI::mainForm::mainForm(); //create a mainForm class
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
//  "pd_b_delete" means a button for deletion in ProductDetails group
//  "pd_l_name" means a label for name in ProductDetails group
////////////////////////////////////
//
//  options for [abbreviation for grp] (grp, or group/groupBox, is where the components locate)
//
//  menu;
//  pd, for product details;
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
//  "Update_pd_tB" means update all textBox components in product details group.
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

#include "stdafx.h"
#include "mainForm.h"
#include "inputForm.h"
#include "addPdForm.h"

using namespace CICMS_UI;

//********************************************************
//*************                            ***************
//*************MEMBER FUNCTION DECLEARATION***************
//*************                            ***************
//********************************************************

//Initialize the components & set their properties; run at startup of class mainForm
void mainForm::InitializeComponent()
{
	//************MENU COMPONENTS INITIALIZATION***************
	this->menu = (gcnew System::Windows::Forms::MenuStrip());
	this->menu_f = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_f_addANewProduct = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_f_loadProductList = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_f_saveProductList = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_f_quit = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_about = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
	this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());

	//************SEARCH COMPONENTS INITIALIZATION***************
	this->s_tB_input = (gcnew System::Windows::Forms::TextBox());
	this->s_b_submit = (gcnew System::Windows::Forms::Button());
	this->s_grp = (gcnew System::Windows::Forms::GroupBox());
	this->s_l_by = (gcnew System::Windows::Forms::Label());
	this->s_rB_byCategory = (gcnew System::Windows::Forms::RadioButton());
	this->s_rB_byBarcode = (gcnew System::Windows::Forms::RadioButton());
	this->s_rB_byName = (gcnew System::Windows::Forms::RadioButton());

	//************PRODUCT DETAILS COMPONENTS INITIALIZATION***************
	this->pd_grp = (gcnew System::Windows::Forms::GroupBox());
	this->pd_tB_name = (gcnew System::Windows::Forms::TextBox());
	this->pd_b_restock = (gcnew System::Windows::Forms::Button());
	this->pd_tB_category = (gcnew System::Windows::Forms::TextBox());
	this->pd_b_sell = (gcnew System::Windows::Forms::Button());
	this->pd_tB_barcode = (gcnew System::Windows::Forms::TextBox());
	this->pd_tB_price = (gcnew System::Windows::Forms::TextBox());
	this->pd_b_delete = (gcnew System::Windows::Forms::Button());
	this->pd_tB_manuf = (gcnew System::Windows::Forms::TextBox());
	this->pd_tB_stock = (gcnew System::Windows::Forms::TextBox());
	this->pd_tB_sold = (gcnew System::Windows::Forms::TextBox());
	this->pd_l_sold = (gcnew System::Windows::Forms::Label());
	this->pd_l_stock = (gcnew System::Windows::Forms::Label());
	this->pd_l_price = (gcnew System::Windows::Forms::Label());
	this->pd_l_manuf = (gcnew System::Windows::Forms::Label());
	this->pd_l_category = (gcnew System::Windows::Forms::Label());
	this->pd_l_barcode = (gcnew System::Windows::Forms::Label());
	this->pd_l_name = (gcnew System::Windows::Forms::Label());

	//************LIST COMPONENTS INITIALIZATION***************
	this->list_lv = (gcnew System::Windows::Forms::ListView());
	this->list_col_name = (gcnew System::Windows::Forms::ColumnHeader());
	this->list_col_category = (gcnew System::Windows::Forms::ColumnHeader());
	this->list_col_barcode = (gcnew System::Windows::Forms::ColumnHeader());
	this->list_col_price = (gcnew System::Windows::Forms::ColumnHeader());
	this->list_col_manuf = (gcnew System::Windows::Forms::ColumnHeader());
	this->list_col_stock = (gcnew System::Windows::Forms::ColumnHeader());
	this->list_col_sold = (gcnew System::Windows::Forms::ColumnHeader());
	this->list_grp = (gcnew System::Windows::Forms::GroupBox());

	//************STATUS COMPONENTS INITIALIZATION***************
	this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
	this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());

	
	//*********************************************
	//************COMPONENTS SETTING***************
	//*********************************************
	//
	// menu
	// 
	this->menu->SuspendLayout();
	this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->menu_f, this->menu_about});
	this->menu->Location = System::Drawing::Point(0, 0);
	this->menu->Name = L"menu";
	this->menu->Size = System::Drawing::Size(853, 24);
	this->menu->TabIndex = 0;
	this->menu->Text = L"menu";
	// 
	// menu_f
	// 
	this->menu_f->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->menu_f_addANewProduct, 
		this->menu_f_loadProductList, this->menu_f_saveProductList, this->menu_f_quit});
	this->menu_f->Name = L"menu_f";
	this->menu_f->Size = System::Drawing::Size(37, 20);
	this->menu_f->Text = L"File";
	// 
	// menu_f_addANewProduct
	// 
	this->menu_f_addANewProduct->Name = L"menu_f_addANewProduct";
	this->menu_f_addANewProduct->Size = System::Drawing::Size(170, 22);
	this->menu_f_addANewProduct->Text = L"Add a new product";
	this->menu_f_addANewProduct->Click += gcnew System::EventHandler(this, &mainForm::menu_f_addANewProduct_Click);
	// 
	// menu_f_loadProductList
	// 
	this->menu_f_loadProductList->Name = L"menu_f_loadProductList";
	this->menu_f_loadProductList->Size = System::Drawing::Size(170, 22);
	this->menu_f_loadProductList->Text = L"Load product list";
	this->menu_f_loadProductList->Click += gcnew System::EventHandler(this, &mainForm::menu_f_loadProductList_Click);
	// 
	// menu_f_saveProductList
	// 
	this->menu_f_saveProductList->Name = L"menu_f_saveProductList";
	this->menu_f_saveProductList->Size = System::Drawing::Size(170, 22);
	this->menu_f_saveProductList->Text = L"Save product list";
	this->menu_f_saveProductList->Click += gcnew System::EventHandler(this, &mainForm::menu_f_saveProductList_Click);
	// 
	// menu_f_quit
	// 
	this->menu_f_quit->Name = L"menu_f_quit";
	this->menu_f_quit->Size = System::Drawing::Size(170, 22);
	this->menu_f_quit->Text = L"Quit";
	this->menu_f_quit->Click += gcnew System::EventHandler(this, &mainForm::menu_f_quit_Click);
	// 
	// menu_about
	// 
	this->menu_about->Name = L"menu_about";
	this->menu_about->Size = System::Drawing::Size(50, 20);
	this->menu_about->Text = L"About";
	this->menu_about->Click += gcnew System::EventHandler(this, &mainForm::menu_about_Click);
	// 
	// openFileDialog
	// 
	this->openFileDialog->AutoUpgradeEnabled = false;
	this->openFileDialog->FileName = L"Data.CICMS";
	this->openFileDialog->InitialDirectory = L"c:\\";
	// 
	// saveFileDialog
	// 
	this->saveFileDialog->AutoUpgradeEnabled = false;
	this->saveFileDialog->InitialDirectory = L"c:\\";
	// 
	// s_tB_input
	// 
	this->s_tB_input->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
		static_cast<System::Byte>(134)));
	this->s_tB_input->Location = System::Drawing::Point(6, 23);
	this->s_tB_input->Name = L"s_tB_input";
	this->s_tB_input->Size = System::Drawing::Size(172, 24);
	this->s_tB_input->TabIndex = 1;
	this->s_tB_input->Text = L" input here";
	// 
	// s_b_submit
	// 
	this->s_b_submit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
		static_cast<System::Byte>(134)));
	this->s_b_submit->Location = System::Drawing::Point(184, 23);
	this->s_b_submit->Name = L"s_b_submit";
	this->s_b_submit->Size = System::Drawing::Size(57, 24);
	this->s_b_submit->TabIndex = 2;
	this->s_b_submit->Text = L"Go";
	this->s_b_submit->UseVisualStyleBackColor = true;
	// 
	// s_grp
	// 
	this->s_grp->SuspendLayout();
	this->s_grp->Controls->Add(this->s_l_by);
	this->s_grp->Controls->Add(this->s_rB_byCategory);
	this->s_grp->Controls->Add(this->s_rB_byBarcode);
	this->s_grp->Controls->Add(this->s_rB_byName);
	this->s_grp->Controls->Add(this->s_tB_input);
	this->s_grp->Controls->Add(this->s_b_submit);
	this->s_grp->Location = System::Drawing::Point(16, 27);
	this->s_grp->Name = L"s_grp";
	this->s_grp->Size = System::Drawing::Size(247, 80);
	this->s_grp->TabIndex = 3;
	this->s_grp->TabStop = false;
	this->s_grp->Text = L"Search";
	// 
	// s_l_by
	// 
	this->s_l_by->AutoSize = true;
	this->s_l_by->Location = System::Drawing::Point(7, 54);
	this->s_l_by->Name = L"s_l_by";
	this->s_l_by->Size = System::Drawing::Size(19, 13);
	this->s_l_by->TabIndex = 6;
	this->s_l_by->Text = L"By";
	// 
	// s_rB_byCategory
	// 
	this->s_rB_byCategory->AutoSize = true;
	this->s_rB_byCategory->Location = System::Drawing::Point(152, 53);
	this->s_rB_byCategory->Name = L"s_rB_byCategory";
	this->s_rB_byCategory->Size = System::Drawing::Size(64, 17);
	this->s_rB_byCategory->TabIndex = 5;
	this->s_rB_byCategory->TabStop = true;
	this->s_rB_byCategory->Text = L"Category";
	this->s_rB_byCategory->UseVisualStyleBackColor = true;
	// 
	// s_rB_byBarcode
	// 
	this->s_rB_byBarcode->AutoSize = true;
	this->s_rB_byBarcode->Location = System::Drawing::Point(87, 53);
	this->s_rB_byBarcode->Name = L"s_rB_byBarcode";
	this->s_rB_byBarcode->Size = System::Drawing::Size(62, 17);
	this->s_rB_byBarcode->TabIndex = 4;
	this->s_rB_byBarcode->TabStop = true;
	this->s_rB_byBarcode->Text = L"Barcode";
	this->s_rB_byBarcode->UseVisualStyleBackColor = true;
	// 
	// s_rB_byName
	// 
	this->s_rB_byName->AutoSize = true;
	this->s_rB_byName->Checked = true;
	this->s_rB_byName->Location = System::Drawing::Point(31, 53);
	this->s_rB_byName->Name = L"s_rB_byName";
	this->s_rB_byName->Size = System::Drawing::Size(50, 17);
	this->s_rB_byName->TabIndex = 3;
	this->s_rB_byName->TabStop = true;
	this->s_rB_byName->Text = L"Name";
	this->s_rB_byName->UseVisualStyleBackColor = true;
	// 
	// pd_grp
	// 
	this->pd_grp->SuspendLayout();
	this->pd_grp->Controls->Add(this->pd_tB_name);
	this->pd_grp->Controls->Add(this->pd_b_restock);
	this->pd_grp->Controls->Add(this->pd_tB_category);
	this->pd_grp->Controls->Add(this->pd_b_sell);
	this->pd_grp->Controls->Add(this->pd_tB_barcode);
	this->pd_grp->Controls->Add(this->pd_tB_price);
	this->pd_grp->Controls->Add(this->pd_b_delete);
	this->pd_grp->Controls->Add(this->pd_tB_manuf);
	this->pd_grp->Controls->Add(this->pd_tB_stock);
	this->pd_grp->Controls->Add(this->pd_tB_sold);
	this->pd_grp->Controls->Add(this->pd_l_sold);
	this->pd_grp->Controls->Add(this->pd_l_stock);
	this->pd_grp->Controls->Add(this->pd_l_price);
	this->pd_grp->Controls->Add(this->pd_l_manuf);
	this->pd_grp->Controls->Add(this->pd_l_category);
	this->pd_grp->Controls->Add(this->pd_l_barcode);
	this->pd_grp->Controls->Add(this->pd_l_name);
	this->pd_grp->Location = System::Drawing::Point(16, 119);
	this->pd_grp->Name = L"pd_grp";
	this->pd_grp->Size = System::Drawing::Size(247, 251);
	this->pd_grp->TabIndex = 4;
	this->pd_grp->TabStop = false;
	this->pd_grp->Text = L"Product details";
	// 
	// pd_tB_name
	// 
	this->pd_tB_name->Location = System::Drawing::Point(88, 24);
	this->pd_tB_name->Name = L"pd_tB_name";
	this->pd_tB_name->ReadOnly = true;
	this->pd_tB_name->Size = System::Drawing::Size(138, 20);
	this->pd_tB_name->TabIndex = 5;
	// 
	// pd_b_restock
	// 
	this->pd_b_restock->Enabled = false;
	this->pd_b_restock->Location = System::Drawing::Point(88, 214);
	this->pd_b_restock->Name = L"pd_b_restock";
	this->pd_b_restock->Size = System::Drawing::Size(75, 23);
	this->pd_b_restock->TabIndex = 8;
	this->pd_b_restock->Text = L"Restock";
	this->pd_b_restock->UseVisualStyleBackColor = true;
	this->pd_b_restock->Click += gcnew System::EventHandler(this, &mainForm::pd_b_restock_Click);
	// 
	// pd_tB_category
	// 
	this->pd_tB_category->Location = System::Drawing::Point(87, 50);
	this->pd_tB_category->Name = L"pd_tB_category";
	this->pd_tB_category->ReadOnly = true;
	this->pd_tB_category->Size = System::Drawing::Size(138, 20);
	this->pd_tB_category->TabIndex = 6;
	// 
	// pd_b_sell
	// 
	this->pd_b_sell->Enabled = false;
	this->pd_b_sell->Location = System::Drawing::Point(10, 214);
	this->pd_b_sell->Name = L"pd_b_sell";
	this->pd_b_sell->Size = System::Drawing::Size(75, 23);
	this->pd_b_sell->TabIndex = 7;
	this->pd_b_sell->Text = L"Sell";
	this->pd_b_sell->UseVisualStyleBackColor = true;
	this->pd_b_sell->Click += gcnew System::EventHandler(this, &mainForm::pd_b_sell_Click);
	// 
	// pd_tB_barcode
	// 
	this->pd_tB_barcode->Location = System::Drawing::Point(87, 76);
	this->pd_tB_barcode->Name = L"pd_tB_barcode";
	this->pd_tB_barcode->ReadOnly = true;
	this->pd_tB_barcode->Size = System::Drawing::Size(138, 20);
	this->pd_tB_barcode->TabIndex = 7;
	// 
	// pd_tB_price
	// 
	this->pd_tB_price->Location = System::Drawing::Point(87, 102);
	this->pd_tB_price->Name = L"pd_tB_price";
	this->pd_tB_price->ReadOnly = true;
	this->pd_tB_price->Size = System::Drawing::Size(138, 20);
	this->pd_tB_price->TabIndex = 8;
	// 
	// pd_b_delete
	// 
	this->pd_b_delete->Enabled = false;
	this->pd_b_delete->Location = System::Drawing::Point(166, 214);
	this->pd_b_delete->Name = L"pd_b_delete";
	this->pd_b_delete->Size = System::Drawing::Size(75, 23);
	this->pd_b_delete->TabIndex = 6;
	this->pd_b_delete->Text = L"Delete";
	this->pd_b_delete->UseVisualStyleBackColor = true;
	this->pd_b_delete->Click += gcnew System::EventHandler(this, &mainForm::pd_b_delete_Click);
	// 
	// pd_tB_manuf
	// 
	this->pd_tB_manuf->Location = System::Drawing::Point(87, 128);
	this->pd_tB_manuf->Name = L"pd_tB_manuf";
	this->pd_tB_manuf->ReadOnly = true;
	this->pd_tB_manuf->Size = System::Drawing::Size(138, 20);
	this->pd_tB_manuf->TabIndex = 9;
	// 
	// pd_tB_stock
	// 
	this->pd_tB_stock->Location = System::Drawing::Point(87, 154);
	this->pd_tB_stock->Name = L"pd_tB_stock";
	this->pd_tB_stock->ReadOnly = true;
	this->pd_tB_stock->Size = System::Drawing::Size(138, 20);
	this->pd_tB_stock->TabIndex = 10;
	// 
	// pd_tB_sold
	// 
	this->pd_tB_sold->Location = System::Drawing::Point(87, 180);
	this->pd_tB_sold->Name = L"pd_tB_sold";
	this->pd_tB_sold->ReadOnly = true;
	this->pd_tB_sold->Size = System::Drawing::Size(138, 20);
	this->pd_tB_sold->TabIndex = 11;
	// 
	// pd_l_sold
	// 
	this->pd_l_sold->AutoSize = true;
	this->pd_l_sold->Location = System::Drawing::Point(11, 183);
	this->pd_l_sold->Name = L"pd_l_sold";
	this->pd_l_sold->Size = System::Drawing::Size(28, 13);
	this->pd_l_sold->TabIndex = 6;
	this->pd_l_sold->Text = L"Sold";
	// 
	// pd_l_stock
	// 
	this->pd_l_stock->AutoSize = true;
	this->pd_l_stock->Location = System::Drawing::Point(11, 157);
	this->pd_l_stock->Name = L"pd_l_stock";
	this->pd_l_stock->Size = System::Drawing::Size(35, 13);
	this->pd_l_stock->TabIndex = 5;
	this->pd_l_stock->Text = L"Stock";
	// 
	// pd_l_price
	// 
	this->pd_l_price->AutoSize = true;
	this->pd_l_price->Location = System::Drawing::Point(11, 105);
	this->pd_l_price->Name = L"pd_l_price";
	this->pd_l_price->Size = System::Drawing::Size(31, 13);
	this->pd_l_price->TabIndex = 4;
	this->pd_l_price->Text = L"Price";
	// 
	// pd_l_manuf
	// 
	this->pd_l_manuf->AutoSize = true;
	this->pd_l_manuf->Location = System::Drawing::Point(11, 131);
	this->pd_l_manuf->Name = L"pd_l_manuf";
	this->pd_l_manuf->Size = System::Drawing::Size(70, 13);
	this->pd_l_manuf->TabIndex = 3;
	this->pd_l_manuf->Text = L"Manufacturer";
	// 
	// pd_l_category
	// 
	this->pd_l_category->AutoSize = true;
	this->pd_l_category->Location = System::Drawing::Point(11, 53);
	this->pd_l_category->Name = L"pd_l_category";
	this->pd_l_category->Size = System::Drawing::Size(49, 13);
	this->pd_l_category->TabIndex = 2;
	this->pd_l_category->Text = L"Category";
	// 
	// pd_l_barcode
	// 
	this->pd_l_barcode->AutoSize = true;
	this->pd_l_barcode->Location = System::Drawing::Point(11, 79);
	this->pd_l_barcode->Name = L"pd_l_barcode";
	this->pd_l_barcode->Size = System::Drawing::Size(47, 13);
	this->pd_l_barcode->TabIndex = 1;
	this->pd_l_barcode->Text = L"Barcode";
	// 
	// pd_l_name
	// 
	this->pd_l_name->AutoSize = true;
	this->pd_l_name->Location = System::Drawing::Point(11, 27);
	this->pd_l_name->Name = L"pd_l_name";
	this->pd_l_name->Size = System::Drawing::Size(35, 13);
	this->pd_l_name->TabIndex = 0;
	this->pd_l_name->Text = L"Name";
	// 
	// list_lv
	// 
	this->list_lv->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(7) {this->list_col_name, this->list_col_category, 
		this->list_col_barcode, this->list_col_price, this->list_col_manuf, this->list_col_stock, this->list_col_sold});
	this->list_lv->FullRowSelect = true;
	this->list_lv->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
	System::Windows::Forms::ListViewItem^  listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(7) {L"hm_name", 
		L"bag", L"000021", L"31", L"H&M", L"31", L"5"}, -1));
	System::Windows::Forms::ListViewItem^  listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(7) {L"jj_test", 
		L"jeans", L"00044", L"5", L"jj", L"25", L"21"}, -1));
	this->list_lv->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(2) {listViewItem1, listViewItem2});
	this->list_lv->Location = System::Drawing::Point(11, 23);
	this->list_lv->MultiSelect = false;
	this->list_lv->Name = L"list_lv";
	this->list_lv->ShowGroups = false;
	this->list_lv->Size = System::Drawing::Size(539, 306);
	this->list_lv->TabIndex = 9;
	this->list_lv->UseCompatibleStateImageBehavior = false;
	this->list_lv->View = System::Windows::Forms::View::Details;
	this->list_lv->SelectedIndexChanged += gcnew System::EventHandler(this, &mainForm::list_lv_SelectedIndexChanged);
	// 
	// list_col_name
	// 
	this->list_col_name->Text = L"Name";
	this->list_col_name->Width = 92;
	// 
	// list_col_category
	// 
	this->list_col_category->Text = L"Category";
	this->list_col_category->Width = 89;
	// 
	// list_col_barcode
	// 
	this->list_col_barcode->Text = L"Barcode";
	this->list_col_barcode->Width = 86;
	// 
	// list_col_price
	// 
	this->list_col_price->Text = L"Price";
	this->list_col_price->Width = 47;
	// 
	// list_col_manuf
	// 
	this->list_col_manuf->Text = L"Manufacturer";
	this->list_col_manuf->Width = 82;
	// 
	// list_col_stock
	// 
	this->list_col_stock->Text = L"Stock";
	// 
	// list_col_sold
	// 
	this->list_col_sold->Text = L"Sold";
	// 
	// list_grp
	// 
	this->list_grp->SuspendLayout();
	this->list_grp->Controls->Add(this->list_lv);
	this->list_grp->Location = System::Drawing::Point(277, 27);
	this->list_grp->Name = L"list_grp";
	this->list_grp->Size = System::Drawing::Size(561, 343);
	this->list_grp->TabIndex = 11;
	this->list_grp->TabStop = false;
	this->list_grp->Text = L"Result list";
	// 
	// statusStrip1
	// 
	this->statusStrip1->SuspendLayout();
	this->statusStrip1->BackColor = System::Drawing::Color::LightSkyBlue;
	this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
	this->statusStrip1->Location = System::Drawing::Point(0, 378);
	this->statusStrip1->Name = L"statusStrip1";
	this->statusStrip1->Size = System::Drawing::Size(853, 22);
	this->statusStrip1->SizingGrip = false;
	this->statusStrip1->TabIndex = 12;
	this->statusStrip1->Text = L"statusStrip";
	// 
	// toolStripStatusLabel1
	// 
	this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
	this->toolStripStatusLabel1->Size = System::Drawing::Size(39, 17);
	this->toolStripStatusLabel1->Text = L"Ready";
	// 
	// mainForm
	// 
	this->SuspendLayout();
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(853, 400);
	this->Controls->Add(this->statusStrip1);
	this->Controls->Add(this->list_grp);
	this->Controls->Add(this->pd_grp);
	this->Controls->Add(this->s_grp);
	this->Controls->Add(this->menu);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
	this->MainMenuStrip = this->menu;
	this->MaximizeBox = false;
	this->Name = L"mainForm";
	this->Text = L"CICMS";
	this->menu->ResumeLayout(false);
	this->menu->PerformLayout();
	this->s_grp->ResumeLayout(false);
	this->s_grp->PerformLayout();
	this->pd_grp->ResumeLayout(false);
	this->pd_grp->PerformLayout();
	this->list_grp->ResumeLayout(false);
	this->statusStrip1->ResumeLayout(false);
	this->statusStrip1->PerformLayout();
	this->ResumeLayout(false);
	this->PerformLayout();
}

//*********************************************
//**********MENU COMPONENTS FUNCTION***********
//*********************************************

//Event: when click menu_f_quit item, close the mainForm window
void mainForm::menu_f_quit_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
//Event: when click menu_f_addANewProduct item, open the addPdForm window to add a new product
void mainForm::menu_f_addANewProduct_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Create_addPdForm();
}
//Event: when click menu_f_loadProductList item, open the openFileDialog window to load data
void mainForm::menu_f_loadProductList_Click(System::Object^  sender, System::EventArgs^  e) {
	this->openFileDialog->ShowDialog();//test only
	if( false /*(stream = openFileDialog->ShowDialog()) != nullptr*/){
		//handle stream here
		this->Update_statusBar("loadS");
	}
	else
		this->Update_statusBar("loadF");
	//handle the stream
}
//Event: when click menu_f_saveProductList item, open the saveFileDialog window to save data
void mainForm::menu_f_saveProductList_Click(System::Object^  sender, System::EventArgs^  e) {
	this->saveFileDialog->ShowDialog();//test only
	if( false /*(stream = saveFileDialog->ShowDialog()) != nullptr*/){
		//handle stream here
		this->Update_statusBar("saveS");
	}
	else
		this->Update_statusBar("saveF");
}
//Event: when click menu_about item, open a messageBox that contains our team's description
void mainForm::menu_about_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Create_messageBox("about");
}
//Fuction: create a addPdForm window, and let logic/handler part handle the input
void mainForm::Create_addPdForm(){
	addPdForm^ dlg = gcnew addPdForm();
	dlg->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
	if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK){
		if( false /*handler.DB_add(dlg->get_product_details());*/ ){
			this->list_lv->Items->Add(dlg->get_product_details());
			this->Update_statusBar("addS");
		}
		else
			this->Update_statusBar("addF");
		//no need to add an item into the list; 'cause the list will only show the result of search
	}
}

//********************************************************
//**********PRODUCT DETAILS COMPONENTS FUNCTION***********
//********************************************************

//Event: when click pd_b_sell button, open an inputForm window for input sale data
void mainForm::pd_b_sell_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Create_inputForm(" Sell a product", "Sell:");
}
//Event: when click pd_b_restock button, open an inputForm window for input restock data
void mainForm::pd_b_restock_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Create_inputForm(" Restock a product", "Restock:");
}
//Event: when click pd_b_delete button, open a msgBox to check whether delete the selectedItem or not
void mainForm::pd_b_delete_Click(System::Object^  sender, System::EventArgs^  e) {
	if(this->Create_messageBox("delete") == System::Windows::Forms::DialogResult::Yes){
		if( false /*Handler.DB_update(pd_tB_barcode->Text, "delete")*/){
			this->Clear_pd_tB();
			this->Clear_selectedList();
			this->Update_statusBar("deleteS");
			this->Toggle_pd_b(false);
		}
		else
			this->Update_statusBar("deleteF");
	}
}
//Function: create an inputForm for input; used by pd_b_sell_Click & pd_b_restock_Click events.
void mainForm::Create_inputForm(System::String^ formTitle, System::String^ inputDescrip){
	inputForm^ dlg = gcnew inputForm(formTitle, inputDescrip);
	dlg->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
	if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK){
		if(formTitle->Contains("Sell")){
			if( false /*int stock = handler.DB_sell(pd_tB_barcode->Text, dlg->getInput())*/){
				//Update_pd_tB_Sell(stock);
				//Update_selectedList_Sell(stock);
				this->Update_statusBar("sellS");
			}
			else{
				this->Update_statusBar("sellF");
			}
		}
		else if(formTitle->Contains("Restock")){
			if( false /*int stock = handler.DB_restock(pd_tB_barcode->Text, dlg->getInput())*/){
				//Update_pd_tB_Restock(stock);
				//Update_selectedList_Restock(stock);
				this->Update_statusBar("restockS");
			}
			else{
				this->Update_statusBar("restockF");
			}
		}
	}
}
//Function: update all pd_tb textBoxes by using a listViewItem
void mainForm::Update_pd_tB(System::Windows::Forms::ListViewItem^ item){
	for(int i = 0, j = 0; i < this->pd_grp->Controls->Count && j < item->SubItems->Count; i++)
		if( this->pd_grp->Controls[i]->GetType()->ToString() == "System.Windows.Forms.TextBox")
			this->pd_grp->Controls[i]->Text = item->SubItems[j++]->Text;
}
//Function: clear all pd_tb textBoxes
void mainForm::Clear_pd_tB(){
	for(int i = 0; i < this->pd_grp->Controls->Count; i++)
		if( this->pd_grp->Controls[i]->GetType()->ToString() == "System.Windows.Forms.TextBox")
			this->pd_grp->Controls[i]->Text = "";
}
//Function: update pd_tB_sold & pd_tB_stock textBoxes, after sell certain number of products
void mainForm::Update_pd_tB_Sell(int stock){
	int sold = System::Int32::Parse(this->pd_tB_stock->Text) - stock + System::Int32::Parse(this->pd_tB_sold->Text);
	this->pd_tB_sold->Text = System::Convert::ToString(sold);
	this->pd_tB_stock->Text = System::Convert::ToString(stock);
}
//Function: update pd_tB_sold & pd_tB_stock textBoxes, after restock certain number of products
void mainForm::Update_pd_tB_Restock(int stock){
	this->pd_tB_stock->Text = System::Convert::ToString(stock);
}
//Function: toggle 'enabled' properties for pd_b_delete, pd_b_sell, pd_b_restock buttons
void mainForm::Toggle_pd_b(bool tof){
	this->pd_b_delete->Enabled = tof;
	this->pd_b_sell->Enabled = tof;
	this->pd_b_restock->Enabled = tof;
}

//*****************************************************
//**********LIST DETAILS COMPONENTS FUNCTION***********
//*****************************************************

//Event: when select an item in the list, update all pd_tB textBoxes by using this item's properties.
void mainForm::list_lv_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if(this->list_lv->SelectedItems->Count != 0){// must ensure there is at least one selectedItem 
		this->Toggle_pd_b(true);
		this->Update_pd_tB(this->list_lv->SelectedItems[0]);
	}
}
//Function: clear the selected item in the list
void mainForm::Clear_selectedList(){
	if( this->list_lv->SelectedItems->Count != 0)
		this->list_lv->SelectedItems[0]->Remove();
}
//Function: update selected item in the list, after sell certain number of products
void mainForm::Update_selectedList_Sell(int stock){
	if( this->list_lv->SelectedItems->Count != 0 ){
		int sold = 
			System::Int32::Parse(this->list_lv->SelectedItems[0]->SubItems[5]->Text)/*old restock*/ - stock + System::Int32::Parse(this->list_lv->SelectedItems[0]->SubItems[6]->Text)/*old sold*/;
		this->list_lv->SelectedItems[0]->SubItems[5]->Text/*restock*/ = System::Convert::ToString(stock);
		this->list_lv->SelectedItems[0]->SubItems[6]->Text/*sold*/ = System::Convert::ToString(sold);
	}
}
//Function: update selected item in the list, after restock certain number of products
void mainForm::Update_selectedList_Restock(int stock){
	if( this->list_lv->SelectedItems->Count != 0 )
		this->list_lv->SelectedItems[0]->SubItems[5]->Text = System::Convert::ToString(stock);
}

//**************************************************
//**********STATUSBAR COMPONENTS FUNCTION***********
//**************************************************

//Function: update statusBar's Text and BackColor
void mainForm::Update_statusBar(System::String^ s){
	//can improve
	if( s == "addS" )
		this->Set_statusBar("Product added successfully", System::Drawing::Color::LightSkyBlue);
	else if( s == "addF" )
		this->Set_statusBar("Product added unsuccessfully", System::Drawing::Color::RosyBrown);

	else if( s == "sellS" )
		this->Set_statusBar("Product sold successfully", System::Drawing::Color::LightSkyBlue);
	else if( s == "sellF" )
		this->Set_statusBar("Product sold unsuccessfully", System::Drawing::Color::RosyBrown);

	else if( s == "restockS" )
		this->Set_statusBar("Product restocked successfully", System::Drawing::Color::LightSkyBlue);
	else if( s == "restockF" )
		this->Set_statusBar("Product restocked unsuccessfully", System::Drawing::Color::RosyBrown);

	else if( s == "deleteS" )
		this->Set_statusBar("Product deleted successfully", System::Drawing::Color::LightSkyBlue);
	else if( s == "deleteF" )
		this->Set_statusBar("Product deleted unsuccessfully", System::Drawing::Color::RosyBrown)
		;
	else if( s == "loadS" )
		this->Set_statusBar("Loaded successfully", System::Drawing::Color::LightSkyBlue);
	else if( s == "loadF" )
		this->Set_statusBar("Loaded unsuccessfully", System::Drawing::Color::RosyBrown);

	else if( s == "saveS" )
		this->Set_statusBar("Saved successfully", System::Drawing::Color::LightSkyBlue);
	else if( s == "saveF" )
		this->Set_statusBar("Saved unsuccessfully", System::Drawing::Color::RosyBrown);
}
//Function: set statusBus's Text and BackColor
void mainForm::Set_statusBar(System::String^ s, System::Drawing::Color c){
	this->toolStripStatusLabel1->Text = s;
	this->statusStrip1->BackColor = c;
}

//**********************************************
//**********OTHER COMPONENTS FUNCTION***********
//**********************************************

//Function: create a type of msgBox according to a string (typeMB, for type for messageBox)
System::Windows::Forms::DialogResult mainForm::Create_messageBox(System::String^ typeMB){
	if(typeMB == "delete")
		return (System::Windows::Forms::MessageBox::Show("Are you sure that you would like \nto delete this product?", 
		" Delete Product",
		System::Windows::Forms::MessageBoxButtons::YesNo,
		System::Windows::Forms::MessageBoxIcon::Warning));
	//else
	return System::Windows::Forms::MessageBox::Show("Hello! Our team: Ashray, Bob, Hui and Kai!", " About");
}
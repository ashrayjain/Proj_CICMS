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

#include "stdafx.h"
#include "mainForm.h"
#include "inputForm.h"
#include "addPdForm.h"
#include "ListViewItemComparer.h"
//#include <vector>
//#include <string>

using namespace CICMS_UI;

//definitions for Update_statusBar()'s parameter
enum STATUSBAR {
	addS, addF,
	loadS, loadF,
	saveS, saveF,
	sellS, sellF,
	restockS, restockF,
	deleteS, deleteF,
	discountS, discountF,
	searchS, searchF
};

enum BYMETHOD { byName, byBarcode, byCategory, byStock, byManuf };

enum SORT_ORDER{Descending = false, Ascending = true};

//********************************************************
//*************                            ***************
//*************MEMBER FUNCTION DECLEARATION***************
//*************                            ***************
//********************************************************

//*********************************************
//**********MENU COMPONENTS FUNCTION***********
//*********************************************

//Event: when click menu_f_quit item, close the mainForm window
void mainForm::menu_f_quit_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
//Event: when click menu_f_addNewProducts item, open the addPdForm window to add new products
void mainForm::menu_f_addNewProducts_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Create_addPdForms();
}
//Event: when click menu_f_loadProductList item, open the openFileDialog window to load data
void mainForm::menu_f_loadProductList_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Create_openFileDlg();
}
//Event: when click menu_f_saveProductList item, open the saveFileDialog window to save data
void mainForm::menu_f_saveProductList_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Create_saveFileDlg();
}
//Event: when click menu_about item, open a messageBox that contains our team's description
void mainForm::menu_about_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Create_messageBox("about", "Hello! Our team: Ashray, Bob, Hui and Kai!");
}
//Fuction: create a addPdForm window, and let logic/handler part handle the input
void mainForm::Create_addPdForms(){
	int num = (int) Create_inputForm(" Add products", "How many products to add?", "Number:", "1");
	for( int i = 0; i < num; i++){
		addPdForm^ dlg = gcnew addPdForm();
		dlg->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
		if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK){
			if( false /*handler.DB_add(dlg->get_product_details());*/ )
				this->Update_statusBar(addS);
			else
				this->Update_statusBar(addF);
		}
	}
}
//Function: create an openfiledialog to handle loading data
void mainForm::Create_openFileDlg(){
	System::IO::Stream^ stm;
	if(this->openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
		if((stm = this->openFileDialog->OpenFile()) != nullptr){
			//handle stream here
			stm->Close();
			//this->Update_statusBar(loadS); /*under construction*/
			this->Update_statusBar(loadF);
		}
		else
			this->Update_statusBar(loadF);
	}
}
//Function: create an savefiledialog to handle saving data
void mainForm::Create_saveFileDlg(){
	System::IO::Stream^ stm;
	if(this->saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
		if((stm = this->saveFileDialog->OpenFile()) != nullptr){
			//handle stream here
			stm->Close();
			//this->Update_statusBar(saveS); /*under construction*/
			this->Update_statusBar(saveF);
		}
		else
			this->Update_statusBar(saveF);
	}
}

//***********************************************
//**********SEARCH COMPONENTS FUNCTION***********
//***********************************************

//Event: when s_b_submit button is clicked
void mainForm::s_b_submit_Click(System::Object^  sender, System::EventArgs^  e){
	int by_method = this->Get_byMethod();
	this->Search_product(this->s_tB_input->Text, by_method);
}
//Function: get the result of checked radioButton (by which method to search)
int mainForm::Get_byMethod(){
	if(this->s_rB_byName->Checked == true)
		return byName;
	else if(this->s_rB_byBarcode->Checked == true)
		return byBarcode;
	else if(this->s_rB_byCategory->Checked == true)
		return byCategory;
	else if(this->s_rB_stockLT->Checked == true)
		return byStock;
	else if(this->s_rB_byManuf->Checked == true)
		return byManuf;
	else
		return byName;
}
//Function: search the products according to a text and a method; if the result is non-empty, it will add an item onto the listView component
void mainForm::Search_product(System::String^ s, int m){
	//std::vector<Product> r = handler.DB_search(s, m);// may need System::String to std::string
	if(false /*!r.empty()*/){
		/*this->list_lv->Clear();
		for(int i = 0; i < r.size(); i++){
		this->list_lv->Items->Add(gcnew System::Windows::Forms::ListViewItem(gcnew cli::array<System::String^>(7) {
		gcnew System::String(r[i].getName().c_str()), 
		gcnew System::String(r[i].getCategory().c_str()), 
		gcnew System::String(r[i].getBarcode().c_str()), 
		gcnew System::String(r[i].getPrice().c_str()), 
		gcnew System::String(r[i].getManuf().c_str()), 
		gcnew System::String(r[i].getStock().c_str()), 
		gcnew System::String(r[i].getSold().c_str())
		}));
		}*/
		this->Update_statusBar(searchS);
	}
	else
		this->Update_statusBar(searchF);
}
//*****************************************************
//**********LIST DETAILS COMPONENTS FUNCTION***********
//*****************************************************

//Event: when click pd_b_sell button, open an inputForm window for input sale data
void mainForm::list_b_sell_Click(System::Object^  sender, System::EventArgs^  e) {
	Create_sellForm();
}
//Event: when click pd_b_restock button, open an inputForm window for input restock data
void mainForm::list_b_restock_Click(System::Object^  sender, System::EventArgs^  e) {
	Create_restockForm();
}
//Event: when click pd_b_discount button, open an inputForm window for input discount data
void mainForm::list_b_discount_Click(System::Object^  sender, System::EventArgs^  e) {
	Create_discountForm();
}
//Event: when click pd_b_delete button, open a msgBox to check whether delete the selectedItem or not
void mainForm::list_b_delete_Click(System::Object^  sender, System::EventArgs^  e) {
	Create_deleteForm();
}
//Function: create an inputForm for input; used by pd_b_sell_Click & pd_b_restock_Click events.
double mainForm::Create_inputForm(System::String^ formTitle, System::String^ pdDescript, System::String^ inputDescript, System::String^ stringInTB){
	inputForm^ dlg = gcnew inputForm();
	dlg->set_inputForm(formTitle, pdDescript, inputDescript, stringInTB);
	dlg->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
	if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		return dlg->get_input();
	else
		return 0;
}
void mainForm::Create_sellForm(){
	for(int i = 0; i < this->list_lv->SelectedItems->Count; i++){
		int num = (int) this->Create_inputForm(" Sell a product", this->Get_sName(i) + " - " + this->Get_sBarcode(i), "Sell:", "1"),
			barcode = this->Get_sBarcode(i);
		//int sold = handler.DB_sell(barcode, num),
		//stock = handler.DB_restock(barcode, -num);
		if(false/*sold != -1 || stock != -1*/){
			//Update_selectedList_Sell(i,sold);
			//Update_selectedList_Restock(i,stock);
			this->Update_statusBar(sellS);
		}
		else
			this->Update_statusBar(sellF);
	}
}
void mainForm::Create_restockForm(){
	for(int i = 0; i < this->list_lv->SelectedItems->Count; i++){
		int num = (int) this->Create_inputForm(" Restock a product", this->Get_sName(i) + " - " + this->Get_sBarcode(i), "Restock:", "1"),
			barcode = this->Get_sBarcode(i);
		//int stock = handler.DB_restock(barcode, num));
		//Update_selectedList_Restock(i,stock);
		//this->Update_statusBar(restockS);
		this->Update_statusBar(restockF);
	}
}
void mainForm::Create_discountForm(){
	for(int i = 0; i < this->list_lv->SelectedItems->Count; i++){
		double num = this->Create_inputForm(" Discount a price", this->Get_sName(i) + " - " + this->Get_sBarcode(i),"Discount:", "0.9");
		num = num <= 0? 1: num;//filter inappropriate discount

		int	barcode = this->Get_sBarcode(i);
		//double price = handler.DB_discount(barcode, num);
		//this->Update_statusBar(discountS);
		this->Update_statusBar(discountF);
	}
}
void mainForm::Create_deleteForm(){
	enum { No_plsDont, Yes_deleteThem, tooMany = 3};
	int deteleAllSelectedItem = No_plsDont;

	if(this->list_lv->SelectedItems->Count > tooMany &&
		this->Create_messageBox("delete", "Are you sure that you would like \nto delete all the selected products?"
		) == System::Windows::Forms::DialogResult::Yes)
		deteleAllSelectedItem = Yes_deleteThem;
	for(int i = 0; i < this->list_lv->SelectedItems->Count; i++){
		if(deteleAllSelectedItem || this->Create_messageBox("delete", 
			"Are you sure that you would like \nto delete this product, " +
			this->Get_sName(i) + " - " + 
			this->Get_sBarcode(i) +
			"?"
			) == System::Windows::Forms::DialogResult::Yes){
				int barcode = this->Get_sBarcode(i);
				/*Handler.DB_delete(barcode)*/
				this->Clear_selectedList(i--);//if delete an item, selectedItems->Count will decrease, index will change as well
		}
	}
	this->Toggle_list_b(false);
	//this->Update_statusBar(deleteS);
	this->Update_statusBar(deleteF);
}
//Function: toggle 'enabled' properties for pd_b_delete, pd_b_sell, pd_b_restock buttons
void mainForm::Toggle_list_b(bool tof){
	this->list_b_delete->Enabled = tof;
	this->list_b_sell->Enabled = tof;
	this->list_b_restock->Enabled = tof;
	this->list_b_discount->Enabled = tof;
}
//Event: when select an item in the list, update all pd_tB textBoxes by using this item's properties.
void mainForm::list_lv_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	this->list_lv->SelectedItems->Count != 0 ? this->Toggle_list_b(true): this->Toggle_list_b(false);
}
//Event: when click the column in the list, sort it
void mainForm::list_lv_ColumnClick(System::Object^, System::Windows::Forms::ColumnClickEventArgs^ e){
	if(e->Column != this->list_sortColumn){// check whether it clicks the same column
		this->list_sortColumn = e->Column;
		this->Sort_list_lv(e, Ascending);
	}
	else{
		if(this->list_sort == Ascending){
			this->Sort_list_lv(e, Descending);
		}
		else{
			this->Sort_list_lv(e, Ascending);
		}
	}
}
//Function: set the sort status, and then sort the list
void mainForm::Sort_list_lv(System::Windows::Forms::ColumnClickEventArgs^ e, bool t){
	this->list_sort = t;// sort status: Ascending or Descending
	this->list_lv->ListViewItemSorter = gcnew ListViewItemComparer(e->Column, t);// sort it
}
//Function: clear the selected item in the list
void mainForm::Clear_selectedList(int index){
	this->list_lv->SelectedItems[index]->Remove();
}
//Function: update selected item in the list, after sell certain number of products
void mainForm::Update_selectedList_Sell(int index,int num_sold){
	this->list_lv->SelectedItems[index]->SubItems[6]->Text/*sold*/ = System::Convert::ToString(num_sold);
}
//Function: update selected item in the list, after restock certain number of products
void mainForm::Update_selectedList_Restock(int index,int num_stock){
	this->list_lv->SelectedItems[index]->SubItems[5]->Text/*stock*/ = System::Convert::ToString(num_stock);
}
//Function: get selected item's barcode number
int mainForm::Get_sBarcode(int index){
	return System::Convert::ToInt32(this->list_lv->SelectedItems[index]->SubItems[2]->Text);
}
//Function: get selected item's name
System::String^ mainForm::Get_sName(int index){
	return this->list_lv->SelectedItems[index]->SubItems[0]->Text;
}

//**************************************************
//**********STATUSBAR COMPONENTS FUNCTION***********
//**************************************************

//Function: update statusBar's Text and BackColor
void mainForm::Update_statusBar(int i){
	array<System::String^>^ text = gcnew array<System::String^>{
		"Product(s) added successfully", "Product(s) added unsuccessfully", //addS , addF
			"Data loaded successfully", "Data loaded unsuccessfully", //loadS, loadF
			"Data saved successfully", "Data saved unsuccessfully", //saveS, saveF
			"Product(s) sold successfully", "Product(s) sold unsuccessfully", //sellS, sellF
			"Product(s) restocked successfully", "Product(s) restocked unsuccessfully", //restockS, restockF
			"Product(s) deleted successfully", "Product(s) deleted unsuccessfully", //deleteS, deleteF
			"Price discounted successfully", "Price discounted unsuccessfully", //discountS, discountF
			"Searched successfully", "Searched unsuccessfully" //searchS, searchF
	};
	this->Set_statusBar(text[i], i % 2? /*failure*/System::Drawing::Color::RosyBrown: /*success*/System::Drawing::Color::LightSkyBlue);
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
System::Windows::Forms::DialogResult mainForm::Create_messageBox(System::String^ typeMB, System::String^ s){
	if(typeMB == "delete")
		return (System::Windows::Forms::MessageBox::Show(s, " Delete Product",
		System::Windows::Forms::MessageBoxButtons::YesNo,
		System::Windows::Forms::MessageBoxIcon::Warning));
	//else
	return System::Windows::Forms::MessageBox::Show(s, " About");
}
//Initialize the components & set their properties; run at startup of class mainForm
void mainForm::InitializeComponent()
{
	System::Windows::Forms::ListViewItem^  listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(7) {L"Rio de SNEAKER", 
		L"Shoes", L"000051", L"35", L"Nike", L"5", L"5"}, -1));
	System::Windows::Forms::ListViewItem^  listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(7) {L"Superstar2 Snake", 
		L"Shoes", L"000023", L"31", L"Adidas", L"31", L"3"}, -1));
	System::Windows::Forms::ListViewItem^  listViewItem3 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(7) {L"H&M 2013 STU", 
		L"Bag", L"000021", L"33", L"H&M", L"66", L"5"}, -1));
	System::Windows::Forms::ListViewItem^  listViewItem4 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(7) {L"JJ 2013 SS2", 
		L"Jeans", L"000044", L"5", L"JJ", L"25", L"21"}, -1));
	System::Windows::Forms::ListViewItem^  listViewItem5 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(7) {L"JOJO Summer", 
		L"Jeans", L"000145", L"16", L"JOJO", L"11", L"23"}, -1));
	this->menu = (gcnew System::Windows::Forms::MenuStrip());
	this->menu_f = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_f_addNewProducts = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_f_loadProductList = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_f_saveProductList = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_f_quit = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_about = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
	this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
	this->s_tB_input = (gcnew System::Windows::Forms::TextBox());
	this->s_b_submit = (gcnew System::Windows::Forms::Button());
	this->s_grp = (gcnew System::Windows::Forms::GroupBox());
	this->s_rB_stockLT = (gcnew System::Windows::Forms::RadioButton());
	this->s_rB_byManuf = (gcnew System::Windows::Forms::RadioButton());
	this->s_l_by = (gcnew System::Windows::Forms::Label());
	this->s_rB_byCategory = (gcnew System::Windows::Forms::RadioButton());
	this->s_rB_byBarcode = (gcnew System::Windows::Forms::RadioButton());
	this->s_rB_byName = (gcnew System::Windows::Forms::RadioButton());
	this->list_b_restock = (gcnew System::Windows::Forms::Button());
	this->list_b_sell = (gcnew System::Windows::Forms::Button());
	this->list_b_delete = (gcnew System::Windows::Forms::Button());
	this->list_lv = (gcnew System::Windows::Forms::ListView());
	this->list_col_name = (gcnew System::Windows::Forms::ColumnHeader());
	this->list_col_category = (gcnew System::Windows::Forms::ColumnHeader());
	this->list_col_barcode = (gcnew System::Windows::Forms::ColumnHeader());
	this->list_col_price = (gcnew System::Windows::Forms::ColumnHeader());
	this->list_col_manuf = (gcnew System::Windows::Forms::ColumnHeader());
	this->list_col_stock = (gcnew System::Windows::Forms::ColumnHeader());
	this->list_col_sold = (gcnew System::Windows::Forms::ColumnHeader());
	this->list_grp = (gcnew System::Windows::Forms::GroupBox());
	this->list_b_discount = (gcnew System::Windows::Forms::Button());
	this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
	this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
	this->menu->SuspendLayout();
	this->s_grp->SuspendLayout();
	this->list_grp->SuspendLayout();
	this->statusStrip1->SuspendLayout();
	this->SuspendLayout();
	// 
	// menu
	// 
	this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->menu_f, this->menu_about});
	this->menu->Location = System::Drawing::Point(0, 0);
	this->menu->Name = L"menu";
	this->menu->Size = System::Drawing::Size(853, 24);
	//this->menu->TabIndex = 0;
	this->menu->Text = L"menu";
	// 
	// menu_f
	// 
	this->menu_f->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->menu_f_addNewProducts, 
		this->menu_f_loadProductList, this->menu_f_saveProductList, this->menu_f_quit});
	this->menu_f->Name = L"menu_f";
	this->menu_f->Size = System::Drawing::Size(37, 20);
	this->menu_f->Text = L"File";
	// 
	// menu_f_addNewProducts
	// 
	this->menu_f_addNewProducts->Name = L"menu_f_addNewProducts";
	this->menu_f_addNewProducts->Size = System::Drawing::Size(170, 22);
	this->menu_f_addNewProducts->Text = L"Add new products";
	this->menu_f_addNewProducts->Click += gcnew System::EventHandler(this, &mainForm::menu_f_addNewProducts_Click);
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
	this->s_tB_input->TabIndex = 0;
	this->s_tB_input->Text = L" input here";
	this->s_tB_input->SelectAll();
	// 
	// s_b_submit
	// 
	this->s_b_submit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
		static_cast<System::Byte>(134)));
	this->s_b_submit->Location = System::Drawing::Point(184, 23);
	this->s_b_submit->Name = L"s_b_submit";
	this->s_b_submit->Size = System::Drawing::Size(57, 24);
	this->s_b_submit->TabIndex = 1;
	this->s_b_submit->Text = L"Go";
	this->s_b_submit->UseVisualStyleBackColor = true;
	this->s_b_submit->Click += gcnew System::EventHandler(this, &mainForm::s_b_submit_Click);
	// 
	// s_grp
	// 
	this->s_grp->Controls->Add(this->s_rB_stockLT);
	this->s_grp->Controls->Add(this->s_rB_byManuf);
	this->s_grp->Controls->Add(this->s_l_by);
	this->s_grp->Controls->Add(this->s_rB_byCategory);
	this->s_grp->Controls->Add(this->s_rB_byBarcode);
	this->s_grp->Controls->Add(this->s_rB_byName);
	this->s_grp->Controls->Add(this->s_tB_input);
	this->s_grp->Controls->Add(this->s_b_submit);
	this->s_grp->Location = System::Drawing::Point(16, 27);
	this->s_grp->Name = L"s_grp";
	this->s_grp->Size = System::Drawing::Size(247, 99);
	//this->s_grp->TabIndex = 3;
	this->s_grp->TabStop = false;
	this->s_grp->Text = L"Search";
	// 
	// s_rB_stockLT
	// 
	this->s_rB_stockLT->AutoSize = true;
	this->s_rB_stockLT->Location = System::Drawing::Point(31, 72);
	this->s_rB_stockLT->Name = L"s_rB_stockLT";
	this->s_rB_stockLT->Size = System::Drawing::Size(50, 17);
	this->s_rB_stockLT->TabIndex = 5;
	this->s_rB_stockLT->TabStop = true;
	this->s_rB_stockLT->Text = L"Stock";
	this->s_rB_stockLT->UseVisualStyleBackColor = true;
	// 
	// s_rB_byManuf
	// 
	this->s_rB_byManuf->AutoSize = true;
	this->s_rB_byManuf->Location = System::Drawing::Point(87, 72);
	this->s_rB_byManuf->Name = L"s_rB_byManuf";
	this->s_rB_byManuf->Size = System::Drawing::Size(85, 17);
	this->s_rB_byManuf->TabIndex = 6;
	this->s_rB_byManuf->TabStop = true;
	this->s_rB_byManuf->Text = L"Manufacturer";
	this->s_rB_byManuf->UseVisualStyleBackColor = true;
	// 
	// s_l_by
	// 
	this->s_l_by->AutoSize = true;
	this->s_l_by->Location = System::Drawing::Point(7, 54);
	this->s_l_by->Name = L"s_l_by";
	this->s_l_by->Size = System::Drawing::Size(19, 13);
	//this->s_l_by->TabIndex = 6;
	this->s_l_by->Text = L"By";
	// 
	// s_rB_byCategory
	// 
	this->s_rB_byCategory->AutoSize = true;
	this->s_rB_byCategory->Location = System::Drawing::Point(152, 53);
	this->s_rB_byCategory->Name = L"s_rB_byCategory";
	this->s_rB_byCategory->Size = System::Drawing::Size(64, 17);
	this->s_rB_byCategory->TabIndex = 4;
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
	this->s_rB_byBarcode->TabIndex = 3;
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
	this->s_rB_byName->TabIndex = 2;
	this->s_rB_byName->TabStop = true;
	this->s_rB_byName->Text = L"Name";
	this->s_rB_byName->UseVisualStyleBackColor = true;
	// 
	// list_b_restock
	// 
	this->list_b_restock->Enabled = false;
	this->list_b_restock->Location = System::Drawing::Point(310, 339);
	this->list_b_restock->Name = L"list_b_restock";
	this->list_b_restock->Size = System::Drawing::Size(75, 23);
	this->list_b_restock->TabIndex = 9;
	this->list_b_restock->Text = L"Restock";
	this->list_b_restock->UseVisualStyleBackColor = true;
	this->list_b_restock->Click += gcnew System::EventHandler(this, &mainForm::list_b_restock_Click);
	// 
	// list_b_sell
	// 
	this->list_b_sell->Enabled = false;
	this->list_b_sell->Location = System::Drawing::Point(227, 339);
	this->list_b_sell->Name = L"list_b_sell";
	this->list_b_sell->Size = System::Drawing::Size(75, 23);
	this->list_b_sell->TabIndex = 8;
	this->list_b_sell->Text = L"Sell";
	this->list_b_sell->UseVisualStyleBackColor = true;
	this->list_b_sell->Click += gcnew System::EventHandler(this, &mainForm::list_b_sell_Click);
	// 
	// list_b_delete
	// 
	this->list_b_delete->Enabled = false;
	this->list_b_delete->Location = System::Drawing::Point(476, 339);
	this->list_b_delete->Name = L"list_b_delete";
	this->list_b_delete->Size = System::Drawing::Size(75, 23);
	this->list_b_delete->TabIndex = 11;
	this->list_b_delete->Text = L"Delete";
	this->list_b_delete->UseVisualStyleBackColor = true;
	this->list_b_delete->Click += gcnew System::EventHandler(this, &mainForm::list_b_delete_Click);
	// 
	// list_lv
	// 
	this->list_lv->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(7) {this->list_col_name, this->list_col_category, 
		this->list_col_barcode, this->list_col_price, this->list_col_manuf, this->list_col_stock, this->list_col_sold});
	this->list_lv->FullRowSelect = true;
	this->list_lv->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Clickable;
	this->list_lv->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(5) {listViewItem1, listViewItem2, listViewItem3, listViewItem4, listViewItem5});
	this->list_lv->Location = System::Drawing::Point(11, 23);
	this->list_lv->Name = L"list_lv";
	this->list_lv->ShowGroups = false;
	this->list_lv->Size = System::Drawing::Size(539, 306);
	this->list_lv->TabIndex = 7;
	this->list_lv->UseCompatibleStateImageBehavior = false;
	this->list_lv->View = System::Windows::Forms::View::Details;
	this->list_lv->SelectedIndexChanged += gcnew System::EventHandler(this, &mainForm::list_lv_SelectedIndexChanged);
	this->list_lv->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &mainForm::list_lv_ColumnClick);
	this->list_sortColumn = -1;
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
	this->list_grp->Controls->Add(this->list_b_discount);
	this->list_grp->Controls->Add(this->list_lv);
	this->list_grp->Controls->Add(this->list_b_restock);
	this->list_grp->Controls->Add(this->list_b_delete);
	this->list_grp->Controls->Add(this->list_b_sell);
	this->list_grp->Location = System::Drawing::Point(277, 27);
	this->list_grp->Name = L"list_grp";
	this->list_grp->Size = System::Drawing::Size(561, 373);
	//this->list_grp->TabIndex = 12;
	this->list_grp->TabStop = false;
	this->list_grp->Text = L"Result list";
	// 
	// list_b_discount
	// 
	this->list_b_discount->Enabled = false;
	this->list_b_discount->Location = System::Drawing::Point(393, 339);
	this->list_b_discount->Name = L"list_b_discount";
	this->list_b_discount->Size = System::Drawing::Size(75, 23);
	this->list_b_discount->TabIndex = 10;
	this->list_b_discount->Text = L"Discount";
	this->list_b_discount->UseVisualStyleBackColor = true;
	this->list_b_discount->Click += gcnew System::EventHandler(this, &mainForm::list_b_discount_Click);
	// 
	// statusStrip1
	// 
	this->statusStrip1->BackColor = System::Drawing::Color::LightSkyBlue;
	this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
	this->statusStrip1->Location = System::Drawing::Point(0, 409);
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
	this->AcceptButton = this->s_b_submit;
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(853, 431);
	this->Controls->Add(this->statusStrip1);
	this->Controls->Add(this->list_grp);
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
	this->list_grp->ResumeLayout(false);
	this->statusStrip1->ResumeLayout(false);
	this->statusStrip1->PerformLayout();
	this->ResumeLayout(false);
	this->PerformLayout();
}
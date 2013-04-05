/*************************************************************************************************/
//
//  class mainForm: mainForm.cpp
//
//  Description: mainForm.h contains the implementation part of class mainForm.
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
//  for functions, we name them as follows:
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
//  for event, we name them as follows:
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
#include "prdForm.h"
#include "statForm.h"
#include "ListViewItemComparer.h"
#include "InputCheck.h"

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
	searchS, searchF,
	recoverS, recoverF
};

enum BYMETHOD { byName, byBarcode, byCategory, byManuf, byStock };

enum SORT_ORDER{Descending = false, Ascending = true};

//********************************************************
//*************                            ***************
//*************MEMBER FUNCTION DECLEARATION***************
//*************                            ***************
//********************************************************

//Event: when there is keyDown in mainForm (KeyDown is for hotkey)
void mainForm::mainForm_KeyDown(Object^ sender, System::Windows::Forms::KeyEventArgs^ e){
	//Enter: will be handled by s_b_Enter_Click
	//
	e->SuppressKeyPress = true;//thus keys here will not send to mainForm_KeyPress
	//Ctrl+A in listView
	if(this->list_lv->Focused && e->Control && e->KeyCode == System::Windows::Forms::Keys::A){
		if(this->CA_in_List_lv_toggle == true){
			this->list_lv->BeginUpdate();
			for(int i = 0; i < this->list_lv->Items->Count; i++)
				this->list_lv->Items[i]->Selected = true;
			this->list_lv->EndUpdate();
			this->CA_in_List_lv_toggle = false;
		}
	}
	//Ctrl+E for Sale button
	else if(e->Control && e->KeyCode == System::Windows::Forms::Keys::E){
		this->list_b_sell->PerformClick();
	}
	//Ctrl+R for Restock button
	else if(e->Control && e->KeyCode == System::Windows::Forms::Keys::R){
		this->list_b_restock->PerformClick();
	}
	//Ctrl+M for Modify button
	else if(e->Control && e->KeyCode == System::Windows::Forms::Keys::M){
		this->list_b_modify->PerformClick();
	}
	//Del for Delete button
	else if(e->KeyCode == System::Windows::Forms::Keys::Delete/* || (e->Control && e->KeyCode == System::Windows::Forms::Keys::D)*/){
		this->list_b_delete->PerformClick();
	}
	//Ctrl+N for Add New Product button
	else if(e->Control && e->KeyCode == System::Windows::Forms::Keys::N)
		this->Create_addPdForms();
	//Ctrl+Shift+S for Save as...
	else if(e->Control && e->Shift && e->KeyCode == System::Windows::Forms::Keys::S)
		this->Save_as_ano_prdList();
	//Ctrl+S for Save
	else if(e->Control && e->KeyCode == System::Windows::Forms::Keys::S){
		if(this->toolStripStatusLabel1->Text != "Data saved successfully")
			this->Save_curr_prdList();
	}
	//Ctrl+L for Load
	else if(e->Control && e->KeyCode == System::Windows::Forms::Keys::L)
		this->Load_prdList();
	//Ctrl+B for batch processing
	else if(e->Control && e->KeyCode == System::Windows::Forms::Keys::B)
		this->Batch_processing();
	else
		e->SuppressKeyPress = false;
}
//Event: when there is keyPress in mainForm (keyPress can differentiate the keyChar specifically)
void mainForm::mainForm_KeyPress(Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e){
	//num, character, space for s_tB_input
	if(!this->s_tB_input->Focused && (System::Char::IsLetterOrDigit(e->KeyChar) ||
		e->KeyChar == ' ')){
			this->s_tB_input->Text = System::Convert::ToString(e->KeyChar);
			this->s_tB_input->Focus();
			this->s_tB_input->SelectionStart = this->s_tB_input->Text->Length;
	}
	//backspace for s_tB_input
	else if(!this->s_tB_input->Focused && e->KeyChar == 8){//8 is Backspace
		this->s_tB_input->Text = "";
		this->s_tB_input->Focus();
		this->s_tB_input->SelectionStart = 0;
	}
}
//Event: when mainForm is loaded
void mainForm::mainForm_Load(System::Object^  sender, System::EventArgs^  e){
	this->s_tB_input->Select();
}
//Initialize the settings before mainForm is loaded
void mainForm::Ini_settings(){
	this->SelectAll_toggle = true;
	this->default_IComparer = this->list_lv->ListViewItemSorter;
	this->CA_in_List_lv_toggle = true;

	this->Bridging = gcnew Bridge;
	//loading at start up
	if(false/*Bridging->CheckRecovery()*/){
		if(System::Windows::Forms::MessageBox::Show("Application crashes detected, do you want to restore\nthe operation(s) last time?",
			" CICMS Recovery",
			System::Windows::Forms::MessageBoxButtons::YesNo,
			System::Windows::Forms::MessageBoxIcon::Question)
			== System::Windows::Forms::DialogResult::Yes){
				if(true/*Bridging->Load(true)*/)
					this->Update_statusBar(recoverS); //successful
				else
					this->Update_statusBar(recoverF); //unsuccessful
		}
		else{
			if(true/*Bridging->Load(false)*/)
				this->Set_statusBar("Ready", System::Drawing::Color::LightSkyBlue);
			else
				this->Update_statusBar(loadF);
		}
	}
	else{
		if(true/*Bridging->Load(false)*/)
			this->Set_statusBar("Ready", System::Drawing::Color::LightSkyBlue);
		else
			this->Update_statusBar(loadF);
	}
}

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
//Event: when click menu_f_save item, Save the current product list
void mainForm::menu_f_save_Click(System::Object^  sender, System::EventArgs^  e){
	this->Save_curr_prdList();
}
//Event: when click menu_f_saveAs item, Save as another product list
void mainForm::menu_f_saveAs_Click(System::Object^  sender, System::EventArgs^  e){
	this->Save_as_ano_prdList();
}
//Event: when click menu_f_load item, Load a product list
void mainForm::menu_f_load_Click(System::Object^  sender, System::EventArgs^  e){
	this->Load_prdList();
}
//Event: when click menu_f_bp item, Submit batch file for batch processing
void mainForm::menu_f_bp_Click(System::Object^  sender, System::EventArgs^  e){
	this->Batch_processing();
}
//Save the current product list
void mainForm::Save_curr_prdList(){
	this->Set_statusBar("Saving...", System::Drawing::Color::Khaki);
	if(true/*Bridging->Save()*/)
		this->Update_statusBar(saveS);//successful
	else
		this->Update_statusBar(saveF);//unsuccessful
}
//Save as another product list
void mainForm::Save_as_ano_prdList(){
	System::Windows::Forms::SaveFileDialog^ sf_dlg = gcnew System::Windows::Forms::SaveFileDialog;
	sf_dlg->FileName = "product";
	sf_dlg->Title = " Save as another product list";
	sf_dlg->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	sf_dlg->FilterIndex = 1;
	if(sf_dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK){
		this->Set_statusBar("Saving...", System::Drawing::Color::Khaki);
		if(true/*Bridging->Save(sf_dlg->FileName)*/)
			this->Update_statusBar(saveS);//successful
		else
			this->Update_statusBar(saveF);//unsuccessful
	}
}
//Load a product list
void mainForm::Load_prdList(){
	System::Windows::Forms::OpenFileDialog^ of_dlg = gcnew System::Windows::Forms::OpenFileDialog;
	of_dlg->FileName = "product";
	of_dlg->Title = " Load product list";
	of_dlg->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	of_dlg->FilterIndex = 1;
	if(of_dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK){
		this->Set_statusBar("Loading...", System::Drawing::Color::Khaki);
		if(true/*Bridging->Load(of_dlg->FileName)*/)
			this->Update_statusBar(loadS); //successful
		else
			this->Update_statusBar(loadF); //unsuccessful
	}
}
//Submit batch file for batch processing
void mainForm::Batch_processing(){
	System::Windows::Forms::OpenFileDialog^ of_dlg = gcnew System::Windows::Forms::OpenFileDialog;
	of_dlg->FileName = "batchjobs";
	of_dlg->Title = " Load batch file";
	of_dlg->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	of_dlg->FilterIndex = 1;
	if(of_dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK){
		this->Set_statusBar("Processing...", System::Drawing::Color::Khaki);
		/*int i = Bridging->Batch_processing(of_dlg->FileName)*/
		int i = 3;//delete this line later
		if(i == 0)
			this->Set_statusBar("Batch file processed successfully", System::Drawing::Color::LightSkyBlue);
		else
			this->Set_statusBar("Batch file processed successfully, " + i + " errors found" , System::Drawing::Color::LightSkyBlue);
	}
}
//Event: when click menu_stat_BSpd_Click item, open the MessageBox window to show the result of Best-Selling product(s)
void mainForm::menu_stat_BSpd_Click(System::Object^  sender, System::EventArgs^  e){
	this->Create_BSpdForm();
}
//Event: when click menu_stat_BSmanu_Click item, open the MessageBox window to show the result of Best-Selling manufacturer(s)
void mainForm::menu_stat_BSmanu_Click(System::Object^  sender, System::EventArgs^  e){
	this->Create_BSmanuForm();
}
//Event: when click menu_stat_BSpdCate
void mainForm::menu_stat_BSpdCate_Click(System::Object^  sender, System::EventArgs^  e){
	this->Create_BSpdCateForm();
}
//Event: when click menu_stat_topXpd_Click item, open the inputForm to take in a number X, then open MessageBox window to show the result of Top X Selling products
void mainForm::menu_stat_topXpd_Click(System::Object^  sender, System::EventArgs^  e){
	this->Create_topXpdForm();
}
//Event: when click menu_help_abt item, open a messageBox that contains our team's description
void mainForm::menu_help_abt_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::MessageBox::Show("Hello! Our team, C07-2: Ashray, Bob, Hui and Kai!", " About");
}
//Event: when click menu_help_hotkey, show a msgbox to display a list of hotkeys supported
void mainForm::menu_help_hotkey_Click(System::Object^  sender, System::EventArgs^  e){
	System::Windows::Forms::MessageBox::Show(
		//"Menu:\n"
		"Ctrl + 1		The Best-Selling product(s)\n" +
		"Ctrl + 2		The Best-Selling manufacturer(s)\n" +
		"Ctrl + 3		The Best-Selling product(s) in a given category\n" +
		"Ctrl + 4		The Top X product(s)\n" +
		"-------------------------------------------------------\n" + 
		"Ctrl + N		Add new product(s)\n" +
		"Ctrl + S		Save current product list\n" +
		"Ctrl + Shift + S	Save as another product list\n" +
		"Ctrl + L		Load product list\n" +
		"Ctrl + B		Submit batch processing\n" +
		"-------------------------------------------------------\n" + 
		"After selecting some products\n" +
		"Ctrl + E		Specify a sale for product(s)\n" +
		"Ctrl + R		Restock product(s)\n" +
		"Ctrl + M		Modify product(s) details\n" +
		"Del		Delete product(s)", " Keyboard shortcuts");
}
//Function: create a addPdForm window, and let logic/handler part handle the input
void mainForm::Create_addPdForms(){
	int num = (int) Create_inputForm(" Add products", "How many products to add?     ", "Number:", "1");
	for( int i = 0; i < num; i++){
		prdForm^ dlg = gcnew prdForm();
		dlg->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
		dlg->set_npd_grp_text("New product " + System::Convert::ToString(i+1) + "/" + System::Convert::ToString(num));
		System::Windows::Forms::DialogResult r = dlg->ShowDialog();
		if (r == System::Windows::Forms::DialogResult::OK){
			if(Bridging->Add(dlg->get_product_details())){
				this->Submit_search();// refresh the search result
				this->Update_statusBar(addS);
			}
			else
				this->Update_statusBar(addF);
		}
		else if(r == System::Windows::Forms::DialogResult::Cancel)
			break;
	}
}
//Function: create a window to display the Best-Selling product(s)
void mainForm::Create_BSpdForm(){
	array<System::Windows::Forms::ListViewItem^>^ r = Bridging->Gen_TopXpd(1);
	if(r->Length == 0){
		System::Windows::Forms::MessageBox::Show("Report not available.");
		return;
	}

	statForm^ dlg = gcnew statForm();
	dlg->Set_grpTitle("The Best-Selling product(s)");
	dlg->Set_listData(r);
	dlg->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
	dlg->ShowDialog();
}
//Function: create a window to display the Best-Selling manufacturer(s)
void mainForm::Create_BSmanuForm(){
	System::String^ output = Bridging->Gen_BSmanu();
	if(output->Length != 0)
		System::Windows::Forms::MessageBox::Show("The Best-Selling manufacturer(s): \n"
		+ "********************************\n"
		+ output);
	else
		System::Windows::Forms::MessageBox::Show("Report not available.");
}
//Function: create a window to display the Best-Selling product(s) in a given category
void mainForm::Create_BSpdCateForm(){
	inputForm^ inputDlg = gcnew inputForm();
	inputDlg->set_inputForm(" Report the Best-Selling product", "Please type the category name ", "Category:  ", "");
	inputDlg->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
	inputDlg->set_formType(STRING);

	System::String^ c;
	if (inputDlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		c = inputDlg->get_input();
	else
		return;

	array<System::Windows::Forms::ListViewItem^>^ r = Bridging->Gen_BSpdCate(c);
	if(r->Length == 0){
		System::Windows::Forms::MessageBox::Show("Report not available.");
		return;
	}

	statForm^ dlg = gcnew statForm();
	dlg->Set_grpTitle("The Best-Selling product of " + c);
	dlg->Set_listData(r);
	dlg->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
	dlg->ShowDialog();
}
//Function: create a window to display the Top X products
void mainForm::Create_topXpdForm(){
	inputForm^ inputDlg = gcnew inputForm();
	inputDlg->set_inputForm(" The Top X Selling products", "Please input a number for X.      ", "X is equal to", "5");
	inputDlg->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
	inputDlg->set_formType(NUMBER);
	inputDlg->TOP_X_filter(true);

	int i;
	if (inputDlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		i = System::Convert::ToInt32(inputDlg->get_input());
	else
		return;

	array<System::Windows::Forms::ListViewItem^>^ r = Bridging->Gen_TopXpd(i);
	if(r->Length == 0){
		System::Windows::Forms::MessageBox::Show("Report not available.");
		return;
	}

	statForm^ dlg = gcnew statForm();
	dlg->Set_grpTitle("The Top " + i.ToString() + " Selling products");
	dlg->Set_listData(r);
	dlg->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
	dlg->ShowDialog();
}

//***********************************************
//**********SEARCH COMPONENTS FUNCTION***********
//***********************************************

//Event: when Text in s_tB_input is changed, used to achieve Search Instant
void mainForm::s_tB_input_TextChanged(System::Object^  sender, System::EventArgs^  e){
	this->Submit_search();//search here
}
//Event: triggered when ENTER is pressed
void mainForm::s_b_Enter_Click(System::Object^  sender, System::EventArgs^  e) {
	this->s_tB_input->Focus();
	this->s_tB_input->SelectAll();
	this->Submit_search();//search here
}
//Event: when s_rB_byName, s_rB_byCategory, s_rB_byManufacturer or s_rB_byBarcode is selected
void mainForm::s_rB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	this->Submit_search();//search here
	this->s_tB_input->SelectAll();
	this->SelectAll_toggle = false;
}
//Event: when s_tB_input is clicked
void mainForm::s_tB_input_Click(System::Object^  sender, System::EventArgs^  e){
	if(this->SelectAll_toggle == true){
		this->s_tB_input->SelectAll();
		this->SelectAll_toggle = false;
	}
}
//Event: when s_tB_input is lost focus
void mainForm::s_tB_input_LostFocus(System::Object^  sender, System::EventArgs^  e){
	this->s_tB_input->SelectAll();
	this->SelectAll_toggle = false;
}
//Event: when s_b_submit button is clicked
void mainForm::Submit_search(){
	//input Checking first
	if(InputCheck::is_empty(this->s_tB_input->Text)){
		this->Set_statusBar("Ready", System::Drawing::Color::LightSkyBlue);
		this->list_lv->Items->Clear();
		this->Toggle_list_b(false);
	}
	else if(this->Get_byMethod() == byBarcode && (this->s_tB_input->Text->Length > 9 || !InputCheck::is_int(this->s_tB_input->Text) || 
		InputCheck::lessThan_zero(this->s_tB_input->Text))){
			this->Update_statusBar(searchF);//barcode shall be an integer, larger than zero and its length <= 9
			this->list_lv->Items->Clear();
			this->Toggle_list_b(false);
	}
	//if all satisfied
	else
		this->Search_product(this->s_tB_input->Text, this->Get_byMethod());
}
//Function: get the result of checked radioButton (by which method to search)
int mainForm::Get_byMethod(){
	if(this->s_rB_byName->Checked == true)
		return byName;
	else if(this->s_rB_byBarcode->Checked == true)
		return byBarcode;
	else if(this->s_rB_byCategory->Checked == true)
		return byCategory;
	else if(this->s_rB_byManufacturer->Checked == true)
		return byManuf;
	else
		return byName;
}
//Function: search the products according to a text and a method; if the result is non-empty, it will add an item onto the listView component
void mainForm::Search_product(System::String^ s, int m){
	array<System::Windows::Forms::ListViewItem^>^ r = Bridging->Search(s, m);
	if(r->Length){
		this->list_lv->BeginUpdate();
		this->list_lv->Items->Clear();
		this->list_lv->ListViewItemSorter = default_IComparer;// set it to default sort mode --- no sort at all; otherwise some results will be confusing
		this->list_lv->Items->AddRange(r);
		this->list_lv->EndUpdate();
		this->list_lv->Items[0]->Selected = true;
		this->Update_statusBar(searchS);
	}
	else{
		this->Update_statusBar(searchF);
		this->list_lv->Items->Clear();
		this->Toggle_list_b(false);
	}
}

//*****************************************************
//**********LIST DETAILS COMPONENTS FUNCTION***********
//*****************************************************

//Event: when click list_b_sell button, open an inputForm window for input sale data
void mainForm::list_b_sell_Click(System::Object^  sender, System::EventArgs^  e) {
	Create_sellForm();
}
//Event: when click list_b_restock button, open an inputForm window for input restock data
void mainForm::list_b_restock_Click(System::Object^  sender, System::EventArgs^  e) {
	Create_restockForm();
}

//Event: when click list_b_delete button, open a msgBox to check whether delete the selectedItem or not
void mainForm::list_b_delete_Click(System::Object^  sender, System::EventArgs^  e) {
	Create_deleteForm();
}
//Event: when click list_b_modify button
void mainForm::list_b_modify_Click(System::Object^  sender, System::EventArgs^  e){
	Set_statusBar("Processing...",System::Drawing::Color::Khaki);
	this->statusStrip1->Refresh();
	this->Create_modifyForm();
}
void mainForm::Create_modifyForm(){
	//create an input data
	System::String^ name, ^category, ^barcode, ^price, ^manuf;
	if(this->list_lv->SelectedItems->Count > 0){
		name = this->list_lv->SelectedItems[0]->SubItems[0]->Text;
		category = this->list_lv->SelectedItems[0]->SubItems[1]->Text;
		barcode = this->list_lv->SelectedItems[0]->SubItems[2]->Text;
		price = this->list_lv->SelectedItems[0]->SubItems[3]->Text;
		manuf = this->list_lv->SelectedItems[0]->SubItems[4]->Text;
	}
	if(this->list_lv->SelectedItems->Count > 1)
			barcode = "(...)";
	for(int i = 1; i < this->list_lv->SelectedItems->Count; i++){
		if(name != "(...)" && name != this->list_lv->SelectedItems[i]->SubItems[0]->Text)
			name = "(...)";
		if(category != "(...)" && category != this->list_lv->SelectedItems[i]->SubItems[1]->Text)
			category = "(...)";
		if(price != "(...)" && price != this->list_lv->SelectedItems[i]->SubItems[3]->Text)
			price = "(...)";
		if(manuf != "(...)" && manuf != this->list_lv->SelectedItems[i]->SubItems[4]->Text)
			manuf = "(...)";
	}
	System::Windows::Forms::ListViewItem^ input = gcnew System::Windows::Forms::ListViewItem(gcnew cli::array<System::String^>(7) {
		name,category,barcode,price,manuf
	});
	//create the window, and send in the input data
	prdForm^ dlg = gcnew prdForm;
	//set up for modification mode
	dlg->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
	dlg->modifyMode_toggle(true);
	dlg->setValue(input);
	dlg->set_npd_grp_text("Product(s) details");
	dlg->setTitle(" Modify product(s) details");
	System::Windows::Forms::ListViewItem^ output;
	//get output, then update the database and listView component
	if(dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK){
		output = dlg->get_product_details();
		bool nameChanged = output->SubItems[0]->Text != input->SubItems[0]->Text,
			categoryChanged = output->SubItems[1]->Text != input->SubItems[1]->Text,
			priceChanged = output->SubItems[3]->Text != input->SubItems[3]->Text,
			manufChanged = output->SubItems[4]->Text != input->SubItems[4]->Text;
		//any changes? update~
		if(nameChanged || categoryChanged || priceChanged || manufChanged){
			this->list_lv->BeginUpdate();
			for(int i = 0; i < this->list_lv->SelectedItems->Count; i++){
				if(nameChanged)
					this->list_lv->SelectedItems[i]->SubItems[0]->Text = output->SubItems[0]->Text;
				if(categoryChanged)
					this->list_lv->SelectedItems[i]->SubItems[1]->Text = output->SubItems[1]->Text;
				if(priceChanged)
					this->list_lv->SelectedItems[i]->SubItems[3]->Text = output->SubItems[3]->Text;
				if(manufChanged)
					this->list_lv->SelectedItems[i]->SubItems[4]->Text = output->SubItems[4]->Text;
				//Bridging->Modify(this->list_lv->SelectedItems[i]);
			}
			this->list_lv->EndUpdate();
		}
		this->list_lv->Focus();
		Set_statusBar("Product(s) modified successfully",System::Drawing::Color::LightSkyBlue);
	}
	else{
		this->list_lv->Focus();
		Set_statusBar("Ready",System::Drawing::Color::LightSkyBlue);
	}
}
//Function: create an inputForm for input; used by pd_b_sell_Click & pd_b_restock_Click events.
double mainForm::Create_inputForm(System::String^ formTitle, System::String^ pdDescript, System::String^ inputDescript, System::String^ stringInTB){
	inputForm^ dlg = gcnew inputForm();
	dlg->set_inputForm(formTitle, pdDescript, inputDescript, stringInTB);
	dlg->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
	if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		return System::Convert::ToDouble(dlg->get_input());
	else
		return 0;// 0 is unique, as user cannot input zero
}
//Function: create a window to specify the sale of a product
void mainForm::Create_sellForm(){
	for(int i = 0; i < this->list_lv->SelectedItems->Count; i++){
		unsigned num = (unsigned) this->Create_inputForm(" Sell a product", this->Get_sName(i) + " (" + this->Get_sCategory(i) + ") - " + this->Get_sBarcode(i), "Sell:", "1");
		if(num == 0)//if cancel the MessageBox
			break;
		else if(Bridging->Sell(this->list_lv->SelectedItems[i], num)){
			this->Update_selectedItem_sell(i, num);
			this->Update_statusBar(sellS);
		}
		else
			this->Update_statusBar(sellF);
	}
}
//Function: create a window to restock a product
void mainForm::Create_restockForm(){
	for(int i = 0; i < this->list_lv->SelectedItems->Count; i++){
		unsigned num = (unsigned) this->Create_inputForm(" Restock a product", this->Get_sName(i) + " (" + this->Get_sCategory(i) + ") - " + this->Get_sBarcode(i), "Restock:", "1");
		if(num == 0)//if cancel the MessageBox
			break;
		else if(Bridging->Restock(this->list_lv->SelectedItems[i], num)){
			this->Update_selectedItem_restock(i, num);
			this->Update_statusBar(restockS);
		}
		else
			this->Update_statusBar(restockF);
	}
}
//Function: create a window to check whether the user want to delete a product or not
void mainForm::Create_deleteForm(){
	enum { No_No, Yes_Yes, tooMany = 1};
	int case_tooMany = No_No;
	System::Windows::Forms::DialogResult r;
	if(this->list_lv->SelectedItems->Count > tooMany){
		case_tooMany = Yes_Yes;
		if(this->list_lv->SelectedItems->Count > 2)
			r = (System::Windows::Forms::MessageBox::Show("Are you sure that you would like \nto delete all the selected products?", " Delete Product",
			System::Windows::Forms::MessageBoxButtons::YesNo,
			System::Windows::Forms::MessageBoxIcon::Warning));
		else// == 2
			r = (System::Windows::Forms::MessageBox::Show("Are you sure that you would like \nto delete both of the selected products?", " Delete Product",
			System::Windows::Forms::MessageBoxButtons::YesNo,
			System::Windows::Forms::MessageBoxIcon::Warning));
		if(r == System::Windows::Forms::DialogResult::Yes)
			;//del all
		else if(r == System::Windows::Forms::DialogResult::No)
			return;//quit the deletion directly
	}
	this->list_lv->BeginUpdate();
	for(int i = 0; i < this->list_lv->SelectedItems->Count; i++){
		if(case_tooMany == Yes_Yes || (System::Windows::Forms::MessageBox::Show("Are you sure that you would like \nto delete this product, " +
			this->Get_sName(i) + " (" + this->Get_sCategory(i) + ") - " + this->Get_sBarcode(i) +
			"?", " Delete Product",
			System::Windows::Forms::MessageBoxButtons::YesNo,
			System::Windows::Forms::MessageBoxIcon::Warning)) == System::Windows::Forms::DialogResult::Yes){
				if(Bridging->Del(this->list_lv->SelectedItems[i]))
				{
					this->Clear_selectedItem(i--);//if delete an item, selectedItems->Count will decrease, index will change as well
					this->Update_statusBar(deleteS);
				}
				else
					this->Update_statusBar(deleteF);
		}
		else{
			//quit the deletion
			this->list_lv->EndUpdate();//must!
			return;
		}
	}
	//aft deletion
	this->list_lv->EndUpdate();
	if(this->list_lv->Items->Count > 0)
		this->list_lv->Items[0]->Selected = true;
	else
		this->Toggle_list_b(false);
}
//Function: toggle 'enabled' properties for pd_b_delete, pd_b_sell, pd_b_restock buttons
void mainForm::Toggle_list_b(bool tof){
	this->list_b_delete->Enabled = tof;
	this->list_b_sell->Enabled = tof;
	this->list_b_restock->Enabled = tof;
	this->list_b_modify->Enabled = tof;

}
//Event: when select an item in the list, turn on/off some toggles
void mainForm::list_lv_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	this->list_lv->SelectedItems->Count != 0 ? this->Toggle_list_b(true): this->Toggle_list_b(false);
	if(this->list_lv->SelectedItems->Count == this->list_lv->Items->Count)// selected all liao
		this->CA_in_List_lv_toggle = false;
	else
		this->CA_in_List_lv_toggle = true;
}
//Event: when click the column in the list, sort it
void mainForm::list_lv_ColumnClick(System::Object^, System::Windows::Forms::ColumnClickEventArgs^ e){
	if(this->list_lv->Items->Count > 0)
	{
		bool is_num = InputCheck::is_number(this->list_lv->Items[0]->SubItems[e->Column]->Text);
		if(e->Column != this->list_sortColumn){// check whether it clicks the same column
			this->list_sortColumn = e->Column;
			this->Sort_list_lv(e, Ascending, is_num);
		}
		else{
			if(this->list_sort == Ascending){
				this->Sort_list_lv(e, Descending, is_num);
			}
			else{
				this->Sort_list_lv(e, Ascending, is_num);
			}
		}
	}

}
//Function: set the sort status, and then sort the list
void mainForm::Sort_list_lv(System::Windows::Forms::ColumnClickEventArgs^ e, bool t, bool is_num){
	this->list_sort = t;// sort status: Ascending or Descending
	this->list_lv->ListViewItemSorter = gcnew ListViewItemComparer(e->Column, t, is_num);// sort it
}
//Function: clear the selected item in the list
void mainForm::Clear_selectedItem(int index){
	this->list_lv->SelectedItems[index]->Remove();
}
//Function: update the selected item's sale number
void mainForm::Update_selectedItem_sell(int index, unsigned num){
	int no_stock = System::Convert::ToInt32(this->list_lv->SelectedItems[index]->SubItems[5]->Text) - num,
		no_sold = System::Convert::ToInt32(this->list_lv->SelectedItems[index]->SubItems[6]->Text) + num;
	this->list_lv->SelectedItems[index]->SubItems[5]->Text = no_stock.ToString();
	this->list_lv->SelectedItems[index]->SubItems[6]->Text = no_sold.ToString();
}
//Function: update the selected item's stock numer
void mainForm::Update_selectedItem_restock(int index, unsigned num){
	int no_stock = System::Convert::ToInt32(this->list_lv->SelectedItems[index]->SubItems[5]->Text) + num;
	this->list_lv->SelectedItems[index]->SubItems[5]->Text = no_stock.ToString();
}
//Function: get selected item's barcode number
System::String^ mainForm::Get_sBarcode(int index){
	return this->list_lv->SelectedItems[index]->SubItems[2]->Text;
}
//Function: get selected item's name
System::String^ mainForm::Get_sName(int index){
	if(this->list_lv->SelectedItems[index]->SubItems[0]->Text->Length > 21)
		return this->list_lv->SelectedItems[index]->SubItems[0]->Text->Substring(0,21) + "...";
	return this->list_lv->SelectedItems[index]->SubItems[0]->Text;
}
//Function: get selected item's category
System::String^ mainForm::Get_sCategory(int index){
	if(this->list_lv->SelectedItems[index]->SubItems[1]->Text->Length > 21)
		return this->list_lv->SelectedItems[index]->SubItems[1]->Text->Substring(0,21) + "...";
	return this->list_lv->SelectedItems[index]->SubItems[1]->Text;
}

//**************************************************
//**********STATUSBAR COMPONENTS FUNCTION***********
//**************************************************

//Function: update statusBar's Text and BackColor
void mainForm::Update_statusBar(int i){
	array<System::String^>^ text = gcnew array<System::String^>{
		"Product(s) added successfully", "Product(s) added unsuccessfully. The barcode already exists", //addS , addF
			"Data loaded successfully", "Data loaded unsuccessfully", //loadS, loadF
			"Data saved successfully", "Data saved unsuccessfully", //saveS, saveF
			"Product(s) sold successfully", "Product(s) sold unsuccessfully. Please check the stock", //sellS, sellF
			"Product(s) restocked successfully", "Product(s) restocked unsuccessfully", //restockS, restockF
			"Product(s) deleted successfully", "Product(s) deleted unsuccessfully", //deleteS, deleteF
			"Price discounted successfully", "Price discounted unsuccessfully", //discountS, discountF
			"Searched successfully", "No results found", //searchS, searchF
			"Data recovered successfully", "Data recovered unsuccessfully" //recoverS, recoverF
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

//Initialize the components & set their properties; run at startup of class mainForm
void mainForm::InitializeComponent()
{
	System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(mainForm::typeid));
	this->menu = (gcnew System::Windows::Forms::MenuStrip());
	this->menu_f = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_f_addNewProducts = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
	this->menu_f_save = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_f_saveAs = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_f_load = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_f_bp = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
	this->menu_f_quit = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_stat = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_stat_BSpd = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_stat_BSmanu = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_stat_BSpdCate = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_stat_topXpd = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_help = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menu_help_hotkey = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
	this->menu_help_abt = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->s_tB_input = (gcnew System::Windows::Forms::TextBox());
	this->s_grp = (gcnew System::Windows::Forms::GroupBox());
	this->s_rB_byManufacturer = (gcnew System::Windows::Forms::RadioButton());
	this->s_l_by = (gcnew System::Windows::Forms::Label());
	this->s_rB_byCategory = (gcnew System::Windows::Forms::RadioButton());
	this->s_rB_byBarcode = (gcnew System::Windows::Forms::RadioButton());
	this->s_rB_byName = (gcnew System::Windows::Forms::RadioButton());
	this->s_b_Enter = (gcnew System::Windows::Forms::Button());
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
	this->list_b_modify = (gcnew System::Windows::Forms::Button());
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
	this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->menu_f, this->menu_stat, 
		this->menu_help});
	this->menu->Location = System::Drawing::Point(0, 0);
	this->menu->Name = L"menu";
	this->menu->Size = System::Drawing::Size(890, 24);
	this->menu->TabIndex = 15;
	this->menu->Text = L"menu";
	// 
	// menu_f
	// 
	this->menu_f->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
	this->menu_f->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {this->menu_f_addNewProducts, 
		this->toolStripSeparator1, this->menu_f_save, this->menu_f_saveAs, this->menu_f_load, this->menu_f_bp, this->toolStripSeparator3, 
		this->menu_f_quit});
	this->menu_f->Name = L"menu_f";
	this->menu_f->ShortcutKeyDisplayString = L"";
	this->menu_f->Size = System::Drawing::Size(37, 20);
	this->menu_f->Text = L"File";
	// 
	// menu_f_addNewProducts
	// 
	this->menu_f_addNewProducts->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
	this->menu_f_addNewProducts->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"menu_f_addNewProducts.Image")));
	this->menu_f_addNewProducts->Name = L"menu_f_addNewProducts";
	this->menu_f_addNewProducts->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
	this->menu_f_addNewProducts->Size = System::Drawing::Size(207, 22);
	this->menu_f_addNewProducts->Text = L"Add new products";
	this->menu_f_addNewProducts->Click += gcnew System::EventHandler(this, &mainForm::menu_f_addNewProducts_Click);
	// 
	// toolStripSeparator1
	// 
	this->toolStripSeparator1->Name = L"toolStripSeparator1";
	this->toolStripSeparator1->Size = System::Drawing::Size(204, 6);
	// 
	// menu_f_save
	// 
	this->menu_f_save->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
	this->menu_f_save->Name = L"menu_f_save";
	this->menu_f_save->ShortcutKeyDisplayString = L"Ctrl+S";
	this->menu_f_save->Size = System::Drawing::Size(207, 22);
	this->menu_f_save->Text = L"Save";
	this->menu_f_save->Click += gcnew System::EventHandler(this, &mainForm::menu_f_save_Click);
	// 
	// menu_f_saveAs
	// 
	this->menu_f_saveAs->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
	this->menu_f_saveAs->Name = L"menu_f_saveAs";
	this->menu_f_saveAs->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
		| System::Windows::Forms::Keys::S));
	this->menu_f_saveAs->Size = System::Drawing::Size(207, 22);
	this->menu_f_saveAs->Text = L"Save as...";
	this->menu_f_saveAs->Click += gcnew System::EventHandler(this, &mainForm::menu_f_saveAs_Click);
	// 
	// menu_f_load
	// 
	this->menu_f_load->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
	this->menu_f_load->Name = L"menu_f_load";
	this->menu_f_load->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::L));
	this->menu_f_load->Size = System::Drawing::Size(207, 22);
	this->menu_f_load->Text = L"Load";
	this->menu_f_load->Click += gcnew System::EventHandler(this, &mainForm::menu_f_load_Click);
	// 
	// menu_f_bp
	// 
	this->menu_f_bp->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
	this->menu_f_bp->Name = L"menu_f_bp";
	this->menu_f_bp->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::B));
	this->menu_f_bp->Size = System::Drawing::Size(207, 22);
	this->menu_f_bp->Text = L"Batch processing";
	this->menu_f_bp->Click += gcnew System::EventHandler(this, &mainForm::menu_f_bp_Click);
	// 
	// toolStripSeparator3
	// 
	this->toolStripSeparator3->Name = L"toolStripSeparator3";
	this->toolStripSeparator3->Size = System::Drawing::Size(204, 6);
	// 
	// menu_f_quit
	// 
	this->menu_f_quit->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
	this->menu_f_quit->Name = L"menu_f_quit";
	this->menu_f_quit->Size = System::Drawing::Size(207, 22);
	this->menu_f_quit->Text = L"Quit";
	this->menu_f_quit->Click += gcnew System::EventHandler(this, &mainForm::menu_f_quit_Click);
	// 
	// menu_stat
	// 
	this->menu_stat->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
	this->menu_stat->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->menu_stat_BSpd, 
		this->menu_stat_BSmanu, this->menu_stat_BSpdCate, this->menu_stat_topXpd});
	this->menu_stat->Name = L"menu_stat";
	this->menu_stat->Size = System::Drawing::Size(64, 20);
	this->menu_stat->Text = L"Statistics";
	// 
	// menu_stat_BSpd
	// 
	this->menu_stat_BSpd->Name = L"menu_stat_BSpd";
	this->menu_stat_BSpd->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D1));
	this->menu_stat_BSpd->Size = System::Drawing::Size(373, 22);
	this->menu_stat_BSpd->Text = L"Report the Best-Selling product";
	this->menu_stat_BSpd->Click += gcnew System::EventHandler(this, &mainForm::menu_stat_BSpd_Click);
	// 
	// menu_stat_BSmanu
	// 
	this->menu_stat_BSmanu->Name = L"menu_stat_BSmanu";
	this->menu_stat_BSmanu->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D2));
	this->menu_stat_BSmanu->Size = System::Drawing::Size(373, 22);
	this->menu_stat_BSmanu->Text = L"Report the Best-Selling manufacturer";
	this->menu_stat_BSmanu->Click += gcnew System::EventHandler(this, &mainForm::menu_stat_BSmanu_Click);
	// 
	// menu_stat_BSpdCate
	// 
	this->menu_stat_BSpdCate->Name = L"menu_stat_BSpdCate";
	this->menu_stat_BSpdCate->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D3));
	this->menu_stat_BSpdCate->Size = System::Drawing::Size(373, 22);
	this->menu_stat_BSpdCate->Text = L"Report the Best-Selling product in a given category";
	this->menu_stat_BSpdCate->Click += gcnew System::EventHandler(this, &mainForm::menu_stat_BSpdCate_Click);
	// 
	// menu_stat_topXpd
	// 
	this->menu_stat_topXpd->Name = L"menu_stat_topXpd";
	this->menu_stat_topXpd->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D4));
	this->menu_stat_topXpd->Size = System::Drawing::Size(373, 22);
	this->menu_stat_topXpd->Text = L"Report the Top X Selling products";
	this->menu_stat_topXpd->Click += gcnew System::EventHandler(this, &mainForm::menu_stat_topXpd_Click);
	// 
	// menu_help
	// 
	this->menu_help->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
	this->menu_help->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->menu_help_hotkey, 
		this->toolStripSeparator2, this->menu_help_abt});
	this->menu_help->Name = L"menu_help";
	this->menu_help->Size = System::Drawing::Size(43, 20);
	this->menu_help->Text = L"Help";
	// 
	// menu_help_hotkey
	// 
	this->menu_help_hotkey->Name = L"menu_help_hotkey";
	this->menu_help_hotkey->Size = System::Drawing::Size(173, 22);
	this->menu_help_hotkey->Text = L"Keyboard shortcuts";
	this->menu_help_hotkey->Click += gcnew System::EventHandler(this, &mainForm::menu_help_hotkey_Click);
	// 
	// toolStripSeparator2
	// 
	this->toolStripSeparator2->Name = L"toolStripSeparator2";
	this->toolStripSeparator2->Size = System::Drawing::Size(170, 6);
	// 
	// menu_help_abt
	// 
	this->menu_help_abt->Name = L"menu_help_abt";
	this->menu_help_abt->Size = System::Drawing::Size(173, 22);
	this->menu_help_abt->Text = L"About";
	this->menu_help_abt->Click += gcnew System::EventHandler(this, &mainForm::menu_help_abt_Click);
	// 
	// s_tB_input
	// 
	this->s_tB_input->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
		static_cast<System::Byte>(134)));
	this->s_tB_input->HideSelection = false;
	this->s_tB_input->Location = System::Drawing::Point(10, 23);
	this->s_tB_input->MaxLength = 42;
	this->s_tB_input->Name = L"s_tB_input";
	this->s_tB_input->Size = System::Drawing::Size(172, 24);
	this->s_tB_input->TabIndex = 0;
	this->s_tB_input->Click += gcnew System::EventHandler(this, &mainForm::s_tB_input_Click);
	this->s_tB_input->TextChanged += gcnew System::EventHandler(this, &mainForm::s_tB_input_TextChanged);
	this->s_tB_input->LostFocus += gcnew System::EventHandler(this, &mainForm::s_tB_input_LostFocus);
	// 
	// s_grp
	// 
	this->s_grp->Controls->Add(this->s_rB_byManufacturer);
	this->s_grp->Controls->Add(this->s_l_by);
	this->s_grp->Controls->Add(this->s_rB_byCategory);
	this->s_grp->Controls->Add(this->s_rB_byBarcode);
	this->s_grp->Controls->Add(this->s_rB_byName);
	this->s_grp->Controls->Add(this->s_tB_input);
	this->s_grp->Controls->Add(this->s_b_Enter);
	this->s_grp->Location = System::Drawing::Point(14, 27);
	this->s_grp->Name = L"s_grp";
	this->s_grp->Size = System::Drawing::Size(193, 101);
	this->s_grp->TabIndex = 14;
	this->s_grp->TabStop = false;
	this->s_grp->Text = L"Search";
	// 
	// s_rB_byManufacturer
	// 
	this->s_rB_byManufacturer->AutoSize = true;
	this->s_rB_byManufacturer->Location = System::Drawing::Point(101, 74);
	this->s_rB_byManufacturer->Name = L"s_rB_byManufacturer";
	this->s_rB_byManufacturer->Size = System::Drawing::Size(85, 17);
	this->s_rB_byManufacturer->TabIndex = 4;
	this->s_rB_byManufacturer->TabStop = true;
	this->s_rB_byManufacturer->Text = L"Manufacturer";
	this->s_rB_byManufacturer->UseVisualStyleBackColor = true;
	this->s_rB_byManufacturer->CheckedChanged += gcnew System::EventHandler(this, &mainForm::s_rB_CheckedChanged);
	// 
	// s_l_by
	// 
	this->s_l_by->AutoSize = true;
	this->s_l_by->Location = System::Drawing::Point(10, 55);
	this->s_l_by->Name = L"s_l_by";
	this->s_l_by->Size = System::Drawing::Size(19, 13);
	this->s_l_by->TabIndex = 7;
	this->s_l_by->Text = L"By";
	// 
	// s_rB_byCategory
	// 
	this->s_rB_byCategory->AutoSize = true;
	this->s_rB_byCategory->Location = System::Drawing::Point(101, 54);
	this->s_rB_byCategory->Name = L"s_rB_byCategory";
	this->s_rB_byCategory->Size = System::Drawing::Size(64, 17);
	this->s_rB_byCategory->TabIndex = 2;
	this->s_rB_byCategory->TabStop = true;
	this->s_rB_byCategory->Text = L"Category";
	this->s_rB_byCategory->UseVisualStyleBackColor = true;
	this->s_rB_byCategory->CheckedChanged += gcnew System::EventHandler(this, &mainForm::s_rB_CheckedChanged);
	// 
	// s_rB_byBarcode
	// 
	this->s_rB_byBarcode->AutoSize = true;
	this->s_rB_byBarcode->Location = System::Drawing::Point(34, 74);
	this->s_rB_byBarcode->Name = L"s_rB_byBarcode";
	this->s_rB_byBarcode->Size = System::Drawing::Size(62, 17);
	this->s_rB_byBarcode->TabIndex = 3;
	this->s_rB_byBarcode->TabStop = true;
	this->s_rB_byBarcode->Text = L"Barcode";
	this->s_rB_byBarcode->UseVisualStyleBackColor = true;
	this->s_rB_byBarcode->CheckedChanged += gcnew System::EventHandler(this, &mainForm::s_rB_CheckedChanged);
	// 
	// s_rB_byName
	// 
	this->s_rB_byName->AutoSize = true;
	this->s_rB_byName->Checked = true;
	this->s_rB_byName->Location = System::Drawing::Point(34, 54);
	this->s_rB_byName->Name = L"s_rB_byName";
	this->s_rB_byName->Size = System::Drawing::Size(50, 17);
	this->s_rB_byName->TabIndex = 1;
	this->s_rB_byName->TabStop = true;
	this->s_rB_byName->Text = L"Name";
	this->s_rB_byName->UseVisualStyleBackColor = true;
	this->s_rB_byName->CheckedChanged += gcnew System::EventHandler(this, &mainForm::s_rB_CheckedChanged);
	// 
	// s_b_Enter
	// 
	this->s_b_Enter->Location = System::Drawing::Point(90, 25);
	this->s_b_Enter->Name = L"s_b_Enter";
	this->s_b_Enter->Size = System::Drawing::Size(75, 17);
	this->s_b_Enter->TabIndex = 16;
	this->s_b_Enter->Text = L"Enter";
	this->s_b_Enter->UseVisualStyleBackColor = true;
	this->s_b_Enter->Click += gcnew System::EventHandler(this, &mainForm::s_b_Enter_Click);
	// 
	// list_b_restock
	// 
	this->list_b_restock->Enabled = false;
	this->list_b_restock->Location = System::Drawing::Point(91, 19);
	this->list_b_restock->Name = L"list_b_restock";
	this->list_b_restock->Size = System::Drawing::Size(75, 23);
	this->list_b_restock->TabIndex = 6;
	this->list_b_restock->Text = L"Restock";
	this->list_b_restock->UseVisualStyleBackColor = true;
	this->list_b_restock->Click += gcnew System::EventHandler(this, &mainForm::list_b_restock_Click);
	// 
	// list_b_sell
	// 
	this->list_b_sell->Enabled = false;
	this->list_b_sell->Location = System::Drawing::Point(10, 19);
	this->list_b_sell->Name = L"list_b_sell";
	this->list_b_sell->Size = System::Drawing::Size(75, 23);
	this->list_b_sell->TabIndex = 5;
	this->list_b_sell->Text = L"Sell";
	this->list_b_sell->UseVisualStyleBackColor = true;
	this->list_b_sell->Click += gcnew System::EventHandler(this, &mainForm::list_b_sell_Click);
	// 
	// list_b_delete
	// 
	this->list_b_delete->Enabled = false;
	this->list_b_delete->Location = System::Drawing::Point(572, 19);
	this->list_b_delete->Name = L"list_b_delete";
	this->list_b_delete->Size = System::Drawing::Size(75, 23);
	this->list_b_delete->TabIndex = 7;
	this->list_b_delete->Text = L"Delete";
	this->list_b_delete->UseVisualStyleBackColor = true;
	this->list_b_delete->Click += gcnew System::EventHandler(this, &mainForm::list_b_delete_Click);
	// 
	// list_lv
	// 
	this->list_lv->Activation = System::Windows::Forms::ItemActivation::OneClick;
	this->list_lv->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(7) {this->list_col_name, this->list_col_category, 
		this->list_col_barcode, this->list_col_price, this->list_col_manuf, this->list_col_stock, this->list_col_sold});
	this->list_lv->FullRowSelect = true;
	this->list_lv->HideSelection = false;
	this->list_lv->Location = System::Drawing::Point(11, 50);
	this->list_lv->Name = L"list_lv";
	this->list_lv->ShowGroups = false;
	this->list_lv->Size = System::Drawing::Size(636, 309);
	this->list_lv->TabIndex = 8;
	this->list_lv->UseCompatibleStateImageBehavior = false;
	this->list_lv->View = System::Windows::Forms::View::Details;
	this->list_lv->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &mainForm::list_lv_ColumnClick);
	this->list_lv->SelectedIndexChanged += gcnew System::EventHandler(this, &mainForm::list_lv_SelectedIndexChanged);
	// 
	// list_col_name
	// 
	this->list_col_name->Text = L"Name";
	this->list_col_name->Width = 146;
	// 
	// list_col_category
	// 
	this->list_col_category->Text = L"Category";
	this->list_col_category->Width = 107;
	// 
	// list_col_barcode
	// 
	this->list_col_barcode->Text = L"Barcode";
	this->list_col_barcode->Width = 86;
	// 
	// list_col_price
	// 
	this->list_col_price->Text = L"Price";
	// 
	// list_col_manuf
	// 
	this->list_col_manuf->Text = L"Manufacturer";
	this->list_col_manuf->Width = 97;
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
	this->list_grp->Controls->Add(this->list_b_modify);
	this->list_grp->Controls->Add(this->list_lv);
	this->list_grp->Controls->Add(this->list_b_restock);
	this->list_grp->Controls->Add(this->list_b_sell);
	this->list_grp->Controls->Add(this->list_b_delete);
	this->list_grp->Location = System::Drawing::Point(218, 27);
	this->list_grp->Name = L"list_grp";
	this->list_grp->Size = System::Drawing::Size(658, 373);
	this->list_grp->TabIndex = 13;
	this->list_grp->TabStop = false;
	this->list_grp->Text = L"Result";
	// 
	// list_b_modify
	// 
	this->list_b_modify->Enabled = false;
	this->list_b_modify->Location = System::Drawing::Point(172, 19);
	this->list_b_modify->Name = L"list_b_modify";
	this->list_b_modify->Size = System::Drawing::Size(75, 23);
	this->list_b_modify->TabIndex = 9;
	this->list_b_modify->Text = L"Modify";
	this->list_b_modify->UseVisualStyleBackColor = true;
	this->list_b_modify->Click += gcnew System::EventHandler(this, &mainForm::list_b_modify_Click);
	// 
	// statusStrip1
	// 
	this->statusStrip1->BackColor = System::Drawing::Color::LightSkyBlue;
	this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
	this->statusStrip1->Location = System::Drawing::Point(0, 409);
	this->statusStrip1->Name = L"statusStrip1";
	this->statusStrip1->Size = System::Drawing::Size(890, 22);
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
	this->AcceptButton = this->s_b_Enter;
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(890, 431);
	this->Controls->Add(this->statusStrip1);
	this->Controls->Add(this->list_grp);
	this->Controls->Add(this->s_grp);
	this->Controls->Add(this->menu);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
	this->KeyPreview = true;
	this->MainMenuStrip = this->menu;
	this->MaximizeBox = false;
	this->Name = L"mainForm";
	this->Text = L" CICMS";
	this->Load += gcnew System::EventHandler(this, &mainForm::mainForm_Load);
	this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &mainForm::mainForm_KeyDown);
	this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &mainForm::mainForm_KeyPress);
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
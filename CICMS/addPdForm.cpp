/*************************************************************************************************/
//
//  class addPdForm: addPdForm.cpp
//
//  Description: addPdForm.cpp contains the implementation part of class addPdForm.
//
//  API:
//  CICMS_UI::addPdForm::addPdForm(); //create a addPdForm object
//  CICMS_UI::addPdForm::System::Windows::Forms::get_product_details() //Allows other objects to pull the data gathered in this object to them
//
//  Main authors: XIE KAI(A0102016E), BOB WONG (A0094718U)
//
/*************************************************************************************************/
#include "stdafx.h"
#include "addPdForm.h"
#include "InputCheck.h"

using namespace CICMS_UI;
addPdForm::addPdForm(void)
{
	InitializeComponent();
	this->DefaultColor = this->npd_tB_name->BackColor;
}

void addPdForm::InitializeComponent(void) //Initializes every single component on the form
{
	this->npd_grp = (gcnew System::Windows::Forms::GroupBox());
	this->npd_tB_name = (gcnew System::Windows::Forms::TextBox());
	this->npd_tB_category = (gcnew System::Windows::Forms::TextBox());
	this->npd_tB_barcode = (gcnew System::Windows::Forms::TextBox());
	this->npd_tB_price = (gcnew System::Windows::Forms::TextBox());
	this->npd_tB_manuf = (gcnew System::Windows::Forms::TextBox());
	this->npd_l_price = (gcnew System::Windows::Forms::Label());
	this->npd_l_manuf = (gcnew System::Windows::Forms::Label());
	this->npd_l_category = (gcnew System::Windows::Forms::Label());
	this->npd_l_barcode = (gcnew System::Windows::Forms::Label());
	this->npd_l_name = (gcnew System::Windows::Forms::Label());
	this->npd_b_cancel = (gcnew System::Windows::Forms::Button());
	this->npd_b_ok = (gcnew System::Windows::Forms::Button());
	this->npd_grp->SuspendLayout();
	this->SuspendLayout();
	// 
	// npd_grp
	// 
	this->npd_grp->Controls->Add(this->npd_tB_name);
	this->npd_grp->Controls->Add(this->npd_tB_category);
	this->npd_grp->Controls->Add(this->npd_tB_barcode);
	this->npd_grp->Controls->Add(this->npd_tB_price);
	this->npd_grp->Controls->Add(this->npd_tB_manuf);
	this->npd_grp->Controls->Add(this->npd_l_price);
	this->npd_grp->Controls->Add(this->npd_l_manuf);
	this->npd_grp->Controls->Add(this->npd_l_category);
	this->npd_grp->Controls->Add(this->npd_l_barcode);
	this->npd_grp->Controls->Add(this->npd_l_name);
	this->npd_grp->Location = System::Drawing::Point(14, 10);
	this->npd_grp->Name = L"npd_grp";
	this->npd_grp->Size = System::Drawing::Size(247, 164);
	this->npd_grp->TabIndex = 5;
	this->npd_grp->TabStop = false;
	this->npd_grp->Text = L"New product details";
	this->npd_grp->Enter += gcnew System::EventHandler(this, &addPdForm::npd_grp_Enter);
	// 
	// npd_tB_name
	// 
	this->npd_tB_name->Location = System::Drawing::Point(88, 24);
	this->npd_tB_name->MaxLength = 42;
	this->npd_tB_name->Name = L"npd_tB_name";
	this->npd_tB_name->Size = System::Drawing::Size(138, 20);
	this->npd_tB_name->TabIndex = 5;
	this->npd_tB_name->TextChanged += gcnew System::EventHandler(this, &addPdForm::npd_tB_name_TextChanged);
	this->npd_tB_name->LostFocus += gcnew System::EventHandler(this, &addPdForm::npd_tB_name_LostFocus);
	// 
	// npd_tB_category
	// 
	this->npd_tB_category->Location = System::Drawing::Point(87, 50);
	this->npd_tB_category->MaxLength = 42;
	this->npd_tB_category->Name = L"npd_tB_category";
	this->npd_tB_category->Size = System::Drawing::Size(138, 20);
	this->npd_tB_category->TabIndex = 6;
	this->npd_tB_category->TextChanged += gcnew System::EventHandler(this, &addPdForm::npd_tB_category_TextChanged);
	this->npd_tB_category->LostFocus += gcnew System::EventHandler(this, &addPdForm::npd_tB_category_LostFocus);
	// 
	// npd_tB_barcode
	// 
	this->npd_tB_barcode->Location = System::Drawing::Point(87, 76);
	this->npd_tB_barcode->MaxLength = 9;
	this->npd_tB_barcode->Name = L"npd_tB_barcode";
	this->npd_tB_barcode->Size = System::Drawing::Size(138, 20);
	this->npd_tB_barcode->TabIndex = 7;
	this->npd_tB_barcode->TextChanged += gcnew System::EventHandler(this, &addPdForm::npd_tB_barcode_TextChanged);
	this->npd_tB_barcode->LostFocus += gcnew System::EventHandler(this, &addPdForm::npd_tB_barcode_LostFocus);
	// 
	// npd_tB_price
	// 
	this->npd_tB_price->Location = System::Drawing::Point(87, 102);
	this->npd_tB_price->MaxLength = 9;
	this->npd_tB_price->Name = L"npd_tB_price";
	this->npd_tB_price->Size = System::Drawing::Size(138, 20);
	this->npd_tB_price->TabIndex = 8;
	this->npd_tB_price->TextChanged += gcnew System::EventHandler(this, &addPdForm::npd_tB_price_TextChanged);
	this->npd_tB_price->LostFocus += gcnew System::EventHandler(this, &addPdForm::npd_tB_price_LostFocus);
	// 
	// npd_tB_manuf
	// 
	this->npd_tB_manuf->Location = System::Drawing::Point(87, 128);
	this->npd_tB_manuf->MaxLength = 42;
	this->npd_tB_manuf->Name = L"npd_tB_manuf";
	this->npd_tB_manuf->Size = System::Drawing::Size(138, 20);
	this->npd_tB_manuf->TabIndex = 9;
	this->npd_tB_manuf->TextChanged += gcnew System::EventHandler(this, &addPdForm::npd_tB_manuf_TextChanged);
	this->npd_tB_manuf->LostFocus += gcnew System::EventHandler(this, &addPdForm::npd_tB_manuf_LostFocus);
	// 
	// npd_l_price
	// 
	this->npd_l_price->AutoSize = true;
	this->npd_l_price->Location = System::Drawing::Point(11, 105);
	this->npd_l_price->Name = L"npd_l_price";
	this->npd_l_price->Size = System::Drawing::Size(31, 13);
	this->npd_l_price->TabIndex = 4;
	this->npd_l_price->Text = L"Price";
	// 
	// npd_l_manuf
	// 
	this->npd_l_manuf->AutoSize = true;
	this->npd_l_manuf->Location = System::Drawing::Point(11, 131);
	this->npd_l_manuf->Name = L"npd_l_manuf";
	this->npd_l_manuf->Size = System::Drawing::Size(70, 13);
	this->npd_l_manuf->TabIndex = 3;
	this->npd_l_manuf->Text = L"Manufacturer";
	// 
	// npd_l_category
	// 
	this->npd_l_category->AutoSize = true;
	this->npd_l_category->Location = System::Drawing::Point(11, 53);
	this->npd_l_category->Name = L"npd_l_category";
	this->npd_l_category->Size = System::Drawing::Size(49, 13);
	this->npd_l_category->TabIndex = 2;
	this->npd_l_category->Text = L"Category";
	// 
	// npd_l_barcode
	// 
	this->npd_l_barcode->AutoSize = true;
	this->npd_l_barcode->Location = System::Drawing::Point(11, 79);
	this->npd_l_barcode->Name = L"npd_l_barcode";
	this->npd_l_barcode->Size = System::Drawing::Size(47, 13);
	this->npd_l_barcode->TabIndex = 1;
	this->npd_l_barcode->Text = L"Barcode";
	// 
	// npd_l_name
	// 
	this->npd_l_name->AutoSize = true;
	this->npd_l_name->Location = System::Drawing::Point(11, 27);
	this->npd_l_name->Name = L"npd_l_name";
	this->npd_l_name->Size = System::Drawing::Size(35, 13);
	this->npd_l_name->TabIndex = 0;
	this->npd_l_name->Text = L"Name";
	// 
	// npd_b_cancel
	// 
	this->npd_b_cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	this->npd_b_cancel->Location = System::Drawing::Point(155, 184);
	this->npd_b_cancel->Name = L"npd_b_cancel";
	this->npd_b_cancel->Size = System::Drawing::Size(75, 23);
	this->npd_b_cancel->TabIndex = 7;
	this->npd_b_cancel->Text = L"Cancel";
	this->npd_b_cancel->UseVisualStyleBackColor = true;
	// 
	// npd_b_ok
	// 
	this->npd_b_ok->Location = System::Drawing::Point(39, 184);
	this->npd_b_ok->Name = L"npd_b_ok";
	this->npd_b_ok->Size = System::Drawing::Size(75, 23);
	this->npd_b_ok->TabIndex = 6;
	this->npd_b_ok->Text = L"OK";
	this->npd_b_ok->UseVisualStyleBackColor = true;
	this->npd_b_ok->Click += gcnew System::EventHandler(this, &addPdForm::npd_b_ok_Click);
	// 
	// addPdForm
	// 
	this->AcceptButton = this->npd_b_ok;
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->CancelButton = this->npd_b_cancel;
	this->ClientSize = System::Drawing::Size(275, 218);
	this->Controls->Add(this->npd_b_cancel);
	this->Controls->Add(this->npd_b_ok);
	this->Controls->Add(this->npd_grp);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
	this->MaximizeBox = false;
	this->MinimizeBox = false;
	this->Name = L"addPdForm";
	this->Text = L" Add a new product";
	this->npd_grp->ResumeLayout(false);
	this->npd_grp->PerformLayout();
	this->ResumeLayout(false);

}

//instant Checking for npd_tB_name
void addPdForm::npd_tB_name_TextChanged(System::Object^  sender, System::EventArgs^  e){
	if(InputCheck::is_empty(this->npd_tB_name->Text))
		this->npd_tB_name->BackColor = System::Drawing::Color::LightSalmon;
	else
		this->npd_tB_name->BackColor = this->DefaultColor;
}
void addPdForm::npd_tB_name_LostFocus(System::Object^  sender, System::EventArgs^  e){
	if(InputCheck::is_empty(this->npd_tB_name->Text))
		this->npd_tB_name->BackColor = System::Drawing::Color::LightSalmon;
}
//instant Checking for npd_tB_category
void addPdForm::npd_tB_category_TextChanged(System::Object^  sender, System::EventArgs^  e){
	if(InputCheck::is_empty(this->npd_tB_category->Text))
		this->npd_tB_category->BackColor = System::Drawing::Color::LightSalmon;
	else
		this->npd_tB_category->BackColor = this->DefaultColor;
}
void addPdForm::npd_tB_category_LostFocus(System::Object^  sender, System::EventArgs^  e){
	if(InputCheck::is_empty(this->npd_tB_category->Text))
		this->npd_tB_category->BackColor = System::Drawing::Color::LightSalmon;
}
//instant Checking for npd_tB_barcode
void addPdForm::npd_tB_barcode_TextChanged(System::Object^  sender, System::EventArgs^  e){
	if(!InputCheck::is_int(this->npd_tB_barcode->Text))
		this->npd_tB_barcode->BackColor = System::Drawing::Color::LightSalmon;
	else if(InputCheck::lessThan_zero(this->npd_tB_barcode->Text))
		this->npd_tB_barcode->BackColor = System::Drawing::Color::LightSalmon;
	else
		this->npd_tB_barcode->BackColor = this->DefaultColor;
}
void addPdForm::npd_tB_barcode_LostFocus(System::Object^  sender, System::EventArgs^  e){
	if(InputCheck::is_empty(this->npd_tB_barcode->Text))
		this->npd_tB_barcode->BackColor = System::Drawing::Color::LightSalmon;
}
//instant Checking for npd_tB_price
void addPdForm::npd_tB_price_TextChanged(System::Object^  sender, System::EventArgs^  e){
	if(!InputCheck::is_number(this->npd_tB_price->Text))
		this->npd_tB_price->BackColor = System::Drawing::Color::LightSalmon;
	else if(InputCheck::lessThan_zero(this->npd_tB_price->Text))
		this->npd_tB_price->BackColor = System::Drawing::Color::LightSalmon;
	else
		this->npd_tB_price->BackColor = this->DefaultColor;
}
void addPdForm::npd_tB_price_LostFocus(System::Object^  sender, System::EventArgs^  e){
	if(InputCheck::is_empty(this->npd_tB_price->Text))
		this->npd_tB_price->BackColor = System::Drawing::Color::LightSalmon;
}
//instant Checking for npd_tB_manuf
void addPdForm::npd_tB_manuf_TextChanged(System::Object^  sender, System::EventArgs^  e){
	if(InputCheck::is_empty(this->npd_tB_manuf->Text))
		this->npd_tB_manuf->BackColor = System::Drawing::Color::LightSalmon;
	else
		this->npd_tB_manuf->BackColor = this->DefaultColor;
}
void addPdForm::npd_tB_manuf_LostFocus(System::Object^  sender, System::EventArgs^  e){
	if(InputCheck::is_empty(this->npd_tB_manuf->Text))
		this->npd_tB_manuf->BackColor = System::Drawing::Color::LightSalmon;
}

// Upon clicking the OK button, stuff happens here
// possibly notifying the logic classes to call get_product_details()
void addPdForm::npd_b_ok_Click(System::Object^  sender, System::EventArgs^  e) {
	//unfocus every textbox to check whether they are empty or not
	this->npd_tB_name->Focus();
	this->npd_tB_category->Focus();
	this->npd_tB_manuf->Focus();
	this->npd_tB_barcode->Focus();
	this->npd_tB_price->Focus();
	this->npd_b_ok->Focus();

	//start input checking
	if(InputCheck::is_empty(this->npd_tB_name->Text)){
		System::Windows::Forms::MessageBox::Show("Please fill in all the fields.");
		this->npd_tB_name->Focus();
	}
	else if(InputCheck::is_empty(this->npd_tB_category->Text)){
		System::Windows::Forms::MessageBox::Show("Please fill in all the fields.");
		this->npd_tB_category->Focus();
	}
	else if(InputCheck::is_empty(this->npd_tB_barcode->Text)){
		System::Windows::Forms::MessageBox::Show("Please fill in all the fields.");
		this->npd_tB_barcode->Focus();
	}
	else if(!InputCheck::is_int(this->npd_tB_barcode->Text)){
		System::Windows::Forms::MessageBox::Show("Please input an integer in the barcode field.");
		this->npd_tB_barcode->Focus();
		this->npd_tB_barcode->SelectAll();
	}
	else if(InputCheck::lessThan_zero(this->npd_tB_barcode->Text)){
		System::Windows::Forms::MessageBox::Show("Please input an integer larger than zero in the barcode field.");
		this->npd_tB_barcode->Focus();
		this->npd_tB_barcode->SelectAll();
	}
	else if(InputCheck::is_empty(this->npd_tB_price->Text)){
		System::Windows::Forms::MessageBox::Show("Please fill in all the fields.");
		this->npd_tB_price->Focus();
	}
	else if(!InputCheck::is_number(this->npd_tB_price->Text)){
		System::Windows::Forms::MessageBox::Show("Please input a number in the price field.");
		this->npd_tB_price->Focus();
		this->npd_tB_price->SelectAll();
	}
	else if(InputCheck::lessThan_zero(this->npd_tB_price->Text)){
		System::Windows::Forms::MessageBox::Show("Please input a number larger than zero in the price field.");
		this->npd_tB_price->Focus();
		this->npd_tB_price->SelectAll();
	}
	else if(InputCheck::is_empty(this->npd_tB_manuf->Text)){
		System::Windows::Forms::MessageBox::Show("Please fill in all the fields.");
		this->npd_tB_manuf->Focus();
	}
	else{
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
}

//Data return in the form of strings
System::Windows::Forms::ListViewItem^ addPdForm::get_product_details(){
	return gcnew System::Windows::Forms::ListViewItem(gcnew cli::array<System::String^>(7) {
		this->npd_tB_name->Text, 
		this->npd_tB_category->Text,
		this->npd_tB_barcode->Text,
		this->npd_tB_price->Text, 
		this->npd_tB_manuf->Text
	});
}

void addPdForm::set_npd_grp_text(System::String^ s){
	this->npd_grp->Text = s;
}
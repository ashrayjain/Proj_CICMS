/*************************************************************************************************/
//
//  class inputForm: inputForm.cpp
//
//  Description: inputForm.h contains the implementation part of class inputForm.
//
//
//  API:
//  CICMS_UI::inputForm::inputForm(); //create a inputForm object
//  CICMS_UI::inputForm::get_input(); // Called to return double datatype of value entered in this object
//  CICMS_UI::inputForm::set_inputForm(); //Called to set the default starting value and name/content of this object
//	CICMS_UI::inputForm::set_formType(int i) //set an inputForm for number or string
//	CICMS_UI::inputForm::TOP_X_filter(bool c) //set a threshold (100) for inputForm (formType: NUMBER)
//
//  Main authors: XIE KAI(A0102016E), HUI HUI(A0105566E)
//
/*************************************************************************************************/

#include "stdafx.h"
#include "inputForm.h"
#include "InputCheck.h"

using namespace CICMS_UI;

void inputForm::InitializeComponent()
{
	this->input_l_descript = (gcnew System::Windows::Forms::Label());
	this->input_b_yes = (gcnew System::Windows::Forms::Button());
	this->input_b_no = (gcnew System::Windows::Forms::Button());
	this->input_tB_input = (gcnew System::Windows::Forms::TextBox());
	this->input_l_pd = (gcnew System::Windows::Forms::Label());
	this->panel1 = (gcnew System::Windows::Forms::Panel());
	this->panel2 = (gcnew System::Windows::Forms::Panel());
	this->panel1->SuspendLayout();
	this->panel2->SuspendLayout();
	this->SuspendLayout();
	// 
	// input_l_descript
	// 
	this->input_l_descript->AutoSize = true;
	this->input_l_descript->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
	this->input_l_descript->Location = System::Drawing::Point(4, 3);
	this->input_l_descript->Name = L"input_l_descript";
	this->input_l_descript->Size = System::Drawing::Size(69, 13);
	this->input_l_descript->TabIndex = 0;
	this->input_l_descript->Text = L"inputDescript";
	// 
	// input_b_yes
	// 
	this->input_b_yes->Enabled = false;
	this->input_b_yes->Location = System::Drawing::Point(3, 3);
	this->input_b_yes->Name = L"input_b_yes";
	this->input_b_yes->Size = System::Drawing::Size(75, 23);
	this->input_b_yes->TabIndex = 2;
	this->input_b_yes->Text = L"OK";
	this->input_b_yes->UseVisualStyleBackColor = true;
	this->input_b_yes->Click += gcnew System::EventHandler(this, &inputForm::input_b_yes_Click);
	// 
	// input_b_no
	// 
	this->input_b_no->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	this->input_b_no->Location = System::Drawing::Point(84, 3);
	this->input_b_no->Name = L"input_b_no";
	this->input_b_no->Size = System::Drawing::Size(75, 23);
	this->input_b_no->TabIndex = 3;
	this->input_b_no->Text = L"Cancel";
	this->input_b_no->UseVisualStyleBackColor = true;
	// 
	// input_tB_input
	// 
	this->input_tB_input->Location = System::Drawing::Point(74, 0);
	this->input_tB_input->MaxLength = 42;
	this->input_tB_input->Name = L"input_tB_input";
	this->input_tB_input->Size = System::Drawing::Size(85, 20);
	this->input_tB_input->TabIndex = 1;
	this->input_tB_input->Text = L"stringInTB";
	this->input_tB_input->TextChanged += gcnew System::EventHandler(this, &inputForm::input_tB_input_TextChanged);
	this->input_tB_input->LostFocus += gcnew System::EventHandler(this, &inputForm::input_tB_input_LostFocus);
	// 
	// input_l_pd
	// 
	this->input_l_pd->AutoSize = true;
	this->input_l_pd->Location = System::Drawing::Point(12, 17);
	this->input_l_pd->Margin = System::Windows::Forms::Padding(3);
	this->input_l_pd->Name = L"input_l_pd";
	this->input_l_pd->Size = System::Drawing::Size(58, 13);
	this->input_l_pd->TabIndex = 4;
	this->input_l_pd->Text = L"pdDescript";
	// 
	// panel1
	// 
	this->panel1->Controls->Add(this->input_b_yes);
	this->panel1->Controls->Add(this->input_b_no);
	this->panel1->Location = System::Drawing::Point(10, 74);
	this->panel1->Name = L"panel1";
	this->panel1->Size = System::Drawing::Size(162, 29);
	this->panel1->TabIndex = 5;
	// 
	// panel2
	// 
	this->panel2->Controls->Add(this->input_tB_input);
	this->panel2->Controls->Add(this->input_l_descript);
	this->panel2->Location = System::Drawing::Point(10, 39);
	this->panel2->Name = L"panel2";
	this->panel2->Size = System::Drawing::Size(162, 22);
	this->panel2->TabIndex = 6;
	// 
	// inputForm
	// 
	this->AcceptButton = this->input_b_yes;
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->AutoSize = true;
	this->BackColor = System::Drawing::SystemColors::ControlLight;
	this->CancelButton = this->input_b_no;
	this->ClientSize = System::Drawing::Size(182, 115);
	this->Controls->Add(this->panel2);
	this->Controls->Add(this->panel1);
	this->Controls->Add(this->input_l_pd);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
	this->MaximizeBox = false;
	this->MinimizeBox = false;
	this->Name = L"inputForm";
	this->Text = L"formTitle";
	this->Load += gcnew System::EventHandler(this, &inputForm::inputForm_Load);
	this->panel1->ResumeLayout(false);
	this->panel2->ResumeLayout(false);
	this->panel2->PerformLayout();
	this->ResumeLayout(false);
	this->PerformLayout();

}
//Event: when input_b_yes is click
void inputForm::input_b_yes_Click(System::Object^  sender, System::EventArgs^  e) {

	if(InputCheck::is_empty(this->input_tB_input->Text)){
		System::Windows::Forms::MessageBox::Show("Please fill in the field.");
		this->input_tB_input->Focus();
		this->input_tB_input->SelectAll();
	}
	else if(this->formType == NUMBER && !InputCheck::is_int(this->input_tB_input->Text)){
		System::Windows::Forms::MessageBox::Show("Please input an integer");
		this->input_tB_input->Focus();
		this->input_tB_input->SelectAll();
	}
	else if(this->formType == NUMBER && InputCheck::lessThan_zero(this->input_tB_input->Text)){
		System::Windows::Forms::MessageBox::Show("Please input an integer larger than zero.");
		this->input_tB_input->Focus();
		this->input_tB_input->SelectAll();
	}
	else if(this->formType == NUMBER && this->TOP_X == true && InputCheck::is_large(this->input_tB_input->Text)){
		System::Windows::Forms::MessageBox::Show("The number for X must be not greater than 100.");
		this->input_tB_input->Focus();
		this->input_tB_input->SelectAll();
	}
	else{
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
}
//Function: set the inputForm's title, 2 descriptions, and the value in the textBox
void inputForm::set_inputForm(System::String^ title, System::String^ pdDescript, System::String^ descript, System::String^ stringInTB){
	this->Text = title;
	this->input_l_pd->Text = pdDescript;
	this->input_l_descript->Text = descript;
	this->input_tB_input->Text = stringInTB;
	this->input_tB_input->BackColor = this->DefaultColor;
	this->input_l_pd->Location = System::Drawing::Point((int) (this->Width - this->input_l_pd->Width) / 2 - 2, 17);
	this->panel2->Location = System::Drawing::Point((int) (this->Width - this->panel2->Width) / 2 - 3, 39);
	this->panel1->Location = System::Drawing::Point((int) (this->Width - this->panel1->Width) / 2 - 3, 74);
}
//Event: triggered when the inputForm is loaded
void inputForm::inputForm_Load(System::Object^  sender, System::EventArgs^  e){
	if(formType == NUMBER)
		this->input_tB_input->MaxLength = 7;
	else if(formType == STRING)
		this->input_tB_input->MaxLength = 42;
	this->input_tB_input->Select();
}
//instant checking
void inputForm::input_tB_input_TextChanged(System::Object^  sender, System::EventArgs^  e){
	this->submitButton_toggle();
	if(InputCheck::is_empty(this->input_tB_input->Text))
		this->input_tB_input->BackColor = System::Drawing::Color::LightSalmon;
	else if(this->formType == NUMBER && !InputCheck::is_int(this->input_tB_input->Text))
		this->input_tB_input->BackColor = System::Drawing::Color::LightSalmon;
	else if(this->formType == NUMBER && InputCheck::lessThan_zero(this->input_tB_input->Text))
		this->input_tB_input->BackColor = System::Drawing::Color::LightSalmon;
	else if(this->formType == NUMBER && this->TOP_X == true && InputCheck::is_large(this->input_tB_input->Text))
		this->input_tB_input->BackColor = System::Drawing::Color::LightSalmon;
	else
		this->input_tB_input->BackColor = this->DefaultColor;
}

//event triggered when the input textBox lose the focus
//show red color to indicate the error
void inputForm::input_tB_input_LostFocus(System::Object^  sender, System::EventArgs^  e){
	if(!this->input_b_no->Focused && InputCheck::is_empty(this->input_tB_input->Text))
		this->input_tB_input->BackColor = System::Drawing::Color::LightSalmon;
}

//if the input textBox is empty, disable the submit button
void inputForm::submitButton_toggle(){
	if(InputCheck::is_empty(this->input_tB_input->Text))
		this->input_b_yes->Enabled = false;
	else
		this->input_b_yes->Enabled = true;
}
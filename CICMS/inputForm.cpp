#include "stdafx.h"
#include "inputForm.h"

using namespace CICMS_UI;

void inputForm::InitializeComponent()
{
	this->input_l_descript = (gcnew System::Windows::Forms::Label());
	this->input_b_yes = (gcnew System::Windows::Forms::Button());
	this->input_b_no = (gcnew System::Windows::Forms::Button());
	this->input_tB_input = (gcnew System::Windows::Forms::TextBox());
	this->input_l_pd = (gcnew System::Windows::Forms::Label());
	this->SuspendLayout();
	// 
	// input_l_descript
	// 
	this->input_l_descript->AutoSize = true;
	this->input_l_descript->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
	this->input_l_descript->Location = System::Drawing::Point(12, 42);
	this->input_l_descript->Name = L"input_l_descript";
	this->input_l_descript->Size = System::Drawing::Size(69, 13);
	this->input_l_descript->TabIndex = 0;
	this->input_l_descript->Text = L"inputDescript";
	// 
	// input_b_yes
	// 
	this->input_b_yes->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->input_b_yes->Location = System::Drawing::Point(13, 73);
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
	this->input_b_no->Location = System::Drawing::Point(94, 73);
	this->input_b_no->Name = L"input_b_no";
	this->input_b_no->Size = System::Drawing::Size(75, 23);
	this->input_b_no->TabIndex = 3;
	this->input_b_no->Text = L"Cancel";
	this->input_b_no->UseVisualStyleBackColor = true;
	// 
	// input_tB_input
	// 
	this->input_tB_input->Location = System::Drawing::Point(82, 39);
	this->input_tB_input->MaxLength = 10;
	this->input_tB_input->Name = L"input_tB_input";
	this->input_tB_input->Size = System::Drawing::Size(85, 20);
	this->input_tB_input->TabIndex = 1;
	this->input_tB_input->Text = L"stringInTB";
	// 
	// input_l_pd
	// 
	this->input_l_pd->AutoSize = true;
	this->input_l_pd->Location = System::Drawing::Point(12, 17);
	this->input_l_pd->Name = L"input_l_pd";
	this->input_l_pd->Size = System::Drawing::Size(58, 13);
	this->input_l_pd->TabIndex = 4;
	this->input_l_pd->Text = L"pdDescript";
	// 
	// inputForm
	// 
	this->AcceptButton = this->input_b_yes;
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->BackColor = System::Drawing::SystemColors::ControlLight;
	this->CancelButton = this->input_b_no;
	this->ClientSize = System::Drawing::Size(182, 115);
	this->Controls->Add(this->input_l_pd);
	this->Controls->Add(this->input_tB_input);
	this->Controls->Add(this->input_b_no);
	this->Controls->Add(this->input_b_yes);
	this->Controls->Add(this->input_l_descript);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
	this->MaximizeBox = false;
	this->MinimizeBox = false;
	this->Name = L"inputForm";
	this->Text = L"formTitle";
	this->ResumeLayout(false);
	this->PerformLayout();
}

void inputForm::input_b_yes_Click(System::Object^  sender, System::EventArgs^  e) {
	//submit check here
	if(!is_valid(input_tB_input->Text))
		input_tB_input->Text = "0";
}

bool inputForm:: is_number(System::String^ s){
	try{
		System::Convert::ToDouble(s);
	} catch(System::FormatException^){
		return false;
	}
	return true;
}

bool inputForm::is_valid(System::String^ s){
	if(s->Contains("%")){
		System::Windows::Forms::MessageBox::Show("Please input something like 0.9, instead of 90%.");
		return false;
	}
	else if(!is_number(s)){
		System::Windows::Forms::MessageBox::Show("Please input a number.");
		return false;
	}
	else return true;
}

void inputForm::set_inputForm(System::String^ title, System::String^ pdDescript, System::String^ descript, System::String^ stringInTB){
	this->Text = title;
	this->input_l_pd->Text = pdDescript;
	this->input_l_descript->Text = descript;
	this->input_tB_input->Text = stringInTB;
}
#pragma once

namespace CICMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for inputForm
	/// </summary>
	public ref class inputForm : public System::Windows::Forms::Form
	{
	public:
		inputForm(String^ formTitle, String^ inputDescrip)
		{
			InitializeComponent(formTitle, inputDescrip);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~inputForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  input_l_descrip;
	private: System::Windows::Forms::Button^  input_b_yes;
	private: System::Windows::Forms::Button^  input_b_no;
	protected: 



	private: System::Windows::Forms::TextBox^  input_tB_input;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(String^ formTitle, String^ inputDescrip)
		{
			this->input_l_descrip = (gcnew System::Windows::Forms::Label());
			this->input_b_yes = (gcnew System::Windows::Forms::Button());
			this->input_b_no = (gcnew System::Windows::Forms::Button());
			this->input_tB_input = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// input_l_descrip
			// 
			this->input_l_descrip->AutoSize = true;
			this->input_l_descrip->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->input_l_descrip->Location = System::Drawing::Point(12, 24);
			this->input_l_descrip->Name = L"input_l_descrip";
			this->input_l_descrip->Size = System::Drawing::Size(27, 13);
			this->input_l_descrip->TabIndex = 0;
			this->input_l_descrip->Text = inputDescrip;
			// 
			// input_b_yes
			// 
			this->input_b_yes->Location = System::Drawing::Point(13, 59);
			this->input_b_yes->Name = L"input_b_yes";
			this->input_b_yes->Size = System::Drawing::Size(75, 23);
			this->input_b_yes->TabIndex = 1;
			this->input_b_yes->Text = L"OK";
			this->input_b_yes->UseVisualStyleBackColor = true;
			this->input_b_yes->Click += gcnew System::EventHandler(this, &inputForm::input_b_yes_Click);
			// 
			// input_b_no
			// 
			this->input_b_no->Location = System::Drawing::Point(94, 59);
			this->input_b_no->Name = L"input_b_no";
			this->input_b_no->Size = System::Drawing::Size(75, 23);
			this->input_b_no->TabIndex = 2;
			this->input_b_no->Text = L"Cancel";
			this->input_b_no->UseVisualStyleBackColor = true;
			this->input_b_no->Click += gcnew System::EventHandler(this, &inputForm::input_b_no_Click);
			// 
			// input_tB_input
			//
			this->input_tB_input->MaxLength = 10;
			this->input_tB_input->Name = L"input_tB_input";
			this->input_tB_input->Text = "1";
			if(inputDescrip == "Sell:"){
				this->input_tB_input->Location = System::Drawing::Point(45, 21);
				this->input_tB_input->Size = System::Drawing::Size(122, 20);
			}
			else{
				this->input_tB_input->Location = System::Drawing::Point(67, 21);
				this->input_tB_input->Size = System::Drawing::Size(100, 20);
			}
			this->input_tB_input->TabIndex = 3;
			// 
			// inputForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(182, 95);
			this->Controls->Add(this->input_tB_input);
			this->Controls->Add(this->input_b_no);
			this->Controls->Add(this->input_b_yes);
			this->Controls->Add(this->input_l_descrip);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"inputForm";
			this->Text = formTitle;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void input_b_yes_Click(System::Object^  sender, System::EventArgs^  e) {
				Close();
			 }
	private: System::Void input_b_no_Click(System::Object^  sender, System::EventArgs^  e) {
				Close();
			 }
};
}

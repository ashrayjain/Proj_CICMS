#include "stdafx.h"
#include "addPdForm.h"

using namespace CICMS_UI;
addPdForm::addPdForm(void)
		{
			InitializeComponent();
		}

void addPdForm::InitializeComponent(void) //Initializes every single component on the form
			 {
				 this->npd_grp = (gcnew System::Windows::Forms::GroupBox());
				 this->npd_tB_name = (gcnew System::Windows::Forms::TextBox());
				 this->npd_tB_category = (gcnew System::Windows::Forms::TextBox());
				 this->npd_tB_barcode = (gcnew System::Windows::Forms::TextBox());
				 this->npd_tB_price = (gcnew System::Windows::Forms::TextBox());
				 this->npd_tB_manuf = (gcnew System::Windows::Forms::TextBox());
				 this->npd_tB_stock = (gcnew System::Windows::Forms::TextBox());
				 this->npd_tB_sold = (gcnew System::Windows::Forms::TextBox());
				 this->npd_l_sold = (gcnew System::Windows::Forms::Label());
				 this->npd_l_stock = (gcnew System::Windows::Forms::Label());
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
				 // Primary groupbox
				 // 
				 this->npd_grp->Controls->Add(this->npd_tB_name);
				 this->npd_grp->Controls->Add(this->npd_tB_category);
				 this->npd_grp->Controls->Add(this->npd_tB_barcode);
				 this->npd_grp->Controls->Add(this->npd_tB_price);
				 this->npd_grp->Controls->Add(this->npd_tB_manuf);
				 this->npd_grp->Controls->Add(this->npd_tB_stock);
				 this->npd_grp->Controls->Add(this->npd_tB_sold);
				 this->npd_grp->Controls->Add(this->npd_l_sold);
				 this->npd_grp->Controls->Add(this->npd_l_stock);
				 this->npd_grp->Controls->Add(this->npd_l_price);
				 this->npd_grp->Controls->Add(this->npd_l_manuf);
				 this->npd_grp->Controls->Add(this->npd_l_category);
				 this->npd_grp->Controls->Add(this->npd_l_barcode);
				 this->npd_grp->Controls->Add(this->npd_l_name);
				 this->npd_grp->Location = System::Drawing::Point(14, 10); 
				 this->npd_grp->Name = L"npd_grp";
				 this->npd_grp->Size = System::Drawing::Size(247, 213); 
				 this->npd_grp->TabIndex = 5;
				 this->npd_grp->TabStop = false;
				 this->npd_grp->Text = L"New product details";
				 // 
				 // Name textbox
				 // 
				 this->npd_tB_name->Location = System::Drawing::Point(88, 24);
				 this->npd_tB_name->Name = L"npd_tB_name";
				 this->npd_tB_name->Size = System::Drawing::Size(138, 20);
				 this->npd_tB_name->TabIndex = 5;
				 // 
				 // Category textbox
				 // 
				 this->npd_tB_category->Location = System::Drawing::Point(87, 50);
				 this->npd_tB_category->Name = L"npd_tB_category";
				 this->npd_tB_category->Size = System::Drawing::Size(138, 20);
				 this->npd_tB_category->TabIndex = 6;
				 // 
				 // Barcode textbox
				 // 
				 this->npd_tB_barcode->Location = System::Drawing::Point(87, 76);
				 this->npd_tB_barcode->Name = L"npd_tB_barcode";
				 this->npd_tB_barcode->Size = System::Drawing::Size(138, 20);
				 this->npd_tB_barcode->TabIndex = 7;
				 // 
				 // Price textbox
				 // 
				 this->npd_tB_price->Location = System::Drawing::Point(87, 102);
				 this->npd_tB_price->Name = L"npd_tB_price";
				 this->npd_tB_price->Size = System::Drawing::Size(138, 20);
				 this->npd_tB_price->TabIndex = 8;
				 // 
				 // Manufacturer textbox
				 // 
				 this->npd_tB_manuf->Location = System::Drawing::Point(87, 128);
				 this->npd_tB_manuf->Name = L"npd_tB_manuf";
				 this->npd_tB_manuf->Size = System::Drawing::Size(138, 20);
				 this->npd_tB_manuf->TabIndex = 9;
				 // 
				 // Stock textbox
				 // 
				 this->npd_tB_stock->Location = System::Drawing::Point(87, 154);
				 this->npd_tB_stock->Name = L"npd_tB_stock";
				 this->npd_tB_stock->Size = System::Drawing::Size(138, 20);
				 this->npd_tB_stock->TabIndex = 10;
				 // 
				 // Sold textbox
				 // 
				 this->npd_tB_sold->Location = System::Drawing::Point(87, 180);
				 this->npd_tB_sold->Name = L"npd_tB_sold";
				 this->npd_tB_sold->Size = System::Drawing::Size(138, 20);
				 this->npd_tB_sold->TabIndex = 11;
				 // 
				 // Sold label
				 // 
				 this->npd_l_sold->AutoSize = true;
				 this->npd_l_sold->Location = System::Drawing::Point(11, 183);
				 this->npd_l_sold->Name = L"npd_l_sold";
				 this->npd_l_sold->Size = System::Drawing::Size(28, 13);
				 this->npd_l_sold->TabIndex = 6;
				 this->npd_l_sold->Text = L"Sold";
				 // 
				 // Stock label
				 // 
				 this->npd_l_stock->AutoSize = true;
				 this->npd_l_stock->Location = System::Drawing::Point(11, 157);
				 this->npd_l_stock->Name = L"npd_l_stock";
				 this->npd_l_stock->Size = System::Drawing::Size(35, 13);
				 this->npd_l_stock->TabIndex = 5;
				 this->npd_l_stock->Text = L"Stock";
				 // 
				 // Price label
				 // 
				 this->npd_l_price->AutoSize = true;
				 this->npd_l_price->Location = System::Drawing::Point(11, 105);
				 this->npd_l_price->Name = L"npd_l_price";
				 this->npd_l_price->Size = System::Drawing::Size(31, 13);
				 this->npd_l_price->TabIndex = 4;
				 this->npd_l_price->Text = L"Price";
				 // 
				 // Manufacturer label
				 // 
				 this->npd_l_manuf->AutoSize = true;
				 this->npd_l_manuf->Location = System::Drawing::Point(11, 131);
				 this->npd_l_manuf->Name = L"npd_l_manuf";
				 this->npd_l_manuf->Size = System::Drawing::Size(70, 13);
				 this->npd_l_manuf->TabIndex = 3;
				 this->npd_l_manuf->Text = L"Manufacturer";
				 // 
				 // Category label
				 // 
				 this->npd_l_category->AutoSize = true;
				 this->npd_l_category->Location = System::Drawing::Point(11, 53);
				 this->npd_l_category->Name = L"npd_l_category";
				 this->npd_l_category->Size = System::Drawing::Size(49, 13);
				 this->npd_l_category->TabIndex = 2;
				 this->npd_l_category->Text = L"Category";
				 // 
				 // Barcode label
				 // 
				 this->npd_l_barcode->AutoSize = true;
				 this->npd_l_barcode->Location = System::Drawing::Point(11, 79);
				 this->npd_l_barcode->Name = L"npd_l_barcode";
				 this->npd_l_barcode->Size = System::Drawing::Size(47, 13);
				 this->npd_l_barcode->TabIndex = 1;
				 this->npd_l_barcode->Text = L"Barcode";
				 // 
				 // Name label
				 // 
				 this->npd_l_name->AutoSize = true;
				 this->npd_l_name->Location = System::Drawing::Point(11, 27);
				 this->npd_l_name->Name = L"npd_l_name";
				 this->npd_l_name->Size = System::Drawing::Size(35, 13);
				 this->npd_l_name->TabIndex = 0;
				 this->npd_l_name->Text = L"Name";
				 // 
				 // Cancel button
				 // 
				 this->npd_b_cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
				 this->npd_b_cancel->Location = System::Drawing::Point(155, 231);
				 this->npd_b_cancel->Name = L"npd_b_cancel";
				 this->npd_b_cancel->Size = System::Drawing::Size(75, 23);
				 this->npd_b_cancel->TabIndex = 7;
				 this->npd_b_cancel->Text = L"Cancel";
				 this->npd_b_cancel->UseVisualStyleBackColor = true;
				 // 
				 // OK button
				 // 
				 this->npd_b_ok->DialogResult = System::Windows::Forms::DialogResult::OK;
				 this->npd_b_ok->Location = System::Drawing::Point(39, 232);
				 this->npd_b_ok->Name = L"npd_b_ok";
				 this->npd_b_ok->Size = System::Drawing::Size(75, 23);
				 this->npd_b_ok->TabIndex = 6;
				 this->npd_b_ok->Text = L"OK";
				 this->npd_b_ok->UseVisualStyleBackColor = true;
				 this->npd_b_ok->Click += gcnew System::EventHandler(this, &addPdForm::npd_b_ok_Click);
				 // 
				 // Misc. 
				 // Creation of data entry form
				 // 
				 this->AcceptButton = this->npd_b_ok;
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13); //Size of elements
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->CancelButton = this->npd_b_cancel;
				 this->ClientSize = System::Drawing::Size(275, 265);
				 this->Controls->Add(this->npd_b_cancel);
				 this->Controls->Add(this->npd_b_ok);
				 this->Controls->Add(this->npd_grp);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
				 this->MaximizeBox = false;
				 this->MinimizeBox = false;
				 this->Name = L"addPdForm";
				 this->Text = L"Add a new product";
				 this->Load += gcnew System::EventHandler(this, &addPdForm::addPdForm_Load);
				 this->npd_grp->ResumeLayout(false);
				 this->npd_grp->PerformLayout();
				 this->ResumeLayout(false);

			 }
			 
			 // Upon clicking the OK button, stuff happens here
			 // possibly notifying the logic classes to call get_product_details()
			 void addPdForm::npd_b_ok_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close(); //Closing the form
			 }

			 //Data return in the form of strings
			 System::Windows::Forms::ListViewItem^ addPdForm::get_product_details(){
				//need to check whether they are blank/number/...
				return gcnew System::Windows::Forms::ListViewItem(gcnew cli::array<System::String^>(7) {
					this->npd_tB_name->Text, 
					this->npd_tB_category->Text, 
					this->npd_tB_barcode->Text, 
					this->npd_tB_price->Text, 
					this->npd_tB_manuf->Text, 
					this->npd_tB_stock->Text, 
					this->npd_tB_sold->Text
				});
			}
			 //Upon loading the form, stuff might happen here
			 System::Void addPdForm::addPdForm_Load(System::Object^  sender, System::EventArgs^  e)
			 {
			 }
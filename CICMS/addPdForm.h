#ifndef _GUARD_UI_addPdForm
#define _GUARD_UI_addPdForm

namespace CICMS_UI {

	public ref class addPdForm : public System::Windows::Forms::Form
	{
	public:
		addPdForm(void)
		{
			InitializeComponent();
		}
	
	//********************************************************
	//*****************PROPERTIES DECLEARATION****************
	//********************************************************
	private: System::Windows::Forms::GroupBox^  npd_grp;
	private: System::Windows::Forms::TextBox^  npd_tB_name;
	private: System::Windows::Forms::TextBox^  npd_tB_category;
	private: System::Windows::Forms::TextBox^  npd_tB_barcode;
	private: System::Windows::Forms::TextBox^  npd_tB_price;
	private: System::Windows::Forms::TextBox^  npd_tB_manuf;
	private: System::Windows::Forms::TextBox^  npd_tB_stock;
	private: System::Windows::Forms::TextBox^  npd_tB_sold;
	private: System::Windows::Forms::Label^  npd_l_sold;
	private: System::Windows::Forms::Label^  npd_l_stock;
	private: System::Windows::Forms::Label^  npd_l_price;
	private: System::Windows::Forms::Label^  npd_l_manuf;
	private: System::Windows::Forms::Label^  npd_l_category;
	private: System::Windows::Forms::Label^  npd_l_barcode;
	private: System::Windows::Forms::Label^  npd_l_name;
	private: System::Windows::Forms::Button^  npd_b_cancel;
	private: System::Windows::Forms::Button^  npd_b_ok;

	//********************************************************
	//*************MEMBER FUNCTION DECLEARATION***************
	//********************************************************
	private: void InitializeComponent(void)
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
				 // npd_grp
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
				 // npd_tB_name
				 // 
				 this->npd_tB_name->Location = System::Drawing::Point(88, 24);
				 this->npd_tB_name->Name = L"npd_tB_name";
				 this->npd_tB_name->Size = System::Drawing::Size(138, 20);
				 this->npd_tB_name->TabIndex = 5;
				 // 
				 // npd_tB_category
				 // 
				 this->npd_tB_category->Location = System::Drawing::Point(87, 50);
				 this->npd_tB_category->Name = L"npd_tB_category";
				 this->npd_tB_category->Size = System::Drawing::Size(138, 20);
				 this->npd_tB_category->TabIndex = 6;
				 // 
				 // npd_tB_barcode
				 // 
				 this->npd_tB_barcode->Location = System::Drawing::Point(87, 76);
				 this->npd_tB_barcode->Name = L"npd_tB_barcode";
				 this->npd_tB_barcode->Size = System::Drawing::Size(138, 20);
				 this->npd_tB_barcode->TabIndex = 7;
				 // 
				 // npd_tB_price
				 // 
				 this->npd_tB_price->Location = System::Drawing::Point(87, 102);
				 this->npd_tB_price->Name = L"npd_tB_price";
				 this->npd_tB_price->Size = System::Drawing::Size(138, 20);
				 this->npd_tB_price->TabIndex = 8;
				 // 
				 // npd_tB_manuf
				 // 
				 this->npd_tB_manuf->Location = System::Drawing::Point(87, 128);
				 this->npd_tB_manuf->Name = L"npd_tB_manuf";
				 this->npd_tB_manuf->Size = System::Drawing::Size(138, 20);
				 this->npd_tB_manuf->TabIndex = 9;
				 // 
				 // npd_tB_stock
				 // 
				 this->npd_tB_stock->Location = System::Drawing::Point(87, 154);
				 this->npd_tB_stock->Name = L"npd_tB_stock";
				 this->npd_tB_stock->Size = System::Drawing::Size(138, 20);
				 this->npd_tB_stock->TabIndex = 10;
				 // 
				 // npd_tB_sold
				 // 
				 this->npd_tB_sold->Location = System::Drawing::Point(87, 180);
				 this->npd_tB_sold->Name = L"npd_tB_sold";
				 this->npd_tB_sold->Size = System::Drawing::Size(138, 20);
				 this->npd_tB_sold->TabIndex = 11;
				 // 
				 // npd_l_sold
				 // 
				 this->npd_l_sold->AutoSize = true;
				 this->npd_l_sold->Location = System::Drawing::Point(11, 183);
				 this->npd_l_sold->Name = L"npd_l_sold";
				 this->npd_l_sold->Size = System::Drawing::Size(28, 13);
				 this->npd_l_sold->TabIndex = 6;
				 this->npd_l_sold->Text = L"Sold";
				 // 
				 // npd_l_stock
				 // 
				 this->npd_l_stock->AutoSize = true;
				 this->npd_l_stock->Location = System::Drawing::Point(11, 157);
				 this->npd_l_stock->Name = L"npd_l_stock";
				 this->npd_l_stock->Size = System::Drawing::Size(35, 13);
				 this->npd_l_stock->TabIndex = 5;
				 this->npd_l_stock->Text = L"Stock";
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
				 this->npd_b_cancel->Location = System::Drawing::Point(155, 231);
				 this->npd_b_cancel->Name = L"npd_b_cancel";
				 this->npd_b_cancel->Size = System::Drawing::Size(75, 23);
				 this->npd_b_cancel->TabIndex = 7;
				 this->npd_b_cancel->Text = L"Cancel";
				 this->npd_b_cancel->UseVisualStyleBackColor = true;
				 // 
				 // npd_b_ok
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
				 // addPdForm
				 // 
				 this->AcceptButton = this->npd_b_ok;
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
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
				 this->npd_grp->ResumeLayout(false);
				 this->npd_grp->PerformLayout();
				 this->ResumeLayout(false);

			 }

	private: void npd_b_ok_Click(System::Object^  sender, System::EventArgs^  e) {
				 //submit check here
				 this->Close();
			 }
	//Function: get the input
	public: System::Windows::Forms::ListViewItem^ get_product_details(){
				//need to check whether they are blank/number/...
				return gcnew System::Windows::Forms::ListViewItem(gcnew cli::array<System::String^>(7) {
					this->npd_tB_name->Text,
					this->npd_tB_category->Text,
					this->npd_tB_manuf->Text,
					this->npd_tB_barcode->Text,
					this->npd_tB_stock->Text,
					this->npd_tB_sold->Text,
					this->npd_tB_price->Text
				});
			}
	};
}
#endif
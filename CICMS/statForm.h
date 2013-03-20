#pragma once
#include "stdafx.h"
#include "InputCheck.h"
#include "ListViewItemComparer.h"

using namespace CICMS_UI;

namespace CICMS_UI {

	/// <summary>
	/// Summary for statForm
	/// </summary>
	public ref class statForm : public System::Windows::Forms::Form
	{
	public:
		statForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~statForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  list_grp;
	protected: 
	private: System::Windows::Forms::ListView^  list_lv;
	private: System::Windows::Forms::ColumnHeader^  list_col_name;
	private: System::Windows::Forms::ColumnHeader^  list_col_category;
	private: System::Windows::Forms::ColumnHeader^  list_col_barcode;
	private: System::Windows::Forms::ColumnHeader^  list_col_price;
	private: System::Windows::Forms::ColumnHeader^  list_col_manuf;
	private: System::Windows::Forms::ColumnHeader^  list_col_stock;
	private: System::Windows::Forms::ColumnHeader^  list_col_sold;
	private: System::Windows::Forms::Button^  button1;
	private: System::Int32 list_sortColumn;
	private: bool list_sort;

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
		void InitializeComponent(void)
		{
			this->list_grp = (gcnew System::Windows::Forms::GroupBox());
			this->list_lv = (gcnew System::Windows::Forms::ListView());
			this->list_col_name = (gcnew System::Windows::Forms::ColumnHeader());
			this->list_col_category = (gcnew System::Windows::Forms::ColumnHeader());
			this->list_col_barcode = (gcnew System::Windows::Forms::ColumnHeader());
			this->list_col_price = (gcnew System::Windows::Forms::ColumnHeader());
			this->list_col_manuf = (gcnew System::Windows::Forms::ColumnHeader());
			this->list_col_stock = (gcnew System::Windows::Forms::ColumnHeader());
			this->list_col_sold = (gcnew System::Windows::Forms::ColumnHeader());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->list_grp->SuspendLayout();
			this->SuspendLayout();
			// 
			// list_grp
			// 
			this->list_grp->Controls->Add(this->list_lv);
			this->list_grp->Location = System::Drawing::Point(12, 12);
			this->list_grp->Name = L"list_grp";
			this->list_grp->Size = System::Drawing::Size(658, 346);
			this->list_grp->TabIndex = 14;
			this->list_grp->TabStop = false;
			this->list_grp->Text = L"Group Name";
			// 
			// list_lv
			// 
			this->list_lv->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(7) {this->list_col_name, this->list_col_category, 
				this->list_col_barcode, this->list_col_price, this->list_col_manuf, this->list_col_stock, this->list_col_sold});
			this->list_lv->FullRowSelect = true;
			this->list_lv->Location = System::Drawing::Point(11, 22);
			this->list_lv->Name = L"list_lv";
			this->list_lv->ShowGroups = false;
			this->list_lv->Size = System::Drawing::Size(636, 309);
			this->list_lv->TabIndex = 8;
			this->list_lv->UseCompatibleStateImageBehavior = false;
			this->list_lv->View = System::Windows::Forms::View::Details;
			this->list_lv->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &statForm::list_lv_ColumnClick);
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
			// button1
			// 
			this->button1->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button1->Location = System::Drawing::Point(595, 363);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 15;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &statForm::button1_Click);
			// 
			// statForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(681, 393);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->list_grp);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"statForm";
			this->Text = L" Statistics";
			this->list_grp->ResumeLayout(false);
			this->ResumeLayout(false);
			this->KeyPreview = true;
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &statForm::statForm_KeyPress);

		}
	private: void statForm_KeyPress(Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e){
				 if(e->KeyChar == 13)
					 this->Close();
			 }
	private: void list_lv_ColumnClick(System::Object^, System::Windows::Forms::ColumnClickEventArgs^ e){
				 enum SORT_ORDER{Descending = false, Ascending = true};
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
	private: void Sort_list_lv(System::Windows::Forms::ColumnClickEventArgs^ e, bool t, bool is_num){
				 this->list_sort = t;// sort status: Ascending or Descending
				 this->list_lv->ListViewItemSorter = gcnew ListViewItemComparer(e->Column, t, is_num);// sort it
			 }
	public: void Set_grpTitle(System::String^ s){
				this->list_grp->Text = s;
			}
	public: void Set_listData(array<System::Windows::Forms::ListViewItem^>^ r){
				if(r->Length){
					this->list_lv->BeginUpdate();
					this->list_lv->Items->Clear();
					this->list_lv->Items->AddRange(r);
					this->list_lv->EndUpdate();
					this->list_lv->Items[0]->Selected = true;
				}
			}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
	};
}

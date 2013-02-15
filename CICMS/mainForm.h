#ifndef _GUARD_UI_mainForm
#define _GUARD_UI_mainForm

#include "inputForm.h"
#include "addForm.h"

//naming
//"pd_b_delete" means a button for deletion in ProductDetails part
//"pd_l_name" means a label for name in ProductDetails part
//etc etc
//
namespace CICMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CICMS;

	/// <summary>
	/// Summary for mainForm
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		mainForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~mainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menu;
	protected: 

	private: System::Windows::Forms::ToolStripMenuItem^  menu_f;
	protected: 

	private: System::Windows::Forms::ToolStripMenuItem^  menu_f_saveProductList;

	private: System::Windows::Forms::ToolStripMenuItem^  menu_f_loadProductList;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_f_quit;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_about;
	private: System::Windows::Forms::TextBox^  s_tB_input;
	private: System::Windows::Forms::Button^  s_b_submit;
	private: System::Windows::Forms::GroupBox^  s_grp;






	private: System::Windows::Forms::Label^  s_l_by;














	private: System::Windows::Forms::RadioButton^  s_rB_byCategory;

	private: System::Windows::Forms::RadioButton^  s_rB_byBarcode;


	private: System::Windows::Forms::RadioButton^  s_rB_byName;
	private: System::Windows::Forms::GroupBox^  pd_grp;



	private: System::Windows::Forms::Label^  pd_l_sold;


	private: System::Windows::Forms::Label^  pd_l_stock;








	private: System::Windows::Forms::Label^  pd_l_price;
	private: System::Windows::Forms::Label^  pd_l_manuf;



	private: System::Windows::Forms::Label^  pd_l_category;
	private: System::Windows::Forms::Label^  pd_l_barcode;




	private: System::Windows::Forms::Label^  pd_l_name;
	private: System::Windows::Forms::TextBox^  pd_tB_name;
	private: System::Windows::Forms::TextBox^  pd_tB_category;
	private: System::Windows::Forms::TextBox^  pd_tB_barcode;
	private: System::Windows::Forms::TextBox^  pd_tB_price;
	private: System::Windows::Forms::TextBox^  pd_tB_manuf;
	private: System::Windows::Forms::TextBox^  pd_tB_stock;
	private: System::Windows::Forms::TextBox^  pd_tB_sold;
	private: System::Windows::Forms::Button^  pd_b_delete;













	private: System::Windows::Forms::Button^  pd_b_sell;
	private: System::Windows::Forms::Button^  pd_b_restock;
	private: System::Windows::Forms::ListView^  list_lv;
	private: System::Windows::Forms::ColumnHeader^  list_col_name;
	private: System::Windows::Forms::ColumnHeader^  list_col_category;
	private: System::Windows::Forms::ColumnHeader^  list_col_barcode;
	private: System::Windows::Forms::ColumnHeader^  list_col_price;








	private: System::Windows::Forms::ToolStripMenuItem^  menu_f_addANewProduct;



	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::ColumnHeader^  list_col_manuf;
	private: System::Windows::Forms::ColumnHeader^  list_col_stock;
	private: System::Windows::Forms::ColumnHeader^  list_col_sold;



	private: System::Windows::Forms::GroupBox^  list_grp;


	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;



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
			System::Windows::Forms::ListViewItem^  listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(7) {L"hm_name", 
				L"bag", L"000021", L"31", L"H&M", L"31", L"5"}, -1));
			System::Windows::Forms::ListViewItem^  listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(7) {L"jj_test", 
				L"jeans", L"00044", L"5", L"jj", L"25", L"21"}, -1));
			this->menu = (gcnew System::Windows::Forms::MenuStrip());
			this->menu_f = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_f_addANewProduct = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_f_loadProductList = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_f_saveProductList = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_f_quit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_about = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->s_tB_input = (gcnew System::Windows::Forms::TextBox());
			this->s_b_submit = (gcnew System::Windows::Forms::Button());
			this->s_grp = (gcnew System::Windows::Forms::GroupBox());
			this->s_l_by = (gcnew System::Windows::Forms::Label());
			this->s_rB_byCategory = (gcnew System::Windows::Forms::RadioButton());
			this->s_rB_byBarcode = (gcnew System::Windows::Forms::RadioButton());
			this->s_rB_byName = (gcnew System::Windows::Forms::RadioButton());
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
			this->list_lv = (gcnew System::Windows::Forms::ListView());
			this->list_col_name = (gcnew System::Windows::Forms::ColumnHeader());
			this->list_col_category = (gcnew System::Windows::Forms::ColumnHeader());
			this->list_col_barcode = (gcnew System::Windows::Forms::ColumnHeader());
			this->list_col_price = (gcnew System::Windows::Forms::ColumnHeader());
			this->list_col_manuf = (gcnew System::Windows::Forms::ColumnHeader());
			this->list_col_stock = (gcnew System::Windows::Forms::ColumnHeader());
			this->list_col_sold = (gcnew System::Windows::Forms::ColumnHeader());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->list_grp = (gcnew System::Windows::Forms::GroupBox());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->menu->SuspendLayout();
			this->s_grp->SuspendLayout();
			this->pd_grp->SuspendLayout();
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
			listViewItem1->StateImageIndex = 0;
			this->list_lv->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(2) {listViewItem1, listViewItem2});
			this->list_lv->Location = System::Drawing::Point(11, 23);
			this->list_lv->MultiSelect = false;
			this->list_lv->Name = L"list_lv";
			this->list_lv->ShowGroups = false;
			this->list_lv->Size = System::Drawing::Size(539, 306);
			this->list_lv->TabIndex = 9;
			this->list_lv->UseCompatibleStateImageBehavior = false;
			this->list_lv->View = System::Windows::Forms::View::Details;
			this->list_lv->SelectedIndexChanged += gcnew System::EventHandler(this, &mainForm::listView1_SelectedIndexChanged);
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
			// openFileDialog1
			// 
			this->openFileDialog1->AutoUpgradeEnabled = false;
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->InitialDirectory = L"c:\\";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->AutoUpgradeEnabled = false;
			this->saveFileDialog1->InitialDirectory = L"c:\\";
			// 
			// list_grp
			// 
			this->list_grp->Controls->Add(this->list_lv);
			this->list_grp->Location = System::Drawing::Point(277, 27);
			this->list_grp->Name = L"list_grp";
			this->list_grp->Size = System::Drawing::Size(561, 343);
			this->list_grp->TabIndex = 11;
			this->list_grp->TabStop = false;
			this->list_grp->Text = L"List of products";
			// 
			// statusStrip1
			// 
			this->statusStrip1->BackColor = System::Drawing::Color::LightSkyBlue;
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
			this->statusStrip1->Location = System::Drawing::Point(0, 378);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(853, 22);
			this->statusStrip1->SizingGrip = false;
			this->statusStrip1->TabIndex = 12;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(39, 17);
			this->toolStripStatusLabel1->Text = L"Ready";
			// 
			// mainForm
			// 
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
	private: System::Void menu_f_quit_Click(System::Object^  sender, System::EventArgs^  e) {
				 Close();
			 }

	private: System::Void pd_b_delete_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(MessageBox::Show("Are you sure that you would like \nto delete this product?", 
					 " Delete Product",
					 MessageBoxButtons::YesNo,
					 MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes){
						 Clear_selectedList();
						 Clear_pd();
						 Disable_pd_b();
				 }
			 }

	private: Void Clear_selectedList(){
				 list_lv->Items->RemoveAt(list_lv->SelectedIndices[0]);
			 }

	private: Void Clear_pd(){
				 pd_tB_name->Text = "";
				 pd_tB_category->Text = "";
				 pd_tB_barcode->Text = "";
				 pd_tB_price->Text = "";
				 pd_tB_manuf->Text = "";
				 pd_tB_stock->Text = "";
				 pd_tB_sold->Text = "";
			 }

	private: Void Disable_pd_b(){
				 pd_b_delete->Enabled = false;
				 pd_b_sell->Enabled = false;
				 pd_b_restock->Enabled = false;
			 }

	private: System::Void pd_b_sell_Click(System::Object^  sender, System::EventArgs^  e) {
				 inputForm^ dlg = gcnew inputForm(" Sell Products", "Sell:");
				 dlg->StartPosition = FormStartPosition::CenterParent;
				 dlg->ShowDialog();
				 delete dlg;//should I?
			 }
	private: System::Void pd_b_restock_Click(System::Object^  sender, System::EventArgs^  e) {
				 inputForm^ dlg = gcnew inputForm(" Restock Products", "Restock:");
				 dlg->StartPosition = FormStartPosition::CenterParent;
				 dlg->ShowDialog();
			 }
	private: System::Void menu_f_addANewProduct_Click(System::Object^  sender, System::EventArgs^  e) {
				 addForm^ dlg1 = gcnew addForm();
				 dlg1->StartPosition = FormStartPosition::CenterParent;
				 if (dlg1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
					 System::Windows::Forms::ListViewItem^  temp = dlg1->get_product_details();
					 this->list_lv->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(1) {temp});
					 delete temp;
				 }
				 delete dlg1;//should I?
			 }
	private: System::Void menu_about_Click(System::Object^  sender, System::EventArgs^  e) {
				 MessageBox::Show("Hello! Our team: Ashray, Bob, Hui and Kai!", " About");
			 }
	private: System::Void menu_f_loadProductList_Click(System::Object^  sender, System::EventArgs^  e) {
				 openFileDialog1->ShowDialog();
			 }
	private: System::Void menu_f_saveProductList_Click(System::Object^  sender, System::EventArgs^  e) {
				 saveFileDialog1->ShowDialog();
			 }
	private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 System::Collections::IEnumerator^ myEnum = this->list_lv->SelectedItems->GetEnumerator();
				 pd_b_delete->Enabled = true;
				 pd_b_sell->Enabled = true;
				 pd_b_restock->Enabled = true;
				 while ( myEnum->MoveNext() ){
					 ListViewItem^ item = safe_cast<ListViewItem^>(myEnum->Current);
					 pd_tB_name->Text = item->SubItems[0]->Text;// can be more elegant??
					 pd_tB_category->Text = item->SubItems[1]->Text;
					 pd_tB_barcode->Text = item->SubItems[2]->Text;
					 pd_tB_price->Text = item->SubItems[3]->Text;
					 pd_tB_manuf->Text = item->SubItems[4]->Text;
					 pd_tB_stock->Text = item->SubItems[5]->Text;
					 pd_tB_sold->Text = item->SubItems[6]->Text;
					 //String^ tb_M = "hi";
					 //this->list_lv->Items->Add(tb_M);
					 //tb_M = "Changed"; the new item will still be "hi" instead of "Changed"
				 }
			 }
	};
}
#endif
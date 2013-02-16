#ifndef _GUARD_UI_mainForm
#define _GUARD_UI_mainForm

#include "inputForm.h"
#include "addPdForm.h"

//naming
//"pd_b_delete" means a button for deletion in ProductDetails part
//"pd_l_name" means a label for name in ProductDetails part
//etc etc
//
namespace CICMS {

	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		mainForm(void)
		{
			InitializeComponent();
		}
	
	//********************************************************
	//*************MEMBER FUNCTION DECLEARATION***************
	//********************************************************

	private: void CICMS::mainForm::InitializeComponent(void);

	//**********MENU COMPONENTS FUNCTION***********
	private: void menu_f_quit_Click(System::Object^  sender, System::EventArgs^  e);
	private: void menu_f_addANewProduct_Click(System::Object^  sender, System::EventArgs^  e);
	private: void menu_f_loadProductList_Click(System::Object^  sender, System::EventArgs^  e);
	private: void menu_f_saveProductList_Click(System::Object^  sender, System::EventArgs^  e);
	private: void menu_about_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Create_addPdForm();

	//**********PRODUCT DETAILS COMPONENTS FUNCTION***********
	private: void pd_b_delete_Click(System::Object^  sender, System::EventArgs^  e);
	private: void pd_b_sell_Click(System::Object^  sender, System::EventArgs^  e);
	private: void pd_b_restock_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Update_pd_tB(ListViewItem^ item);
	private: void Update_pd_tB_Sell(int stock);
	private: void Update_pd_tB_Restock(int stock);
	private: void Clear_pd_tB();
	private: void Toggle_pd_b(bool tof);
	private: void Create_inputForm(String^ formTitle, String^ inputDescrip);

	//**********LIST DETAILS COMPONENTS FUNCTION***********
	private: void list_lv_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: void Update_selectedList_Sell(int stock);
	private: void Update_selectedList_Restock(int stock);
	private: void Clear_selectedList();

	//**********STATUSBAR COMPONENTS FUNCTION***********
	void Update_statusBar(String^ s);
	void Set_statusBar(String^ s, System::Drawing::Color c);

	//**********OTHER COMPONENTS FUNCTION***********
	private: System::Windows::Forms::DialogResult Create_messageBox(String^ typeMB);
	
	
	//********************************************************
	//*****************DATA DECLEARATION**********************
	//********************************************************

	//**********MENU COMPONENTS DECLEARATION***********
	private: System::Windows::Forms::MenuStrip^  menu;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_f;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_f_saveProductList;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_f_loadProductList;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_f_quit;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_about;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_f_addANewProduct;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog;

	//**********SEARCH COMPONENTS DECLEARATION***********
	private: System::Windows::Forms::TextBox^  s_tB_input;
	private: System::Windows::Forms::Button^  s_b_submit;
	private: System::Windows::Forms::GroupBox^  s_grp;
	private: System::Windows::Forms::Label^  s_l_by;
	private: System::Windows::Forms::RadioButton^  s_rB_byCategory;
	private: System::Windows::Forms::RadioButton^  s_rB_byBarcode;
	private: System::Windows::Forms::RadioButton^  s_rB_byName;

	//**********PRODUCT DETAILS COMPONENTS DECLEARATION***********
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

	//**********LIST COMPONENTS DECLEARATION***********
	private: System::Windows::Forms::ListView^  list_lv;
	private: System::Windows::Forms::ColumnHeader^  list_col_name;
	private: System::Windows::Forms::ColumnHeader^  list_col_category;
	private: System::Windows::Forms::ColumnHeader^  list_col_barcode;
	private: System::Windows::Forms::ColumnHeader^  list_col_price;
	private: System::Windows::Forms::ColumnHeader^  list_col_manuf;
	private: System::Windows::Forms::ColumnHeader^  list_col_stock;
	private: System::Windows::Forms::ColumnHeader^  list_col_sold;
	private: System::Windows::Forms::GroupBox^  list_grp;

	//**********STATUS COMPONENTS DECLEARATION***********
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	};
}
#endif
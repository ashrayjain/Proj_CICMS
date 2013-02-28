#ifndef _GUARD_UI_addPdForm
#define _GUARD_UI_addPdForm

namespace CICMS_UI {

	public ref class addPdForm : public System::Windows::Forms::Form
	{
	public:
		addPdForm(void);  //Constructor: Calls InitializeComponent to create GUI
		
		System::Windows::Forms::ListViewItem^ get_product_details(); //Is called by logic object to obtain product details from the form
	
	//********************************************************
	//*****************PROPERTIES DECLARATION****************
	//********************************************************
	private: 
	 System::Windows::Forms::GroupBox^  npd_grp;
	 System::Windows::Forms::TextBox^  npd_tB_name;
	 System::Windows::Forms::TextBox^  npd_tB_category;
	 System::Windows::Forms::TextBox^  npd_tB_barcode;
	 System::Windows::Forms::TextBox^  npd_tB_price;
	 System::Windows::Forms::TextBox^  npd_tB_manuf;
	 System::Windows::Forms::TextBox^  npd_tB_stock;
	 System::Windows::Forms::TextBox^  npd_tB_sold;
	 System::Windows::Forms::Label^  npd_l_sold;
	 System::Windows::Forms::Label^  npd_l_stock;
	 System::Windows::Forms::Label^  npd_l_price;
	 System::Windows::Forms::Label^  npd_l_manuf;
	 System::Windows::Forms::Label^  npd_l_category;
	 System::Windows::Forms::Label^  npd_l_barcode;
	 System::Windows::Forms::Label^  npd_l_name;
	 System::Windows::Forms::Button^  npd_b_cancel;
	 System::Windows::Forms::Button^  npd_b_ok;

	//********************************************************
	//*************MEMBER FUNCTION DECLARATION***************
	//********************************************************
	void InitializeComponent(void); //Creates the GUI
	
	void npd_b_ok_Click(System::Object^  sender, System::EventArgs^  e); //Stuff that happens when OK button is clicked
};
}
#endif

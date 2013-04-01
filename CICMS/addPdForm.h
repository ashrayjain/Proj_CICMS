/*************************************************************************************************/
//
//  class addPdForm: addPdForm.h
//
//  Description: addPdForm.h contains the specification part of class addPdForm. class addPdForm is 
//  the window which opens to add products to the database for CICMS. In our top-down design, addPdForm 
//  is directly below the top. It contains 5 textboxes for data entry when adding a new product,
//  as well as a public function, get_product_details(), which will be called by mainForm's function,
//  Create_addPdForms(), in order to pass this data to the logic object. 
//  to 
//
//  API:
//  CICMS_UI::addPdForm::addPdForm(); //create a mainForm object
//  CICMS_UI::addPdForm::System::Windows::Forms::get_product_details() //Allows other objects to retrieve the data gathered by this object
//
//  Main authors: XIE KAI(A0102016E), BOB WONG(A0094718U)
//
/*************************************************************************************************/

#ifndef _GUARD_UI_addPdForm
#define _GUARD_UI_addPdForm

namespace CICMS_UI {

	public ref class addPdForm : public System::Windows::Forms::Form
	{
	
	
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
	 System::Windows::Forms::Label^  npd_l_price;
	 System::Windows::Forms::Label^  npd_l_manuf;
	 System::Windows::Forms::Label^  npd_l_category;
	 System::Windows::Forms::Label^  npd_l_barcode;
	 System::Windows::Forms::Label^  npd_l_name;
	 System::Windows::Forms::Button^  npd_b_cancel;
	 System::Windows::Forms::Button^  npd_b_ok;
	 System::Drawing::Color DefaultColor;

	//********************************************************
	//*************MEMBER FUNCTION DECLARATION***************
	//********************************************************
	void InitializeComponent(void); //Creates the GUI
	void npd_b_ok_Click(System::Object^  sender, System::EventArgs^  e); //Stuff that happens when OK button is clicked
	System::Void npd_grp_Enter(System::Object^  sender, System::EventArgs^  e) {}
	public:
		addPdForm(void);  //Constructor: Calls InitializeComponent to create GUI
	public:
		void set_npd_grp_text(System::String^ s);
		System::Windows::Forms::ListViewItem^ get_product_details(); //Is called by mainForm object to obtain product details from the form
	//text changed event
	private: void npd_tB_name_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: void npd_tB_category_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: void npd_tB_barcode_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: void npd_tB_price_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: void npd_tB_manuf_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: void npd_tB_name_LostFocus(System::Object^  sender, System::EventArgs^  e);
	private: void npd_tB_category_LostFocus(System::Object^  sender, System::EventArgs^  e);
	private: void npd_tB_barcode_LostFocus(System::Object^  sender, System::EventArgs^  e);
	private: void npd_tB_price_LostFocus(System::Object^  sender, System::EventArgs^  e);
	private: void npd_tB_manuf_LostFocus(System::Object^  sender, System::EventArgs^  e);
	};
}
#endif

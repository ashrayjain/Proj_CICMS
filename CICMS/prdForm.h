/*************************************************************************************************/
//
//  class prdForm: prdForm.h
//
//  Description: prdForm.h contains the specification part of class prdForm. Class prdForm is 
//  the window which opens to add products or modify products. It contains 5 textboxes for data 
//  entry.
//
//  API:
//  CICMS_UI::prdForm::prdForm(); //create a mainForm object
//  CICMS_UI::prdForm::get_product_details() //Allows other objects to retrieve the data gathered by this object
//	setTitle() //set the form title
//	setValue() //set the values in the textBoxes
//	modifyMode_toggle() //toggle for Modification Mode
//
//  Main authors: XIE KAI(A0102016E), BOB WONG(A0094718U)
//
/*************************************************************************************************/

#ifndef _GUARD_UI_prdForm
#define _GUARD_UI_prdForm

namespace CICMS_UI {

	public ref class prdForm : public System::Windows::Forms::Form
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
	 bool modifyMode;
	 System::String^ npd_no_in_stock;
	 System::String^ npd_no_in_sold;

	//********************************************************
	//*************MEMBER FUNCTION DECLARATION***************
	//********************************************************
	public: prdForm(void);  //Constructor: Calls InitializeComponent to create GUI
	public: System::Windows::Forms::ListViewItem^ get_product_details(); //Is called by mainForm object to obtain product details from the form
	public: void setValue(System::Windows::Forms::ListViewItem^ item);
	public: void setTitle(System::String^ formTitle, System::String^ grpTitle);
	public: void modifyMode_toggle(bool tof, System::Windows::Forms::ListViewItem^ item);
	//.......
	private: void InitializeComponent(void); //Creates the GUI
	private: void npd_b_ok_Click(System::Object^  sender, System::EventArgs^  e); //Stuff that happens when OK button is clicked
	private: System::Void npd_grp_Enter(System::Object^  sender, System::EventArgs^  e) {}
	private: bool additional_check(System::String^ s);
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

	private: void submitButton_toggle();
	
	};
}
#endif

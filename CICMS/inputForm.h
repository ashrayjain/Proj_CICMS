/*************************************************************************************************/
//
//  class inputForm: inputForm.h
//
//  Description: inputForm.h contains the specification part of class inputForm. class inputForm defines
//  the window which opens for miscellaneous administrative functions such as deleting or restocking products,
//  as well as taking the value for the number of unique products to add; any function which requires a single value
//  at any time may create this object and make use of its public functions.
//
//
//  API:
//  CICMS_UI::inputForm::inputForm(); //create a inputForm object
//  CICMS_UI::inputForm::get_input(); // Called to return double datatype of value entered in this object
//  CICMS_UI::inputForm::set_inputForm(); //Called to set the default starting value and name/content of this object
//
//  Main authors: XIE KAI(A0102016E),  
//
/*************************************************************************************************/

#ifndef _GUARD_UI_inputForm
#define _GUARD_UI_inputForm

namespace CICMS_UI {

	public ref class inputForm : public System::Windows::Forms::Form
	{
	public:
		inputForm()
		{
			InitializeComponent();
		}
	//********************************************************
	//*****************PROPERTIES DECLEARATION****************
	//********************************************************
	private: System::Windows::Forms::Label^  input_l_descript;
	private: System::Windows::Forms::Button^  input_b_yes;
	private: System::Windows::Forms::Button^  input_b_no;
	private: System::Windows::Forms::Label^  input_l_pd;
	private: System::Windows::Forms::TextBox^  input_tB_input;

	//********************************************************
	//*************MEMBER FUNCTION DECLEARATION***************
	//********************************************************
	private: void InitializeComponent();

	private: void input_b_yes_Click(System::Object^  sender, System::EventArgs^  e) ;

	//this function should be in the handler/logic part
	private: bool is_number(System::String^ s);

	//this function should be in the handler/logic part
	private: bool is_valid(System::String^ s);

	//API Function: get the input from inputForm
	public: System::Double get_input(){
				return System::Convert::ToDouble(this->input_tB_input->Text);
			}

	//API Function: set the title, description for inputForm class
	public: void set_inputForm(System::String^ title, System::String^ pdDescript, System::String^ descript, System::String^ stringInTB);
	};
}
#endif
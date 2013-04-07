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
//	CICMS_UI::inputForm::set_formType(int i) //set an inputForm for number or string
//	CICMS_UI::inputForm::set_formType(int i, bool topXfilter) //a special case for top X feature
//
//  Main authors: XIE KAI(A0102016E), HUI HUI(A0105566E)
//
/*************************************************************************************************/

#ifndef _GUARD_UI_inputForm
#define _GUARD_UI_inputForm

enum FORMTYPE { NUMBER, STRING };

namespace CICMS_UI {

	public ref class inputForm : public System::Windows::Forms::Form
	{

		//********************************************************
		//*****************PROPERTIES DECLEARATION****************
		//********************************************************
	private: 
		System::Windows::Forms::Label^  input_l_descript;
		System::Windows::Forms::Button^  input_b_yes;
		System::Windows::Forms::Button^  input_b_no;
		System::Windows::Forms::Label^  input_l_pd;
		System::Windows::Forms::TextBox^  input_tB_input;
		int formType;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
			 bool TOP_X;
			 System::Drawing::Color DefaultColor;

		//********************************************************
		//*************MEMBER FUNCTION DECLEARATION***************
		//********************************************************
		void InitializeComponent();

		void input_b_yes_Click(System::Object^  sender, System::EventArgs^  e) ;

	public:
		inputForm()
		{
			InitializeComponent();
			formType = NUMBER;
			TOP_X = false;
			DefaultColor = this->input_tB_input->BackColor;
		}

		//API Function: get the input from inputForm
		System::String^ get_input(){
			return this->input_tB_input->Text;
		}
		//set formType: String or Number
		void set_formType(int i){
			this->formType = i;
		}
		//set formType: String or Number. if Number, then can set TOP_X_filter
		void set_formType(int i, bool TOP_X_filter){
			if(i == NUMBER)
				this->TOP_X = TOP_X_filter;
		}

		//API Function: set the title, description for inputForm class
		void set_inputForm(System::String^ title, System::String^ pdDescript, System::String^ descript, System::String^ stringInTB);

	private: void inputForm_Load(System::Object^  sender, System::EventArgs^  e);
	private: void input_tB_input_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: void input_tB_input_LostFocus(System::Object^  sender, System::EventArgs^  e);
	private: void submitButton_toggle();
	};

}
#endif
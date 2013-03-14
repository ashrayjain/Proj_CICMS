/*************************************************************************************************/
//
//  main.cpp, entry-point file.
//
//  Description: just a normal entry-point file :)
//
//  API:
//  CICMS_UI::mainForm::mainForm(); //create a mainForm class
//
//  Main authors: XIE KAI(A0102016E)
//
/*************************************************************************************************/

#include "stdafx.h"
#include "mainForm.h"

using namespace System;

[STAThreadAttribute] //thus saveFileDialog & loadFileDialog can be safely used in class mainForm
int main(array<System::String ^> ^args)
{
	//make window style pretty
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	//Autobots, roll out!
	CICMS_UI::mainForm^ UI_main = gcnew CICMS_UI::mainForm();
	UI_main->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
    System::Windows::Forms::Application::Run(UI_main);
    return 0;
}

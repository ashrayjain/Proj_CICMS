// main.cpp : entry-point file.
#include "stdafx.h"
#include "mainForm.h"

using namespace System;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
    System::Windows::Forms::Application::Run(gcnew CICMS_UI::mainForm());
    return 0;
}

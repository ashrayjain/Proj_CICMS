// CICMS.cpp : main project file.

#include "stdafx.h"
#include "mainForm.h"

using namespace CICMS;
using namespace System;

[STAThreadAttribute]
//if no STA.. savefiledialog or openfiledialog will crash. WHY?
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew mainForm());
    return 0;
}

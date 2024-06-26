#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	LabOC3PartTwo::MyForm form;
	Application::Run(% form);
}
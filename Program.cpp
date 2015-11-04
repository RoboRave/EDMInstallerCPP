#pragma once
#include "Program.h"
#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;

namespace EDMInstallerCPP
{
	/// <summary>
	/// The main entry point for the application.
	/// </summary>
	[STAThreadAttribute]
	void Program::Main()
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		EDMInstallerCPP::MainWindow form;
		Application::Run(%form);
	}
}

#pragma once
#include "EDMI.h"
#include "Config.h"

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace EDMInstallerCPP { ref class Config; }
namespace EDMInstallerCPP { ref class EDMI; }

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

namespace EDMInstallerCPP
{
	public ref class Json
	{
	public:
		static Json ^instance = gcnew Json();
	private:
		String ^RunLocation = Application::StartupPath;

	public:
		static Config ^config = gcnew Config();
		static EDMI ^es = gcnew EDMI();

		static void genDefaults();

		void run();
	};
}

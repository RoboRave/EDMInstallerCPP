#pragma once

using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace System::Windows::Forms;

namespace EDMInstallerCPP
{
	private ref class DownloadFiles
	{
	public:
		static void downloadEDM();

		static void DownloadForge();
	};
}

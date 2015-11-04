#include "DownloadFiles.h"

using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace System::Windows::Forms;

namespace EDMInstallerCPP
{

	void DownloadFiles::downloadEDM()
	{
		if (File::Exists(Application::StartupPath + "/EDM.jar"))
		{
			MessageBox::Show("Hey, You Already Downloaded it. Moving file.");
		}
		else
		{
//C# TO C++ CONVERTER NOTE: The following 'using' block is replaced by its C++ equivalent:
//ORIGINAL LINE: using (var client = new WebClient())
			auto client = gcnew WebClient();
			try
			{
				client->DownloadFile("http://addons-origin.cursecdn.com/files/2237/271/[1.7.10]EDM-4.1.0-Universal.jar", "EDM.jar");
			}
			finally
			{
				delete client;
			}
		}
	}

	void DownloadFiles::DownloadForge()
	{
		if (File::Exists(Application::StartupPath + "/forge.exe"))
		{
			Console::WriteLine("Already Downloaded Forge, going to install.");
		}
		else
		{
//C# TO C++ CONVERTER NOTE: The following 'using' block is replaced by its C++ equivalent:
//ORIGINAL LINE: using (var client = new WebClient())
			auto client = gcnew WebClient();
			try
			{
				client->DownloadFile("http://files.minecraftforge.net/maven/net/minecraftforge/forge/1.7.10-10.13.2.1291/forge-1.7.10-10.13.2.1291-installer-win.exe", "forge.exe");
				Console::WriteLine("Downloaded Forge");
			}
			finally
			{
				delete client;
			}
		}
	}
}

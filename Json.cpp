#include "Json.h"
#include "Config.h"
#include "EDMI.h"

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace Newtonsoft::Json;

namespace EDMInstallerCPP
{

	void Json::genDefaults()
	{
		config->name = "MinecraftForge";
		config->value = "false";
		es->name = "EDM";
		es->value = "false";
		Console::WriteLine("Generated defaults");
	}

	void Json::run()
	{
		File::WriteAllText(RunLocation + "/config.json", JsonConvert::SerializeObject(config));
		File::WriteAllText(RunLocation + "/config.json", JsonConvert::SerializeObject(es));
		// serialize JSON directly to a file
//C# TO C++ CONVERTER NOTE: The following 'using' block is replaced by its C++ equivalent:
//ORIGINAL LINE: using (StreamWriter file = File.CreateText(RunLocation + "/config.json"))
		StreamWriter ^file = File::CreateText(RunLocation + "/config.json");
		try
		{
			JsonSerializer ^serializer = gcnew JsonSerializer();
			serializer->Serialize(file, config);
			serializer->Serialize(file, es);
		}
		finally
		{
			delete file;
		}
	}
}

#pragma once
#include "MainWindow.h"
#include "Json.h"
#include "DownloadFiles.h"

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

namespace EDMInstallerCPP
{
	MainWindow::MainWindow()
	{
		InitializeComponent();
		Json::genDefaults();
		Json::instance->run();
	}

	void MainWindow::FindButton_Click(Object ^sender, EventArgs ^e)
	{
		FolderBrowser->RootFolder = Environment::SpecialFolder::ApplicationData;
		// Show the FolderBrowserDialog
		System::Windows::Forms::DialogResult result = FolderBrowser->ShowDialog();
		if (result == System::Windows::Forms::DialogResult::OK)
		{
			FileLocation->Text = FolderBrowser->SelectedPath;
			InstallLocation = FolderBrowser->SelectedPath;
		}
	}

	void MainWindow::FolderBrowser_HelpRequest(Object ^sender, EventArgs ^e)
	{
	}

	void MainWindow::ForgeInstall_CheckedChanged(Object ^sender, EventArgs ^e)
	{
		if (ForgeInstall->Checked)
		{
			Json::config->value = "true";
			Json::instance->run();
			Console::WriteLine(Json::config->value->ToString());
		}
		else
		{
			Json::config->value = "false";
			Json::instance->run();
			Console::WriteLine(Json::config->value->ToString());
		}
	}

	void MainWindow::EDMInstall_CheckedChanged(Object ^sender, EventArgs ^e)
	{
		if (EDMInstall->Checked)
		{
			Json::es->value = "true";
			Json::instance->run();
			Console::WriteLine(Json::es->value->ToString());
		}
		else
		{
			Json::es->value = "false";
			Json::instance->run();
			Console::WriteLine(Json::es->value->ToString());
		}
	}

	void MainWindow::InstallButton_Click(Object ^sender, EventArgs ^e)
	{
		if (Json::es->value == "true")
		{
			Console::WriteLine("It Worked!!!");
			if (!File::Exists(Application::StartupPath + "/EDM.jar"))
			{
				DownloadFiles::downloadEDM();
			}
			else
			{
				MessageBox::Show("Already Downloaded. Moving file...");
			}

			if (!File::Exists(InstallLocation + "/mods/EDM.jar"))
			{
				File::Move(Application::StartupPath + "/EDM.jar", InstallLocation + "/mods/EDM.jar");
			}
			else
			{
				MessageBox::Show("Mod is already installed");
			}
		}
		else
		{
			Console::WriteLine("Oops!! Something went wrong!! " + Json::es->name->ToString() + " was not vaild or the config was tampered with, so no install happened.");
		}

		if (Json::config->value == "true")
		{
			DownloadFiles::DownloadForge();
			System::Diagnostics::Process::Start(Application::StartupPath + "/forge.exe");
		}
		else
		{
			Console::WriteLine("Oops!! Something went wrong!!");
		}
	}

	void MainWindow::DisposeObject(bool disposing)
	{
		if (disposing && (components != nullptr))
		{
			delete components;
		}
		//C# TO C++ CONVERTER NOTE: There is no explicit call to the base class destructor in C++:
		//		base.Dispose(disposing);
	}

	void MainWindow::InitializeComponent()
	{
		this->InstallButton = gcnew System::Windows::Forms::Button();
		this->ForgeInstall = gcnew System::Windows::Forms::CheckBox();
		this->EDMInstall = gcnew System::Windows::Forms::CheckBox();
		this->FileLocation = gcnew System::Windows::Forms::TextBox();
		this->FindButton = gcnew System::Windows::Forms::Button();
		this->FolderBrowser = gcnew System::Windows::Forms::FolderBrowserDialog();
		this->SuspendLayout();
		//
		// InstallButton
		//
		this->InstallButton->Location = System::Drawing::Point(14, 84);
		this->InstallButton->Name = "InstallButton";
		this->InstallButton->Size = System::Drawing::Size(75, 23);
		this->InstallButton->TabIndex = 0;
		this->InstallButton->Text = "Install";
		this->InstallButton->UseVisualStyleBackColor = true;
		this->InstallButton->Click += gcnew System::EventHandler(this, &MainWindow::InstallButton_Click);
		//
		// ForgeInstall
		//
		this->ForgeInstall->AutoSize = true;
		this->ForgeInstall->Location = System::Drawing::Point(14, 38);
		this->ForgeInstall->Name = "ForgeInstall";
		this->ForgeInstall->Size = System::Drawing::Size(162, 17);
		this->ForgeInstall->TabIndex = 1;
		this->ForgeInstall->Text = "MinecraftForge Version 1291";
		this->ForgeInstall->UseVisualStyleBackColor = true;
		this->ForgeInstall->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::ForgeInstall_CheckedChanged);
		//
		// EDMInstall
		//
		this->EDMInstall->AutoSize = true;
		this->EDMInstall->Location = System::Drawing::Point(14, 61);
		this->EDMInstall->Name = "EDMInstall";
		this->EDMInstall->Size = System::Drawing::Size(189, 17);
		this->EDMInstall->TabIndex = 2;
		this->EDMInstall->Text = "Extra Diamonds Mod Version 4.1.0";
		this->EDMInstall->UseVisualStyleBackColor = true;
		this->EDMInstall->CheckedChanged += gcnew System::EventHandler(this, &MainWindow::EDMInstall_CheckedChanged);
		//
		// FileLocation
		//
		this->FileLocation->Location = System::Drawing::Point(12, 12);
		this->FileLocation->Name = "FileLocation";
		this->FileLocation->Size = System::Drawing::Size(229, 20);
		this->FileLocation->TabIndex = 3;
		//
		// FindButton
		//
		this->FindButton->Location = System::Drawing::Point(247, 12);
		this->FindButton->Name = "FindButton";
		this->FindButton->Size = System::Drawing::Size(27, 23);
		this->FindButton->TabIndex = 4;
		this->FindButton->Text = "...";
		this->FindButton->UseVisualStyleBackColor = true;
		this->FindButton->Click += gcnew System::EventHandler(this, &MainWindow::FindButton_Click);
		//
		// FolderBrowser
		//
		this->FolderBrowser->HelpRequest += gcnew System::EventHandler(this, &MainWindow::FolderBrowser_HelpRequest);
		//
		// MainWindow
		//
		this->AutoScaleDimensions = System::Drawing::SizeF(6.0F, 13.0F);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(304, 121);
		this->Controls->Add(this->FindButton);
		this->Controls->Add(this->FileLocation);
		this->Controls->Add(this->EDMInstall);
		this->Controls->Add(this->ForgeInstall);
		this->Controls->Add(this->InstallButton);
		this->MaximizeBox = false;
		this->Name = "MainWindow";
		this->Text = "EDM Installer For Minecraft 1.7.10";
		this->ResumeLayout(false);
		this->PerformLayout();
	}
}
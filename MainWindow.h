#pragma once
using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

namespace EDMInstallerCPP
{
	public ref class MainWindow : System::Windows::Forms::Form
	{
	private:
		String ^InstallLocation = "Install Location";

		public:
		~MainWindow()
		{
			this->DisposeObject(true);
		}

		private protected:
		!MainWindow()
		{
			this->DisposeObject(false);
		}

	public:
		MainWindow();

	private:
		void FindButton_Click(Object ^sender, EventArgs ^e);

		void FolderBrowser_HelpRequest(Object ^sender, EventArgs ^e);

		void ForgeInstall_CheckedChanged(Object ^sender, EventArgs ^e);

		void EDMInstall_CheckedChanged(Object ^sender, EventArgs ^e);

		void InstallButton_Click(Object ^sender, EventArgs ^e);


		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::IContainer ^components = nullptr;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		void DisposeObject(bool disposing);

		#pragma region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent();

		#pragma endregion

		System::Windows::Forms::Button ^InstallButton;
		System::Windows::Forms::CheckBox ^ForgeInstall;
		System::Windows::Forms::CheckBox ^EDMInstall;
		System::Windows::Forms::TextBox ^FileLocation;
		System::Windows::Forms::Button ^FindButton;
		System::Windows::Forms::FolderBrowserDialog ^FolderBrowser;
	};
}

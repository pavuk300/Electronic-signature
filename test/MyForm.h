#pragma once
#using <System.DLL>
#using <System.Drawing.DLL>
#using <System.Windows.Forms.DLL>
#include <windows.h>
#include <Commdlg.h>
#include <stdio.h>
#include <commctrl.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <locale.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <locale>
#include "string.h"
#include <msclr/marshal_cppstd.h>

using namespace std;

string shifr(string adr, string name)
{
	string preres;
	setlocale(LC_ALL, ".1251");
	ifstream tyty;
	tyty.open(adr.c_str());
	tyty >> preres;
	preres = preres + "00000";
	for (int i = 0; i < 5; ++i)
	{
		preres[i] = preres[i] + '0' + name[i];
	}
	for (int i = 4; i >= 0; --i)
	{
		preres[i + i] = preres[i];
		preres[i + i + 1] = preres[i] + 1;
	}
	for (int i = 0; i < 10; ++i)
	{
		if (preres[i] < 48 && preres[i] >= 0)
			preres[i] += 48;
		if (preres[i] < 65 && preres[i]>57)
			preres[i] += 7;
		if (preres[i] < 97 && preres[i]>90)
			preres[i] += 6;
		if ((preres[i] + '0' < ('0' + 'А')) && (preres[i] + '0' < ('0' + 'z')) && (preres[i] + 69 + '0' <= ('0' + 'я')))
			preres[i] += 69;
		if (preres[i] + '0' < 'А' + '0' && preres[i] + '0' < 'z' + '0' && preres[i] + 69 > 255)
			/// if (preres[i]+'0'<'0'+'z')
			preres[i] += 63;
		if (preres[i] > 255)
			preres[i] = 255;
	}
	return preres;
}

void splitString(const string& fullstr,
	vector<string>& elements,
	const string& delimiter) {
	string::size_type lastpos =
		fullstr.find_first_not_of(delimiter, 0);
	string::size_type pos =
		fullstr.find_first_of(delimiter, lastpos);
	while ((string::npos != pos) || (string::npos != lastpos)) {
		elements.push_back(fullstr.substr(lastpos, pos - lastpos));
		lastpos = fullstr.find_first_not_of(delimiter, pos);
		pos = fullstr.find_first_of(delimiter, lastpos);
	}
}

void readData(const string& filename,
	const string& csvdelimiter,
	vector< vector<string> >& sarr) {
	ifstream fin(filename.c_str());
	string s;
	vector<string> selements;
	vector<string> delements;
	while (!fin.eof()) {
		getline(fin, s);
		if (!s.empty()) {
			splitString(s, selements, csvdelimiter);
			for (size_t i = 0; i < selements.size(); i++) {
				delements.
					push_back(selements[i]);
			}
			sarr.push_back(delements);
			selements.clear();
			delements.clear();
		}
	}
	fin.close();
}

namespace test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::OpenFileDialog^ openFD1;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::OpenFileDialog^ openFD2;
	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ textBox3;






	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFD1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->openFD2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(11, 13);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(229, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"Выберите путь до базы";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(246, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(28, 20);
			this->button1->TabIndex = 1;
			this->button1->Text = L"...";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// openFD1
			// 
			this->openFD1->FileName = L"openFileDialog1";
			this->openFD1->InitialDirectory = L"C:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(246, 38);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(28, 20);
			this->button2->TabIndex = 3;
			this->button2->Text = L"...";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::button2_MouseClick);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 38);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(229, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"Выберите путь до зашифрованного файла";
			// 
			// openFD2
			// 
			this->openFD2->FileName = L"openFileDialog1";
			// 
			// button3
			// 
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(12, 67);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(263, 44);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Проверка";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button5
			// 
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(12, 117);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(263, 44);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Выход";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(14, 168);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(261, 21);
			this->comboBox1->TabIndex = 7;
			this->comboBox1->Text = L"Выберите сотрудника";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(75, 195);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(128, 20);
			this->textBox3->TabIndex = 8;
			this->textBox3->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::MediumTurquoise;
			this->ClientSize = System::Drawing::Size(283, 229);
			this->ControlBox = false;
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Электронная подпись";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		openFD1->InitialDirectory = "C:";
		openFD1->Title = "База данных";
		openFD1->FileName = "";
		openFD1->Filter = "(.csv)|*.csv";
		openFD1->CheckFileExists = TRUE;
		openFD1->CheckPathExists = TRUE;
		if (openFD1->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
		{
			textBox1->Text = openFD1->FileName;
		}
	}
	private: System::Void button2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		openFD2->InitialDirectory = "C:";
		openFD2->Title = "Персональный файл";
		openFD2->FileName = "";
		openFD2->Filter = "(.txt)|*.txt";
		openFD2->CheckFileExists = TRUE;
		openFD2->CheckPathExists = TRUE;
		if (openFD2->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
		{
			textBox2->Text = openFD2->FileName;
		}
	}


private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
	}

private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	vector< vector<string> > sarr;
	string database = msclr::interop::marshal_as<std::string>(textBox1->Text);
	readData(database, ";", sarr);
	for (size_t i = 0; i < sarr.size(); i++) {
		comboBox1->Items->Add(gcnew System::String(sarr[i][1].c_str()));
	}

}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	vector< vector<string> > sarr;
	string name = msclr::interop::marshal_as<std::string>(comboBox1->Text);
	string adr = msclr::interop::marshal_as<std::string>(textBox2->Text);
	string database = msclr::interop::marshal_as<std::string>(textBox1->Text);
	if (name != "Выберите сотрудника") {
		string cod = shifr(adr, name);
		string res;
		readData(database, ";", sarr);
		for (size_t i = 0; i < sarr.size(); i++) {
			if (sarr[i][1] == name) {
				res = sarr[i][7].c_str();
				if (cod == res) {
					textBox3->Text = "ACCAPTED";
					textBox3->Visible = TRUE;
				}
				else
					textBox3->Text = "DENIED";
					textBox3->Visible = TRUE;
					//textBox3->Text = gcnew System::String(cod.c_str());
			}
		}
	}
}
};
}

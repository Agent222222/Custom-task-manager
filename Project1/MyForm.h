#pragma once
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <chrono>
#include <Psapi.h>
#include <list>
#include <tlhelp32.h>
#include <msclr/marshal_cppstd.h>
#include <Windows.h>
#include <sstream>
#include <string>
#include <conio.h>
#include <vector>
#include <algorithm>
namespace LabOC3PartTwo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;
	using namespace msclr::interop;


	int count = 0;
	

	struct ProcessInfoPair {
		DWORD key;                 
		PROCESS_INFORMATION value;  
		int index;
	};
	std::vector<ProcessInfoPair> processList;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^ checkBox_VS;
	private: System::Windows::Forms::CheckBox^ checkBox_tracert;
	private: System::Windows::Forms::CheckBox^ checkBox_Fibonachi;
	private: System::Windows::Forms::Button^ button_inputPrioruty;
	private: System::Windows::Forms::Button^ button_resume;
	private: System::Windows::Forms::Button^ button_suspend;
	private: System::Windows::Forms::ComboBox^ comboBox_priority;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
	private: System::Windows::Forms::Button^ button_Set_affinity;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Status;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Priority;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Time;
	private: System::ComponentModel::IContainer^ components;

	protected:



	protected:

	private:

		int indexVS, indexResmon, indexSort;
	private: System::Windows::Forms::TextBox^ textBox_id;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button_create;


#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->checkBox_VS = (gcnew System::Windows::Forms::CheckBox());
			   this->checkBox_tracert = (gcnew System::Windows::Forms::CheckBox());
			   this->checkBox_Fibonachi = (gcnew System::Windows::Forms::CheckBox());
			   this->button_inputPrioruty = (gcnew System::Windows::Forms::Button());
			   this->button_resume = (gcnew System::Windows::Forms::Button());
			   this->button_suspend = (gcnew System::Windows::Forms::Button());
			   this->comboBox_priority = (gcnew System::Windows::Forms::ComboBox());
			   this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			   this->button_Set_affinity = (gcnew System::Windows::Forms::Button());
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Status = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Priority = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->button_create = (gcnew System::Windows::Forms::Button());
			   this->textBox_id = (gcnew System::Windows::Forms::TextBox());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // checkBox_VS
			   // 
			   this->checkBox_VS->AutoSize = true;
			   this->checkBox_VS->Location = System::Drawing::Point(78, 467);
			   this->checkBox_VS->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->checkBox_VS->Name = L"checkBox_VS";
			   this->checkBox_VS->Size = System::Drawing::Size(124, 24);
			   this->checkBox_VS->TabIndex = 0;
			   this->checkBox_VS->Text = L"VisualStudio";
			   this->checkBox_VS->UseVisualStyleBackColor = true;
			   // 
			   // checkBox_tracert
			   // 
			   this->checkBox_tracert->AutoSize = true;
			   this->checkBox_tracert->Location = System::Drawing::Point(78, 522);
			   this->checkBox_tracert->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->checkBox_tracert->Name = L"checkBox_tracert";
			   this->checkBox_tracert->Size = System::Drawing::Size(81, 24);
			   this->checkBox_tracert->TabIndex = 1;
			   this->checkBox_tracert->Text = L"tracert";
			   this->checkBox_tracert->UseVisualStyleBackColor = true;
			   // 
			   // checkBox_Fibonachi
			   // 
			   this->checkBox_Fibonachi->AutoSize = true;
			   this->checkBox_Fibonachi->Location = System::Drawing::Point(78, 573);
			   this->checkBox_Fibonachi->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->checkBox_Fibonachi->Name = L"checkBox_Fibonachi";
			   this->checkBox_Fibonachi->Size = System::Drawing::Size(104, 24);
			   this->checkBox_Fibonachi->TabIndex = 2;
			   this->checkBox_Fibonachi->Text = L"Fibonachi";
			   this->checkBox_Fibonachi->UseVisualStyleBackColor = true;
			   // 
			   // button_inputPrioruty
			   // 
			   this->button_inputPrioruty->Location = System::Drawing::Point(643, 499);
			   this->button_inputPrioruty->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->button_inputPrioruty->Name = L"button_inputPrioruty";
			   this->button_inputPrioruty->Size = System::Drawing::Size(176, 35);
			   this->button_inputPrioruty->TabIndex = 4;
			   this->button_inputPrioruty->Text = L"Change priority";
			   this->button_inputPrioruty->UseVisualStyleBackColor = true;
			   this->button_inputPrioruty->Click += gcnew System::EventHandler(this, &MyForm::button_inputPrioruty_Click);
			   // 
			   // button_resume
			   // 
			   this->button_resume->Location = System::Drawing::Point(642, 657);
			   this->button_resume->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->button_resume->Name = L"button_resume";
			   this->button_resume->Size = System::Drawing::Size(174, 28);
			   this->button_resume->TabIndex = 5;
			   this->button_resume->Text = L"Resume";
			   this->button_resume->UseVisualStyleBackColor = true;
			   this->button_resume->Click += gcnew System::EventHandler(this, &MyForm::button_resume_Click);
			   // 
			   // button_suspend
			   // 
			   this->button_suspend->Location = System::Drawing::Point(643, 609);
			   this->button_suspend->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->button_suspend->Name = L"button_suspend";
			   this->button_suspend->Size = System::Drawing::Size(173, 28);
			   this->button_suspend->TabIndex = 6;
			   this->button_suspend->Text = L"Suspend";
			   this->button_suspend->UseVisualStyleBackColor = true;
			   this->button_suspend->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			   // 
			   // comboBox_priority
			   // 
			   this->comboBox_priority->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->comboBox_priority->FormattingEnabled = true;
			   this->comboBox_priority->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				   L"REALTIME_PRIORITY", L"HIGH_PRIORITY",
					   L"ABOVE_NORMAL_PRIORITY", L"NORMAL_PRIORITY", L"BELOW_NORMAL_PRIORITY", L"IDLE_PRIORITY"
			   });
			   this->comboBox_priority->Location = System::Drawing::Point(643, 459);
			   this->comboBox_priority->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->comboBox_priority->Name = L"comboBox_priority";
			   this->comboBox_priority->Size = System::Drawing::Size(175, 28);
			   this->comboBox_priority->TabIndex = 7;
			   // 
			   // checkedListBox1
			   // 
			   this->checkedListBox1->ColumnWidth = 60;
			   this->checkedListBox1->FormattingEnabled = true;
			   this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
				   L"ЦП 0", L"ЦП 1", L"ЦП 2", L"ЦП 3", L"ЦП 4",
					   L"ЦП 5", L"ЦП 6", L"ЦП 7", L"ЦП 8", L"ЦП 9", L"ЦП 10", L"ЦП 11", L"ЦП 12", L"ЦП 13", L"ЦП 14", L"ЦП 15"
			   });
			   this->checkedListBox1->Location = System::Drawing::Point(899, 499);
			   this->checkedListBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->checkedListBox1->MultiColumn = true;
			   this->checkedListBox1->Name = L"checkedListBox1";
			   this->checkedListBox1->Size = System::Drawing::Size(268, 165);
			   this->checkedListBox1->TabIndex = 1;
			   // 
			   // button_Set_affinity
			   // 
			   this->button_Set_affinity->Location = System::Drawing::Point(1019, 460);
			   this->button_Set_affinity->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->button_Set_affinity->Name = L"button_Set_affinity";
			   this->button_Set_affinity->Size = System::Drawing::Size(148, 31);
			   this->button_Set_affinity->TabIndex = 10;
			   this->button_Set_affinity->Text = L"Set affinity";
			   this->button_Set_affinity->UseVisualStyleBackColor = true;
			   this->button_Set_affinity->Click += gcnew System::EventHandler(this, &MyForm::button_Set_affinity_Click);
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				   this->Name, this->ID,
					   this->Status, this->Priority, this->Time
			   });
			   this->dataGridView1->Location = System::Drawing::Point(78, 15);
			   this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->RowHeadersWidth = 51;
			   this->dataGridView1->RowTemplate->Height = 24;
			   this->dataGridView1->Size = System::Drawing::Size(1089, 405);
			   this->dataGridView1->TabIndex = 12;
			   // 
			   // Name
			   // 
			   this->Name->HeaderText = L"Name";
			   this->Name->MinimumWidth = 6;
			   this->Name->Name = L"Name";
			   this->Name->Width = 125;
			   // 
			   // ID
			   // 
			   this->ID->HeaderText = L"ID";
			   this->ID->MinimumWidth = 6;
			   this->ID->Name = L"ID";
			   this->ID->Width = 125;
			   // 
			   // Status
			   // 
			   this->Status->HeaderText = L"Status";
			   this->Status->MinimumWidth = 6;
			   this->Status->Name = L"Status";
			   this->Status->Width = 125;
			   // 
			   // Priority
			   // 
			   this->Priority->HeaderText = L"Priority";
			   this->Priority->MinimumWidth = 6;
			   this->Priority->Name = L"Priority";
			   this->Priority->Width = 125;
			   // 
			   // Time
			   // 
			   this->Time->HeaderText = L"Time";
			   this->Time->MinimumWidth = 6;
			   this->Time->Name = L"Time";
			   this->Time->Width = 125;
			   // 
			   // button_create
			   // 
			   this->button_create->Location = System::Drawing::Point(340, 513);
			   this->button_create->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->button_create->Name = L"button_create";
			   this->button_create->Size = System::Drawing::Size(123, 84);
			   this->button_create->TabIndex = 13;
			   this->button_create->Text = L"Create";
			   this->button_create->UseVisualStyleBackColor = true;
			   this->button_create->Click += gcnew System::EventHandler(this, &MyForm::button_create_Click);
			   // 
			   // textBox_id
			   // 
			   this->textBox_id->Location = System::Drawing::Point(344, 462);
			   this->textBox_id->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->textBox_id->Name = L"textBox_id";
			   this->textBox_id->Size = System::Drawing::Size(116, 26);
			   this->textBox_id->TabIndex = 14;
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(643, 558);
			   this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(173, 29);
			   this->button1->TabIndex = 15;
			   this->button1->Text = L"button_kill";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Interval = 1000;
			   this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::OnTimerTick);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1206, 690);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->textBox_id);
			   this->Controls->Add(this->button_create);
			   this->Controls->Add(this->dataGridView1);
			   this->Controls->Add(this->button_Set_affinity);
			   this->Controls->Add(this->checkedListBox1);
			   this->Controls->Add(this->comboBox_priority);
			   this->Controls->Add(this->button_suspend);
			   this->Controls->Add(this->button_resume);
			   this->Controls->Add(this->button_inputPrioruty);
			   this->Controls->Add(this->checkBox_Fibonachi);
			   this->Controls->Add(this->checkBox_tracert);
			   this->Controls->Add(this->checkBox_VS);
			   this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);/*
			   this->Name = L"MyForm";*/
			   this->Text = L"MyForm";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }

#pragma endregion

	String^ GetProcessNameByPID(DWORD processId) {
		HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processId);
		if (hProcess != NULL) {
			WCHAR processName[MAX_PATH];
			if (GetModuleBaseNameW(hProcess, NULL, processName, sizeof(processName) / sizeof(WCHAR))) {
				CloseHandle(hProcess);
				std::wstring wstr(processName); // Конвертація в std::wstring
				return msclr::interop::marshal_as<String^>(wstr);
			}
			CloseHandle(hProcess);
		}
		return L"Unknown";
	}

	int NameGrid(DWORD name, int index) {

		index = dataGridView1->RowCount - 1;
		dataGridView1->Rows->Add(GetProcessNameByPID(name));
		dataGridView1->Refresh();
		return index;
	}

	void IdGrid(PROCESS_INFORMATION& processInfo, int index) {
		DWORD dwProcessId = processInfo.dwProcessId; // Припустимо, що у вас є dwProcessId типу DWORD
		int processIdInt = static_cast<int>(dwProcessId); // Конвертувати DWORD у int
		String^ processIdString = System::Convert::ToString(processIdInt);
		dataGridView1->Rows[index]->Cells[1]->Value = processIdString;
		dataGridView1->Refresh();

	}

	void StatusGrid(int index, String^ str) {
		dataGridView1->Rows[index]->Cells[2]->Value = str;
		dataGridView1->Refresh();
	}

	void StatusGrid(PROCESS_INFORMATION& name, int index) {
		dataGridView1->Rows[index]->Cells[2]->Value = GetStatus(name);
		dataGridView1->Refresh();
	}

	String^ GetStatus(PROCESS_INFORMATION& processInfo) {
		if (processInfo.hProcess) {
			DWORD exitCode;
			if (GetExitCodeProcess(processInfo.hProcess, &exitCode)) {
				if (exitCode == STILL_ACTIVE) {
					return "R";
				}
				else {
					return "S";
				}
			}
			else {
				return "E";
			}
		}
		else {
			return "E";
		}

	}

	void PriorityGrid(HANDLE& hProcess, int index) {
		dataGridView1->Rows[index]->Cells[3]->Value = GetPriotiry(hProcess);
	}

	String^ GetPriotiry(HANDLE& hProcess) {
		DWORD exitCode = GetPriorityClass(hProcess);
		String^ str = exitCode.ToString();
		if (exitCode == 128) {
			str = "HIGH";
		}
		else if (exitCode == 32768) {
			str = "ABOVE_NORMAL";
		}
		else if (exitCode == 32) {
			str = "NORMAL";
		}
		else if (exitCode == 16384) {
			str = "BELOW_NORMAL";
		}
		else if (exitCode == 64) {
			str = "IDLE_NORMAL";
		}
		else if (exitCode == 256) {
			str = "REALTIME_NORMAL";
		}


		return str;
	}

	private:bool SuspendProcess(DWORD processId) {
		HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

		THREADENTRY32 threadEntry;
		threadEntry.dwSize = sizeof(THREADENTRY32);

		Thread32First(hThreadSnapshot, &threadEntry);

		do
		{
			if (threadEntry.th32OwnerProcessID == processId)
			{
				HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE,
					threadEntry.th32ThreadID);

				SuspendThread(hThread);
				CloseHandle(hThread);
			}
		} while (Thread32Next(hThreadSnapshot, &threadEntry));

		CloseHandle(hThreadSnapshot);
		return true;
	}

	private:bool ResumeProcess(DWORD processId) {
		HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

		THREADENTRY32 threadEntry;
		threadEntry.dwSize = sizeof(THREADENTRY32);

		Thread32First(hThreadSnapshot, &threadEntry);

		do
		{
			if (threadEntry.th32OwnerProcessID == processId)
			{
				HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE,
					threadEntry.th32ThreadID);

				ResumeThread(hThread);
				CloseHandle(hThread);
			}
		} while (Thread32Next(hThreadSnapshot, &threadEntry));

		CloseHandle(hThreadSnapshot);
		return true;
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}

	private:void OnTimerTick(Object^ sender, EventArgs^ e) {
		checkIfAllRun();
		refreshTable();
	}

	private: void refreshTable() {
		for (int i = 0; i < processList.size(); i++) {
			::FILETIME F, M, C, D;
			GetProcessTimes(reinterpret_cast<HANDLE>(processList[i].value.hProcess), &F, &M, &C, &D);
			double timeP = FileTimeToTimestamp(C) + FileTimeToTimestamp(D);
			dataGridView1->Rows[i]->Cells[4]->Value = timeP;
			dataGridView1->Refresh();
		}
	}

	private: void checkIfAllRun() {
		for (int i = 0; i < processList.size(); i++) {
			if (GetStatus(processList[i].value) != "R") {
				RemoveRows(processList[i].index);
			}

		}
	}

	private: double FileTimeToTimestamp(const ::FILETIME& fileTime) {
		ULARGE_INTEGER uli;
		uli.LowPart = fileTime.dwLowDateTime;
		uli.HighPart = fileTime.dwHighDateTime;
		return static_cast<long long>(uli.QuadPart) / 10000000.0;
	}

		   bool CreateProcesses(wchar_t* cmdLine, ProcessInfoPair& processInfo) {

			   STARTUPINFO si = {};
			   ZeroMemory(&si, sizeof(si));
			   si.cb = sizeof(si);

			   if (CreateProcess(NULL, cmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &processInfo.value)) {
				   processInfo.key = processInfo.value.dwProcessId;
				   processInfo.index = count;
				   count++;

				   return true;
			   }
			   else {
				   DWORD error = GetLastError();
				   LPVOID errorMsg;
				   FormatMessage(
					   FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
					   NULL,
					   error,
					   0,
					   (LPWSTR)&errorMsg,
					   0,
					   NULL
				   );
				   std::wcerr << L"Error creating process: " << errorMsg << std::endl;
				   LocalFree(errorMsg);
				   return false;
			   }
		   }

			private: System::Void button_create_Click(System::Object^ sender, System::EventArgs^ e) {
				if (checkBox_VS->Checked) {
					wchar_t name[256];
					_snwprintf_s(name, sizeof(name), L"E:\\Slavery\\ONLY_FANS\\2curs\\ОС-лаб\\lab-3\\vscode\\x64\\Debug\\vscode.exe");
					ProcessInfoPair processInfo;
					if (CreateProcesses(name, processInfo)) {
						Sleep(300);
						processList.push_back(processInfo);
						indexVS = NameGrid(processInfo.value.dwProcessId, processInfo.index);
						IdGrid(processInfo.value, processInfo.index);
						StatusGrid(processInfo.value, processInfo.index);
						PriorityGrid(processInfo.value.hProcess, processInfo.index);
					}
				}
				if (checkBox_tracert->Checked) {
					std::wstring command;
					wchar_t name[256];
					int result = _snwprintf_s(name, sizeof(name), L"tracert -w 300 google.com");
					command = name;
					result = _wsystem(command.c_str());

					ProcessInfoPair processInfo;
					if (CreateProcesses(name, processInfo)) {
						Sleep(300);
						processList.push_back(processInfo);
						indexVS = NameGrid(processInfo.value.dwProcessId, processInfo.index);
						IdGrid(processInfo.value, processInfo.index);
						StatusGrid(processInfo.value, processInfo.index);
						PriorityGrid(processInfo.value.hProcess, processInfo.index);

					}
				}
				if (checkBox_Fibonachi->Checked) {
					wchar_t name[256];
					_snwprintf_s(name, sizeof(name), L"E:\\Slavery\\ONLY_FANS\\2curs\\ОС-лаб\\lab-3\\find\\x64\\Debug\\find.exe");
					ProcessInfoPair processInfo;
					if (CreateProcesses(name, processInfo)) {
						Sleep(300);
						processList.push_back(processInfo);
						indexVS = NameGrid(processInfo.value.dwProcessId, processInfo.index);
						IdGrid(processInfo.value, processInfo.index);
						StatusGrid(processInfo.value, processInfo.index);
						PriorityGrid(processInfo.value.hProcess, processInfo.index);

					}
				}
			}

		   void TerminateProcessIfExists(PROCESS_INFORMATION& processInfo) {
			   if (processInfo.hProcess != NULL && processInfo.hThread != NULL) {
				   TerminateProcess(processInfo.hProcess, 0);
				   CloseHandle(processInfo.hProcess);
				   CloseHandle(processInfo.hThread);
				   ZeroMemory(&processInfo, sizeof(processInfo));
			   }
			   if (WaitForSingleObject(processInfo.hProcess, INFINITE) != WAIT_OBJECT_0) {
				   // Помилка очікування завершення процесу
				   std::wcerr << L"Error waiting for process termination." << std::endl;
			   }
		   }

	private: System::Void button_inputPrioruty_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ selectedPriority = (comboBox_priority->SelectedItem->ToString());
		DWORD dwValue = Convert::ToInt32(textBox_id->Text);
		HANDLE hProcess;
		ProcessInfoPair processInfoPair;
		for (int i = 0; i < processList.size(); i++) {
			if (processList[i].key == dwValue)
			{
				processInfoPair = processList[i];
				break;
			}
		}

		int priorityClass;
		if (selectedPriority == L"REALTIME_PRIORITY") {
			priorityClass = REALTIME_PRIORITY_CLASS;
		}
		else if (selectedPriority == L"HIGH_PRIORITY") {
			priorityClass = HIGH_PRIORITY_CLASS;
		}
		else if (selectedPriority == L"ABOVE_NORMAL_PRIORITY") {
			priorityClass = ABOVE_NORMAL_PRIORITY_CLASS;
		}
		else if (selectedPriority == L"NORMAL_PRIORITY") {
			priorityClass = NORMAL_PRIORITY_CLASS;
		}
		else if (selectedPriority == L"BELOW_NORMAL_PRIORITY") {
			priorityClass = BELOW_NORMAL_PRIORITY_CLASS;
		}
		else if (selectedPriority == L"IDLE_PRIORITY") {
			priorityClass = IDLE_PRIORITY_CLASS;
		}

		BOOL success = SetPriorityClass(processInfoPair.value.hProcess, priorityClass);
		PriorityGrid(processInfoPair.value.hProcess, processInfoPair.index);
	}


	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		DWORD dwValue = Convert::ToInt32(textBox_id->Text);
		HANDLE hThread;
		ProcessInfoPair processInfoPair;
		for (int i = 0; i < processList.size(); i++) {
			if (processList[i].key == dwValue)
			{
				processInfoPair = processList[i];
				break;
			}
		}

		hThread = OpenThread(THREAD_SUSPEND_RESUME, FALSE, processInfoPair.value.dwThreadId);
		SuspendProcess(processInfoPair.value.dwProcessId); 
		Sleep(300);
		StatusGrid(processInfoPair.index, "S");
	}

	private: System::Void button_resume_Click(System::Object^ sender, System::EventArgs^ e) {
		DWORD dwValue = Convert::ToInt32(textBox_id->Text);
		HANDLE hThread;
		ProcessInfoPair processInfoPair;
		for (int i = 0; i < processList.size(); i++) {
			if (processList[i].key == dwValue)
			{
				processInfoPair = processList[i];
				break;
			}
		}

		hThread = OpenThread(THREAD_SUSPEND_RESUME, FALSE, processInfoPair.value.dwThreadId);
		ResumeProcess(processInfoPair.value.dwProcessId); 
		Sleep(300);
		StatusGrid(processInfoPair.index, "R");
	}

	private: System::Void button_Set_affinity_Click(System::Object^ sender, System::EventArgs^ e) {

		DWORD dwValue = Convert::ToInt32(textBox_id->Text);

		ProcessInfoPair processInfoPair;
		for (int i = 0; i < processList.size(); i++) {
			if (processList[i].key == dwValue)
			{
				processInfoPair = processList[i];
				break;
			}
		}
		HANDLE hThread = processInfoPair.value.hProcess;
		DWORD_PTR affinityMask = 0;
		for (int i = 0; i < checkedListBox1->Items->Count; i++) {
			if (checkedListBox1->GetItemChecked(i)) {
				affinityMask = affinityMask | (1 << i);
			}
		}
		SetProcessAffinityMask(hThread, affinityMask);

	}

	void ClearCheckList() {
		for (int i = 0; i < checkedListBox1->Items->Count; i++) {
			checkedListBox1->SetItemChecked(i, false);
		}
	}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		DWORD dwValue = Convert::ToInt32(textBox_id->Text);
		HANDLE hThread;
		ProcessInfoPair processInfoPair;
		processInfoPair.index = -1;
		for (int i = 0; i < processList.size(); i++) {
			if (processList[i].key == dwValue)
			{
				processInfoPair = processList[i];
				break;
			}

		}
		if (processInfoPair.index == -1)
			return;
		TerminateProcessIfExists(processInfoPair.value);
		RemoveRows(processInfoPair.index);

	}

	void RemoveRows(int rowIndexToRemove) {
		count--;
		dataGridView1->Rows->RemoveAt(rowIndexToRemove);
		dataGridView1->Refresh();

		if (rowIndexToRemove >= 0 && rowIndexToRemove < processList.size()) {
			processList.erase(processList.begin() + rowIndexToRemove);
		}
		ProcessInfoPair processInfoPair;
		for (int i = rowIndexToRemove; i < processList.size(); i++) {
			processList[i].index -= 1;
		}
	}

	};

}
#pragma once

namespace OceanSea {

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
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ FileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ OpenFileWithPointsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ OpenFileWithOceanSeaToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxSeasList;
	private: System::Windows::Forms::TextBox^ textBoxPointsList;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartAllPoints;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::ComboBox^ comboBoxYears;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartWorldPoints;
	private: System::Windows::Forms::ListBox^ listBoxAllSea;
	private: System::Windows::Forms::ListBox^ listBoxViewSea;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ buttonAddSea;
	private: System::Windows::Forms::Button^ buttonDelSea;


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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->FileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OpenFileWithPointsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OpenFileWithOceanSeaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxSeasList = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPointsList = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->chartAllPoints = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBoxYears = (gcnew System::Windows::Forms::ComboBox());
			this->chartWorldPoints = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->listBoxAllSea = (gcnew System::Windows::Forms::ListBox());
			this->listBoxViewSea = (gcnew System::Windows::Forms::ListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->buttonAddSea = (gcnew System::Windows::Forms::Button());
			this->buttonDelSea = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartAllPoints))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartWorldPoints))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->FileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1482, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyForm::menuStrip1_ItemClicked);
			// 
			// FileToolStripMenuItem
			// 
			this->FileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->OpenFileWithPointsToolStripMenuItem,
					this->OpenFileWithOceanSeaToolStripMenuItem
			});
			this->FileToolStripMenuItem->Name = L"FileToolStripMenuItem";
			this->FileToolStripMenuItem->Size = System::Drawing::Size(59, 24);
			this->FileToolStripMenuItem->Text = L"Файл";
			// 
			// OpenFileWithPointsToolStripMenuItem
			// 
			this->OpenFileWithPointsToolStripMenuItem->Name = L"OpenFileWithPointsToolStripMenuItem";
			this->OpenFileWithPointsToolStripMenuItem->Size = System::Drawing::Size(360, 26);
			this->OpenFileWithPointsToolStripMenuItem->Text = L"Открыть файл с точками ...";
			this->OpenFileWithPointsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::OpenFileWithPointsToolStripMenuItem_Click_1);
			// 
			// OpenFileWithOceanSeaToolStripMenuItem
			// 
			this->OpenFileWithOceanSeaToolStripMenuItem->Name = L"OpenFileWithOceanSeaToolStripMenuItem";
			this->OpenFileWithOceanSeaToolStripMenuItem->Size = System::Drawing::Size(360, 26);
			this->OpenFileWithOceanSeaToolStripMenuItem->Text = L"Открыть файл с морями и океанами ...";
			this->OpenFileWithOceanSeaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::OpenFileWithOceanSeaToolStripMenuItem_Click);
			// 
			// openFileDialog
			// 
			this->openFileDialog->Filter = L"JSON (*.json)|*.json";
			this->openFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(94, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Файл";
			// 
			// textBoxSeasList
			// 
			this->textBoxSeasList->Location = System::Drawing::Point(97, 66);
			this->textBoxSeasList->Multiline = true;
			this->textBoxSeasList->Name = L"textBoxSeasList";
			this->textBoxSeasList->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxSeasList->Size = System::Drawing::Size(264, 313);
			this->textBoxSeasList->TabIndex = 2;
			// 
			// textBoxPointsList
			// 
			this->textBoxPointsList->Location = System::Drawing::Point(97, 404);
			this->textBoxPointsList->Multiline = true;
			this->textBoxPointsList->Name = L"textBoxPointsList";
			this->textBoxPointsList->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxPointsList->Size = System::Drawing::Size(264, 300);
			this->textBoxPointsList->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(94, 382);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Файл";
			// 
			// chartAllPoints
			// 
			chartArea1->Name = L"ChartArea1";
			this->chartAllPoints->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chartAllPoints->Legends->Add(legend1);
			this->chartAllPoints->Location = System::Drawing::Point(724, 59);
			this->chartAllPoints->Name = L"chartAllPoints";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->LegendText = L"Кол-во точек";
			series1->Name = L"Series1";
			this->chartAllPoints->Series->Add(series1);
			this->chartAllPoints->Size = System::Drawing::Size(554, 324);
			this->chartAllPoints->TabIndex = 5;
			this->chartAllPoints->Text = L"chart1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1318, 95);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 33);
			this->button1->TabIndex = 6;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// comboBoxYears
			// 
			this->comboBoxYears->FormattingEnabled = true;
			this->comboBoxYears->Location = System::Drawing::Point(1318, 179);
			this->comboBoxYears->Name = L"comboBoxYears";
			this->comboBoxYears->Size = System::Drawing::Size(121, 24);
			this->comboBoxYears->TabIndex = 7;
			this->comboBoxYears->Text = L"All";
			this->comboBoxYears->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxYears_SelectedIndexChanged);
			// 
			// chartWorldPoints
			// 
			chartArea2->AxisX->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea2->AxisX->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			chartArea2->AxisY->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea2->AxisY->MajorGrid->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			chartArea2->BackImage = L"C:\\Users\\Катя\\Documents\\Политех\\Программирование С++\\coursework\\OceanSea\\60397316"
				L".jpg";
			chartArea2->BackImageWrapMode = System::Windows::Forms::DataVisualization::Charting::ChartImageWrapMode::Scaled;
			chartArea2->Name = L"ChartArea1";
			this->chartWorldPoints->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chartWorldPoints->Legends->Add(legend2);
			this->chartWorldPoints->Location = System::Drawing::Point(392, 404);
			this->chartWorldPoints->Name = L"chartWorldPoints";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series2->Legend = L"Legend1";
			series2->LegendText = L"Точка наблюдения";
			series2->Name = L"Series1";
			this->chartWorldPoints->Series->Add(series2);
			this->chartWorldPoints->Size = System::Drawing::Size(886, 300);
			this->chartWorldPoints->TabIndex = 8;
			this->chartWorldPoints->Text = L"chart1";
			this->chartWorldPoints->Click += gcnew System::EventHandler(this, &MyForm::chartWorldPoints_Click);
			// 
			// listBoxAllSea
			// 
			this->listBoxAllSea->DisplayMember = L"1";
			this->listBoxAllSea->FormattingEnabled = true;
			this->listBoxAllSea->ItemHeight = 16;
			this->listBoxAllSea->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Баренцево море", L"Море Лаптевых", L"Черное море",
					L"Средиземное море"
			});
			this->listBoxAllSea->Location = System::Drawing::Point(392, 64);
			this->listBoxAllSea->Name = L"listBoxAllSea";
			this->listBoxAllSea->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->listBoxAllSea->Size = System::Drawing::Size(145, 308);
			this->listBoxAllSea->TabIndex = 9;
			// 
			// listBoxViewSea
			// 
			this->listBoxViewSea->FormattingEnabled = true;
			this->listBoxViewSea->ItemHeight = 16;
			this->listBoxViewSea->Location = System::Drawing::Point(578, 59);
			this->listBoxViewSea->Name = L"listBoxViewSea";
			this->listBoxViewSea->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->listBoxViewSea->Size = System::Drawing::Size(131, 324);
			this->listBoxViewSea->TabIndex = 10;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(391, 40);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(150, 16);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Полный список морей";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(569, 40);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(117, 16);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Выбранные моря";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// buttonAddSea
			// 
			this->buttonAddSea->Location = System::Drawing::Point(543, 133);
			this->buttonAddSea->Name = L"buttonAddSea";
			this->buttonAddSea->Size = System::Drawing::Size(30, 30);
			this->buttonAddSea->TabIndex = 13;
			this->buttonAddSea->Text = L">>";
			this->buttonAddSea->UseVisualStyleBackColor = true;
			this->buttonAddSea->Click += gcnew System::EventHandler(this, &MyForm::buttonAddSea_Click);
			// 
			// buttonDelSea
			// 
			this->buttonDelSea->Location = System::Drawing::Point(543, 181);
			this->buttonDelSea->Name = L"buttonDelSea";
			this->buttonDelSea->Size = System::Drawing::Size(30, 30);
			this->buttonDelSea->TabIndex = 14;
			this->buttonDelSea->Text = L"<<";
			this->buttonDelSea->UseVisualStyleBackColor = true;
			this->buttonDelSea->Click += gcnew System::EventHandler(this, &MyForm::buttonDelSea_Click);
			// 
			// MyForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1482, 826);
			this->Controls->Add(this->buttonDelSea);
			this->Controls->Add(this->buttonAddSea);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->listBoxViewSea);
			this->Controls->Add(this->listBoxAllSea);
			this->Controls->Add(this->chartWorldPoints);
			this->Controls->Add(this->comboBoxYears);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chartAllPoints);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxPointsList);
			this->Controls->Add(this->textBoxSeasList);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Точки наблюдения в морях и океанах";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartAllPoints))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartWorldPoints))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void OpenFileWithPointsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
	private: System::Void OpenFileWithPointsToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e);
	private: System::Void OpenFileWithOceanSeaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonAddSea_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonDelSea_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}
private: System::Void comboBoxYears_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void chartWorldPoints_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}

};
}

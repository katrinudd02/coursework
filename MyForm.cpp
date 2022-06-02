#include "MyForm.h"
#include <iostream>
#include <fstream>
#include "json_support.hpp"
#include "Seas.h"
#include <string>
#include <msclr\marshal_cppstd.h>
#include "Adapter.h"
#include "Point.h"
#include <map>
#include <set>


using json = nlohmann::json;

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace msclr::interop;

Sea *SeasList;
int CountSeas;
Pointt* all_points;
int CountPoints;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	OceanSea::MyForm form;
	Application::Run(% form);


}



System::Void OceanSea::MyForm::OpenFileWithPointsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void OceanSea::MyForm::openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{
	return System::Void();
}

System::Void OceanSea::MyForm::OpenFileWithPointsToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e)
{
	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

		
		msclr::interop::marshal_context context;
		std::string standardString = context.marshal_as<std::string>(openFileDialog->FileName);
		std::ifstream fileJson(standardString);
		
		if (fileJson.is_open()) {
			label2->Text = openFileDialog->FileName;

			json j;
			fileJson >> j;
fileJson.close();

json results = j["results"];
CountPoints = (int)(j["count"]);
all_points = new Pointt[CountPoints];

Adapter all_data(j["count"], &results, all_points);

textBoxPointsList->Clear();
for (int i = 0; i < 100; i++) {
	textBoxPointsList->Text += i + "\r\n";
	textBoxPointsList->Text += "lon: " + all_points[i].GetLon().ToString() + "\r\n";
	textBoxPointsList->Text += "lat: " + all_points[i].GetLat().ToString() + "\r\n";
	textBoxPointsList->Text += "type: ";
	if (all_points[i].Get_type(graph)) textBoxPointsList->Text += "graph ";
	if (all_points[i].Get_type(map)) textBoxPointsList->Text += "map ";
	if (all_points[i].Get_type(record)) textBoxPointsList->Text += "record ";
	if (all_points[i].Get_type(satellite)) textBoxPointsList->Text += "satellite ";
	if (all_points[i].Get_type(table)) textBoxPointsList->Text += "table ";
	textBoxPointsList->Text += "\r\n";
	if (all_points[i].GetYear_record() > 0) {
		textBoxPointsList->Text += "year: " + all_points[i].GetYear_record() + "\r\n";
		textBoxPointsList->Text += "month: " + all_points[i].GetMonth_record() + "\r\n";
	}
	else {
		textBoxPointsList->Text += "date: " + (gcnew System::String(all_points[i].Get_date().c_str())) + "\r\n" ;

	}
}

// заполним список годов
comboBoxYears->Items->Clear();
comboBoxYears->Text = "All";
comboBoxYears->Items->Add(comboBoxYears->Text);
std::set <int> Years;
std::set <int>::iterator itYears;
for (int i = 0; i < CountPoints; i++) {
	if (all_points[i].GetYear_record() > 0)
		Years.insert(all_points[i].GetYear_record());
}
itYears = Years.begin();
for (int i = 0; itYears != Years.end(); itYears++, i++) {
	comboBoxYears->Items->Add(*itYears);
}


		}
		//else {
		//// TODO  сообщение об ошибке
		//}


	}



	return System::Void();
}

System::Void OceanSea::MyForm::OpenFileWithOceanSeaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

		msclr::interop::marshal_context context;
		std::string standardString = context.marshal_as<std::string>(openFileDialog->FileName);
		std::ifstream fileJson(standardString);

		if (fileJson.is_open()) {
			label1->Text = openFileDialog->FileName;

			CountSeas = ReadSeaList(fileJson, &SeasList);


			fileJson.close();
		}
		//else {
		//// TODO  сообщение об ошибке
		//}

		//ShowSeaList(SeasList);
		textBoxSeasList->Clear();
		int Count_sqs;
		for (int i = 0; i < CountSeas; i++) {
			textBoxSeasList->Text += gcnew System::String(SeasList[i].GetName().c_str()) + "\r\n";
			textBoxSeasList->Text += gcnew System::String(SeasList[i].GetId().ToString()) + "\r\n";
			Count_sqs = SeasList[i].GetCount_sqs();
			for (int j = 0; j < SeasList[i].GetCount_sqs(); j++) {
				for (int k = 0; k < 4; k++) {
					textBoxSeasList->Text += "LAT POINT" + k + ":" + gcnew System::String(SeasList[i].GetSquare(j).GetPoint(k).GetLat().ToString()) + "\r\n";
					textBoxSeasList->Text += "LAT POINT" + k + ":" + gcnew System::String(SeasList[i].GetSquare(j).GetPoint(k).GetLat().ToString()) + "\r\n";
				}
			}
		};


	}

	return System::Void();
}

System::Void OceanSea::MyForm::buttonAddSea_Click(System::Object^ sender, System::EventArgs^ e)
{
	for (int i=0; i < listBoxAllSea->SelectedItems->Count; i++) {
		if (!listBoxViewSea->Items->Contains(listBoxAllSea->SelectedItems[i])) {
			listBoxViewSea->Items->Add(listBoxAllSea->SelectedItems[i]);
		}
	}
	return System::Void();
}

System::Void OceanSea::MyForm::buttonDelSea_Click(System::Object^ sender, System::EventArgs^ e)
{
	for (int i = 0; i < listBoxViewSea->SelectedItems->Count; i++) {
		listBoxViewSea->Items->Remove(listBoxViewSea->SelectedItems[i]);
	}
	return System::Void();
}

System::Void OceanSea::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::map<int, int> mapYearsPoint;
	std::map<int, int>::iterator it;

	std::map<double, double> mapWorldPoint;
	std::map<double, double>::iterator itwp;

	int year;
	if(comboBoxYears->Text == "All") {
		year = 0;
	}
	else {
		year = Int32::Parse(comboBoxYears->Text);
	}

	for (int i = 0; i < CountPoints; i++) {
		if (year == 0) {
			it = mapYearsPoint.find(all_points[i].GetYear_record());
			if (it == mapYearsPoint.end()) {
				mapYearsPoint[all_points[i].GetYear_record()] = 1;
			}
			else {
				it->second++;
			}
		}
		else {
			if (all_points[i].GetYear_record() == year) {
				it = mapYearsPoint.find(all_points[i].GetMonth_record());
				if (it == mapYearsPoint.end()) {
					mapYearsPoint[all_points[i].GetMonth_record()] = 1;
				}
				else {
					it->second++;
				}
			}
		}

		chartWorldPoints->Series[0]->Points->AddXY(all_points[i].GetLon(), all_points[i].GetLat());
	}
	it = mapYearsPoint.begin();
	textBoxSeasList->Clear();
	chartAllPoints->Series[0]->Points->Clear();
	for (int i = 0; it != mapYearsPoint.end(); it++, i++) {  // выводим их
		textBoxSeasList->Text += it->first + " : " + it->second + "\r\n";
		if(it->first>0) chartAllPoints->Series[0]->Points->AddXY(it->first, it->second);
	}


	return System::Void();
}

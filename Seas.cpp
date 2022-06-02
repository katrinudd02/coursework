#include "Seas.h"
#include <iostream>
#include "json_support.hpp"
#include <iostream>
#include <fstream>

using json = nlohmann::json;

Coord::Coord() {
	lat = 0;
	lon = 0;
}

//Coord::Coord(double _lat, double _lon) {
//	lat = _lat;
//	lon = _lon;
//}
Coord& Coord::operator=(const Coord& right) {
	//проверка на самоприсваивание
	if (this == &right) {
		return *this;
	}

	lat = right.GetLat();
	lon = right.GetLon();
	return *this;
}

Square::Square(Coord* _points) {
	int i;
	for (i = 0; i < 4; i++) {
		points[i] = _points[i];
	}
}


Square& Square::operator=(const Square& right) {
	//проверка на самоприсваивание
	if (this == &right) {
		return *this;
	}
	for (int i = 0; i < 4; i++) {
		points[i] = right.points[i];
	}
	return *this;
}

//bool Square::CheckCoord(Coord _c) {
//	bool result = false;
//	if ( _c.GetLon() >= this->points[0].GetLon() && 
//		 _c.GetLon() >= this->points[1].GetLon() && 
//		 _c.GetLat() <= this->points[0].GetLat() &&
//		_c.GetLat() >= this->points[3].GetLat()) {
//		result = true;
//	}
//	return result;
//}



Sea::Sea(int _id, std::string _name, int _count_sqs, Square* _sqs) : id(_id), name(_name), count_sqs(_count_sqs), sqs(_sqs) {

}

//void Sea::Fill(int _id, std::string _name, int _count_sqs, Square* _sqs) {
//	this->id = _id;
//	this->name = _name;
//	if (this->count_sqs) {
//		delete [] this->sqs;
//	}
//	this->count_sqs = _count_sqs;
//	this->sqs = new Square[count_sqs];
//	for (int i = 0; i < count_sqs; i++) {
//		this->sqs[i] = _sqs[i];
//	}
//}

//bool Sea::CheckCoord(Coord _c) {
//	bool result = true;
//	for (int i = 0; i < count_sqs; i++) {
//		if (!sqs[i].CheckCoord(_c)) {
//			result = false;
//			break;
//	}
//	return result;
//}

int ReadSeaList(std::ifstream & inputfile, Sea** seas) {
	json js;
	int count_sqs = 0;
	Square* sqs;
	Coord* points;

	inputfile >> js;
	int count_sea = js["Count"];
	(*seas) = new Sea[count_sea];

	for (int i = 0; i < count_sea; i++) {

		count_sqs = js["Seas"][i]["count_sqs"];
		sqs = new Square[count_sqs];

		for (int j = 0; j < count_sqs; j++) {
			points = new Coord[4];
			for (int k = 0; k < 4; k++) {
				points[k].Set_lat(js["Seas"][i]["sqs"][j]["points"][k]["lat"]);
				points[k].Set_lon(js["Seas"][i]["sqs"][j]["points"][k]["lon"]);
			}
			sqs[j].Fill(points);
		}
		(*seas)[i].Fill((int)(js["Seas"][i]["id"]), (std::string)(js["Seas"][i]["name"]), count_sqs, sqs);
	}

	return count_sea;
}
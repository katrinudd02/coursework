#include "Point.h"
#include <iostream>

Point::Point(double _lon, double _lat, std::string _date) : lon(_lon), lat(_lat), date(_date) {
	Create_month_year();
}

void Point::Create_month_year() {
	if (date == "") {
		return;
	}
	year_record = std::stoi(date.substr(0, date.find("-")));
	month_record = std::stoi(date.substr(date.find("-") + 1, date.find("-")));
}

void Point::PrintPoint() const {
	std::cout << "lon " << lon << std::endl;
	std::cout << "lat " << lat << std::endl;
	std::cout << "type " << type << std::endl;
	if (type[map]) std::cout << "map ";
	if (type[graph]) std::cout << "graph ";
	if (type[satellite]) std::cout << "satellite ";
	if (type[record]) std::cout << "record ";
	if (type[table]) std::cout << "table ";
	std::cout << std::endl;
	std::cout << "date " << date << std::endl;
	std::cout << "year " << year_record << std::endl;
	std::cout << "month " << month_record << std::endl;
}
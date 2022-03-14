#include "Adapter.h"
#include <iostream>

Adapter::Adapter(int _count_records, json* _results, Point* _all_points) : count_records(_count_records), results(*_results), all_points(_all_points) {
	for (int i = 0; i < count_records; i++) {
		if (results[i]["lat"] != nlohmann::detail::value_t::null) {
			all_points[i].Set_lat(results[i]["lat"]);
		}
		else {
			all_points[i].Set_lat(0);
		}
		if (results[i]["lon"] != nlohmann::detail::value_t::null) {
			all_points[i].Set_lon(results[i]["lon"]);
		}
		else {
			all_points[i].Set_lon(0); //ask initialise
		}
		for (int j = 0; j < 5; j++) {
			if (results[i]["new_types"][j]["value"] != nlohmann::detail::value_t::null) {
				if (results[i]["new_types"][j]["value"] == 0) {
					all_points[i].Set_type(map);
				}
				if (results[i]["new_types"][j]["value"] == 1) {
					all_points[i].Set_type(graph);
				}
				if (results[i]["new_types"][j]["value"] == 2) {
					all_points[i].Set_type(satellite);
				}
				if (results[i]["new_types"][j]["value"] == 3) {
					all_points[i].Set_type(record);
				}
				if (results[i]["new_types"][j]["value"] == 4) {
					all_points[i].Set_type(table);
				}
			}
		}
		if (results[i]["date"] != nlohmann::detail::value_t::null) {
			all_points[i].Set_date(results[i]["date"]);
			all_points[i].Create_month_year();
		}
	}
}

void Adapter::PrintAll() const {
	std::ofstream ofs("info.txt");
	for (int i = 0; i < count_records; i++) {
		ofs << i << std::endl;
		ofs << "lon: " << all_points[i].GetLon() << std::endl;
		ofs << "lat: " << all_points[i].GetLat() << std::endl;
		ofs << "type: ";
		if (all_points[i].Get_type(graph)) ofs << "graph ";
		if (all_points[i].Get_type(map)) ofs << "map ";
		if (all_points[i].Get_type(record)) ofs << "record ";
		if (all_points[i].Get_type(satellite)) ofs << "satellite ";
		if (all_points[i].Get_type(table)) ofs << "table ";
		ofs << std::endl;
		ofs << "year: " << all_points[i].GetYear_record() << std::endl;
		ofs << "month: " << all_points[i].GetMonth_record() << std::endl;
	}
}

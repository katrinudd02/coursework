#include "Adapter.h"
#include <iostream>

Adapter::Adapter(int _count_records, json* _results, Point* _all_points) : count_records(_count_records), results(*_results), all_points(_all_points) {
	//create_arr_points(count_records, results, all_points);
	//std::cout << results[6] <<std::endl <<std::endl;
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
					all_points[i].Set_map(true);
				}
				if (results[i]["new_types"][j]["value"] == 1) {
					all_points[i].Set_graph(true);
				}
				if (results[i]["new_types"][j]["value"] == 2) {
					all_points[i].Set_satellite(true);
				}
				if (results[i]["new_types"][j]["value"] == 3) {
					all_points[i].Set_record(true);
				}
				if (results[i]["new_types"][j]["value"] == 4) {
					all_points[i].Set_table(true);
				}
			}
		}
		if (results[i]["new_types"][0]["value"] != nlohmann::detail::value_t::null) {
			all_points[i].Set_type(results[i]["new_types"][0]["value"]);
		}
		else {
			all_points[i].Set_type(-1);
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
		if (all_points[i].GetGraph()) ofs << "graph ";
		if (all_points[i].GetMap()) ofs << "map ";
		if (all_points[i].GetRecord()) ofs << "record ";
		if (all_points[i].GetSatellite()) ofs << "satellite ";
		if (all_points[i].GetTable()) ofs << "table ";
		ofs << std::endl;
		ofs << "year: " << all_points[i].GetYear_record() << std::endl;
		ofs << "month: " << all_points[i].GetMonth_record() << std::endl;
	}
}

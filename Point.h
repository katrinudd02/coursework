#pragma once
#include <string>



enum TYPE {map, graph, satellite, record, table, size};
class Pointt
{
public:
	Pointt() {};
	Pointt(double _lat, double _lon, std::string _date);
	double GetLon() const { return lon; }
	double GetLat() const { return lat; }
	int GetYear_record() const { return year_record; }
	int GetMonth_record() const { return month_record; }
	//bool GetMap() const { return map; }
	//bool GetGraph() const { return graph; }
	//bool GetSatellite() const { return satellite; }
	//bool GetRecord() const { return record; }
	//bool GetTable() const { return table; }
	bool Get_type(TYPE _type) const { return type[_type]; }
	void Set_lon(double _lon) { lon = _lon; };
	void Set_lat(double _lat) { lat = _lat; };
	void Set_type(TYPE _type) { type[_type] = true; };
	void Set_date(std::string _date) { date = _date; };
	//void Set_map(bool _map) { map = _map; };
	//void Set_graph(bool _graph) { graph = _graph; };
	//void Set_satellite(bool _satellite) { satellite = _satellite; };
	//void Set_record(bool _record) { record = _record; };
	//void Set_table(bool _table) { table = _table; };
	void Create_month_year();
	std::string Get_date() const { return date; }
	void PrintPoint() const;
private:
	double lon;
	double lat;
	bool type[(int)TYPE::size] = {false};
	std::string date;
	int year_record;
	int month_record;
	/*bool map = false;
	bool graph = false;
	bool satellite = false;
	bool record = false;
	bool table = false;*/
};


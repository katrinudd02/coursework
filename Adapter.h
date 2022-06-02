#pragma once
#include "json_support.hpp"
#include "Point.h"
#include <vector>
#include <fstream>
using json = nlohmann::json;

class Adapter
{
private:
	json results;
	int count_records;
	Pointt* all_points;
public:
	Adapter(int _count_records, json* _results, Pointt* all_points);
	Pointt* GetAllPoints() const { return all_points; }
	void PrintAll() const;
};


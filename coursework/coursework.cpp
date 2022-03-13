#include <iostream>
#include <fstream>
#include "json_support.hpp"
#include "Point.h"
#include "adapter.h"
using json = nlohmann::json;

int main() {
    std::ifstream ifs("records.json");
    if (!ifs.is_open()) {
        std::cout << "Error" << std::endl;
        return -1;
    }
    json j;
    ifs >> j;
    ifs.close();
    std::cout << j["count"] << std::endl;
    json results = j["results"];
    Point* all_point = new Point[(int)j["count"]];
    Adapter all_data(j["count"], &results, all_point);
    all_data.PrintAll();
}


#pragma once
#include <string>




class Coord 
{
public:
	Coord();
	Coord(double _lat, double _lon) : lat(_lat), lon(_lon) { };
	double GetLon() const { return lon; }
	double GetLat() const { return lat; }
	void Set_lon(double _lon) { lon = _lon; };
	void Set_lat(double _lat) { lat = _lat; };
	Coord& operator=(const Coord& right);
private:
	double lon;
	double lat;
};

class Square
{
public:
	Square() {};
	Square(Coord* _points);
	void Fill(Coord* _points) { points = _points; };
	Square& operator=(const Square& right);
	Coord GetPoint(int numpoint) const { return points[numpoint]; }
	bool CheckCoord(Coord _c) {
		bool result = false;
		if (_c.GetLon() <= this->points[0].GetLon() &&
			_c.GetLon() >= this->points[3].GetLon() &&
			_c.GetLat() <= this->points[1].GetLat() &&
			_c.GetLat() >= this->points[0].GetLat()) {
			result = true;
		}
		return result;
	}
private:
	Coord *points;
};


class Sea
{
public:
	Sea() {};
	Sea(int _id, std::string _name, int _count_sqs, Square* _sqs);
	void Fill(int _id, std::string _name, int _count_sqs, Square* _sqs) { id = _id; name = _name; count_sqs = _count_sqs; sqs = _sqs;  };
	bool CheckCoord(Coord _c)
	{
		bool result = true;
		for (int i = 0; i < count_sqs; i++) {
			if (!sqs[i].CheckCoord(_c)) {
				result = false;
				break;
			}
			return result;
		}
	}
	std::string GetName() const { return name; }
	int GetId() const { return id; }
	int GetCount_sqs() const { return count_sqs; }
	Square GetSquare(int numsquare) const { return sqs[numsquare]; }

private:
	int count_sqs;
	std::string name;
	int id;
	Square* sqs;

};

int ReadSeaList(std::ifstream &, Sea**);
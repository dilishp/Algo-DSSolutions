#ifndef STATION
#define STATION

#include <string>

using namespace std;

class Station
{
public:
	Station();
	Station(double freq, string name);
	~Station();
	string getName() const;
	double getFrequency() const;
	void setName(string name);
private:
	double m_frequency;
	string m_name;
};

#endif

#include "pch.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

enum Direction
{
	NORTH,
	SOUTH, 
	EAST,
	WEST
};

class Track
{
public:
	Track(Direction direction, bool bmotorOnly) :m_direction(direction), m_bMotorcyclesOnly(bmotorOnly) {}
	Direction getTrackDirection() const
	{
		return m_direction;
	}
	bool isMotorCyclesOnlyTrack() const
	{
		return m_bMotorcyclesOnly;
	}
private:
	Direction m_direction;
	bool m_bMotorcyclesOnly;
};

class Vehicle
{
public:
	Vehicle(string licenseNumber):m_licenseNumber(licenseNumber){}
	virtual void accelerate() = 0;
	virtual void decelerate() = 0;
	virtual void calculateCurrPosition() = 0;
	void setTrack(Track* aTrack)
	{
		m_track = aTrack;
	}
	Track* getTrack()
	{
		return m_track;
	}
	double getCurPosition()
	{
		return m_curPosition;
	}
	void setCurPosition(double pos)
	{
		m_curPosition = pos;
	}
	void setCurSpeed(double curSpeed)
	{
		m_curSpeed = curSpeed;
	}
	string getType() const
	{
		return m_type;
	}
protected:
	string m_type;
	string m_licenseNumber;
	double m_maxSpeed;
	double m_curSpeed = 0.0;
	double m_curPosition = 0.0;
	Track* m_track;
};

class Car:public Vehicle
{
public:
	Car(string licenseNumber) :Vehicle(licenseNumber)
	{
		m_maxSpeed = 7.0;
		m_type = "C";
	}
	void accelerate() override
	{
		if (m_curSpeed < m_maxSpeed)
			m_curSpeed += 2;

		if (m_curSpeed > m_maxSpeed)
			m_curSpeed = m_maxSpeed;
	}

	void decelerate() override
	{
		if(m_curSpeed > 0)
			m_curSpeed -= 2;

		if (m_curSpeed < 0)
			m_curSpeed = 0;
	}

	void calculateCurrPosition() override
	{
		if (m_track->getTrackDirection() == Direction::EAST)
		{
			m_curPosition += m_curSpeed * 1;
		}
		else if (m_track->getTrackDirection() == Direction::WEST)
		{
			m_curPosition -= m_curSpeed * 1;
		}
	}

};

class Truck :public Vehicle
{
public:
	Truck(string licenseNumber) :Vehicle(licenseNumber)
	{
		m_maxSpeed = 4.0;
		m_type = "T";
	}
	void accelerate() override
	{
		if(m_curSpeed < m_maxSpeed)
			m_curSpeed += 1;

		if (m_curSpeed > m_maxSpeed)
			m_curSpeed = m_maxSpeed;
	}

	void decelerate() override
	{
		if (m_curSpeed > 0)
			m_curSpeed -= 1;

		if (m_curSpeed < 0)
			m_curSpeed = 0;
	}

	void calculateCurrPosition() override
	{
		if (m_track->getTrackDirection() == Direction::EAST)
		{
			m_curPosition += m_curSpeed * 1;
		}
		else if (m_track->getTrackDirection() == Direction::WEST)
		{
			m_curPosition -= m_curSpeed * 1;
		}
	}
};

class Motorcycle :public Vehicle
{
public:
	Motorcycle(string licenseNumber) :Vehicle(licenseNumber)
	{
		m_maxSpeed = 8.0;
		m_type = "M";
	}
	void accelerate() override
	{
		if (m_curSpeed < m_maxSpeed)
			m_curSpeed += 2;

		if (m_curSpeed > m_maxSpeed)
			m_curSpeed = m_maxSpeed;
	}

	void decelerate() override
	{
		if (m_curSpeed > 0)
			m_curSpeed -= 2;

		if (m_curSpeed < 0)
			m_curSpeed = 0;
	}

	void calculateCurrPosition() override
	{
		if (m_track->getTrackDirection() == Direction::EAST)
		{
			m_curPosition += m_curSpeed * 1;
		}
		else if (m_track->getTrackDirection() == Direction::WEST)
		{
			m_curPosition -= m_curSpeed * 1;
		}
	}
};




class Highway
{
public:
	void addVehicle(Vehicle* vehicle,Track* track)
	{
		//Do not add any other vehicle other than the Motocycle in Motorcycle only track
		if (track->isMotorCyclesOnlyTrack())
		{
			if (vehicle->getType() != "M")
				return;
		}
		vehicle->setCurSpeed(3);
		if (track->getTrackDirection() == Direction::EAST)
		{
			vehicle->setCurPosition(0);
			for (Vehicle* aVehicle : vVehicles)
			{
				//Safety check whether the vehicle belongs to the same track and the distance
				if (aVehicle->getTrack() == track && aVehicle->getCurPosition() <= 3)
					return;
			}
		}
		else if (track->getTrackDirection() == Direction::WEST)
		{
			vehicle->setCurPosition(30);
			for (Vehicle* aVehicle : vVehicles)
			{
				if (aVehicle->getTrack() == track && aVehicle->getCurPosition() <= 27)
					return;
			}
		}
		vehicle->setTrack(track);
		vVehicles.push_back(vehicle);
	}

	void addTrack(Track* track)
	{
		vTracks.push_back(track);
	}

	void show()
	{
		cout << "----------------------------------------------------------------";
		for (size_t i = 0; i < vTracks.size(); i++)
		{
			cout << "\n-----------------------------------------------------------------------";
			cout << "\n";
			cout << "\n";
			for (size_t j = 0; j < vVehicles.size(); j++)
			{
				if (vVehicles[j]->getTrack() == vTracks[i] &&
					vVehicles[j]->getCurPosition() < 30)
				{
					cout << setw(vVehicles[j]->getCurPosition()) << vVehicles[j]->getType();
				}
			}
			cout << "\n";
			cout << "\n";
			cout << "\n-----------------------------------------------------------------------";
		}
		
	}

	void advanceTime()
	{
		for (Vehicle*& aVehicle : vVehicles)
		{
			aVehicle->calculateCurrPosition();
		}
	}
private:
	vector<Track*> vTracks;
	vector<Vehicle*> vVehicles;
};

int main(int argc, char** argv)
{
	Highway testHighway;

	Track t1(Direction::EAST, false);
	Track t2(Direction::EAST, true);
	Track t3(Direction::WEST, false);

	testHighway.addTrack(&t1);
	testHighway.addTrack(&t2);
	testHighway.addTrack(&t3);

	Car c1("ABC-123");
	Truck tr1("REG-ABC");
	Motorcycle m1("MC-AI00");

	testHighway.addVehicle(&c1, &t1);
	testHighway.addVehicle(&tr1, &t3);
	testHighway.addVehicle(&m1, &t2);

	m1.accelerate();
	testHighway.advanceTime();
	c1.accelerate();
	c1.accelerate();
	testHighway.advanceTime();
	testHighway.advanceTime();
	testHighway.show();
	return 0;
}


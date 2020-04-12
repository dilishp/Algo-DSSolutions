#include"pch.h"
using namespace std;

#ifndef CVEHICLE_H
#define CVEHICLE_H

#include <iostream>
#include <string>

class CVehicle
{
public:
    // constructors
    CVehicle(){}
    CVehicle(std::string make, std::string model, std::string vehicleName,
        double miles = 36000, double fuelLevel = 100,
        char fuelType = 'G') :m_make(make), m_model(model), m_vehicleName(vehicleName), m_miles(miles), m_fuelLevel(fuelLevel),
        m_fuelType(fuelType)
    {

    }

    // member functions
    std::string GetMake() const { return m_make; }
    std::string GetModel() const { return m_model; }
    std::string GetVehicleName() const { return m_vehicleName; }
    char GetFuelType() const { return m_fuelType; }
    double GetFuelLevel() const { return m_fuelLevel; }
    double GetNumMiles() const { return m_miles; }
    void SetMake(std::string make) { m_make = make; }
    void SetModel(std::string model) { m_model = model; }
    void SetVehicleName(std::string vehicleName) { m_vehicleName = vehicleName; }
    void SetFuelType(char fuelType) { m_fuelType = fuelType; }
    void SetFuelLevel(double fuelLevel) { m_fuelLevel = fuelLevel; }
    void SetNumMiles(double miles) { m_miles = miles; }
    virtual void Drive(double numMiles) = 0;
    virtual void DispVehicleInfo() const = 0;

protected:
    // protected data members
    double m_miles;

    // protected member function
    void Driving(double numMiles, double fuelRate,
        std::string methodTravel, std::string noFuelMesg);

private:
    // private data members
    string m_make;
    string m_model;
    string m_vehicleName;
    char m_fuelType; // G>as, D>iesel, S>teamPowered
    double m_fuelLevel; // percentage (0% -> EMPTY and 100% -> FULL)
};

#endif // CVEHICLE_H
#ifndef CCAR_H
#define CCAR_H

#include <iostream>
#include <string>

class CCar : public CVehicle
{
public:
    // constructors
    CCar(){}
    CCar(std::string make, std::string model, std::string vehicleName,
        char transmission = 'M', int numDoors = 2,
        double miles = 57000, double fuelLevel = 63, char fuelType = 'G') :CVehicle(make, model, vehicleName, miles, fuelLevel, fuelType)
    {
        m_numDoors = numDoors;
        m_transmission = transmission;
    }

    // member functions
    char GetTransmission() const { return m_transmission; }
    int GetNumberDoors() const { return m_numDoors; }
    void SetTransmission(char transmission) { m_transmission = transmission; }
    void SetNumDoors(int numDoors) { m_numDoors = numDoors; }

    // 2 virtual functions needed
    virtual void Drive(double distance){}
    virtual void DispVehicleInfo() const
    {
        cout << "\nCar With " << m_transmission << "  " << m_numDoors;
    }

private:
    // private data members
    char m_transmission; // A>utomatic or M>anual
    int m_numDoors;
};

#endif // CCAR_H
#ifndef CTRUCK_H
#define CTRUCK_H

#include <iostream>
#include <string>

class CTruck : public CCar
{
public:
    // constructors
    CTruck(){}
    CTruck(std::string make, std::string model, std::string vehicleName,
        char transmission = 'A', int numDoors = 4,
        double miles = 97350, double fuelLevel = 98, char fuelType = 'D',
        char cabSize = 'C', std::string bedSize = "Short",
        bool fourWD = false):CCar(make, model, vehicleName, miles, fuelLevel, fuelType)
    {
        m_cabSize = cabSize;
        m_bedSize = bedSize;
        m_fourWD = fourWD;
        m_miles = miles;
    }

    // member functions
    char GetCabSize() const { return m_cabSize; }
    std::string GetBedSize() const { return m_bedSize; }
    bool GetFourWD() const { return m_fourWD; }
    void SetCabSize(char cabSize) { m_cabSize = cabSize; }
    void SetBedSize(std::string bedSize) { m_bedSize = bedSize; }
    void SetFourWD(bool fourWD) { m_fourWD = fourWD; }

    // 2 virtual functions needed
    virtual void Drive(double distance){}
    virtual void DispVehicleInfo() const
    {
        cout << "\nTruck With "<<m_cabSize<<"  "<<m_bedSize<<"  "<<m_fourWD;
    }

private:
    // private data members
    char m_cabSize; // S>ingle Cab, Q>uad Cab, C>rew Cab
    std::string m_bedSize; // "Long" 8 feet, "Standard" 6.5 feet,
    // "Short" 5.7 feet
    bool m_fourWD; // True if four-wheel-drive, false otherwise
};

#endif // CTRUCK_H

#include "cvehicle.h"
#include "ccar.h"
#include "ctruck.h"

// function prototypes
void DisplayInfo(const CVehicle& object);

int main()
{
    CCar myCar("Chevolet" // make
        , "Camaro" // model
        , "Bumblebee" // name
        , 'A' // Automatic
        , 2 // Two doors
        , 175000 // 175,000 miles
    );
    CTruck myTruck("Ram" // make
        , "Rebel" // model
        , "Optimus Prime" // name
        , 'A' // Automatic
        , 4 // Four doors
        , 125 // 125 miles
        , 91 // 91% fuel
        , 'D' // Diesel Fuel Type
        , 'C' // Crew Cab
        , "Short" // Short Bed
        , true // Four-Wheel-Drive Enabled
    );


    cout << " Displaying Initial Settings\n";

    DisplayInfo(myCar);
    DisplayInfo(myTruck);

    cout << endl;


    cout << " Driving Vehicles\n";

    myCar.Drive(103);
    myTruck.Drive(50);
    cout << " Displaying Secondary Settings\n";

    DisplayInfo(myCar);
    DisplayInfo(myTruck);


    cout << " Driving Vehicles Again\n";
    myCar.Drive(1000);
    myTruck.Drive(1000);
    cout << " Displaying Final Settings\n";
    DisplayInfo(myCar);
    DisplayInfo(myTruck);


    return 0;

}


void DisplayInfo(const CVehicle& object)
{
    object.DispVehicleInfo();
}



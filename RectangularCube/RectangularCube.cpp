// RectangularCube.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

//RectangularCube.h
class RectangularCube
{
public:
	RectangularCube();
	~RectangularCube();
	RectangularCube(int length, int width, int height);

#pragma region Getters&Setters
	inline int getLength() const;
	inline int getWidth() const;
	inline int getHeight() const;
	inline void setLength(int l);
	inline void setWidth(int w);
	inline void setHeight(int h);
#pragma endregion

	int volume() const;
	int surfaceArea() const;
private:
	int m_length;
	int m_width;
	int m_height;
};

//RectangularCube.cpp
RectangularCube::RectangularCube():m_height(1),m_length(1),m_width(1)
{
}

RectangularCube::~RectangularCube()
{
}

RectangularCube::RectangularCube(int length, int width, int height):
	m_height(height),
	m_length(length),
	m_width(width)
{

}
inline int RectangularCube::getLength() const
{
	return m_length;
}
inline int RectangularCube::getWidth() const
{
	return m_width;
}
inline int RectangularCube::getHeight() const
{
	return m_height;
}
inline void RectangularCube::setLength(int l)
{
	m_length = l;
}
inline void RectangularCube::setWidth(int w)
{
	m_width = w;
}
inline void RectangularCube::setHeight(int h)
{
	m_height = h;
}
int RectangularCube::volume() const
{
	//Volume will be the product of all three dimensions
	return m_height * m_width * m_length;
}
int RectangularCube::surfaceArea() const
{
	//Total Surface Area will be the sum of all 6 Surface Area
	return (2 * (m_length * m_height) + 2 * (m_width * m_height) + 2 * (m_length * m_width));
}

int main()
{
	//Creation of the two instances of the Rectangular Cube
	RectangularCube cube1;
	RectangularCube cube2(2, 4, 5);

	//Displaying Volume and Surface area
	cout << "\nVolume of the first cube created using Default Parameters :" << cube1.volume();
	cout << "\nVolume of the Second cube created using Custom Parameters(L= 2,W = 4,H = 5) :" << cube2.volume();

	cout << "\nSurface Area of the first cube created using Default Parameters :" << cube1.surfaceArea();
	cout << "\nSurface Area of the Second cube created using Custom Parameters(L= 2,W = 4,H = 5) :" << cube2.surfaceArea();

	//Invoking the set function on cube1 and changing its length to 4
	cube1.setLength(4);

	//Displaying Volume and Surface area
	cout << "\nVolume of the first cube created using changed Length Parameters :" << cube1.volume();
	cout << "\nSurface Area of the first cube created using changed Length Parameters :" << cube1.surfaceArea();

	//Using the assignment operator assign an annonymous object to cube1;
	RectangularCube cube3(3, 2, 1);
	cube1 = cube3;

	//Displaying Volume and Surface area
	cout << "\nVolume of the first cube created using changed Parameters :" << cube1.volume();
	cout << "\nSurface Area of the first cube created using changed Parameters :" << cube1.surfaceArea();

	return 0;
}


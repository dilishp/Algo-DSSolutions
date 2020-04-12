#include "pch.h"
#include <iostream>
#include "PhoneEntry.h"


//PhoneEntry.cpp

std::string PhoneEntry::getName() const
{
	return m_name;
}

std::string PhoneEntry::getNumber() const
{
	return m_number;
}

void PhoneEntry::setName(std::string newName)
{
	m_name = newName;
}

void PhoneEntry::setNumber(std::string newNumber)
{
	m_number = newNumber;
}

const PhoneEntry& PhoneEntry::operator=(const PhoneEntry &rhs)
{
	m_name = rhs.m_name;
	m_number = rhs.m_number;
	return *this;
}


bool PhoneEntry::operator==(const PhoneEntry &rhs) const
{
	if ((m_name == rhs.m_name) && (m_number == rhs.m_number))
	{
		return true;
	}
	return false;
}

bool PhoneEntry::operator!=(const PhoneEntry &rhs) const
{
	if ((m_name != rhs.m_name) || (m_number != rhs.m_number))
	{
		return true;
	}
	return false;
}



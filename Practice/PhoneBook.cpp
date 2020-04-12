#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include "PhoneEntry.h"

//PhoneBook.h
class PhoneBook
{
	size_t m_entries = 0;
	PhoneEntry* phoneEntries;
	size_t m_capacity = 4;
public:
	PhoneBook() = default;
	PhoneBook(const PhoneBook& aPhoneBook);
	~PhoneBook();
	size_t getSize() const;
	void addEntry(const PhoneEntry& aPhoneEntry);
	PhoneBook& operator = (const PhoneBook& aPhoneBook);
	const PhoneEntry& operator [](const int index) const;
	const PhoneEntry& phoneEntryAt(const int index) const;
	bool operator ==(const PhoneBook& aPhoneBook) const;
	bool operator !=(const PhoneBook& aPhoneBook) const;

};

//PhoneBook.cpp
size_t PhoneBook::getSize() const
{
	return m_entries;
}

void PhoneBook::addEntry(const PhoneEntry& aPhoneEntry)
{
	size_t sizeofpe = sizeof(int) * 8;
	if (!phoneEntries)
	{
		phoneEntries = /*new PhoneEntry()*/(PhoneEntry*)malloc(sizeofpe);
	}
	else
	{
		
		phoneEntries = (PhoneEntry*)realloc(phoneEntries, sizeofpe * (m_entries +  1));

		//PhoneEntry* newPhoneEntry = new PhoneEntry[m_capacity * 2];
		//for (size_t i = 0; i < m_entries; i++)
		//{
		//	newPhoneEntry[i].setName(phoneEntries[i].getName());
		//	newPhoneEntry[i].setNumber(phoneEntries[i].getNumber());
		//}
		//delete[] phoneEntries;
		//phoneEntries = newPhoneEntry;
		//m_capacity *= 2;
	}
	
	(phoneEntries + m_entries)->setName(aPhoneEntry.getName());
	(phoneEntries + m_entries)->setNumber(aPhoneEntry.getNumber());
	m_entries++;
}

PhoneBook::PhoneBook(const PhoneBook& aPhoneBook)
{
	m_entries = aPhoneBook.m_entries;
	phoneEntries = new PhoneEntry[aPhoneBook.m_entries];
}
PhoneBook::~PhoneBook()
{
	if (phoneEntries)
	{
		delete[] phoneEntries;
		phoneEntries = nullptr;
	}
	m_entries = 0;
}

PhoneBook& PhoneBook::operator = (const PhoneBook& aPhoneBook)
{
	//If phone Entries are already allocated memeory then delete teh allocated memeory and reallocate them
	if(this==&aPhoneBook)
		return *this;
	if (phoneEntries)
	{
		delete[] phoneEntries;				
		phoneEntries = nullptr;
	}
	phoneEntries = new PhoneEntry[aPhoneBook.m_entries];
	for (size_t i = 0; i < aPhoneBook.m_entries; i++)
	{
		//filling the values
		phoneEntries[i].setName(aPhoneBook.phoneEntries[i].getName());
		phoneEntries[i].setNumber(aPhoneBook.phoneEntries[i].getNumber());
	}
	m_entries = aPhoneBook.m_entries;
	return *this;
}

const PhoneEntry& PhoneBook::operator [](const int index) const
{
	if (index < m_entries)
	{
		return phoneEntries[index];
	}
}
const PhoneEntry& PhoneBook::phoneEntryAt(const int index) const
{
	return operator[](index);
}

bool PhoneBook::operator ==(const PhoneBook& aPhoneBook) const
{
	//check the element vise equality
	if (m_entries == aPhoneBook.m_entries)
	{
		for (size_t i = 0; i < aPhoneBook.m_entries; i++)
		{
			if ((phoneEntries[i].getName() != aPhoneBook.phoneEntries[i].getName()) ||
				(phoneEntries[i].getNumber() != aPhoneBook.phoneEntries[i].getNumber()))
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
	
}
bool PhoneBook::operator !=(const PhoneBook& aPhoneBook) const
{
	if (m_entries == aPhoneBook.m_entries)
	{
		for (size_t i = 0; i < aPhoneBook.m_entries; i++)
		{
			if ((phoneEntries[i].getName() != aPhoneBook.phoneEntries[i].getName()) ||
				(phoneEntries[i].getNumber() != aPhoneBook.phoneEntries[i].getNumber()))
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		return true;
	}
}


struct A
{
	int a = 6;
	A()
	{
		a = 7;
	}
};

class B
{
public:
	A obj;
	static void print()
	{
		std::cout << "hello";
	}
};
void main()
{
	B obj;
	B::print();
	obj.print();
	std::cout << B().obj.a;
	/*PhoneBook aPhoneBook;
	PhoneEntry aPhoneEntry1,aPhoneEntry2,aPhoneEntry3,aphoneEntry4,pe5,pe6;
	aPhoneEntry1.setName("myName1");
	aPhoneEntry1.setNumber("myNum1");
	aPhoneEntry2.setName("myName2");
	aPhoneEntry2.setNumber("myNum2");
	aPhoneEntry3.setName("myName3");
	aPhoneEntry3.setNumber("myNum3");
	aphoneEntry4.setName("myName4");
	aphoneEntry4.setNumber("myNum4");
	pe5.setName("myName5");
	pe5.setNumber("myNum5");
	pe6.setName("myName6");
	pe6.setNumber("myNum6");
	aPhoneBook.addEntry(aPhoneEntry1);
	aPhoneBook.addEntry(aPhoneEntry2);
	aPhoneBook.addEntry(aPhoneEntry3);
	aPhoneBook.addEntry(aphoneEntry4);
	aPhoneBook.addEntry(pe5);
	aPhoneBook.addEntry(pe6);

	for (size_t i = 0; i < aPhoneBook.getSize(); i++)
	{
		std::cout << aPhoneBook[i].getName() <<"  "<< aPhoneBook.phoneEntryAt(i).getNumber()<<std::endl;
	}*/
}


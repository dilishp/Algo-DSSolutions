#include "pch.h"
#include<iostream>

using namespace std;

// Some compilers require that we prototype the << and >> operator functions
// outside the class. For this reason, we have added the following 3 lines to the
// MyString.h class specificaiton file.
class MyString; // Forward Declaration
ostream& operator <<(ostream&, const MyString&);
istream& operator >>(istream&, MyString&);

class MyString
{
public:
	// CONSTRUCTORS and DESTRUCTOR
	MyString(const char str[] = "");
	MyString(const MyString& source); // This is the copy constructor
	~MyString();

	// CONSTANT MEMBER FUNCTIONS
	size_t getLength() const;
	char& operator[](size_t position) const;

	// MODIFICATION MEMBER FUNCTIONS
	void reserve(size_t n);
	const MyString& operator =(const MyString& source);
	void operator +=(const MyString& addend);
	void operator +=(const char addend[]);
	void operator +=(char addend);
	//MyString operator +(const MyString& addend2)
	//{
	//	return MyString();
	//}

	// FRIEND FUNCTIONS
	friend MyString operator +(const MyString& addend1, const MyString& addend2);
	friend bool operator ==(const MyString& s1, const MyString& s2);
	friend bool operator !=(const MyString& s1, const MyString& s2);
	friend bool operator >=(const MyString& s1, const MyString& s2);
	friend bool operator <=(const MyString& s1, const MyString& s2);
	friend bool operator > (const MyString& s1, const MyString& s2);
	friend bool operator < (const MyString& s1, const MyString& s2);
	friend ostream& operator <<(ostream& outs, const MyString& source);
	friend istream& operator >>(istream& ins, MyString& target);
	friend istream& getline(istream& ins, MyString& target);

private:
	char *sequence;
	size_t allocated; // size_t is defined as an unsigned int type. Using size_t
		// rather than unsigned int for string length leads to
		// better portability of the code.
};

MyString::~MyString()
{
	if (sequence)
	{
		delete[] sequence;
		sequence = nullptr;
	}
}
MyString::MyString(const char str[])
{
	int index = 0;
	while (str[index] != '\0')
	{
		index++;
	}

	if (!sequence)
	{
		sequence = new char[index + 1];
	}
	strcpy_s(sequence, index + 1, str);
	allocated = index + 1;
}

MyString::MyString(const MyString& source)
{
	this->allocated = source.allocated;
	
	sequence = new char[this->allocated];
	strcpy_s(sequence, this->allocated, source.sequence);
}

size_t MyString::getLength() const
{
	return this->allocated - 1;
}

char& MyString::operator[](size_t position) const
{
	if(position < allocated)
		return this->sequence[position];
}

void MyString::reserve(size_t n)
{
	sequence = (char*)realloc(sequence, n);
}

const MyString& MyString::operator =(const MyString& source)
{
	this->allocated = source.allocated;
	if (sequence)
	{
		delete[] sequence;
		sequence = nullptr;
	}
	sequence = new char[source.allocated];
	strcpy_s(sequence, this->allocated, source.sequence);
	return *this;
}
void MyString::operator +=(const MyString& addend)
{
	this->sequence = (char*)realloc(this->sequence, (this->allocated + addend.allocated + 1));
	size_t i = 0;
	for (; i < addend.allocated; i++)
	{
		this->sequence[this->allocated + i - 1] = addend.sequence[i];
	}
	this->sequence[this->allocated + i] = '\0';
	this->allocated += addend.allocated;
}
void MyString::operator +=(const char addend[])
{
	int index = 0;
	while (addend[index] != '\0')
	{
		index++;
	}

	this->sequence = (char*)realloc(this->sequence, this->allocated + index + 2);
	size_t i = 0;
	for (; i < (index + 1); i++)
	{
		this->sequence[this->allocated + i - 1] = addend[i];
	}
	this->sequence[this->allocated + i] = '\0';
	this->allocated += (index + 1);

}
void MyString::operator +=(char addend)
{
	this->sequence = (char*)realloc(this->sequence, this->allocated + 2);
	this->sequence[this->allocated - 1] = addend;
	this->sequence[this->allocated] = '\0';
}

MyString operator +(const MyString& addend1, const MyString& addend2)
{
	MyString aString;

	aString.sequence = new char[addend1.allocated + addend2.allocated];
	aString.allocated = addend1.allocated + addend2.allocated;

	int index = 0;

	while (addend1.sequence[index] != '\0')
	{
		aString.sequence[index] = addend1[index];
		index++;
	}

	int count = 0;

	while (addend2.sequence[count] != '\0')
	{
		aString.sequence[index] = addend2[count];
		index++;
		count++;
	}

	aString.sequence[index] = '\0';
	return aString;
}

bool operator ==(const MyString& s1, const MyString& s2)
{
	if ((strcmp(s1.sequence, s2.sequence) == 0) && (s1.allocated == s2.allocated))
	{
		return true;
	}
	return false;
}

bool operator !=(const MyString& s1, const MyString& s2)
{
	if ((strcmp(s1.sequence, s2.sequence) != 0) || (s1.allocated != s2.allocated))
	{
		return true;
	}
	return false;
}

bool operator >=(const MyString& s1, const MyString& s2)
{
	if ((strcmp(s1.sequence, s2.sequence) >= 0))
	{
		return true;
	}
	return false;
}

bool operator <=(const MyString& s1, const MyString& s2)
{
	if ((strcmp(s1.sequence, s2.sequence) <= 0))
	{
		return true;
	}
	return false;
}

bool operator > (const MyString& s1, const MyString& s2)
{
	if ((strcmp(s1.sequence, s2.sequence) > 0))
	{
		return true;
	}
	return false;
}

bool operator < (const MyString& s1, const MyString& s2)
{
	if ((strcmp(s1.sequence, s2.sequence) < 0))
	{
		return true;
	}
	return false;
}

ostream& operator <<(ostream& outs, const MyString& source)
{
	outs << source.sequence;
	return outs;
}

istream& operator >>(istream& ins, MyString& target)
{
	char tempString[20];
	gets_s(tempString, 20);
	target.sequence = (char*)realloc(target.sequence, strlen(tempString) + 1);
	strcpy_s(target.sequence, strlen(tempString) + 1, tempString);
	target.allocated = strlen(tempString) + 1;
	return ins;
}

istream& getline(istream& ins, MyString& target)
{
	ins.getline(target.sequence, target.allocated);
	return ins;
}

void main()
{
	MyString aString1,aString2;
	cout << "Enter a String" << endl;
	cin >> aString1;
	cout << "Enter another String" << endl;
	cin >> aString2;
	aString1 += aString2;
	MyString STRING = aString1 + aString2;
	operator +(aString1, aString2);
	cout << "Appended String is " << aString1 << endl;
}
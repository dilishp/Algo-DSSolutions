#include "pch.h"
#include <iostream>
using namespace std;

template<typename T>
class MyComplex {
public:
	MyComplex();
	MyComplex(T);
	MyComplex(T, T);

	T Re();
	T Im();

	void setRe(T);
	void setIm(T);

	MyComplex operator+ (MyComplex) const;
	friend MyComplex operator+ (T, MyComplex);

	MyComplex operator- (MyComplex) const;
	MyComplex operator- (T) const;
	friend MyComplex operator- (T, MyComplex);

	MyComplex operator* (MyComplex) const;
	friend MyComplex operator* (T, MyComplex);

	MyComplex operator/ (T) const;
	MyComplex operator/ (MyComplex) const;

	MyComplex& conjugate();

	template<typename T>
	friend ostream& operator <<(ostream& dout, const MyComplex<T>& c);
	template<typename T>
	friend istream& operator >>(istream& din, MyComplex<T>& c);

private:
	T real, imag;
};

template<typename T>
T MyComplex<T>::Re() {
	return real;
}
template<typename T>
T MyComplex<T>::Im() {
	return imag;
}
template<typename T>
void MyComplex<T>::setRe(T r) {
	real = r;
}
template<typename T>
void MyComplex<T>::setIm(T i) {
	imag = i;
}
template<typename T>
MyComplex<T>::MyComplex<T>() {
	this->real = 0.0;
	this->imag = 0.0;
}
template<typename T>
MyComplex<T>::MyComplex<T>(T r) {
	this->real = r;
	this->imag = 0;
}
template<typename T>
MyComplex<T>::MyComplex<T>(T r, T i) {
	this->real = r;
	this->imag = i;
}
template<typename T>
MyComplex<T> MyComplex<T>::operator+ (MyComplex<T> c2) const {
	return MyComplex<T>(this->real + c2.real, this->imag + c2.imag);
}
template<typename T>
MyComplex<T> operator+ (T lhs, MyComplex<T> rhs) {
	return MyComplex<T>(rhs.real + lhs, rhs.imag);
}
template<typename T>
MyComplex<T> MyComplex<T>::operator- (MyComplex<T> c2) const {
	return MyComplex<T>(this->real - c2.real, this->imag - c2.imag);
}
template<typename T>
MyComplex<T> MyComplex<T>::operator- (T d) const {
	return MyComplex<T>(this->real - d, this->imag);
}
template<typename T>
MyComplex<T> operator- (double lhs, MyComplex<T> rhs) {
	return MyComplex<T>(lhs - rhs.real, -(rhs.imag));
}
template<typename T>
MyComplex<T> MyComplex<T>::operator* (MyComplex<T> c2) const {
	return MyComplex<T>(this->real * c2.real - this->imag * c2.imag, this->imag * c2.real + this->real * c2.imag);
}
template<typename T>
MyComplex<T> operator* (double lhs, MyComplex<T> rhs) {
	return MyComplex<T>(rhs.real * lhs, rhs.imag * lhs);
}
template<typename T>
MyComplex<T> MyComplex<T>::operator/ (T d) const {
	return MyComplex<T>(this->real / d, this->imag / d);
}
template<typename T>
MyComplex<T> MyComplex<T>::operator/ (MyComplex<T> c2) const {
	double d = c2.real * c2.real + c2.imag * c2.imag;
	return MyComplex<T>((this->real * c2.real + this->imag * c2.imag) / d, (this->imag * c2.real - this->real * c2.imag) / d);
}
template<typename T>
MyComplex<T>& MyComplex<T>::conjugate() {
	this->imag = -(this->imag);
	return *this;
}

template<typename T>
ostream& operator <<(ostream& dout, const MyComplex<T>& c) 
{
	// case if real = 0
	if (c.real == 0 && c.imag != 0) {
		dout << c.imag << "i";
	}

	// case if imag = 0 and real = 0
	if (c.real == 0 && c.imag == 0) {
		dout << 0;
	}

	// case if imag = 0
	if (c.imag == 0 && c.real != 0) {
		dout << c.real;
	}

	// case if real != 0 & imag != 0
	if (c.imag != 0 && c.real != 0) {
		if (c.imag < 0)
			dout << c.real << " - " << (-c.imag) << "i";
		else
			dout << c.real << " + " << c.imag << "i";
	}

	return dout;
}

template<typename T>
istream& operator >>(istream& din, MyComplex<T>& c) {
	char str[80];
	char* pEnd;
	char* pEnd2;
	cout << "Enter a real, imaginary or complex number: ";
	din.getline(str, 80);

	double d1, d2;

	int& aValue = 2;

	d1 = strtod(str, &pEnd);
	d2 = strtod(pEnd, &pEnd2);

	if (*pEnd != 'i') {
		c.real = d1;
		if (*pEnd2 == 'i')
			c.imag = d2;
	}
	if (*pEnd == 'i')
		c.imag = d1;
}

int main(int argc, char *argv[])
{
	MyComplex<double> c1(5, 3);
	cout << c1 << endl;
	return 0;
}
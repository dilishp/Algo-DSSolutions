#include "pch.h"
#include <iostream>

using namespace std;

template<typename T>
class Mvector
{
public:
	Mvector();
	void operator ^(int i);
private:
	int vsize;
	int vcap;
	T* v;
};

template<typename T>
Mvector<T>::Mvector()
{

}

template<typename T>
void Mvector<T>::operator^(int i)
{
	for (int i = 0;i < vsize;++i)
	{
		for (int j = 0; j < vsize - i; j++)
		{
			if (v[j] > v[j + 1])
			{
				T temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}
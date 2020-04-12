#include "pch.h"
#include <iostream>
#include <vector>

template <typename T>
std::vector<std::vector<std::vector<T>>> add_3d
(const std::vector<std::vector<std::vector<T>>>& vec3d1,
 const std::vector<std::vector<std::vector<T>>>& vec3d2)
{
	std::vector<std::vector<std::vector<T>>> out3dvec;
	auto itr1 = vec3d1.begin();
	auto itr2 = vec3d2.begin();
	for (;itr1 != vec3d1.end(), itr2 != vec3d2.end();itr1++, itr2++)
	{
		std::vector<std::vector<T>> vecdim1;
		auto itr11 = (*itr1).begin();
		auto itr21 = (*itr2).begin();
		for (;itr11 != itr1->end(), itr21 != itr2->end();
			itr11++,itr21++)
		{
			std::vector<T> vecdim2;
			auto itr12 = itr11->begin();
			auto itr22 = itr21->begin();
			for (;itr12 != itr11->end(), itr22 != itr21->end();
				itr12++, itr22++)
			{
				vecdim2.push_back(*itr12 + *itr22);
			}
			vecdim1.push_back(vecdim2);
		}
		out3dvec.push_back(vecdim1);
	}

	return out3dvec;
}

void main()
{
	std::vector<std::vector<std::vector<int>>> v = 
	{
		{
			{
				1,
				2,
				3,
				4,
				5,
				6,
				7,
				8
			}
		}
	};
	auto rs = add_3d<int>(v, v);

	for (auto v : rs)
	{
		for (auto v1 : v)
		{
			for (auto num : v1)
			{
				std::cout << num<<"\n";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}
}
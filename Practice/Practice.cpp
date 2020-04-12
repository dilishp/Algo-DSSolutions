#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>

std::string editDistance(std::string s1, std::string s2)
{
	static std::string res = "";
	static int total = 0;
	if (s2.length() == 0)
	{
		return res;
	}
	std::cout << "Right" << std::setw(50) << res + s1 << std::setw(8) << 0 << std::setw(8) << total << std::endl;
	if (s1[0] != s2[0])
	{
		s1[0] = s2[0];
		total += 4;
		std::cout <<  "Replace by "<<s2[0] << std::setw(40) << res + s1 << std::setw(8) << 4 << std::setw(8) << total<<	std::endl;
	}
	res.push_back(s1[0]);

	return editDistance(s1.substr(1, s1.length()), s2.substr(1, s2.length()));
}

int main()
{
	std::string eleeng = "electrical engineering";
	std::string cseng = "computer science";
	std::cout << "Operation" << std::setw(40) << "z" << std::setw(8) << "Cost" << std::setw(8) << "Total"<<std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Initial String" << std::setw(40) << eleeng << std::setw(8) << 0 << std::setw(8) << 0<<std::endl;
	std::cout << "delete" << std::setw(40) << editDistance(eleeng,cseng) << std::setw(8) << 0 << std::setw(8) << 0 << std::endl;
}
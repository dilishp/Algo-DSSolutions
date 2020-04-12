#include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <fstream>
#include <memory>


//class DataRepository
//{
//public:
//	bool findWord(const std::string& word,const int& nOccurence);
//	void populateData(const std::string& filename);
//private:
//	std::map<std::string,int> mapOfString;
//};
//
//class CommandExecutor
//{
//public:
//	CommandExecutor();
//	std::string execute(std::string);
//private:
//	DataRepository m_reposObj;
//};
//
//CommandExecutor::CommandExecutor()
//{
//
//}
//
//bool DataRepository::findWord(const std::string& word,const int& occurence)
//{
//	const auto& itr = mapOfString.find(word);
//
//	if (itr != mapOfString.end())
//	{
//		if (itr->second >= occurence)
//		{
//			return true;
//		}
//	}
//
//	return false;
//}
//
//void DataRepository::populateData(const std::string& filename)
//{
//	std::ifstream fileReader(filename);
//
//	if (!fileReader)
//	{
//		std::cout << "Unable to open the file";
//		return;
//	}
//
//	while (!fileReader.eof())
//	{
//		std::string word;
//		fileReader >> word;
//		mapOfString[word]++;
//	}
//}
//
//std::string CommandExecutor::execute(std::string command)
//{
//	if (command == "load")
//	{
//		std::string filename("newbooks.txt");
//
//		m_reposObj.populateData(filename);
//	}
//	else if (command == "find")
//	{
//		std::cout << "Enter the word and which occurence" << std::endl;
//
//		std::string word;int occurence;
//
//		std::cin >> word >> occurence;
//
//		std::cout << "Word found : " << std::boolalpha << m_reposObj.findWord(word, occurence) << std::endl;
//	}
//	return "";
//}

int main()
{
	enum class Color
	{
		RED = 2,
		GREEN,
		BROWN = 7,
		ORANGE
	};

	Color clr = Color::GREEN;

	switch (clr)
	{
	default:
		break;
	case Color::GREEN:
		std::cout << "green";
		break;
	case Color::BROWN:
		std::cout << "brown";
		break;
	case Color::ORANGE:
		std::cout << "orange";
		break;
	case Color::RED:
		std::cout << "red";
		break;

	}

	std::shared_ptr<Color[]> colors(new Color[10]);

	const std::string& n = "Hello";
	return 0;
}
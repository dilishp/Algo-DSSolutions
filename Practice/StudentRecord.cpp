#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

struct StudentInfo
{
	string m_name;
	int m_grade;

	StudentInfo(string name, int grade):m_name(name),m_grade(grade)
	{

	}
};

void main()
{
	vector<StudentInfo> vStudentInfo;
	while (true)
	{
		string sName;
		int grade;

		cout << "\nPlease Enter Student Name";
		std::getline(cin, sName);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (sName == "Done")
		{
			break;
		}

		try 
		{
			cout << "\nEnter grade";
			cin >> grade;

			if (grade < 0)
			{
				throw exception("Id is Negative");
			}
		}
		catch (exception ex)
		{
			cout << "\nPlease Re-enter id";
			cin >> grade;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		StudentInfo aStudent(sName, grade);

		vStudentInfo.push_back(aStudent);
		
	}

	sort(vStudentInfo.begin(), vStudentInfo.end(), [](const StudentInfo& aStudent1, const StudentInfo& aStudent2) {
		return aStudent1.m_name < aStudent2.m_name;
	});

	auto result = minmax_element(begin(vStudentInfo), end(vStudentInfo), [](const StudentInfo& aStudent1,const StudentInfo& aStudent2)->bool {
		return aStudent1.m_grade < aStudent2.m_grade;
	});

	vector<int> vGrades;

	transform(vStudentInfo.begin(), vStudentInfo.end(), back_inserter(vGrades), [](StudentInfo& aStudent)->int {
		return aStudent.m_grade;
	});

	int sumresult = accumulate(vGrades.begin(), vGrades.end(), 0, [](int grade1,int grade2)->int {
		return (grade1 + grade2);
	});
	
	
	double classavg = (double)sumresult / vStudentInfo.size();

	double classmedian = 0.0;

	if ((vStudentInfo.size() % 2) == 0)
	{
		classmedian = (vStudentInfo[(vStudentInfo.size() / 2) - 1].m_grade + vStudentInfo[vStudentInfo.size() / 2].m_grade) / 2;
	}
	else
	{
		classmedian = vStudentInfo[vStudentInfo.size() / 2].m_grade;
	}

	cout << "Roll No     " << "  Grade" << "\n";
	int count = 1;
	for (StudentInfo& aStudent : vStudentInfo)
	{
		char grade = (aStudent.m_grade > 70) ? 'P' : 'F';
		cout << count << "          " << grade;
		count++;
		cout << "\n\n";
	}

	cout << "\n\nClass Stats \n\n";

	cout << "\nClass Max Grade : " << result.second->m_grade << " Name : " << result.second->m_name;

	cout << "\nClass Min Grade : " << result.first->m_grade << " Name : " << result.first->m_name;

	cout << "\nClass Avg : " << classavg;

	cout << "\n Class Median : " << classmedian;

}

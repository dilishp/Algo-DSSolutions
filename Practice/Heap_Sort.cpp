#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Student
{
	string m_lastName;
	string m_firstName;
	long m_id;
	double m_grade;
	char m_letterGrade;

	static int nSortSelector;

	Student(string lastName, string firstName, long id, double grade, char letterGrade):
		m_lastName(lastName)
		,m_firstName(firstName)
		,m_id(id)
		,m_grade(grade)
		,m_letterGrade(letterGrade)
	{

	}

	bool operator < (const Student& aStudent)
	{
		bool bComparisonResult;
		switch (nSortSelector)
		{
		case 0:
			bComparisonResult = (this->m_firstName < aStudent.m_firstName);
			break;
		case 1:
			bComparisonResult = (this->m_lastName < aStudent.m_lastName);
			break;
		case 2:
			bComparisonResult = (this->m_id < aStudent.m_id);
			break;
		case 3:
			bComparisonResult = (this->m_grade < aStudent.m_grade);
			break;
		case 4:
			bComparisonResult =  (this->m_letterGrade < aStudent.m_letterGrade);
			break;
		default:
			break;
		}
		return bComparisonResult;
	}

	bool operator > (const Student& aStudent)
	{
		bool bComparisonResult;
		switch (nSortSelector)
		{
		case 0:
			bComparisonResult = (this->m_firstName > aStudent.m_firstName);
			break;
		case 1:
			bComparisonResult = (this->m_lastName > aStudent.m_lastName);
			break;
		case 2:
			bComparisonResult = (this->m_id > aStudent.m_id);
			break;
		case 3:
			bComparisonResult = (this->m_grade > aStudent.m_grade);
			break;
		case 4:
			bComparisonResult = (this->m_letterGrade > aStudent.m_letterGrade);
			break;
		default:
			break;
		}
		return bComparisonResult;
	}

	friend ostream& operator << (ostream& out, const Student& aStudent)
	{
		out << aStudent.m_lastName << "  " << aStudent.m_firstName << "  " << aStudent.m_id << " "
			<< aStudent.m_grade << "  " << aStudent.m_letterGrade << endl;
		return out;
	}
};

int Student::nSortSelector = 0;

void heapify(vector<Student>& vStudents,int nSize,int nIndex, bool& bAscending)
{
	int largest = nIndex;
	int left = 2 * nIndex + 1;
	int right = 2 * nIndex + 2;


	if ((right < nSize) && (left < nSize))
	{
		bool bleftDecision = (bAscending) ? (vStudents[left] > vStudents[largest]) :
			(vStudents[left] < vStudents[largest]);
		if (bleftDecision)
		{
			largest = left;
		}
		bool brightDecision = (bAscending) ? (vStudents[right] > vStudents[largest]) :
			(vStudents[right] < vStudents[largest]);
		if (brightDecision)
		{
			largest = right;
		}

	}

	
	if (largest != nIndex)
	{
		swap(vStudents[largest], vStudents[nIndex]);

		heapify(vStudents, nSize, largest, bAscending);
	}
}

void heap_sort(vector<Student>& vStudents, bool& bAscending)
{
	//build heap(Max/Min) depending on the choice
	for (int i = (vStudents.size() / 2) - 1; i >= 0; i--)
	{
		heapify(vStudents,vStudents.size(), i, bAscending);
	}

	for (int i = vStudents.size() - 1; i >= 0; i--)
	{
		swap(vStudents[0], vStudents[i]);
		
		heapify(vStudents,i,0, bAscending);
	}
		
}


void main()
{
	ifstream infile;
	infile.open("input.txt", ios::binary);
	if (!infile.is_open())
		return;

	vector<Student> vStudents;
	string input;

	while (std::getline(infile,input))
	{
		stringstream buffer(input);

		string lastName;
		string firstName;
		long id;
		double grade;
		char letterGrade;

		while (buffer >> lastName >> firstName >> id >> grade >> letterGrade);
		
		Student aStudent(lastName, firstName, id, grade, letterGrade);

		vStudents.push_back(aStudent);
	}

	cout << R"(Enter the parameter which should be used to sort 
				0 - FirstName
				1 - LastName
				2 - Id
				3 - grade
			    4 - lettergrade)"<<endl;

	int option;
	cin >> Student::nSortSelector;

	cout << R"(  Sort Order
				0 - Ascending
				1 - Descending
			 )";
	int nSortOption;
	cin >> nSortOption;

	bool bAscending = (nSortOption == 0) ? true:false;

	heap_sort(vStudents,bAscending);
	
	for (Student aStudent : vStudents)
	{
		cout << aStudent;
	}

}
#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct Candidate {
	string Fname;
	string Lname;
	int votes;
	double Score = 0;
};

const int MAX_SIZE = 100;

void readFile(Candidate[]);

void displayList(Candidate[]);

void sortByVotes(Candidate[]);

void displayCandidate(Candidate);

Candidate getWinner(Candidate[]);

Candidate getLast(Candidate[]);

void calculateScores(Candidate[]);

int candidateCnt = 0;

int main() {
	Candidate candidates[MAX_SIZE];
	readFile(candidates);
	displayList(candidates);
	sortByVotes(candidates);
	calculateScores(candidates);
	cout << endl;
	cout << "Winner : \n";
	displayCandidate(getWinner(candidates));
	cout << endl;
	cout << "Lowest Score : \n";
	displayCandidate(getLast(candidates));
	return 0;
}

void readFile(Candidate candidates[]) {

	string line;

	ifstream infile;

	infile.open("elections.txt");


	while (!infile.eof()) {

		getline(infile, line);

		bool bExcludeLine = false;  //flag to exclude the line
		int findResult = 0;
		findResult = line.find('=', findResult); //getting the first =
		int loopCount = 0; //To determine which word
		Candidate aCadidate;
		//The idea here is that findResult will point to the = in the string 
		//Inside the while loop there is another find to get the next = in the string
		//Get the substring between those two =
		//Check for the , delimitor in that substring
		//If , is not present then set the bExcludeLine = true and break
		//If , is present then find out the substring Fname,Lname etc.
		//Add to the Candidate array only if the bExcludeLine = false
		while (findResult != string::npos)
		{
			int offset = 0;
			offset = line.find('=', (findResult + 1));
			bool bIsLastWord = false;
			if (offset == string::npos)
			{
				offset = line.length();
				bIsLastWord = true;
			}
			int commapos = 0;
			string aString = line.substr((findResult + 1), (offset - findResult));
			if (!bIsLastWord && (commapos = aString.find(',')) == string::npos)
			{
				bExcludeLine = true;
				break;
			}
			if (bIsLastWord)
			{
				int votes = atoi(aString.c_str());
				aCadidate.votes = votes;
				break;
			}
			if (0 == loopCount) //To determine which is the string
			{
				aCadidate.Fname = aString.substr(0, commapos);
			}
			else if (1 == loopCount)
			{
				aCadidate.Lname = aString.substr(0, commapos);
			}
			findResult = offset;
			++loopCount;
		}

		if(!bExcludeLine)
			candidates[candidateCnt++] = aCadidate;

	}

	infile.close();

}

void displayList(Candidate candidates[]) {
	cout << std::setw(15) << "First:" <<
		std::setw(15) << "Last:" <<
		std::setw(15) << "Votes:" <<
		std::setw(15) << "%Score:\n";
	for (int i = 0; i < candidateCnt; i++)
	{
		cout << std::setw(15) << candidates[i].Fname <<
			std::setw(15) << candidates[i].Lname <<
			std::setw(15) << candidates[i].votes <<
			std::setw(15) << candidates[i].Score;
		cout << endl;
	}
}

void sortByVotes(Candidate candidates[]) {
	//Used Bubble Sort
	for (int i = 0; i < candidateCnt; i++)
	{
		for (int j = 0; j < candidateCnt - i - 1; j++)
		{
			if (candidates[j].votes > candidates[j + 1].votes)
			{
				Candidate tempCandidate = candidates[j];
				candidates[j] = candidates[j + 1];
				candidates[j + 1] = tempCandidate;
			}
		}
	}
}

void displayCandidate(Candidate candidates) {
	cout << "\nFIRST NAME:" << candidates.Fname <<
		"\nLAST NAME:" << candidates.Lname <<
		"\nVOTES:" << candidates.votes <<
		"\n% GAINED:" << candidates.Score << endl;
	cout << endl;
}

Candidate getWinner(Candidate candidates[]) {
	int maxScoreIndex = 0;
	double maxScore = candidates[0].Score;
	for (int i = 0; i < candidateCnt; i++)
	{
		if (candidates[i].Score > maxScore)
		{
			maxScore = candidates[i].Score;
			maxScoreIndex = i;
		}
	}
	return candidates[maxScoreIndex];
}

Candidate getLast(Candidate candidates[]) {
	int minScoreIndex = 0;
	double minScore = candidates[0].Score;
	for (int i = 0; i < candidateCnt; i++)
	{
		if (candidates[i].Score < minScore)
		{
			minScore = candidates[i].Score;
			minScoreIndex = i;
		}
	}
	return candidates[minScoreIndex];
}

void calculateScores(Candidate candidates[]) {
	double sumofVotes = 0.00;
	for (int i = 0; i < candidateCnt; i++)
	{
		sumofVotes += candidates[i].votes;
	}

	for (int i = 0; i < candidateCnt; i++)
	{
		candidates[i].Score = (candidates[i].votes / sumofVotes) * 100;
	}
}

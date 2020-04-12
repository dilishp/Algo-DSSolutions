#include "pch.h"
#include <iostream>
#include "question.h"

using namespace std;

Question::Question()
{
}

void Question::add_line(string line)
{
	text += line + "\n";
}

void Question::set_answer(string correct_response)
{
	answer = correct_response;
}

bool Question::check_answer(string response) const
{
	return (answer == response);
}

void Question::display() const
{
	cout << text << endl;
}
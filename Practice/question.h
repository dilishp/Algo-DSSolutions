#ifndef QUESTION_H
#define QUESTION_H 
#include <string> 
using namespace std;

class Question
{
public:
	/** Constructs a question with empty question and answer. */
	Question();
	/** @param line the line of text to add to this question */
	void add_line(string line);
	/** @param correct_response the answer for this question */
	void set_answer(string correct_response);
	/** @param response the response to check
	 *@return true if the response was correct, false otherwise */
	virtual bool check_answer(string response) const;
	/** Displays this question. */
	virtual void display() const;
private:
	string text;
	string answer;
};


#endif 

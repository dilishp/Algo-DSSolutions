#ifndef CHOICEQUESTION_H 
#define CHOICEQUESTION_H 

#include "question.h" 

class ChoiceQuestion : public Question
{
public:
	/** Constructs a choice question with a given text and no choices.
	 *@param question_text the text of this question */
	ChoiceQuestion(string question_text);
	/** Adds an answer choice to this question.
	 *@param choice the choice to add
	 *@param correct true if this is the correct choice, false otherwise */
	void add_choice(string choice, bool correct);
private:
	int num_choices;
};


#endif


#include "pch.h"
#include "choicequestion.h"

ChoiceQuestion::ChoiceQuestion(string question_text)
{
	num_choices = 0;
	add_line(question_text);
}

void ChoiceQuestion::add_choice(string choice, bool correct)
{
	if (correct)
		set_answer(choice);
	add_line(choice);
	num_choices++;
}
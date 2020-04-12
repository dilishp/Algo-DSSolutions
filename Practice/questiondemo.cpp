#include  "pch.h"
#include <iostream> 
#include <sstream> 
#include "choicequestion.h" 

using namespace std; 

int main()
{ 
	string response; 
	cout << boolalpha; 
	// Make a quiz with two questions 
	const int QUIZZES = 2; 
	Question* quiz[QUIZZES]; 
	quiz[0] = new Question; 
	quiz[0]->add_line("Who was the inventor of C++?"); 
	quiz[0]->set_answer("Bjarne Stroustrup"); 
	ChoiceQuestion* cq_pointer = new ChoiceQuestion( "In which country was the inventor of C++ born?"); 
	cq_pointer->add_choice("Australia", false);
	cq_pointer->add_choice("Denmark", true); 
	cq_pointer->add_choice("Korea", false); 
	cq_pointer->add_choice("United States", false); 
	quiz[1] = cq_pointer; 
	// Check answers for all questions 
	for (int i = 0; i < QUIZZES; i++)
	{
		quiz[i]->display(); 
		cout << "Your answer: "; 
		getline(cin, response); 
		cout << response << endl; 
		cout << quiz[i]->check_answer(response) << endl;
		cout << endl;
	} 
	return 0; 
}
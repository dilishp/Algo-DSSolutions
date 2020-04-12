#ifndef TEXT_H
#define TEXT_H
#include <string.h>


class Text {
private:
	std::string line; // Only primitive datatypes are allowed in a Header file. String class objects are not allowed in Header files.
	char ch;
	int upperCasecount, lowerCaseCount, digitCount, charCount;

public:
	//Default constructor that initializes all 3 counters to 0.
	Text();

	//Function that reads the argument file and updates the upperCasecount, lowerCaseCount, and digitCount variables during each iteration of the loop
	void updateCounters(std::string fname);

	//Function that displays the values stored in all 3 counters
	void displayCounters() const;

};
#endif // !TEXT_H

#include "pch.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

template<typename T>
class Stack
{
	list<T> m_list;
public:
	void push(const T& item);
	void pop();
	T top() const;
	int getLength() const;
};

template<typename T>
void Stack<T>::push(const T& item)
{
	m_list.push_front(item);
}

template<typename T>
T Stack<T>::top() const
{
	return m_list.front();
}

template<typename T>
void Stack<T>::pop()
{
	m_list.pop_front();
}

template<typename T>
int Stack<T>::getLength() const
{
	return m_list.size();
}

bool paliandromeJudger(string inString)
{
	Stack<char> stack;

	for (char& ch : inString)
	{
		stack.push(ch);
	}

	string reversedString;

	while(stack.getLength())
	{
		reversedString += stack.top();
		stack.pop();
	}

	if (reversedString == inString)
	{
		return true;
	}

	return false;
}

int main()
{
	string instring = "malayalam";
	bool bisPal = paliandromeJudger(instring);
	if (bisPal)
		cout << instring << " is paliandrome";
	else
		cout << instring << "is not a paliandrome";
	return 0;
}
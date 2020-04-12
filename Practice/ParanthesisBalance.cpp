#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Stack
{
	vector<char> vParanThesis;

public:
	void push(char ch)
	{
		vParanThesis.push_back(ch);
	}

	char pop()
	{
		char returnChar =  vParanThesis[vParanThesis.size() - 1];
		vParanThesis.pop_back();
		return returnChar;
	}

	int size() const
	{
		return vParanThesis.size();
	}

};

void main()
{
	Stack sParanthesis;
	vector<char> vCharacters;
	cout << "Enter the expression";
	while (true)
	{
		char ch = getchar();
		if (ch == '0')
		{
			break;
		}
		vCharacters.push_back(ch);
	}
	bool bIsMatched = true;
	for (char ch : vCharacters)
	{
		if ((ch == '(') || (ch == '<') || (ch == '[') || (ch == '{'))
		{
			cout << ch << " ";
			sParanthesis.push(ch);
		}
		else if ((ch == ')') || (ch == '>') || (ch == ']') || (ch == '}'))
		{
			if (sParanthesis.size() == 0)
			{
				cout << " Too many close " << ch;
				bIsMatched = false;
			}
			char paran = sParanthesis.pop();
			switch (ch)
			{
			case ')':
				if (paran != '(')
				{
					cout << "No Close " << ')';
					cout << "\n";
					bIsMatched = false;
				}
				else
				{
					cout << ch<<" ";
				}
				break;
			case '>':
				if (paran != '<')
				{
					cout << "No Close " << '>';
					cout << "\n";
					bIsMatched = false;
				}
				else
				{
					cout << ch<<" ";
				}
				break;
			case ']':
				if (paran != '[')
				{
					cout << "No Close " << ']';
					cout << "\n";
					bIsMatched = false;
				}
				else
				{
					cout << ch<< " ";
				}
				break;
			case '}':
				if (paran != '{')
				{
					cout << "No Close " << '}';
					cout << "\n";
					bIsMatched = false;
				}
				else
				{
					cout << ch<<" ";
				}
				break;
			default:
				break;
			}
		}
		if (!bIsMatched)
		{
			break;
		}
	}

	if (bIsMatched && (sParanthesis.size() == 0))
	{
		cout << " This set is Balanced";
	}
	else
	{
		cout << " This set is not matched ";
	}
	
}
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

string Solution(string& S,string& T)
{
	if (S == T)
		return "EQUAL";

	int diff = S.length() - T.length();
	diff = abs(diff);
	if (diff > 1)
		return "IMPOSSIBLE";

	if(S.find(T) != string::npos)
	{
		int startPos = S.find(T);

		int endPos = T.length();

		return "REMOVE " + string(1,S[endPos]);
	}
	else if(S.find(T.substr(1,T.length() - 1)) != string::npos)
	{
		return "INSERT " + string(1,T[0]);
	}
	else if(S.length() == T.length())
	{
		for (int i = 0;i < S.length();++i)
		{
			if(S[i] != T[i])
			{
				if(S[i + 1] == T[i] && S[i] == T[i + 1])
				{
					string space = "  ";
					return "SWAP " + string(1,S[i]) + space + string(1,S[i + 1]);
				}
			}
		}
	}

	return "IMPOSSIBLE";
}

int main()
{
	string s1 = "gain";
	string t1 = "again";
	cout<<Solution(s1,t1)<<endl;

	string s2 = "parks";
	string t2 = "park";
	cout << Solution(s2, t2) << endl;

	string s3 = "form";
	string t3 = "from";
	cout << Solution(s3, t3) << endl;

	string s4 = "o";
	string t4 = "odd";
	cout << Solution(s4, t4) << endl;
}
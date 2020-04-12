#include "pch.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class BigNumbers
{
public:
	void setNumber(vector<int> invector)
	{
		m_bignumbers = invector;
	}	
	void setNumber(string inString)
	{
		for (char ch : inString)
		{
			int digit = atoi(&ch);
			m_bignumbers.push_back(digit);
		}
	}
	BigNumbers operator +(const BigNumbers& num)
	{
		vector<int> maxVector;
		vector<int> minVector;

		if (m_bignumbers.size() > num.m_bignumbers.size())
		{
			maxVector = m_bignumbers;
			minVector = num.m_bignumbers;
		}
		else
		{
			maxVector = num.m_bignumbers;
			minVector = m_bignumbers;
		}
		
		auto maxitr = maxVector.end() - 1;
		auto minitr = minVector.end() - 1;
		vector<int> outVector(maxVector.size() + 1,0);
		int count = 0;
		while (count < maxVector.size())
		{
			int borrow = 0;
			int sum = *maxitr + *minitr;


			outVector[count] += (sum % 10);

			if (sum >= 10 || outVector[count] >= 10)
				borrow = 1;

			count++;

			if (borrow == 1)
			{
				outVector[count] = 1;
			}
			if(maxitr != maxVector.begin())
				maxitr--;
			if (minitr != minVector.begin())
				minitr--;
		}

		std::reverse(outVector.begin(), outVector.end());

		BigNumbers out;
		out.setNumber(outVector);

		return out;
	}

	BigNumbers operator -(const BigNumbers& num)
	{
		vector<int> maxVector;

		if (m_bignumbers.size() > num.m_bignumbers.size())
		{
			maxVector = m_bignumbers;
		}
		else
		{
			maxVector = num.m_bignumbers;
		}

		auto maxitr = m_bignumbers.end() - 1;
		auto minitr = num.m_bignumbers.end() - 1;

		vector<int> outVector(maxVector.size() + 1, 0);

		int count = 0;

		while (count < maxVector.size())
		{
			int borrow = 0;
			int diff = *maxitr - *minitr;

			outVector[count] += (abs(diff));

			if (diff < 0 || outVector[count] < 0)
				borrow = -1;

			count++;

			if (borrow == -1)
			{
				outVector[count] = -1;
			}

			if (maxitr != m_bignumbers.begin())
				maxitr--;
			if (minitr != num.m_bignumbers.begin())
				minitr--;
		}

		std::reverse(outVector.begin(), outVector.end());

		BigNumbers out;
		out.setNumber(outVector);

		return out;
	}


private:
	vector<int> m_bignumbers = { 0 };
};

int main()
{
	char ch;
	vector<int> invector;
	while (ch = getchar())
	{
		if (ch == '\n')
			break;
		int digit = atoi(&ch);
		invector.push_back(digit);
	}
	BigNumbers num;
	num.setNumber(invector);

	BigNumbers num1;
	num1.setNumber("86");

	BigNumbers addsum = num - num1;

}
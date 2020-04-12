#include <vector>
#include <stack>

int getMaxArea(std::vector<int>& vPillars)
{
	std::stack<int> s;

	int maxArea = 0;
	int i = 0;

	while (i < vPillars.size())
	{
		if (s.empty() || vPillars[i] >= vPillars[s.top()])
		{
			s.push(i++);
		}
		else
		{
			int top = s.top();
			s.pop();
			if ((s.empty() ? i : (i - top - 1)) == vPillars[top])
			{
				int area = (s.empty() ? i : (i - top - 1)) *  vPillars[top];
				if (area > maxArea)
					maxArea = area;
			}

		}
	}

	while (!s.empty())
	{
		int top = s.top();
		s.pop();
		if ((s.empty() ? i : (i - top - 1)) == vPillars[top])
		{
			int area = (s.empty() ? i : (i - top - 1)) * vPillars[top];
			if (area > maxArea)
				maxArea = area;
		}
	}

	return maxArea;

}

int maximalSquare(std::vector<std::vector<char>> matrix) {

	if (matrix.size() == 0)
		return 0;

	int maxArea = 0;

	int noofColumns = matrix[0].size();

	std::vector<int> vPillars(noofColumns, 0);

	for (int i = 0;i < matrix.size();i++)
	{
		for (int j = 0;j < noofColumns;j++)
		{
			if ((matrix[i][j] - '0') == 0)
				vPillars[j] = 0;
			else
				vPillars[j] = vPillars[j] + (matrix[i][j] - '0');
		}
		int area = getMaxArea(vPillars);
		if (area > maxArea)
			maxArea = area;
	}

	return maxArea;

}

int main()
{
	maximalSquare({
		{'1','0','1','0','0'},
		{'1','0','1','1','1'},
		{'1','1','1','1','1'},
		{'1','0','0','1','0'}
	 });
}
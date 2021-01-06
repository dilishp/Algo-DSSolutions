#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Compare
{
    int index;
    int maxDay;
	bool operator < (const Compare& day2) const
	{
        return maxDay > day2.maxDay;
	}
};

int eatenApples(std::vector<int>& apples, vector<int>& days) {

    std::vector<int> maxDays(days.size(), 0);
    int i = 0;
    for (int day : days)
    {
        maxDays[i] = i + day;
        ++i;
    }

    std::priority_queue<Compare> appleQueue;
	
    int day = 0, totalApplesTaken = 0;
    for (;;++day)
    {
        int appleTaken = 0;

        while (!appleQueue.empty() && !appleTaken && ((day < apples.size() && apples[day] &&
            appleQueue.top().maxDay < maxDays[day]) ||
            (day < apples.size() && !apples[day]) || day >= apples.size()))
        {
            Compare cmp = appleQueue.top();
            if (day < cmp.maxDay)
            {
                --apples[cmp.index];
                ++appleTaken;
                if (!apples[cmp.index])
                {
                    appleQueue.pop();
                }
            }
            else
                appleQueue.pop();
        }
        
        if (!appleTaken &&
            day >= apples.size())
            break;

    	if (!appleTaken &&
            day < apples.size() && apples[day] && days[day])
        {
            --apples[day];
            ++appleTaken;
            if (apples[day])
            {
                Compare cmp;
                cmp.index = day;
                cmp.maxDay = maxDays[day];
                appleQueue.push(cmp);
            }
        }
        else if (appleTaken &&
            day < apples.size() && apples[day] && days[day])
        {
            Compare cmp;
            cmp.index = day;
            cmp.maxDay = maxDays[day];
            appleQueue.push(cmp);
        }

        if (appleTaken)
            ++totalApplesTaken;
    }

    return totalApplesTaken;
}


int main()
{
    vector<int> apples = { 1, 2, 3, 5, 2 };
    vector<int> days = { 3, 2, 1, 4, 2 };
    cout<<eatenApples(apples, days);
}
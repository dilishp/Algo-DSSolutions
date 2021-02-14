#include "pch.h"
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    std::string minWindow(string s, string t) {
        if (s.length() == 0)
            return "";

        if (s == t)
            return s;

        std::unordered_map<char, int> umap;

        for (char ch : t)
        {
            umap[ch]++;
        }
        std::unordered_map<char, int> refmap(umap);
        umap.clear();
        int i = 0;
        int j = 0;
        int matchCount = 0;
        int minLength = INT_MAX;
        string res = "";
        while (i <= j)
        {
            if (matchCount < refmap.size() &&
                j < s.length())
            {
                if (refmap.find(s[j]) != refmap.end())
                {
                    ++umap[s[j]];
                    if (umap[s[j]] == refmap[s[j]])
                        ++matchCount;
                }
                ++j;
            }
            else
            {

                if ((j - i) < minLength &&
                    matchCount == refmap.size())
                {
                    minLength = j - i;
                    res = s.substr(i, minLength);
                }

            	
                if (refmap.find(s[i]) != refmap.end())
                {
                    --umap[s[i]];
                	if(umap[s[i]] < refmap[s[i]])
						--matchCount;
                }

                ++i;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
	s.minWindow("bbaac",
		"aba");
}

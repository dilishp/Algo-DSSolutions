#include "pch.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    vector<string> res;
    std::unordered_map<char, vector<string>> mappings;
    string _digits;
    void letterCombinations(int currIndex,string result)
    {
        if (currIndex >= _digits.length())
        {
            res.push_back(result);
            return;
        }

        for (auto& s : mappings[_digits[currIndex]])
        {
            result += s;
            letterCombinations(currIndex + 1,result);
            result.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        mappings.insert({ '2',{"a","b","c"} });
        mappings.insert({ '3',{"d","e","f"} });
        mappings.insert({ '4',{"g","h","i"} });
        mappings.insert({ '5',{"j","k","l"} });
        mappings.insert({ '6',{"m","n","o"} });
        mappings.insert({ '7',{"p","q","r","s"} });
        mappings.insert({ '8',{"t","u","v"} });
        mappings.insert({ '9',{"w","x","y","z"} });

        _digits = digits;
        string result;
        letterCombinations(0,result);

        return res;
    }
};

int main()
{
    Solution s;
    s.letterCombinations("23");
}
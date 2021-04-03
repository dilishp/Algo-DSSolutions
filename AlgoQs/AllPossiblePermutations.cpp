#include "pch.h"
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
	vector<vector<int> > permute(vector<int>& num) {
		vector<vector<int> > result;

		permuteRecursive(num, 0, result);
		return result;
	}

	// permute num[begin..end]
	// invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int>& num, int begin, vector<vector<int> >& result) {
		if (begin >= num.size()) {
			// one permutation instance
			result.push_back(num);
			return;
		}

		for (int i = begin; i < num.size(); i++) {
			swap(num[begin], num[i]);
			permuteRecursive(num, begin + 1, result);
			// reset
			swap(num[begin], num[i]);
		}
	}
};

class SubSetSolution {
    vector<int> _nums;
    void subsets(vector<int>& subset, int curIndex, vector<vector<int>>& res)
    {
        if (curIndex >= _nums.size())
        {
			res.push_back(subset);
			return;
        }

        res.push_back(subset);

        for (int i = curIndex;i < _nums.size();++i)
        {
            subset.push_back(_nums[i]);
            subsets(subset, i + 1, res);
            //Back Track
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<vector<int>> result;
        _nums = nums;
        vector<int> subset;
        subsets(subset, 0, result);

        return result;
    }
};

class CombinationSolution {
    vector<vector<int>> res;
    int _n;
    int _k;
    void combine(int currIndex, vector<int>& comb)
    {
        if (comb.size() == _k)
        {
            res.push_back(comb);
            return;
        }

        if (currIndex > _n)
        {
            return;
        }

        comb.push_back(currIndex);
        combine(currIndex + 1, comb);
        comb.pop_back();
        combine(currIndex + 1, comb);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        _n = n;
        _k = k;
        vector<int> comb;
        combine(1, comb);
        return res;
    }
};
int main()
{
    CombinationSolution s;
	s.combine(4,2);
}
#include "pch.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


vector<int> partitionLabels(string S) {
    vector<int> v;
    pmr::unordered_map<char, int> umap;

    for (int i = 0;i < S.length();++i)
    {
        umap[S[i]] = i;
    }

    int index = 0;
    int start = 0;
    int end = 0;
    while (index < S.length())
    {
        int partitionEnd = umap[S[index]];
        for (int i = index;i <= partitionEnd;++i)
        {
            end = max(end, umap[S[i]]);
            partitionEnd = max(partitionEnd, end);
        }
        index += end - start + 1;
        v.push_back(end - start + 1);
        start = end + 1;
    }

    return v;
}
int main()
{
    vector<int> v;
    string s = "qiejxqfnqceocmy";
    partitionLabels(s);
    return 0;
}
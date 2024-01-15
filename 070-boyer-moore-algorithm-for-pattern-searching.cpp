#include <bits/stdc++.h>
using namespace std;

// Today's Date - 13 Jan 2024
// Question Name - Boyer Moore Algorithm for Pattern Searching.

// this is incomplete solution

class Solution
{
public:
    int patternSearch(vector<char> text, string toFind)
    {
    }

    unordered_map<char, int> designBadMatchTable(string toFind)
    {
        int n = toFind.size();
        unordered_map<char, int> badMatchTable;

        for (int i = 0; i < n - 1; ++i)
            badMatchTable[toFind[i]] = max(1, n - i - 1);
        badMatchTable['*'] = n;
        badMatchTable[toFind[n - 1]] = n;

        return badMatchTable;
    }
};

int main()
{
    // vector<int> vec = {};
    Solution solution;

    return 0;
}
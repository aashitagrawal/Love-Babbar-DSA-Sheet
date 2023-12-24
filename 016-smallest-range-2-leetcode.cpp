#include <bits/stdc++.h>
using namespace std;

// Today's Date - 20 Dec
// Leetcode Question Name - Smallest Range II

class Solution
{
public:
    int smallestRangeII(vector<int> &nums, int k)
    {
    }
};

int main()
{
    // vector<int> vec = {7, 8, 8}; //k=4
    vector<int> vec = {7, 8, 8, 5, 2}; // k=4
    Solution solution;
    cout << solution.smallestRangeII(vec, 4) << endl;

    for (auto ele : vec)
        cout << ele << " ";
    return 0;
}
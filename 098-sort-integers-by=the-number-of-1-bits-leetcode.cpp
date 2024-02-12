#include <bits/stdc++.h>
using namespace std;

// Today's Date - 12 Feb 2024
// Leetcode Question Name - Sort Integers by The Number of 1 Bits

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        // return true when the first argument should come before the second argument in the sorted order, and false otherwises
        sort(begin(arr), end(arr), [&](int a, int b)
             {
            if (__builtin_popcount(a) < __builtin_popcount(b))
                return true;
            else if (__builtin_popcount(a) == __builtin_popcount(b) && a < b)
                return true;
            else
                return false; });
        return arr;
    }
};

int main()
{
    Solution solution;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> ans = solution.sortByBits(arr);
    for (auto ele : ans)
        cout << ele << " ";

    return 0;
}
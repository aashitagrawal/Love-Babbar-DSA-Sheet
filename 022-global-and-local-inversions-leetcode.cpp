#include <bits/stdc++.h>
using namespace std;

// Today's Date - 24 Dec 2023
// Leetcode Question Name - Global and Local Inversions

class Solution
{
public:
    bool isIdealPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int maxTillNow = INT_MIN;
        for (int i = 0; i < n - 2; ++i)
        {
            maxTillNow = max(maxTillNow, nums[i]);
            if(maxTillNow > nums[i+2])
                return false;
        }

        return true;
    }
};

int main()
{
    vector<int> vec = {2, 4, 1, 3, 5};
    Solution solution;
    cout << solution.isIdealPermutation(vec) << endl;
    return 0;
}
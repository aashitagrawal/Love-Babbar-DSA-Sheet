#include <bits/stdc++.h>
using namespace std;

// Today's Date - 22 Dec 2023
// Leetcode Question Name - Find the Duplicate Number

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // Phase 1
        int slow = 0;
        int fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2
        int finder = 0;
        while (finder != slow)
        {
            finder = nums[finder];
            slow = nums[slow];
        }

        return finder;
    }
};

// Time Complexity O(n)
// Space Complexity O(1)

int main()
{
    vector<int> vec = {1,5,6,6,3,2,4};
    Solution solution;
    cout << solution.findDuplicate(vec) << endl;
    return 0;
}
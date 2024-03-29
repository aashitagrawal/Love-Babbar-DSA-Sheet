#include <bits/stdc++.h>
using namespace std;

// Today's Date - 5 Feb 2024
// Leetcode Question Name - Find First and Last Position of Element in Sorted Array

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        bool found = binary_search(nums.begin(), nums.end(), target);
        if (!found)
            return {-1, -1};
        auto l = lower_bound(begin(nums), end(nums), target);
        auto r = upper_bound(begin(nums), end(nums), target);

        int left_index = distance(begin(nums), l);
        int right_index;
        if (r == nums.end())
            right_index = nums.size()-1;
        else
            right_index = distance(begin(nums), r) - 1; //-1 because upper bound points to next greater element
        return {left_index, right_index};
    }
};

int main()
{
    vector<int> nums = {1, 1, 2};
    int target = 1;
    Solution solution;
    vector<int> result = solution.searchRange(nums, target);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Today's Date - 6 Feb 2024
// Leetcode Question Name - Search in Rotated Sorted Array

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        const int n = nums.size();
        int index = index_of_smallest_ele(nums);

        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (nums[(mid + index) % n] == target)
                return (mid + index) % n;
            else if (nums[(mid + index) % n] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }

    int index_of_smallest_ele(const vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

int main()
{
    // vector<int> vec = {4, 5, 6, 7, 0, 1, 2};
    vector<int> vec = {5, 4, 3, 2, 1};
    int target = 1;
    Solution solution;
    int result = solution.search(vec, target);
    cout << "result = " << result << endl;
    return 0;
}
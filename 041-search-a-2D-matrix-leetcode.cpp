#include <bits/stdc++.h>
using namespace std;

// Today's Date - 1 Jan 2024
// Leetcode Question Name - Search a 2D Matrix

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int left = 0, right = matrix.size() - 1;
        int middle = left + ((right - left) / 2);

        while (left < right - 1)
        {
            if (matrix[middle][0] > target)
                right = middle - 1;
            else if (matrix[middle][0] < target)
                left = middle;
            else
                return true;
            middle = left + ((right - left) / 2);
        }
        return binary_search(matrix[left], target) || binary_search(matrix[right], target);
    }

    bool binary_search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int middle = left + ((right - left) / 2);

        while (left <= right)
        {
            if (nums[middle] < target)
                left = middle + 1;
            else if (nums[middle] > target)
                right = middle - 1;
            else
                return true;

            middle = left + ((right - left) / 2);
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> vec = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 20;
    Solution solution;
    cout << solution.searchMatrix(vec, target);
    return 0;
}
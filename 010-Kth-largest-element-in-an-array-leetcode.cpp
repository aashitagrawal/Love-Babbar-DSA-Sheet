#include <bits/stdc++.h>
using namespace std;

// Today's Date - 18 Dec 2023
// Leetcode Question Name - Kth-largest-element-in-an-array-leetcode.cpp

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int index_to_find = nums.size() - k;
        return quick_select(nums, 0, nums.size() - 1, index_to_find);
    }

    int quick_select(vector<int> &nums, int low, int high, int index_to_find)
    {
        if (low == high)
            return nums[high];

        srand(time(NULL));
        int random_pivot_index = low + rand() % (high - low);
        swap(nums[high], nums[random_pivot_index]);

        int pivot_element = nums[high];
        int pivot_index = low - 1;
        int j = low;
        int equalPivot = 0;

        while (j != high)
        {
            if (nums[j] <= pivot_element)
            {
                pivot_index++;
                swap(nums[pivot_index], nums[j]);
            }
            if (nums[j] == pivot_element)
                equalPivot++;
            j++;
        }
        pivot_index++;
        swap(nums[pivot_index], nums[high]);

        if (index_to_find <= pivot_index && index_to_find >= pivot_index - equalPivot)
            return nums[pivot_index];
        else if (index_to_find < pivot_index)
            return quick_select(nums, low, pivot_index - 1, index_to_find);
        else
            return quick_select(nums, pivot_index + 1, high, index_to_find);
    }
};

int main()
{
    vector<int> vec = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    Solution solution;
    cout << solution.findKthLargest(vec, 4);

    return 0;
}
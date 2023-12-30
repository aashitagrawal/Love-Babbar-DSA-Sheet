#include <bits/stdc++.h>
using namespace std;

// Today's Date - 30 Dec 2023
// Leetcode Question Name - Three way partitioning

class Solution
{
public:
    void threeWayPartition(vector<int> &nums, int a, int b)
    {
        int i = 0;
        int j = i;
        while (j != nums.size())
        {
            if (nums[j] < a)
                swap(nums[i++], nums[j]);
            j++;
        }

        j = i;
        while (j != nums.size())
        {
            if (nums[j] <= b)
                swap(nums[i++], nums[j]);
            j++;
        }
    }
};

int main()
{
    vector<int> vec = {1, 4, 3, 6, 2, 1};
    Solution solution;
    solution.threeWayPartition(vec, 1, 3);
    for (auto ele : vec)
        cout << ele << " ";
    cout << endl;
    return 0;
}
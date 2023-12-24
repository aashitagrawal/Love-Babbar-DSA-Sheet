#include <bits/stdc++.h>
using namespace std;

// Today's Date - 19 Dec 2023
// Leetcode Question Name - Sort Colors

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int pointer = -1;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == 0)
                swap(nums[++pointer], nums[i]);

        for (int i = pointer + 1; i < nums.size(); ++i)
            if (nums[i] == 1)
                swap(nums[++pointer], nums[i]);
    }
};

int main()
{
    vector<int> vec = {2, 0, 2, 1, 1, 0};

    for (auto ele : vec)
        cout << ele << " ";
    cout << endl;

    Solution solution;
    solution.sortColors(vec);

    for (auto ele : vec)
        cout << ele << " ";
    cout << endl;
    return 0;
}
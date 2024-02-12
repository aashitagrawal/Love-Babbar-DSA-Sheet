#include <bits/stdc++.h>
using namespace std;

// Today's Date - 12 Feb 2024
// Leetcode Question Name - Product of Array Except Self

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        const int n = nums.size();
        vector<int> rightMul(n, 1);
        for (int i = n - 2; i >= 0; --i)
            rightMul[i] = nums[i + 1] * rightMul[i + 1];

        int leftMul = 1;
        for (int i = 0; i < n; ++i)
        {
            rightMul[i] = rightMul[i] * leftMul;
            leftMul = nums[i] * leftMul;
        }

        return rightMul;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = solution.productExceptSelf(nums);

    cout << endl
         << "Final answer = " << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
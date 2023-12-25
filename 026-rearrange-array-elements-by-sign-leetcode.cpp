#include <bits/stdc++.h>
using namespace std;

// Today's Date - 25 Dec 2023
// Leetcode Question Name - Rearrange Array Elements by Sign

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        int pos = 0, neg = 1;
        for (auto ele : nums)
        {
            if (ele > 0)
            {
                ans[pos] = ele;
                pos+=2;
            }
            else
            {
                ans[neg] = ele;
                neg+=2;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> vec = {3, 1, -2, -5, 2, -4};
    Solution solution;
    vec = solution.rearrangeArray(vec);
    for (int ele : vec)
        cout << ele << " ";
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Today's Date - 22 Dec 2023
// Leetcode Question Name - Jump Game 2

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        int currPos = 0;
        while (currPos < n - 1)
        {
            if (currPos + nums[currPos] >= n - 1)
                return ans + 1;

            int startIndex = currPos + 1;
            int endIndex = currPos + nums[currPos];

            int maxi = INT_MIN;
            int nextPos;
            for (int i = startIndex; i <= endIndex; ++i)
            {
                if (nums[i] - (endIndex - i) > maxi)
                {
                    nextPos = i;
                    maxi = nums[i] - (endIndex - i);
                }
            }

            currPos = nextPos;
            // cout<<"jump at = "<<currPos<<endl;
            ans++;
        }
        // cout<<"jump at last"<<endl;
        return ans;
    }
};

int main()
{
    vector<int> vec = {1, 4, 3, 2, 6, 7};
    // vector<int> vec = {2,3,0,1,4};
    Solution solution;
    cout << solution.jump(vec);
    return 0;
}
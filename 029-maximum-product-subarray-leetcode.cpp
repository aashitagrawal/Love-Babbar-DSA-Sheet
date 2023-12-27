#include <bits/stdc++.h>
using namespace std;

// Today's Date - 27 Dec 2023
// Leetcode Question Name - Maximum Product Subarray

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int currMax=1, currMin=1;
        int result = *max_element(nums.begin(), nums.end());
        
        for(int ele: nums)
        {
            if(ele==0)
            {
                currMax = 1;
                currMin = 1;
                continue;
            }
            int a = currMax * ele;
            int b = currMin * ele;
            currMax = max({a,b,ele});
            currMin = min({a,b,ele});
            result = max(result, currMax);
        }

        return result;
    }
};

int main()
{
    vector<int> vec = {2, 3, -2, 4};
    Solution solution;
    cout << solution.maxProduct(vec) << endl;
    return 0;
}
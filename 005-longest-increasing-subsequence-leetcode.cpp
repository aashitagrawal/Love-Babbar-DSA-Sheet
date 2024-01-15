#include<bits/stdc++.h>
using namespace std;

// Today's Date - 11 Dec 2023
// Leetcode Question Name - Longest Increasing SubSequence

class Solution {
public:
    int dp[2505];

    int lengthOfLIS(vector<int>& nums)
    {
        memset(dp, -1, sizeof(dp));
        int answer = -1;
        for(int i=0; i<nums.size(); i++)
            answer = max(answer, length(i,nums));
        
        return answer;
    }

    int length(int index, vector<int>& nums) //returns the max length of subsequence, that ends on the index
    {
        if(dp[index]!=-1)
            return dp[index];

        int answer = 1;
        for(int i=0; i<index; ++i)
            if(nums[index]>nums[i])
                answer = max(answer, length(i,nums)+1);
        
        return dp[index] = answer;
    }
};

//O(N^2)

int main()
{
    vector<int> vec = {10,9,2,5,3,7,101,18};
    Solution solution;
    cout<<solution.lengthOfLIS(vec);

    return 0;
}
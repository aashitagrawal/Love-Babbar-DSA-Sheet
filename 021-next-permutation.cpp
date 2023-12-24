#include <bits/stdc++.h>
using namespace std;

// Today's Date - 24 Dec 2023
// Leetcode Question Name - Next Permutation

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        
        // 1. Find Breakpoint
        int index = n-1;
        for(int i=n-2; i>=0; --i)
        {
            if(nums[i] < nums[i+1])
            {
                index = i;
                break;
            }
        }
        
        if(index==n-1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 2. Swap the index with next permuation
        for(int i=n-1; i>=0; --i)
        {
            if(nums[i] > nums[index])
            {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // 3. Reverse the rest position
        reverse(nums.begin()+index+1, nums.end());
    }
};

int main()
{
    vector<int> vec = {3,2,1};
    Solution solution;
    solution.nextPermutation(vec);

    for (auto ele : vec)
        cout << ele << " ";
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Today's Date - 19 Dec
// Leetcode Question Name - First Missing Positive

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int size_nums = nums.size();
        for (int i = 0; i < size_nums; ++i)
            if (nums[i] <= 0)
                nums[i] = 0;

        // our answer will lie in range [1, len(nums)+1]

        for (int i = 0; i < size_nums; ++i)
        {
            int index = abs(nums[i]) - 1;
            if (index >= 0 && index <= size_nums-1)
            {
                if(nums[index]==0)
                    nums[index] = -1 * (size_nums+1);
                if(nums[index]>0)
                    nums[index] *= -1;
            }
        }

        // now in array, all negative numbers represnts 'marked', and positives and zeros represents unmarked
        //first unmarked number's index + 1 is our solution

        for(int i=0; i<size_nums; ++i)
            if(nums[i]>=0)
                return i+1;
        return size_nums+1;   
    }
};

int main()
{
    Solution solution;
    vector<int> vec = {1, 2, 0};
    cout << solution.firstMissingPositive(vec) << endl;

    vec = {3, 4, -1, 1};
    cout << solution.firstMissingPositive(vec) << endl;

    vec = {7, 8, 9, 11, 12};
    cout << solution.firstMissingPositive(vec) << endl;
    return 0;
}
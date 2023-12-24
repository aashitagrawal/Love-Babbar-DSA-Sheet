#include <bits/stdc++.h>
using namespace std;

// Today's Date - 18 December 2023
// Leetcode Question Name - Removing Minimum and Maximum From Array

class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int max_index = max_element(nums.begin(), nums.end()) - nums.begin();
        int min_index = min_element(nums.begin(), nums.end()) - nums.begin();
        int size = nums.size();

        if (min_index > max_index)
            swap(min_index, max_index);
        
        return min({max_index+1, size-min_index, min_index+1+size-max_index});
    }
};

int main()
{
    vector<int> vec = {2,10,7,5,4,1,8,6};
    for (auto ele : vec)
        cout << ele << " ";
    cout << endl;

    Solution solution;
    cout << solution.minimumDeletions(vec);
    return 0;
}
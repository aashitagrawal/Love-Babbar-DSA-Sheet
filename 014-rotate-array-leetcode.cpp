#include <bits/stdc++.h>
using namespace std;

// Today's Date - 20 Dec
// Leetcode Question Name - Rotate Array

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k%nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7};
    Solution solution;
    solution.rotate(vec,3);

    for(auto ele:vec)
        cout<<ele<<" ";
    cout<<endl;
    return 0;
}
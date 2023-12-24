#include <bits/stdc++.h>
using namespace std;

// Today's Date - 20 Dec 2023
// Leetcode Question Name - Intersection of Two Arrays

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> check(1001, 0);

        for (int i = 0; i < nums1.size(); ++i)
            check[nums1[i]] = 1;
        
        for (int i = 0; i < nums2.size(); ++i)
        {
            if(check[nums2[i]]==1)
                check[nums2[i]]=2; 
        }

        nums1.clear();

        for (int i = 0; i < check.size(); i++)
            if (check[i] == 2)
                nums1.push_back(i);
        return nums1;
    }
};

int main()
{
    vector<int> vec1 = {4,9,5};
    vector<int> vec2 = {9,4,9,8,4};
    Solution solution;
    vector<int> ans = solution.intersection(vec1, vec2);
    for(auto ele:ans) cout<<ele<<" ";
    cout<<endl;
    return 0;
}
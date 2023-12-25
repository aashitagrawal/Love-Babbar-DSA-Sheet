#include <bits/stdc++.h>
using namespace std;

// Today's Date - 25 Dec 2023
// Leetcode Question Name - Find Common Elements Between Two Arrays

class Solution
{
public:
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
    {
        int arr1[101]{}; //initializes array elements to 0
        int arr2[101]{};

        for (auto ele : nums1)
            arr1[ele]++;
        for (auto ele : nums2)
            arr2[ele]++;

        int count1 = 0, count2 = 0;
        for (int i = 0; i < 101; ++i)
        {
            if (arr1[i] != 0 && arr2[i] != 0)
            {
                count1 += arr1[i];
                count2 += arr2[i];
            }
        }
        return {count1, count2};
    }
};

int main()
{
    vector<int> vec1 = {4, 3, 2, 3, 1};
    vector<int> vec2 = {2, 2, 5, 2, 3, 6};
    Solution solution;
    vector<int> ans = solution.findIntersectionValues(vec1, vec2);

    for (auto ele : ans)
        cout << ele << " ";
    cout << endl;

    return 0;
}
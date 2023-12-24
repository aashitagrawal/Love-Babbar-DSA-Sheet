#include <bits/stdc++.h>
using namespace std;

// Today's Date - 22 Dec 2023
// Leetcode Question Name - Merge Sorted Array

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (m == 0)
            nums1 = nums2;
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i != -1 && j != -1)
        {
            if (nums1[i] >= nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }

        if (i == -1)
            while (k != -1)
                nums1[k--] = nums2[j--];
    }
};

int main()
{
    // vector<int> vec = {};
    Solution solution;

    return 0;
}
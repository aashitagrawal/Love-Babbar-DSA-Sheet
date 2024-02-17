#include <bits/stdc++.h>
using namespace std;

// Today's Date - 14 Feb 2024
// Leetcode Question Name - K-th element of two Arrays

class Solution
{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if (n > m)
            return kthElement(arr2, arr1, m, n, k); // making sure nums1 should be smaller

        int low = max(0, k-m);
        int high = min(k,n);
        int elementsInLeft = k;

        while (low <= high)
        {
            int mid1 = low + (high - low) / 2;
            int mid2 = elementsInLeft - mid1;

            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

            if (mid1 < n)
                r1 = arr1[mid1];
            if (mid2 < m)
                r2 = arr2[mid2];
            if (mid1 - 1 >= 0)
                l1 = arr1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = arr2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1)
                return max(l1, l2);
            else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    int arr1[] = {2, 3, 6, 7, 9};
    int arr2[] = {1, 4, 8, 10};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int k = 7;
    cout << solution.kthElement(arr1, arr2, n, m, k);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Today's Date - 30 Dec 2023
// Leetcode Question Name - Minimum swaps and K together

class Solution
{
public:
    int minSwap(int arr[], int n, int k)
    {
        int windowsize = 0;
        for (int i = 0; i < n; ++i)
            if (arr[i] <= k)
                windowsize++;

        int minSwaps = INT_MAX;
        int currNonFavorableElements=0;

        for (int i = 0; i < windowsize; ++i)
            if (arr[i] > k)
                currNonFavorableElements++;
        minSwaps = min(currNonFavorableElements, minSwaps);

        for (int i = windowsize; i < n; ++i)
        {
            if (arr[i] > k && arr[i - windowsize] <= k)
                currNonFavorableElements++;
            if (arr[i] <= k && arr[i - windowsize] > k)
                currNonFavorableElements--;
            minSwaps = min(currNonFavorableElements, minSwaps);
        }
        return minSwaps;
    }
};

int main()
{
    // vector<int> vec = {};
    int n = 7;
    int arr[n] = {2, 7, 9, 5, 8, 7, 4};
    Solution solution;
    cout << solution.minSwap(arr, n, 6) << endl;
    return 0;
}
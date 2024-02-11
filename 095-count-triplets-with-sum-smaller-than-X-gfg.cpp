#include <bits/stdc++.h>
using namespace std;

// Today's Date - 11 Feb 2024
// Leetcode Question Name - Count triplets with sum smaller than X

class Solution
{
public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        long long ans = 0;
        sort(arr, arr + n);

        for (int i = 0; i < n - 2; ++i)
        {
            if (i != 0 && arr[i] == arr[i - 1])
                continue;

            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                long long currsum = 0LL + arr[i] + arr[l] + arr[r];
                if (currsum < sum)
                {
                    ans += (r - l);
                    l++;
                }
                else
                    r--;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    long long arr[] = {-2, 0, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long sum = 2;
    cout << solution.countTriplets(arr, n, sum) << endl;
    return 0;
}
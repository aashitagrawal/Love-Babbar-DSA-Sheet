#include <bits/stdc++.h>
using namespace std;

// Today's Date - 29 Dec 2023
// Leetcode Question Name - Chocolate Distribution Problem

class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(), a.end());
        long long ans = INT_MAX;
        for(int i=0; i<=n-m; ++i)
        {
            ans = min(ans, a[i+m-1]-a[i]);
        }
        return ans;
    }
};

int main()
{
    vector<long long> vec = {11, 13, 7, 5, 13, 12};
    Solution solution;
    cout<<solution.findMinDiff(vec, vec.size(), 4);
    return 0;
}
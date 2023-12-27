#include <bits/stdc++.h>
using namespace std;

// Today's Date - 25 Dec 2023
// Leetcode Question Name - Subarray Sum Equals K

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> hashmap;
        hashmap[0]++;

        int sum = 0, result = 0;
        for (auto ele : nums)
        {
            sum += ele;
            bool isPresent = hashmap.count(sum - k);
            if (isPresent)
                result += hashmap[sum - k];

            hashmap[sum]++; // default value is 0, so no worries
        }

        return result;
    }
};

int main()
{
    vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution solution;
    cout << solution.subarraySum(vec, 0) << endl;
    return 0;
}
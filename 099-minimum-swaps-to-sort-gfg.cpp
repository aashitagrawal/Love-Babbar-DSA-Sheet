#include <bits/stdc++.h>
using namespace std;

// Today's Date - 13 Feb 2024
// GFG Question Name - Minimum Swaps to Sort

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        const int n = nums.size();
        vector<int> sorted = nums;
        sort(begin(sorted), end(sorted));

        unordered_map<int, int> map; // storing real indicies of the each ele
        for (int i = 0; i < n; ++i)
            map[sorted[i]] = i;

        for(auto ele:map)
            cout<<ele.first<<" "<<ele.second<<endl;
        cout<<endl;

        int swaps = 0;
        for (int i = 0; i < n; ++i)
        {
            cout << i << endl;
            auto it = map.find(nums[i]);
            cout<<it->first<<" "<<it->second<<endl;
            while (i != it->second)
            {
                swap(nums[i], nums[it->second]);
                swaps++;
                it = map.find(nums[i]);
            }
        }

        return swaps;
    }
};

int main()
{
    // vector<int> vec = {8, 3, 14, 17, 15, 1, 12};
    vector<int> vec = {0, 2, 3, 4, 5, 1};
    Solution solution;
    cout << "Result = " << solution.minSwaps(vec);
    return 0;
}
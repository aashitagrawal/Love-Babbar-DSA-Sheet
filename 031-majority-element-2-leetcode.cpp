#include <bits/stdc++.h>
using namespace std;

// Today's Date - 27 Dec 2023
// Leetcode Question Name - Majority Element II

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> hashmap;
        for (int &ele : nums)
        {
            hashmap[ele]++;

            if (hashmap.size() <= 2)
                continue;

            for (auto it = hashmap.begin(); it != hashmap.end();)
            {
                it->second--;
                if (it->second == 0)
                    it = hashmap.erase(it);
                else
                    ++it;
            }
        }

        vector<int> ans;
        for(auto &pair : hashmap)
            ans.push_back(pair.first);
        
        for (int i = 0; i < ans.size(); i++)
        {
            int ele = ans[i];
            int countEle = count(nums.begin(), nums.end(), ele);
            if (countEle <= floor(nums.size() / 3))
            {
                ans.erase(ans.begin() + i);
                i--;
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> vec = {1,2,3,3,4,9,3,11};
    Solution solution;
    vec = solution.majorityElement(vec);
    for (auto ele : vec)
        cout << ele << " ";
    cout << endl;
    return 0;
}
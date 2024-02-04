#include <bits/stdc++.h>
using namespace std;

// Today's Date - 3 Feb 2024
// Leetcode Question Name - Group Anagrams

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> hashMap;
        for (const auto ele : strs)
        {
            string sorted = ele;
            sort(begin(sorted), end(sorted));
            hashMap[sorted].push_back(ele);
        }

        vector<vector<string>> answer;
        for (auto ele : hashMap)
            answer.push_back(ele.second);
        return answer;
    }
};

int main()
{
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = solution.groupAnagrams(strs);
    for (const auto &group : result)
    {
        for (const auto &str : group)
            cout << str << " ";
        cout << endl;
    }
    return 0;
}
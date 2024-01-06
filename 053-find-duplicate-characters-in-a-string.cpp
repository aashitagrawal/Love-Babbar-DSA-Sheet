#include <bits/stdc++.h>
using namespace std;

// Today's Date - 6 Jan 2024
// Question Name - Find Duplicate characters in a string

class Solution
{
public:
    vector<pair<char, int>> findDuplicates(string &s)
    {
        unordered_map<char, int> hashMap;
        for (auto &ele : s)
            hashMap[ele]++;

        vector<pair<char, int>> ans;
        for (auto &pair : hashMap)
            if (pair.second > 1)
                ans.push_back({pair.first, pair.second});

        return ans;
    }
};

int main()
{
    string s = "Yes, there is an error in your main function where you initialize the string s. The string should be enclosed in double quotes, not single quotes. Here's the corrected line";
    Solution solution;
    vector<pair<char, int>> ans = solution.findDuplicates(s);
    for (auto &pair : ans)
        cout << pair.first << " -> " << pair.second << endl;
    return 0;
}

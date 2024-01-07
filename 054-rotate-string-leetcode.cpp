#include <bits/stdc++.h>
using namespace std;

// Today's Date - 7 Jan 2023
// Leetcode Question Name - Rotate String

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int n = s.size();
        vector<int> indicies;
        for (int i = 0; i < n; ++i)
            if (goal[i] == s[0])
                indicies.push_back(i);

        bool ans = false;
        for (auto &index : indicies)
        {
            string temp = goal;
            reverse(temp.begin(), temp.begin()+index);
            reverse(temp.begin()+index, temp.end());
            reverse(temp.begin(), temp.end());

            if(temp==s)
            {
                ans |= true;
                break;
            }
        }
        return ans;
    }
};

int main()
{
    string s = "bbbacddceeb";
    string goal = "ceebbbbacdd";
    Solution solution;
    cout << solution.rotateString(s, goal) << endl;
    return 0;
}
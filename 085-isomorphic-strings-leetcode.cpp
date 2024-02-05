#include <bits/stdc++.h>
using namespace std;

// Today's Date - 4 Feb 2024
// Leetcode Question Name - Isomorphic Strings

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        const int size = s.size();
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;

        for (int i = 0; i < size; ++i)
        {
            if (map1[s[i]] && map1[s[i]] != t[i])
                return false;

            if (map2[t[i]] && map2[t[i]] != s[i])
                return false;
            
            map1[s[i]]=t[i];
            map2[t[i]]=s[i];
        }
        return true;
    }
};

int main()
{
    Solution solution;
    cout << solution.isIsomorphic("egg", "add") << endl;     // Expected output: true
    cout << solution.isIsomorphic("foo", "bar") << endl;     // Expected output: false
    cout << solution.isIsomorphic("paper", "title") << endl; // Expected output: true

    return 0;
}
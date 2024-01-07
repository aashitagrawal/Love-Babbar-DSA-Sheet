#include <bits/stdc++.h>
using namespace std;

// Today's Date - 7 Jan 2023
// Question Name - Checking valid shuffle of two Strings

class Solution
{
public:
    bool isShuffle(string s1, string s2, string shuffle)
    {
        unordered_map<char, int> hashMap1;
        unordered_map<char, int> hashMap2;

        for (auto &ele : s1)
            hashMap1[ele]++;
        for (auto &ele : s2)
            hashMap1[ele]++;
        for (auto &ele : shuffle)
            hashMap2[ele]++;

        if (hashMap1.size() != hashMap2.size())
            return false;

        for (auto &pair : hashMap1)
        {
            char key = pair.first;
            int value = pair.second;

            if (hashMap2.find(key) == hashMap2.end() || hashMap2[key] != value)
                return false;
        }

        return true;
    }
};

int main()
{
    string s1 = "BA";
    string s2 = "XY";
    string shuffle = "XAYB";
    Solution solution;
    cout << solution.isShuffle(s1, s2, shuffle) << endl;
    return 0;
}
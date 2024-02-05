#include <bits/stdc++.h>
using namespace std;

// Today's Date - 4 Feb 2024
// GFG Question Name - Transform One String to Another using Minimum Number of Given Operation

class Solution
{
public:
    int transform(string A, string B)
    {
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;

        for(auto ele:A)
            map1[ele]++;
        for(auto ele:B)
            map2[ele]++;
        if(map1!=map2)
            return -1;

        int ans = 0;
        int n = A.size();
        int i = B.size() - 1;
        while (n--)
        {
            if (A[n] == B[i])
                i--;
            else
                ans++;
        }
        return ans;
    }
};

int main()
{
    // vector<int> vec = {};
    Solution solution;
    cout << solution.transform("geeksforgeeks", "forgeeksgeeks") << endl;

    return 0;
}
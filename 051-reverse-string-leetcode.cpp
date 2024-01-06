#include <bits/stdc++.h>
using namespace std;

// Today's Date - 6 Jan 2024
// Leetcode Question Name - Reverse String

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        for(int k=0; k<n/2; ++k)
            swap(s[k], s[n-k-1]);
    }
};

int main()
{
    vector<char> vec = {'h', 'e', 'l', 'l', 'o'};
    Solution solution;
    solution.reverseString(vec);
    for (auto &ele : vec)
        cout << ele;
    return 0;
}
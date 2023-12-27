#include <bits/stdc++.h>
using namespace std;

// Today's Date - 27 Dec 2023
// GFG Question Name - Array Subset of another array

class Solution
{
public:
    string isSubset(int a1[], int a2[], int n, int m)
    {
        unordered_map<int,int> hashmap;
        for (int i = 0; i < n; i++)
            hashmap[a1[i]]++;
        
        string ans = "Yes";
        for (int i = 0; i < m; i++)
        {
            if (hashmap[a2[i]]==0)
            {
                ans = "No";
                break;
            }
            else
                hashmap[a2[i]]--;
        }

        return ans;
    }
};

int main()
{
    // vector<int> vec = {};
    Solution solution;
    int a[8] = {1,2,3,4,5,6,7,8};
    int b[4] = {1,2,3,1};
    cout << solution.isSubset(a, b, 8, 4) << endl;
    return 0;
}
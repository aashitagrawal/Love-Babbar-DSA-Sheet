#include <bits/stdc++.h>
using namespace std;

// Today's Date - 2 Feb 2024
// GFG Question Name - Minimum characters to be added at front to make string palindrome

class Solution
{
public:
    int minChar(string str)
    {
        const int n = str.size();
        int ans=0;
        int left=0, right=n-1;
        while(left<right)
        {
            if(str[left]==str[right])
            {
                left++;
                right--;
            }
            else
            {
                ans++;
                left=0;
                right=n-1-ans;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string str = "aashit";
    int result = solution.minChar(str);
    cout<<result<<endl;
    return 0;
}
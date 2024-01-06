#include <bits/stdc++.h>
using namespace std;

// Today's Date - 6 Jan 2024
// Leetcode Question Name - Valid Palindrome

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string a;
        for(auto&ele:s)
            if(isalnum(ele))
                a+=tolower(ele);

        int i=0, j=a.size()-1;
        while(i<j)
            if(a[i++]!=a[j--])
                return false;
        return true;
    }
};

int main()
{
    string s = "A man, a plan, a canal: Panama";
    Solution solution;
    cout<<solution.isPalindrome(s)<<endl;
    return 0;
}
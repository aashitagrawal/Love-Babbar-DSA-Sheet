#include <bits/stdc++.h>
using namespace std;

// Today's Date - 11 Jan 2024
// GFG Question Name - Count the Reversals

class Solution
{
public:
    int countRev(string s)
    {
        int n = s.size();
        if (n & 1)
            return -1;

        stack<char> stack;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '}' && !stack.empty() && stack.top() == '{')
                stack.pop();
            else
                stack.push(s[i]);
        }

        int open = 0, close=0;
        while (!stack.empty())
        {
            if(stack.top()=='{')
                open++;
            else
                close++;
            stack.pop();
        }

        return ceil(open/2.0) + ceil(close/2.0);
    }
};

int main()
{
    // string s = "}{{}}{{{";
    string s = "}}}}}}{}{}}}{{}}}}{}}{{{}{}{}{}}{{{{}}}{}}";
    Solution solution;
    cout << solution.countRev(s) << endl;
    return 0;
}
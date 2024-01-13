#include <bits/stdc++.h>
using namespace std;

// Today's Date - 9 Jan 2024
// Leetcode Question Name - Valid Parentheses

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> my_stack;
        for (auto &ele : s)
        {
            if (ele == '(' || ele == '{' || ele == '[')
                my_stack.push(ele);
            else
            {
                if (my_stack.empty())
                    return false;

                char top_ele = my_stack.top();
                if (!((top_ele == '(' && ele == ')') || (top_ele == '{' && ele == '}') || (top_ele == '[' && ele == ']')))
                    return false;
                my_stack.pop();
            }
        }
        return my_stack.empty();
    }
};

int main()
{
    string s = "((()))()[]{}";
    Solution solution;
    cout << solution.isValid(s) << endl;
    return 0;
}
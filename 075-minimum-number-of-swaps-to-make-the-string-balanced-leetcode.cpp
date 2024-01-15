#include <bits/stdc++.h>
using namespace std;

// Today's Date - 15 Jan 2024
// Leetcode Question Name - Minimum Number of Swaps to Make the String Balanced

// Initial Solution
// class Solution
// {
// public:
//     int minSwaps(string s)
//     {
//         int n = s.size();
//         if (n == 0)
//             return 0;

//         stack<char> stack;

//         for (auto &bracket : s)
//         {
//             if (!stack.empty() && stack.top() == '[' && bracket == ']')
//                 stack.pop();
//             else
//                 stack.push(bracket);
//             // cout << "Curr ele = " << stack.top() << endl;
//         }

//         int count_of_opening_or_closing_bracket = 0;
//         while (!stack.empty())
//         {
//             cout << stack.top() <<" "<< endl;
//             if (stack.top() == '[')
//                 count_of_opening_or_closing_bracket++;
//             stack.pop();
//         }
//         cout<<"count of opening = "<<count_of_opening_or_closing_bracket<<endl;

//         return ceil(count_of_opening_or_closing_bracket/2.0);
//     }
// };


// Optimized solution
class Solution
{
public:
    int minSwaps(string s)
    {
        int currentClosingBrackets{}, maxClosingBrackets{};
        for(auto&bracket:s)
        {
            if(bracket==']')
                currentClosingBrackets++;
            else
                currentClosingBrackets--;
            maxClosingBrackets = max(maxClosingBrackets, currentClosingBrackets);
        }
        return ceil(maxClosingBrackets/2.0);
    }
};

int main()
{
    Solution solution;
    string s = "][][";
    int result = solution.minSwaps(s);
    cout << "Result: " << result << endl;

    return 0;
}
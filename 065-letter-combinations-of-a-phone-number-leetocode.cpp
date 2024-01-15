#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;
    unordered_map<int, string> digitToChar;

    void backtracking(int curr_digit_index, string currString, string &digits)
    {
        if (curr_digit_index == digits.size())
        {
            ans.push_back(currString);
            return;
        }
        for (char ele : digitToChar[int(digits[curr_digit_index] - '0')])
            backtracking(curr_digit_index + 1, currString + ele, digits);
    }

    vector<string> letterCombinations(string digits)
    {
        digitToChar[2] = "abc";
        digitToChar[3] = "def";
        digitToChar[4] = "ghi";
        digitToChar[5] = "jkl";
        digitToChar[6] = "mno";
        digitToChar[7] = "pqrs";
        digitToChar[8] = "tuv";
        digitToChar[9] = "wxyz";

        if (digits.size() == 0)
            return ans;
        string currString = "";
        backtracking(0, currString, digits);
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<string> result = solution.letterCombinations("23");

    for (const string &str : result)
        cout << str << " ";
    cout << endl;

    return 0;
}

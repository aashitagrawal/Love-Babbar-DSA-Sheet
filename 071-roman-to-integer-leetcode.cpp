#include <bits/stdc++.h>
using namespace std;

// Today's Date - 13 Jan 2024
// Leetcode Question Name - Roman to Integer

class Solution
{
public:
    int romanToInt(string s)
    {
        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            switch (s[i])
            {
            case 'I':
                if (i + 1 < n && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                    result -= 1;
                else
                    result += 1;
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                if (i + 1 < n && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                    result -= 10;
                else
                    result += 10;
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                if (i + 1 < n && (s[i + 1] == 'D' || s[i + 1] == 'M'))
                    result -= 100;
                else
                    result += 100;
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string roman = "MCMXCIV";
    int result = solution.romanToInt(roman);
    cout << "Result: " << result << endl;

    return 0;
}
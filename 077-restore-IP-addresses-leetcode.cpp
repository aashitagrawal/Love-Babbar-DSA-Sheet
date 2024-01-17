#include <bits/stdc++.h>
using namespace std;

// Today's Date - 15 Jan 2024
// Leetcode Question Name - Restore IP Addresses

class Solution
{
private:
    vector<string> answer;
    string ans{};
    int dotCount{};

public:
    vector<string> restoreIpAddresses(string s)
    {
        ipAddress(s, s.size(), 0);
        for (auto &str : answer)
            str.erase(str.length() - 1, 1);

        return answer;
    }
    /**
     * @brief Generates all possible valid IP addresses from a given string.
     *
     * This function takes a string and generates all possible valid IP addresses
     * by splitting the string into four parts and checking if each part is a valid
     * IP address component. The generated IP addresses are stored in the 'result'
     * vector.
     *
     * @param s The input string.
     * @param size The size of the input string.
     * @param index The current index in the input string.
     */
    void ipAddress(string &s, int size, int index)
    {
        if (dotCount > 4)
            return;

        if (index == size && dotCount == 4)
        {
            answer.push_back(ans);
            return;
        }

        for (int len = 1; len <= 3; ++len)
        {
            if ((index + len) <= size && stoi(s.substr(index, len)) <= 255) // index out of bound handling, IP add number out of bound handling
            {
                if (stoi(s.substr(index, len)) == 0 && len > 1)
                    continue;
                else if (s[index] == '0' && len > 1)
                    continue;
                else
                {
                    ans += s.substr(index, len); // start from i, till length 'len'
                    ans += ".";
                    dotCount++;

                    ipAddress(s, size, index + len);

                    ans.erase(ans.length() - (len + 1), len + 1); // erase len+1 elements
                    dotCount--;
                }
            }
        }
    }
};

int main()
{
    Solution solution;
    // string input = "25525511135";
    string input = "101023";
    vector<string> result = solution.restoreIpAddresses(input);

    for (const string &ip : result)
    {
        cout << ip << endl;
    }
    return 0;
}
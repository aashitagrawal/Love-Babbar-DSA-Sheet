#include <bits/stdc++.h>
using namespace std;

// Today's Date - 1 Feb 2024
// Leetcode Question Name - Reorganize String

class Solution
{
public:
    string reorganizeString(string s)
    {
        unordered_map<char, int> hashMap;
        for (auto ele : s)
            hashMap[ele]++;

        priority_queue<pair<int, char>> maxHeap;
        for (auto pair : hashMap)
            maxHeap.push({pair.second, pair.first});

        string ans;
        auto prevPair = make_pair(0, '1');
        while (!maxHeap.empty())
        {
            auto currPair = maxHeap.top();
            maxHeap.pop();

            if (currPair.second != prevPair.second)
            {
                ans.push_back(currPair.second);
                currPair.first--;
                if (currPair.first != 0)
                    maxHeap.push({currPair.first, currPair.second});

                prevPair = currPair;
            }
            else
            {
                if (!maxHeap.empty())
                {
                    auto newCurr = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(currPair);

                    ans.push_back(newCurr.second);
                    newCurr.first--;
                    if (newCurr.first != 0)
                        maxHeap.push({newCurr.first, newCurr.second});
                    prevPair = newCurr;
                }
                else
                    return "";
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string input = "vvvlo"; // Replace "example" with your desired input string
    string result = solution.reorganizeString(input);
    cout << result << endl;

    return 0;
}
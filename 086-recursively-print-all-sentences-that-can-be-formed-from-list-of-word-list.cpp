#include <bits/stdc++.h>
using namespace std;

// Today's Date - 5 Feb 2024
// Question Name - Recursively print all sentences that can be formed from list of word lists

class Solution
{
public:
    vector<string> finalAns;
    string currSentence;

    vector<string> sentence(vector<vector<string>> words)
    {
        foo(words, words.size(), 0);
        return finalAns;
    }

    void foo(const vector<vector<string>> words, const int size, int index)
    {
        if (index == size)
        {
            finalAns.push_back(currSentence);
            return;
        }

        for (auto word : words[index])
        {
            currSentence += word;
            currSentence += " ";
            foo(words, size, index + 1);
            currSentence = currSentence.substr(0, currSentence.length() - word.length() - 1);
        }
    }
};

int main()
{
    Solution solution;
    vector<vector<string>> words = {{"you", "we"}, {"have", "are"}, {"sleep", "eat", "drink"}};
    vector<string> ans = solution.sentence(words);
    for (auto sentence : ans)
    {
        cout << sentence << endl;
    }
    return 0;
}
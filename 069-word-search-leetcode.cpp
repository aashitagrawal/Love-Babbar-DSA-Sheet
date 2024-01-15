#include <bits/stdc++.h>
using namespace std;

// Today's Date - 13 Jan 2024
// Leetcode Question Name - Word Search

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        char target = word[0];
        bool ans = false;
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (board[i][j] == target && patternMatch(board, word, i, j, 0))
                    return true;
        return ans;
    }

    bool patternMatch(vector<vector<char>> &board, string word, int i, int j, int index)
    {
        if (!(i >= 0 && i < board.size() && j >= 0 && j < board[0].size()))
            return false;

        if (board[i][j] != word[index])
            return false;

        if (index + 1 == word.size())
            return true;

        char temp = board[i][j];
        board[i][j] = '0';

        bool res = patternMatch(board, word, i + 1, j, index + 1) ||
                   patternMatch(board, word, i - 1, j, index + 1) ||
                   patternMatch(board, word, i, j + 1, index + 1) ||
                   patternMatch(board, word, i, j - 1, index + 1);
        board[i][j] = temp;
        return res;
    }
};

int main()
{
    Solution solution;
    // vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    vector<vector<char>> board = {{'A', 'H', 'I', 'D'}, {'A', 'S', 'T', 'E'}, {'A', 'D', 'E', 'E'}};
    // string word = "ABCCED";
    string word = "AASHIT";
    bool result = solution.exist(board, word);
    cout << "ans = " << (result ? "true" : "false") << endl;
    return 0;
}
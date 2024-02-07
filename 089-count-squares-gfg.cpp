#include <bits/stdc++.h>
using namespace std;

// Today's Date - 6 Feb 2024
// Leetcode Question Name - Count Squares

class Solution
{
public:
    int countSquares(int N)
    {
        float x = SquareRootBinarySearch(N);
        if(x*x == N)
            return x-1;
        return x;
    }

};

int main()
{
    
    Solution solution;
    cout << solution.countSquares(781445) << endl;
    return 0;
}
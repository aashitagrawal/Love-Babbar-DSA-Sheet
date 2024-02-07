#include <bits/stdc++.h>
using namespace std;

// Today's Date - 6 Feb 2024
// Leetcode Question Name - Count Squares

class Solution
{
public:
    int countSquares(int N)
    {
        double x = sqrt(N);
        cout<<x<<endl;
        if(x*x == double(N))
            return int(x-1);
        return floor(x);
    }

    // double SquareRootBinarySearch(double N)
    // {
    //     if (N == 0 || N == 1)
    //         return N;

    //     double left = 0;
    //     double right = N;
    //     while (right - left > 0.01)
    //     {
    //         double mid = left + ((right - left) / 2);
    //         double square = mid * mid;
    //         if (square == N)
    //             return mid;
    //         else if (square < N)
    //             left = mid;
    //         else
    //             right = mid;
    //     }
    //     return (left + ((right - left) / 2));
    // }
};

int main()
{

    Solution solution;
    cout << solution.countSquares(48580200) << endl;
    return 0;
}
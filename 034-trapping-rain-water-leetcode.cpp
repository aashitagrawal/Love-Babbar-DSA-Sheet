#include <bits/stdc++.h>
using namespace std;

// Today's Date - 28 Dec 2023
// Leetcode Question Name - Trapping Rain Water

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int maxLeft = height[0];
        int maxRight = height[n - 1];

        int i = 0;
        int j = n - 1;

        int answer = 0;

        while (i < j)
        {
            if (maxLeft <= maxRight)
            {
                i++;
                int temp = min(maxLeft, maxRight) - height[i];
                if (temp > 0)
                    answer += temp;
                maxLeft = max(maxLeft, height[i]);
            }
            else
            {
                j--;
                int temp = min(maxLeft, maxRight) - height[j];
                if (temp > 0)
                    answer += temp;
                maxRight = max(maxRight, height[j]);
            }
        }

        return answer;
    }
};

int main()
{
    vector<int> vec = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution solution;
    cout << solution.trap(vec) << endl;
    return 0;
}
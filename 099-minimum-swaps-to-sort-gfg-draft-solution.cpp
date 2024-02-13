#include <bits/stdc++.h>
using namespace std;

// Today's Date - 13 Feb 2024
// GFG Question Name - Minimum Swaps to Sort

class Solution
{
public:
    static constexpr int N = 1e6 + 2;
    vector<int> graph[N];
    bool visited[N] = {false}; // global array initialized to zero/false

    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        const int n = nums.size();
        vector<int> sorted = nums;
        sort(begin(sorted), end(sorted));

        for (int i = 0; i < n; ++i)
        {
            if (sorted[i] != nums[i])
            {
                graph[nums[i]].push_back(sorted[i]);
                graph[sorted[i]].push_back(nums[i]);
            }
        }

        int finalAns = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[nums[i]] == false)
            {
                // for (int i = 1; i <= 20; ++i)
                // {
                //     if (i == 1 || i == 8 || i == 1 || i == 12 || i == 14 || i == 15 || i == 17)
                //         cout << i << " = " << visited[i] << endl;
                // }
                // cout << endl;

                int count = 0;
                dfs(nums[i], count);
                // cout << "count = " << count << endl;
                finalAns += (count - 1);
                // cout << "finalAns = " << finalAns << endl;
                count = 0;
            }
        }
        return finalAns;
    }

    void dfs(int vertex, int &count)
    {
        visited[vertex] = true;
        count++;
        for (int child : graph[vertex])
        {
            if (visited[child])
                continue;
            dfs(child, count);
        }
    }
};

int main()
{
    // vector<int> vec = {8, 3, 14, 17, 15, 1, 12};
    vector<int> vec = {1,3,4,5,2};
    Solution solution;
    cout << "Result = " << solution.minSwaps(vec);
    return 0;
}
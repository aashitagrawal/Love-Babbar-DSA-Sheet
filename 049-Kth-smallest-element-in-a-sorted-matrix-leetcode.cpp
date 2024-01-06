#include<bits/stdc++.h>
using namespace std;

// Today's Date - 5 Jan 2024
// Leetcode Question Name - Kth Smallest Element in a Sorted Matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        priority_queue<int> maxHeap;
        for(auto &vec:matrix)
        {
            for(auto &ele:vec)
            {
                maxHeap.push(ele);
                if(maxHeap.size() > k)
                    maxHeap.pop();
            }
        }

        return maxHeap.top();

    }
};

int main()
{
    vector<vector<int>> vec = {{1,5,9},{10,11,13},{12,13,15}};
    // vector<vector<int>> vec = {{1,2},{1,3}};
    int k = 2;
    Solution solution;
    cout<<solution.kthSmallest(vec, k)<<endl;
    return 0;
}
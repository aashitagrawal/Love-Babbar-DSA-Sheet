#include <bits/stdc++.h>
using namespace std;

// Today's Date - 6 Jan 2024
// Coding Ninjas Question Name - Common Elements Present In All Rows Of Matrix

class Solution
{
public:
    vector<int> findCommonElements(vector<vector<int>> &mat)
    {
        unordered_set<int> tempSet;
        unordered_map<int, int> hashMap;
        for (int row = 0; row < mat.size(); ++row)
        {
            tempSet.clear();
            for (auto &ele : mat[row])
                tempSet.insert(ele);

            if (row == 0)
                for (auto &ele : tempSet)
                    hashMap[ele]++;
            else
                for (auto &ele : tempSet)
                    if (hashMap.count(ele) > 0)
                        hashMap[ele]++;
        }

        vector<int> ans;
        for (auto &pair : hashMap)
        {
            cout << pair.first << " " << pair.second << endl;
            if (pair.second == mat.size())
                ans.push_back(pair.first);
        }
        cout<<"end"<<endl;

        return ans;
    }
};

int main()
{
    // vector<vector<int>> vec = {{0, 0, 3, 5}, {2, 3, 3, 0}, {1, 3, 8, 9}};
    vector<vector<int>> vec = {{1, 4, 5, 6},{3, 4, 5, 6},{5, 6, 7, 2}};
    Solution solution;
    vector<int> ans = solution.findCommonElements(vec);
    for (auto &ele : ans)
        cout << ele << " ";
    cout << endl;
    return 0;
}
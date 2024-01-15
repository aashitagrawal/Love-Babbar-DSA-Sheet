#include <bits/stdc++.h>
using namespace std;

// Today's Date - 15 Jan 2024
// GFG Question Name - Second most repeated string in a sequence

class Solution
{
public:
    string secFrequent(string arr[], int n)
    {
        unordered_map<string, int> hashMap;
        for (int i = 0; i < n; ++i)
            hashMap[arr[i]]++;

        // Print the contents of the hashMap
        for (auto &pair : hashMap)
            cout << pair.first << ": " << pair.second << endl;
        cout << endl;

        int most_freq = INT_MIN;
        for (auto &pair : hashMap)
        {
            if (pair.second > most_freq)
            {
                most_freq = pair.second;
            }
        }

        // Print the contents of the hashMap
        for (auto &pair : hashMap)
            cout << pair.first << ": " << pair.second << endl;
        cout << "most freq = " << most_freq << endl;
        cout << endl;

        int second_most_freq = INT_MIN;
        string ans;
        for (auto &pair : hashMap)
        {
            if (pair.second > second_most_freq && pair.second!=most_freq)
            {
                ans = pair.first;
                second_most_freq = pair.second;
            }
        }

        // Print the contents of the hashMap
        for (auto &pair : hashMap)
            cout << pair.first << ": " << pair.second << endl;
        cout << "second most freq = " << second_most_freq << endl;
        cout << endl;

        return ans;
    }
};

int main()
{
    Solution solution;
    string arr[] = {"apple", "banana", "apple", "orange", "banana", "apple"};
    int n = sizeof(arr) / sizeof(arr[0]);
    string result = solution.secFrequent(arr, n);
    cout << "Second most repeated string: " << result << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Today's Date - 9 Jan 2024
// Leetcode Question Name - Find the Index of the First Occurrence in a String (Rabin Karp Algo)

// About the RAbin Karp Algorithm
//  * An implementation of the Rabin-Karp string-matching algorithm.  Given two
//  * strings - a text string T and a pattern string P, the Rabin-Karp algorithm
//  * outputs the position of the first spot in which P matches T, or reports that
//  * no such matching exists.

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int haystack_size = haystack.length();
        int needle_size = needle.length();

        if (needle_size == 0)
            return 0; // Handle empty needle

        if (needle_size > haystack_size)
            return -1;

        const int prime = 31; // prime number for rolling hash
        const int mod = 1e9 + 9;

        // Precompute powers of prime
        vector<long long> power(needle_size);
        power[0] = 1;
        for (int i = 1; i < needle_size; i++)
            power[i] = (power[i - 1] * prime) % mod;

        // Compute hash values for haystack and needle
        vector<long long> hash(haystack_size + 1, 0);
        for (int i = 0; i < haystack_size; i++)
            hash[i + 1] = (hash[i] + (haystack[i] - 'a' + 1) * power[i]) % mod;

        long long needleHash = 0;
        for (int i = 0; i < needle_size; i++)
            needleHash = (needleHash + (needle[i] - 'a' + 1) * power[i]) % mod;

        // Perform rolling hash and check for match
        for (int i = 0; i + needle_size - 1 < haystack_size; i++)
        {
            long long currHash = (hash[i + needle_size] + mod - hash[i]) % mod;
            if (currHash == needleHash * power[i] % mod && haystack.substr(i, needle_size) == needle)
                return i;
        }

        return -1; // No match found
    }
};

int main()
{
    string haystack = "sadbutsad";
    string needle = "sad";
    Solution solution;

    int result = solution.strStr(haystack, needle);
    cout << result << endl;

    // vector<int> ans = solution.strStr_all_occurrencs(haystack, needle);
    // for (auto &ele : ans)
    //     cout << ele << " ";
    // cout << endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

// Today's Date - 7 Jan 2024
// Leetcode Question Name - Print all Subsequences of a string.

class Solution {
public:
    void printAllSubseq(string subseq, int currIndex, int& size, string& myStr)
    {
        if(currIndex==size)
            cout<<subseq<<endl;
        else
        {
            printAllSubseq(subseq, currIndex+1, size, myStr);
            subseq+=myStr[currIndex];
            printAllSubseq(subseq, currIndex+1, size, myStr);
        }
    }
};

int main()
{
    string myStr = "radha";
    int size = myStr.size();
    Solution solution;
    solution.printAllSubseq("",0,size, myStr);
    return 0;
}
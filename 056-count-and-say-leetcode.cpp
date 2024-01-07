#include <bits/stdc++.h>
using namespace std;

// Today's Date - 7 Jan 2024
// Leetcode Question Name -  Count and Say

class Solution
{
public:
    string countAndSay(int n)
    {
        string currAns = "1";
        if (n == 1)
            return currAns;

        for (int i = 2; i <= n; ++i)
        {
            stringstream newAns;

            int count = 1;
            char currEle = currAns[0];
            for (int index = 1; index < currAns.size(); ++index)
            {
                if (currEle == currAns[index])
                    count++;
                else
                {
                    newAns << count << currEle;
                    currEle = currAns[index];
                    count = 1;
                }
            }
            newAns << count << currEle;
            currAns = newAns.str();
        }
        return currAns;
    }
};

// class Solution
// {
// public:
//     string countAndSay(int n)
//     {
//         string currAns = "1";
//         if (n == 1)
//             return currAns;

//         for (int i = 2; i <= n; ++i)
//         {
//             string newAns;

//             int startIndex = 0;
//             string currEle = currAns.substr(startIndex, 1);
//             for (int index = 0; index < currAns.size() - 1; ++index)
//             {
//                 if (currEle == currAns.substr(index+1, 1))
//                 {
//                     index++;
//                     continue;
//                 }

//                 int count = index - startIndex + 1;
//                 newAns += to_string(count);
//                 newAns += currAns.substr(index, 1);

//                 startIndex = index + 1;
//                 currEle = currAns.substr(startIndex, 1);
//             }
//             int index = currAns.size() - 1;
//             int count = index - startIndex + 1;
//             newAns += to_string(count);
//             newAns += currAns.substr(index, 1);

//             currAns = newAns.str();
//         }
//         return currAns;
//     }
// };

int main()
{
    Solution solution;
    cout << solution.countAndSay(6) << endl;
    return 0;
}